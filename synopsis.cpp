namespace std {
  namespace experimental {
    namespace datapar_abi {
      struct scalar {};  // always present
      // implementation-defined tag types, e.g. sse, avx, avx512, neon, ...
      typedef implementation_defined compatible;  // always present
      typedef implementation_defined widest;  // always present
    }

    struct unaligned_tag {};
    struct aligned_tag {};

    template <class T, size_t N> struct abi_for_width { typedef implementation_defined type; };
    template <size_t N> using abi_for_width_t = typename abi_for_width<N>::type;

    template <class T, class Abi = datapar_abi::compatible>
    struct datapar_size : public integral_constant<size_t, implementation_defined> {};
    template <class T, class Abi = datapar_abi::compatible>
    constexpr size_t datapar_size_v = datapar_size<T, Abi>::value;

    template <class T, class Abi = datapar_abi::compatible> class datapar;
    template <class T, class Abi = datapar_abi::compatible> class mask;

    // compound assignment
    template <class T, class Abi, class U> datapar<T, Abi> &operator+= (datapar<T, Abi> &, U &&);
    template <class T, class Abi, class U> datapar<T, Abi> &operator-= (datapar<T, Abi> &, U &&);
    template <class T, class Abi, class U> datapar<T, Abi> &operator*= (datapar<T, Abi> &, U &&);
    template <class T, class Abi, class U> datapar<T, Abi> &operator/= (datapar<T, Abi> &, U &&);
    template <class T, class Abi, class U> datapar<T, Abi> &operator%= (datapar<T, Abi> &, U &&);
    template <class T, class Abi, class U> datapar<T, Abi> &operator&= (datapar<T, Abi> &, U &&);
    template <class T, class Abi, class U> datapar<T, Abi> &operator|= (datapar<T, Abi> &, U &&);
    template <class T, class Abi, class U> datapar<T, Abi> &operator^= (datapar<T, Abi> &, U &&);
    template <class T, class Abi, class U> datapar<T, Abi> &operator<<=(datapar<T, Abi> &, U &&);
    template <class T, class Abi, class U> datapar<T, Abi> &operator>>=(datapar<T, Abi> &, U &&);

    template <class L, class R> using datapar_return_type = ...;  // exposition only

    template <class T, class Abi, class U>
    datapar_return_type<datapar<T, Abi>, U> operator+ (datapar<T, Abi>, const U &);
    template <class T, class Abi, class U>
    datapar_return_type<datapar<T, Abi>, U> operator- (datapar<T, Abi>, const U &);
    template <class T, class Abi, class U>
    datapar_return_type<datapar<T, Abi>, U> operator* (datapar<T, Abi>, const U &);
    template <class T, class Abi, class U>
    datapar_return_type<datapar<T, Abi>, U> operator/ (datapar<T, Abi>, const U &);
    template <class T, class Abi, class U>
    datapar_return_type<datapar<T, Abi>, U> operator% (datapar<T, Abi>, const U &);
    template <class T, class Abi, class U>
    datapar_return_type<datapar<T, Abi>, U> operator& (datapar<T, Abi>, const U &);
    template <class T, class Abi, class U>
    datapar_return_type<datapar<T, Abi>, U> operator| (datapar<T, Abi>, const U &);
    template <class T, class Abi, class U>
    datapar_return_type<datapar<T, Abi>, U> operator^ (datapar<T, Abi>, const U &);
    template <class T, class Abi, class U>
    datapar_return_type<datapar<T, Abi>, U> operator<<(datapar<T, Abi>, const U &);
    template <class T, class Abi, class U>
    datapar_return_type<datapar<T, Abi>, U> operator>>(datapar<T, Abi>, const U &);
    template <class T, class Abi, class U>
    datapar_return_type<datapar<T, Abi>, U> operator+ (const U &, datapar<T, Abi>);
    template <class T, class Abi, class U>
    datapar_return_type<datapar<T, Abi>, U> operator- (const U &, datapar<T, Abi>);
    template <class T, class Abi, class U>
    datapar_return_type<datapar<T, Abi>, U> operator* (const U &, datapar<T, Abi>);
    template <class T, class Abi, class U>
    datapar_return_type<datapar<T, Abi>, U> operator/ (const U &, datapar<T, Abi>);
    template <class T, class Abi, class U>
    datapar_return_type<datapar<T, Abi>, U> operator% (const U &, datapar<T, Abi>);
    template <class T, class Abi, class U>
    datapar_return_type<datapar<T, Abi>, U> operator& (const U &, datapar<T, Abi>);
    template <class T, class Abi, class U>
    datapar_return_type<datapar<T, Abi>, U> operator| (const U &, datapar<T, Abi>);
    template <class T, class Abi, class U>
    datapar_return_type<datapar<T, Abi>, U> operator^ (const U &, datapar<T, Abi>);
    template <class T, class Abi, class U>
    datapar_return_type<datapar<T, Abi>, U> operator<<(const U &, datapar<T, Abi>);
    template <class T, class Abi, class U>
    datapar_return_type<datapar<T, Abi>, U> operator>>(const U &, datapar<T, Abi>);

    template <class T, class Abi>
    mask<T, Abi> operator==(const datapar<T, Abi> &, const datapar<T, Abi> &);
    template <class T, class Abi>
    mask<T, Abi> operator!=(const datapar<T, Abi> &, const datapar<T, Abi> &);
    template <class T, class Abi>
    mask<T, Abi> operator>=(const datapar<T, Abi> &, const datapar<T, Abi> &);
    template <class T, class Abi>
    mask<T, Abi> operator<=(const datapar<T, Abi> &, const datapar<T, Abi> &);
    template <class T, class Abi>
    mask<T, Abi> operator>(const datapar<T, Abi> &, const datapar<T, Abi> &);
    template <class T, class Abi>
    mask<T, Abi> operator<(const datapar<T, Abi> &, const datapar<T, Abi> &);

    template <class T> struct is_datapar : public false_type {};
    template <class T, class Abi> struct is_datapar<datapar<T, Abi>> : public true_type {};
    template <class T> constexpr bool is_datapar_v = is_datapar<T>::value;

    template <class T, class U, class... Us>
    enable_if_t<(T::size() == (U::size() + Us::size()...) / T::size() * T::size() && is_datapar_v<T> &&
                 is_datapar_v<U> && is_datapar_v<Us>...),
                conditional_t<(T::size() == (U::size() + Us::size()...)), T, array<T, N>>>
        datapar_cast(U, Us...);
  }
}
