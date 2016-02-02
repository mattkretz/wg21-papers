namespace std {
  namespace experimental {
    namespace datapar_target {
      struct scalar {};  // always present
      // implementation-defined tag types, e.g. sse, avx, avx512, neon, ...
      typedef implementation_defined compatible;  // always present
      typedef implementation_defined widest;  // always present
    }

    struct unaligned_tag {};
    struct aligned_tag {};

    template <class T, size_t N> struct target_for_width { typedef implementation_defined type; };
    template <size_t N> using target_for_width_t = typename target_for_width<N>::type;

    template <class T, class Target = datapar_target::compatible>
    struct datapar_size : public integral_constant<size_t, implementation_defined> {};
    template <class T, class Target = datapar_target::compatible>
    constexpr size_t datapar_size_v = datapar_size<T, Target>::value;

    template <class T, class Target = datapar_target::compatible> class datapar;
    template <class T, class Target = datapar_target::compatible> class mask;

    template <class T, class Target>
    datapar<T, Target> &operator+=(datapar<T, Target> &, const datapar<T, Target> &);
    template <class T, class Target>
    datapar<T, Target> &operator-=(datapar<T, Target> &, const datapar<T, Target> &);
    template <class T, class Target>
    datapar<T, Target> &operator*=(datapar<T, Target> &, const datapar<T, Target> &);
    template <class T, class Target>
    datapar<T, Target> &operator/=(datapar<T, Target> &, const datapar<T, Target> &);
    template <class T, class Target>
    datapar<T, Target> &operator%=(datapar<T, Target> &, const datapar<T, Target> &);
    template <class T, class Target>
    datapar<T, Target> &operator&=(datapar<T, Target> &, const datapar<T, Target> &);
    template <class T, class Target>
    datapar<T, Target> &operator|=(datapar<T, Target> &, const datapar<T, Target> &);
    template <class T, class Target>
    datapar<T, Target> &operator^=(datapar<T, Target> &, const datapar<T, Target> &);
    template <class T, class Target>
    datapar<T, Target> &operator<<=(datapar<T, Target> &, const datapar<T, Target> &);
    template <class T, class Target>
    datapar<T, Target> &operator>>=(datapar<T, Target> &, const datapar<T, Target> &);

    template <class T, class Target>
    datapar<T, Target> operator+(const datapar<T, Target> &, const datapar<T, Target> &);
    template <class T, class Target>
    datapar<T, Target> operator-(const datapar<T, Target> &, const datapar<T, Target> &);
    template <class T, class Target>
    datapar<T, Target> operator*(const datapar<T, Target> &, const datapar<T, Target> &);
    template <class T, class Target>
    datapar<T, Target> operator/(const datapar<T, Target> &, const datapar<T, Target> &);
    template <class T, class Target>
    datapar<T, Target> operator%(const datapar<T, Target> &, const datapar<T, Target> &);
    template <class T, class Target>
    datapar<T, Target> operator&(const datapar<T, Target> &, const datapar<T, Target> &);
    template <class T, class Target>
    datapar<T, Target> operator|(const datapar<T, Target> &, const datapar<T, Target> &);
    template <class T, class Target>
    datapar<T, Target> operator^(const datapar<T, Target> &, const datapar<T, Target> &);
    template <class T, class Target>
    datapar<T, Target> operator<<(const datapar<T, Target> &, const datapar<T, Target> &);
    template <class T, class Target>
    datapar<T, Target> operator>>(const datapar<T, Target> &, const datapar<T, Target> &);

    template <class T, class Target>
    mask<T, Target> operator==(const datapar<T, Target> &, const datapar<T, Target> &);
    template <class T, class Target>
    mask<T, Target> operator!=(const datapar<T, Target> &, const datapar<T, Target> &);
    template <class T, class Target>
    mask<T, Target> operator>=(const datapar<T, Target> &, const datapar<T, Target> &);
    template <class T, class Target>
    mask<T, Target> operator<=(const datapar<T, Target> &, const datapar<T, Target> &);
    template <class T, class Target>
    mask<T, Target> operator>(const datapar<T, Target> &, const datapar<T, Target> &);
    template <class T, class Target>
    mask<T, Target> operator<(const datapar<T, Target> &, const datapar<T, Target> &);

    template <class T> struct is_datapar : public false_type {};
    template <class T, class Target> struct is_datapar<datapar<T, Target>> : public true_type {};
    template <class T> constexpr bool is_datapar_v = is_datapar<T>::value;

    template <class T, class U, class... Us>
    enable_if_t<(T::size() == (U::size() + Us::size()...) / T::size() * T::size() && is_datapar_v<T> &&
                 is_datapar_v<U> && is_datapar_v<Us>...),
                conditional_t<(T::size() == (U::size() + Us::size()...)), T, array<T, N>>>
        datapar_cast(U, Us...);
  }
}
