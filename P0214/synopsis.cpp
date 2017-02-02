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
    datapar_return_type<datapar<T, Abi>, U> operator+ (const datapar<T, Abi> &, const U &);
    template <class T, class Abi, class U>
    datapar_return_type<datapar<T, Abi>, U> operator- (const datapar<T, Abi> &, const U &);
    template <class T, class Abi, class U>
    datapar_return_type<datapar<T, Abi>, U> operator* (const datapar<T, Abi> &, const U &);
    template <class T, class Abi, class U>
    datapar_return_type<datapar<T, Abi>, U> operator/ (const datapar<T, Abi> &, const U &);
    template <class T, class Abi, class U>
    datapar_return_type<datapar<T, Abi>, U> operator% (const datapar<T, Abi> &, const U &);
    template <class T, class Abi, class U>
    datapar_return_type<datapar<T, Abi>, U> operator& (const datapar<T, Abi> &, const U &);
    template <class T, class Abi, class U>
    datapar_return_type<datapar<T, Abi>, U> operator| (const datapar<T, Abi> &, const U &);
    template <class T, class Abi, class U>
    datapar_return_type<datapar<T, Abi>, U> operator^ (const datapar<T, Abi> &, const U &);
    template <class T, class Abi, class U>
    datapar_return_type<datapar<T, Abi>, U> operator<<(const datapar<T, Abi> &, const U &);
    template <class T, class Abi, class U>
    datapar_return_type<datapar<T, Abi>, U> operator>>(const datapar<T, Abi> &, const U &);
    template <class T, class Abi, class U>
    datapar_return_type<datapar<T, Abi>, U> operator+ (const U &, const datapar<T, Abi> &);
    template <class T, class Abi, class U>
    datapar_return_type<datapar<T, Abi>, U> operator- (const U &, const datapar<T, Abi> &);
    template <class T, class Abi, class U>
    datapar_return_type<datapar<T, Abi>, U> operator* (const U &, const datapar<T, Abi> &);
    template <class T, class Abi, class U>
    datapar_return_type<datapar<T, Abi>, U> operator/ (const U &, const datapar<T, Abi> &);
    template <class T, class Abi, class U>
    datapar_return_type<datapar<T, Abi>, U> operator% (const U &, const datapar<T, Abi> &);
    template <class T, class Abi, class U>
    datapar_return_type<datapar<T, Abi>, U> operator& (const U &, const datapar<T, Abi> &);
    template <class T, class Abi, class U>
    datapar_return_type<datapar<T, Abi>, U> operator| (const U &, const datapar<T, Abi> &);
    template <class T, class Abi, class U>
    datapar_return_type<datapar<T, Abi>, U> operator^ (const U &, const datapar<T, Abi> &);
    template <class T, class Abi, class U>
    datapar_return_type<datapar<T, Abi>, U> operator<<(const U &, const datapar<T, Abi> &);
    template <class T, class Abi, class U>
    datapar_return_type<datapar<T, Abi>, U> operator>>(const U &, const datapar<T, Abi> &);

    // compares [datapar.comparison]
    template <class T, class Abi, class U>
    typename datapar_return_type<datapar<T, Abi>, U>::mask_type operator==(const datapar<T, Abi> &, const U &);
    template <class T, class Abi, class U>
    typename datapar_return_type<datapar<T, Abi>, U>::mask_type operator!=(const datapar<T, Abi> &, const U &);
    template <class T, class Abi, class U>
    typename datapar_return_type<datapar<T, Abi>, U>::mask_type operator>=(const datapar<T, Abi> &, const U &);
    template <class T, class Abi, class U>
    typename datapar_return_type<datapar<T, Abi>, U>::mask_type operator<=(const datapar<T, Abi> &, const U &);
    template <class T, class Abi, class U>
    typename datapar_return_type<datapar<T, Abi>, U>::mask_type operator> (const datapar<T, Abi> &, const U &);
    template <class T, class Abi, class U>
    typename datapar_return_type<datapar<T, Abi>, U>::mask_type operator< (const datapar<T, Abi> &, const U &);
    template <class T, class Abi, class U>
    typename datapar_return_type<datapar<T, Abi>, U>::mask_type operator==(const U &, const datapar<T, Abi> &);
    template <class T, class Abi, class U>
    typename datapar_return_type<datapar<T, Abi>, U>::mask_type operator!=(const U &, const datapar<T, Abi> &);
    template <class T, class Abi, class U>
    typename datapar_return_type<datapar<T, Abi>, U>::mask_type operator>=(const U &, const datapar<T, Abi> &);
    template <class T, class Abi, class U>
    typename datapar_return_type<datapar<T, Abi>, U>::mask_type operator<=(const U &, const datapar<T, Abi> &);
    template <class T, class Abi, class U>
    typename datapar_return_type<datapar<T, Abi>, U>::mask_type operator> (const U &, const datapar<T, Abi> &);
    template <class T, class Abi, class U>
    typename datapar_return_type<datapar<T, Abi>, U>::mask_type operator< (const U &, const datapar<T, Abi> &);

    // casts [datapar.casts]
    template <class T, class U, class... Us>
    conditional_t<(T::size() == (U::size() + Us::size()...)), T,
                  array<T, (U::size() + Us::size()...) / T::size()>> datapar_cast(U, Us...);

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
    template <class M, class T> class where_expression {
    public:
      where_expression(const where_expression &) = delete;
      where_expression &operator=(const where_expression &) = delete;
      where_expression(const M &k, T &d);
      template <class U> void operator=(U &&x);
      template <class U> void operator+=(U &&x);
      template <class U> void operator-=(U &&x);
      template <class U> void operator*=(U &&x);
      template <class U> void operator/=(U &&x);
      template <class U> void operator%=(U &&x);
      template <class U> void operator&=(U &&x);
      template <class U> void operator|=(U &&x);
      template <class U> void operator^=(U &&x);
      template <class U> void operator<<=(U &&x);
      template <class U> void operator>>=(U &&x);
      T &operator++();
      T operator++(int);
      T &operator--();
      T operator--(int);
      T operator-() const;
      auto operator!() const;

    private:
      const M &mask;  // exposition only
      T &data;        // exposition only
    };
    template <class T0, class A0, class T1, class A1>
    where_expression<mask<T1, A1>, datapar<T1, A1>> where(const mask<T0, A0> &, datapar<T1, A1> &);
    template <class T> where_expression<bool, T> where(bool, T &);

    // reductions [datapar.reductions]
    template <class BinaryOperation = std::plus<>, class T, class Abi>
    T reduce(const datapar<T, Abi> &, BinaryOperation = BinaryOperation());
    template <class BinaryOperation = std::plus<>, class M, class V>
    typename V::value_type reduce(const where_expression<M, V> &x,
                                  typename V::value_type init,
                                  BinaryOperation binary_op = BinaryOperation());
    template <class T, class A> T hmin(const datapar<T, A> &);
    template <class M, class V> T hmin(const where_expression<M, V> &);
    template <class T, class A> T hmax(const datapar<T, A> &);
    template <class M, class V> T hmax(const where_expression<M, V> &);

    // algorithms [datapar.alg]
    template <class T, class A>
    datapar<T, A> min(const datapar<T, A> &, const datapar<T, A> &);
    template <class T, class A>
    datapar<T, A> max(const datapar<T, A> &, const datapar<T, A> &);
    template <class T, class A>
    std::pair<datapar<T, A>, datapar<T, A>> minmax(const datapar<T, A> &,
                                                   const datapar<T, A> &);
    template <class T, class A>
    datapar<T, A> clamp(const datapar<T, A> &v, const datapar<T, A> &lo,
                        const datapar<T, A> &hi);
  }
}
