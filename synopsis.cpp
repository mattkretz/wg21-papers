namespace std {
  namespace experimental {
    namespace datapar_abi {
      struct scalar {};  // always present
      template <int N> struct fixed_size {};  // always present
      // implementation-defined tag types, e.g. sse, avx, avx512, neon, ...
      typedef implementation_defined compatible;  // always present
      typedef implementation_defined native;  // always present
    }

    namespace flags {
        struct unaligned_tag {};
        struct aligned_tag {};
        using load_default = unaligned_tag;
        using store_default = unaligned_tag;
        constexpr unaligned_tag unaligned{};
        constexpr aligned_tag aligned{};
    }

    // traits [datapar.traits]
    template <class T> struct is_datapar;
    template <class T> constexpr bool is_datapar_v = is_datapar<T>::value;

    template <class T> struct is_mask;
    template <class T> constexpr bool is_mask_v = is_mask<T>::value;

    template <class T, size_t N> struct abi_for_size { typedef implementation_defined type; };
    template <class T, size_t N> using abi_for_size_t = typename abi_for_size<T, N>::type;

    template <class T, class Abi = datapar_abi::compatible>
    struct datapar_size : public integral_constant<size_t, implementation_defined> {};
    template <class T, class Abi = datapar_abi::compatible>
    constexpr size_t datapar_size_v = datapar_size<T, Abi>::value;

    template <class T, class U = typename T::value_type>
    constexpr size_t memory_alignment = implementation_defined;

    // class template datapar [datapar]
    template <class T, class Abi = datapar_abi::compatible> class datapar;

    // class template mask [mask]
    template <class T, class Abi = datapar_abi::compatible> class mask;

    // datapar load function [datapar.load]
    template <class T = void, class U, class Flags = flags::load_default>
    conditional_t<is_same_v<T, void>, datapar<U>, conditional_t<is_datapar_v<T>, T, datapar<T>>> load(
        const U *, Flags = Flags{});

    // datapar store functions [datapar.store]
    template <class T, class Abi, class U, class Flags = flags::store_default>
    void store(const datapar<T, Abi> &, U *, Flags = Flags{});

    template <class T0, class A0, class U, class T1, class A1, class Flags = flags::store_default>
    void store(const datapar<T0, A0> &, U *, const mask<T1, A1> &, Flags = Flags{});

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
    template <class T, class Flags = flags::load_default> T load(const bool *, Flags = Flags{});

    // mask store functions [mask.store]
    template <class T, class Abi, class Flags = flags::load_default>
    void store(const mask<T, Abi> &, bool *, Flags = Flags{});

    template <class T0, class A0, class T1, class A1, class Flags = flags::load_default>
    void store(const mask<T0, A0> &, bool *, const mask<T1, A1> &, Flags = Flags{});

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
