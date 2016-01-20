namespace std {
  namespace experimental {
    namespace datapar_target {
      struct scalar {};  // always present
      // implementation-defined tag types, e.g. sse, avx, avx512, neon, ...
      typedef implementation_defined widest;  // always present
    }

    struct unaligned_tag {};
    struct aligned_tag {};

    template <typename T, size_t WT> struct target_for_width {
      typedef implementation_defined type;
    };
    template <size_t N> using target_for_width_t = typename target_for_width<N>::type;

    template <typename T, typename Target = implementation_defined> class datapar;
    template <typename T, typename Target = implementation_defined> class mask;

    template <typename T, typename Target>
    template <typename U>
    constexpr size_t datapar<T, Target>::memory_alignment<U>;

    template <typename T, typename Target>
    datapar<T, Target> &operator+=(datapar<T, Target> &, const datapar<T, Target> &);
    template <typename T, typename Target>
    datapar<T, Target> &operator-=(datapar<T, Target> &, const datapar<T, Target> &);
    template <typename T, typename Target>
    datapar<T, Target> &operator*=(datapar<T, Target> &, const datapar<T, Target> &);
    template <typename T, typename Target>
    datapar<T, Target> &operator/=(datapar<T, Target> &, const datapar<T, Target> &);
    template <typename T, typename Target>
    datapar<T, Target> &operator%=(datapar<T, Target> &, const datapar<T, Target> &);
    template <typename T, typename Target>
    datapar<T, Target> &operator&=(datapar<T, Target> &, const datapar<T, Target> &);
    template <typename T, typename Target>
    datapar<T, Target> &operator|=(datapar<T, Target> &, const datapar<T, Target> &);
    template <typename T, typename Target>
    datapar<T, Target> &operator^=(datapar<T, Target> &, const datapar<T, Target> &);
    template <typename T, typename Target>
    datapar<T, Target> &operator<<=(datapar<T, Target> &, const datapar<T, Target> &);
    template <typename T, typename Target>
    datapar<T, Target> &operator>>=(datapar<T, Target> &, const datapar<T, Target> &);

    template <typename T, typename Target>
    datapar<T, Target> operator+(const datapar<T, Target> &, const datapar<T, Target> &);
    template <typename T, typename Target>
    datapar<T, Target> operator-(const datapar<T, Target> &, const datapar<T, Target> &);
    template <typename T, typename Target>
    datapar<T, Target> operator*(const datapar<T, Target> &, const datapar<T, Target> &);
    template <typename T, typename Target>
    datapar<T, Target> operator/(const datapar<T, Target> &, const datapar<T, Target> &);
    template <typename T, typename Target>
    datapar<T, Target> operator%(const datapar<T, Target> &, const datapar<T, Target> &);
    template <typename T, typename Target>
    datapar<T, Target> operator&(const datapar<T, Target> &, const datapar<T, Target> &);
    template <typename T, typename Target>
    datapar<T, Target> operator|(const datapar<T, Target> &, const datapar<T, Target> &);
    template <typename T, typename Target>
    datapar<T, Target> operator^(const datapar<T, Target> &, const datapar<T, Target> &);
    template <typename T, typename Target>
    datapar<T, Target> operator<<(const datapar<T, Target> &, const datapar<T, Target> &);
    template <typename T, typename Target>
    datapar<T, Target> operator>>(const datapar<T, Target> &, const datapar<T, Target> &);

    template <typename T, typename Target>
    mask<T, Target> operator==(const datapar<T, Target> &, const datapar<T, Target> &);
    template <typename T, typename Target>
    mask<T, Target> operator!=(const datapar<T, Target> &, const datapar<T, Target> &);
    template <typename T, typename Target>
    mask<T, Target> operator>=(const datapar<T, Target> &, const datapar<T, Target> &);
    template <typename T, typename Target>
    mask<T, Target> operator<=(const datapar<T, Target> &, const datapar<T, Target> &);
    template <typename T, typename Target>
    mask<T, Target> operator>(const datapar<T, Target> &, const datapar<T, Target> &);
    template <typename T, typename Target>
    mask<T, Target> operator<(const datapar<T, Target> &, const datapar<T, Target> &);

    template <typename T> struct is_datapar : public false_type {};
    template <typename T, typename Target> struct is_datapar<datapar<T, Target>> : public true_type {};
    template <typename T> constexpr bool is_datapar_v = is_datapar<T>::value;

    template <typename T, typename U, typename... Us>
    enable_if_t<(T::size() == (U::size() + Us::size()...) / T::size() * T::size() && is_datapar_v<T> &&
                 is_datapar_v<U> && is_datapar_v<Us>...),
                conditional_t<(T::size() == (U::size() + Us::size()...)), T, array<T, N>>>
        datapar_cast(U, Us...);
  }
}
