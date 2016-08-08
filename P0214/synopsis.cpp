namespace std {
  namespace experimental {
    namespace datapar_abi {
      struct scalar {};  // always present
      template <int N> struct fixed_size {};  // always present
      constexpr int max_fixed_size = implementation_defined;
      // implementation-defined tag types, e.g. sse, avx, neon, altivec, ...
      template <typename T> using compatible = implementation_defined;  // always present
      template <typename T> using native = implementation_defined;  // always present
    }

    namespace flags {
        struct element_aligned_tag {};
        struct vector_aligned_tag {};
        template <std::align_val_t> struct overaligned_tag {};
        constexpr element_aligned_tag element_aligned{};
        constexpr vector_aligned_tag vector_aligned{};
        template <std::align_val_t N> constexpr overaligned_tag<N> overaligned = {};
    }

    // traits [datapar.traits]
    template <class T> struct is_datapar;
    template <class T> constexpr bool is_datapar_v = is_datapar<T>::value;

    template <class T> struct is_mask;
    template <class T> constexpr bool is_mask_v = is_mask<T>::value;

    template <class T, size_t N> struct abi_for_size { typedef implementation_defined type; };
    template <class T, size_t N> using abi_for_size_t = typename abi_for_size<T, N>::type;

    template <class T, class Abi = datapar_abi::compatible<T>>
    struct datapar_size : public integral_constant<size_t, implementation_defined> {};
    template <class T, class Abi = datapar_abi::compatible<T>>
    constexpr size_t datapar_size_v = datapar_size<T, Abi>::value;

    template <class T, class U = typename T::value_type>
    constexpr size_t memory_alignment = implementation_defined;

    // class template datapar [datapar]
    template <class T, class Abi = datapar_abi::compatible<T>> class datapar;

    // class template mask [mask]
    template <class T, class Abi = datapar_abi::compatible<T>> class mask;

    // datapar load function [datapar.load]
    template <class T = void, class U, class Flags>
    conditional_t<is_same_v<T, void>, datapar<U>, conditional_t<is_datapar_v<T>, T, datapar<T>>> load(
        const U *, Flags);

    // datapar store functions [datapar.store]
    template <class T, class Abi, class U, class Flags>
    void store(const datapar<T, Abi> &, U *, Flags);

    template <class T0, class A0, class U, class T1, class A1, class Flags>
    void store(const datapar<T0, A0> &, U *, const mask<T1, A1> &, Flags);

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

    // mask load function [mask.load]
    template <class T, class Flags> T load(const bool *, Flags);

    // mask store functions [mask.store]
    template <class T, class Abi, class Flags>
    void store(const mask<T, Abi> &, bool *, Flags);

    template <class T0, class A0, class T1, class A1, class Flags>
    void store(const mask<T0, A0> &, bool *, const mask<T1, A1> &, Flags);

    // mask binary operators [mask.binary]
    template <class T0, class A0, class T1, class A1> using mask_return_type = ...  // exposition only
    template <class T0, class A0, class T1, class A1>
    mask_return_type<T0, A0, T1, A1> operator&&(const mask<T0, A0> &, const mask<T1, A1> &);
    template <class T0, class A0, class T1, class A1>
    mask_return_type<T0, A0, T1, A1> operator||(const mask<T0, A0> &, const mask<T1, A1> &);
    template <class T0, class A0, class T1, class A1>
    mask_return_type<T0, A0, T1, A1> operator& (const mask<T0, A0> &, const mask<T1, A1> &);
    template <class T0, class A0, class T1, class A1>
    mask_return_type<T0, A0, T1, A1> operator| (const mask<T0, A0> &, const mask<T1, A1> &);
    template <class T0, class A0, class T1, class A1>
    mask_return_type<T0, A0, T1, A1> operator^ (const mask<T0, A0> &, const mask<T1, A1> &);

    // mask compares [mask.comparison]
    template <class T0, class A0, class T1, class A1>
    bool operator==(const mask<T0, A0> &, const mask<T1, A1> &);
    template <class T0, class A0, class T1, class A1>
    bool operator!=(const mask<T0, A0> &, const mask<T1, A1> &);

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
    template <class T, class Abi> int find_last_set(mask<T, Abi>);
    constexpr int find_last_set(bool);

    // masked assignment [mask.where]
    template <class T0, class A0, class T1, class A1>
    implementation_defined where(const mask<T0, A0> &, datapar<T1, A1> &);
    template <class T> implementation_defined where(bool, T &);
  }
}
