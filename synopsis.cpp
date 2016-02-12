namespace std {
  namespace experimental {
    namespace datapar_abi {
      struct scalar {};  // always present
      // implementation-defined tag types, e.g. sse, avx, avx512, neon, ...
      typedef implementation_defined compatible;  // always present
      typedef implementation_defined native;  // always present
    }

    struct unaligned_tag {};
    struct aligned_tag {};

    // traits [datapar.traits]
    template <class T> struct is_datapar;
    template <class T> constexpr bool is_datapar_v = is_datapar<T>::value;

    template <class T> struct is_mask;
    template <class T> constexpr bool is_mask_v = is_mask<T>::value;

    template <class T, size_t N> struct abi_for_size { typedef implementation_defined type; };
    template <size_t N> using abi_for_size_t = typename abi_for_size<N>::type;

    template <class T, class Abi = datapar_abi::compatible>
    struct datapar_size : public integral_constant<size_t, implementation_defined> {};
    template <class T, class Abi = datapar_abi::compatible>
    constexpr size_t datapar_size_v = datapar_size<T, Abi>::value;

    // class template datapar [datapar]
    template <class T, class Abi = datapar_abi::compatible> class datapar;

    // class template mask [mask]
    template <class T, class Abi = datapar_abi::compatible> class mask;

    // compound assignment [datapar.cassign]
    template <class T, class Abi, class U> datapar<T, Abi> &operator+= (datapar<T, Abi> &, const U &);
    template <class T, class Abi, class U> datapar<T, Abi> &operator-= (datapar<T, Abi> &, const U &);
    template <class T, class Abi, class U> datapar<T, Abi> &operator*= (datapar<T, Abi> &, const U &);
    template <class T, class Abi, class U> datapar<T, Abi> &operator/= (datapar<T, Abi> &, const U &);
    template <class T, class Abi, class U> datapar<T, Abi> &operator%= (datapar<T, Abi> &, const U &);
    template <class T, class Abi, class U> datapar<T, Abi> &operator&= (datapar<T, Abi> &, const U &);
    template <class T, class Abi, class U> datapar<T, Abi> &operator|= (datapar<T, Abi> &, const U &);
    template <class T, class Abi, class U> datapar<T, Abi> &operator^= (datapar<T, Abi> &, const U &);
    template <class T, class Abi, class U> datapar<T, Abi> &operator<<=(datapar<T, Abi> &, const U &);
    template <class T, class Abi, class U> datapar<T, Abi> &operator>>=(datapar<T, Abi> &, const U &);

    // binary operators [datapar.binary]
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

    // compares [datapar.comparison]
    template <class T, class Abi, class U>
    typename datapar_return_type<datapar<T, Abi>, U>::mask_type operator==(datapar<T, Abi>, const U &);
    template <class T, class Abi, class U>
    typename datapar_return_type<datapar<T, Abi>, U>::mask_type operator!=(datapar<T, Abi>, const U &);
    template <class T, class Abi, class U>
    typename datapar_return_type<datapar<T, Abi>, U>::mask_type operator>=(datapar<T, Abi>, const U &);
    template <class T, class Abi, class U>
    typename datapar_return_type<datapar<T, Abi>, U>::mask_type operator<=(datapar<T, Abi>, const U &);
    template <class T, class Abi, class U>
    typename datapar_return_type<datapar<T, Abi>, U>::mask_type operator> (datapar<T, Abi>, const U &);
    template <class T, class Abi, class U>
    typename datapar_return_type<datapar<T, Abi>, U>::mask_type operator< (datapar<T, Abi>, const U &);
    template <class T, class Abi, class U>
    typename datapar_return_type<datapar<T, Abi>, U>::mask_type operator==(const U &, datapar<T, Abi>);
    template <class T, class Abi, class U>
    typename datapar_return_type<datapar<T, Abi>, U>::mask_type operator!=(const U &, datapar<T, Abi>);
    template <class T, class Abi, class U>
    typename datapar_return_type<datapar<T, Abi>, U>::mask_type operator>=(const U &, datapar<T, Abi>);
    template <class T, class Abi, class U>
    typename datapar_return_type<datapar<T, Abi>, U>::mask_type operator<=(const U &, datapar<T, Abi>);
    template <class T, class Abi, class U>
    typename datapar_return_type<datapar<T, Abi>, U>::mask_type operator> (const U &, datapar<T, Abi>);
    template <class T, class Abi, class U>
    typename datapar_return_type<datapar<T, Abi>, U>::mask_type operator< (const U &, datapar<T, Abi>);

    // casts [datapar.casts]
    template <class T, class U, class... Us>
    conditional_t<(T::size() == (U::size() + Us::size()...)), T,
                  array<T, (U::size() + Us::size()...) / T::size()>> datapar_cast(U, Us...);

    // mask compares [mask.comparison]
    template <class T, class Abi, class U> bool operator==(mask<T, Abi>, const U &);
    template <class T, class Abi, class U> bool operator!=(mask<T, Abi>, const U &);
    template <class T, class Abi, class U> bool operator==(const U &, mask<T, Abi>);
    template <class T, class Abi, class U> bool operator!=(const U &, mask<T, Abi>);

    // reductions [mask.reductions]
    template <class T, class Abi> bool  all_of(mask<T, Abi>);
    constexpr bool  all_of(bool);
    template <class T, class Abi> bool  any_of(mask<T, Abi>);
    constexpr bool  any_of(bool);
    template <class T, class Abi> bool none_of(mask<T, Abi>);
    constexpr bool none_of(bool);
    template <class T, class Abi> bool some_of(mask<T, Abi>);
    constexpr bool some_of(bool);
    template <class T, class Abi> int popcount(mask<T, Abi>);
    constexpr int popcount(bool);
    template <class T, class Abi> int find_first_set(mask<T, Abi>);
    constexpr int find_first_set(bool);

    // masked assignment [mask.where]
    template <class T, class U, class Abi> implementation_defined where(mask<U, Abi>, datapar<T, Abi> &);
    template <class T> implementation_defined where(bool, T &);
  }
}
