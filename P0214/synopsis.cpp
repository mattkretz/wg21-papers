namespace std {
  namespace experimental {
    namespace simd_abi {
      struct scalar {};
      template <int N> struct fixed_size {};
      template <typename T> constexpr int max_fixed_size = implementation-defined;
      template <typename T> using compatible = implementation-defined;
      template <typename T> using native = implementation-defined;
    }

    namespace flags {
      struct element_aligned_tag {};
      struct vector_aligned_tag {};
      template <size_t> struct overaligned_tag {};
      constexpr element_aligned_tag element_aligned{};
      constexpr vector_aligned_tag vector_aligned{};
      template <size_t N> constexpr overaligned_tag<N> overaligned = {};
    }

    // traits [simd.traits]
    template <class T> struct is_abi_tag;
    template <class T> constexpr bool is_abi_tag_v = is_abi_tag<T>::value;

    template <class T> struct is_simd;
    template <class T> constexpr bool is_simd_v = is_simd<T>::value;

    template <class T> struct is_simd_mask;
    template <class T> constexpr bool is_simd_mask_v = is_simd_mask<T>::value;

    template <class T, size_t N> struct abi_for_size { using type = implementation-defined; };
    template <class T, size_t N> using abi_for_size_t = typename abi_for_size<T, N>::type;

    template <class T, class Abi = simd_abi::compatible<T>> struct simd_size;
    template <class T, class Abi = simd_abi::compatible<T>>
    constexpr size_t simd_size_v = simd_size<T, Abi>::value;

    template <class T, class U = typename T::value_type> struct memory_alignment;
    template <class T, class U = typename T::value_type>
    constexpr size_t memory_alignment_v = memory_alignment<T, U>::value;

    // class template simd [simd]
    template <class T, class Abi = simd_abi::compatible<T>> class simd;
    template <class T> using native_simd = simd<T, simd_abi::native<T>>;
    template <class T, int N> using fixed_size_simd = simd<T, simd_abi::fixed_size<N>>;

    // class template simd_mask [simd_mask]
    template <class T, class Abi = simd_abi::compatible<T>> class simd_mask;
    template <class T> using native_mask = simd_mask<T, simd_abi::native<T>>;
    template <class T, int N> using fixed_size_mask = simd_mask<T, simd_abi::fixed_size<N>>;

    // casts [simd.casts]
    template <class T, class U, class A> simd<T, /*see below*/> static_simd_cast(const simd<U, A>&);

    template <class T, class A>
    simd<T, simd_abi::fixed_size<simd_size_v<T, A>>> to_fixed_size(const simd<T, A>&) noexcept;
    template <class T, class A>
    simd_mask<T, simd_abi::fixed_size<simd_size_v<T, A>>> to_fixed_size(const simd_mask<T, A>&) noexcept;
    template <class T, size_t N>
    simd<T, simd_abi::native<T>> to_native(const simd<T, simd_abi::fixed_size<N>>&) noexcept;
    template <class T, size_t N>
    simd_mask<T, simd_abi::native<T>> to_native(const simd_mask<T, simd_abi::fixed_size<N>>&) noexcept;
    template <class T, size_t N>
    simd<T, simd_abi::compatible<T>> to_compatible(const simd<T, simd_abi::fixed_size<N>>&) noexcept;
    template <class T, size_t N>
    simd_mask<T, simd_abi::compatible<T>> to_compatible(const simd_mask<T, simd_abi::fixed_size<N>>&) noexcept;

    // reductions [simd_mask.reductions]
    template <class T, class Abi> bool  all_of(simd_mask<T, Abi>) noexcept;
    template <class T, class Abi> bool  any_of(simd_mask<T, Abi>) noexcept;
    template <class T, class Abi> bool none_of(simd_mask<T, Abi>) noexcept;
    template <class T, class Abi> bool some_of(simd_mask<T, Abi>) noexcept;
    template <class T, class Abi> int popcount(simd_mask<T, Abi>) noexcept;
    template <class T, class Abi> int find_first_set(simd_mask<T, Abi>);
    template <class T, class Abi> int find_last_set(simd_mask<T, Abi>);

    bool  all_of(implementation-defined) noexcept;
    bool  any_of(implementation-defined) noexcept;
    bool none_of(implementation-defined) noexcept;
    bool some_of(implementation-defined) noexcept;
    int popcount(implementation-defined) noexcept;
    int find_first_set(implementation-defined) noexcept;
    int find_last_set(implementation-defined) noexcept;

    // masked assignment [simd_mask.where]
    template <class M, class T> class const_where_expression;
    template <class M, class T> class where_expression;

    template <class T, class A>
    where_expression<simd_mask<T, A>, simd<T, A>> where(const typename simd<T, A>::mask_type&,
                                                        simd<T, A>&) noexcept;
    template <class T, class A>
    const const_where_expression<simd_mask<T, A>, const simd<T, A>> where(
        const typename simd<T, A>::mask_type&, const simd<T, A>&) noexcept;

    template <class T, class A>
    where_expression<simd_mask<T, A>, simd_mask<T, A>> where(const remove_const_t<simd_mask<T, A>>&,
                                                             simd_mask<T, A>&) noexcept;
    template <class T, class A>
    const const_where_expression<simd_mask<T, A>, const simd_mask<T, A>> where(
        const remove_const_t<simd_mask<T, A>>&, const simd_mask<T, A>&) noexcept;

    template <class T> where_expression<bool, T> where(implementation-defined k, T& d) noexcept;

    // reductions [simd.reductions]
    template <class BinaryOperation = std::plus<>, class T, class Abi>
    T reduce(const simd<T, Abi>&, BinaryOperation = BinaryOperation());
    template <class BinaryOperation = std::plus<>, class M, class V>
    typename V::value_type reduce(const const_where_expression<M, V>& x,
                                  typename V::value_type neutral_element = default_neutral_element,
                                  BinaryOperation binary_op = BinaryOperation());

    template <class T, class A> T hmin(const simd<T, A>&) noexcept;
    template <class M, class V> T hmin(const const_where_expression<M, V>&) noexcept;
    template <class T, class A> T hmax(const simd<T, A>&) noexcept;
    template <class M, class V> T hmax(const const_where_expression<M, V>&) noexcept;

    // algorithms [simd.alg]
    template <class T, class A> simd<T, A> min(const simd<T, A>&, const simd<T, A>&) noexcept;
    template <class T, class A> simd<T, A> max(const simd<T, A>&, const simd<T, A>&) noexcept;
    template <class T, class A>
    std::pair<simd<T, A>, simd<T, A>> minmax(const simd<T, A>&, const simd<T, A>&) noexcept;
    template <class T, class A>
    simd<T, A> clamp(const simd<T, A>& v, const simd<T, A>& lo, const simd<T, A>& hi);
  }
}
