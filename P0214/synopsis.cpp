namespace std::experimental {
  inline namespace parallelism_v2 {
    namespace simd_abi {
      struct scalar {};
      template <int N> struct fixed_size {};
      template <typename T> inline constexpr int max_fixed_size = implementation-defined;
      template <typename T> using compatible = implementation-defined;
      template <typename T> using native = implementation-defined;
    }

    struct element_aligned_tag {};
    struct vector_aligned_tag {};
    template <size_t> struct overaligned_tag {};
    inline constexpr element_aligned_tag element_aligned{};
    inline constexpr vector_aligned_tag vector_aligned{};
    template <size_t N> inline constexpr overaligned_tag<N> overaligned{};

    // traits \ref{sec:simd.traits}
    template <class T> struct is_abi_tag;
    template <class T> inline constexpr bool is_abi_tag_v = is_abi_tag<T>::value;

    template <class T> struct is_simd;
    template <class T> inline constexpr bool is_simd_v = is_simd<T>::value;

    template <class T> struct is_simd_mask;
    template <class T> inline constexpr bool is_simd_mask_v = is_simd_mask<T>::value;

    template <class T> struct is_simd_flag_type;
    template <class T> inline constexpr bool is_simd_flag_type_v = is_simd_flag_type<T>::value;

    template <class T, size_t N> struct abi_for_size { using type = @\emph{see below}@; };
    template <class T, size_t N> using abi_for_size_t = typename abi_for_size<T, N>::type;

    template <class T, class Abi = simd_abi::compatible<T>> struct simd_size;
    template <class T, class Abi = simd_abi::compatible<T>>
    inline constexpr size_t simd_size_v = simd_size<T, Abi>::value;

    template <class T, class U = typename T::value_type> struct memory_alignment;
    template <class T, class U = typename T::value_type>
    inline constexpr size_t memory_alignment_v = memory_alignment<T, U>::value;

    // class template simd \ref{sec:simd.class}
    template <class T, class Abi = simd_abi::compatible<T>> class simd;
    template <class T> using native_simd = simd<T, simd_abi::native<T>>;
    template <class T, int N> using fixed_size_simd = simd<T, simd_abi::fixed_size<N>>;

    // class template simd_mask \ref{sec:simd.mask.class}
    template <class T, class Abi = simd_abi::compatible<T>> class simd_mask;
    template <class T> using native_simd_mask = simd_mask<T, simd_abi::native<T>>;
    template <class T, int N> using fixed_size_simd_mask = simd_mask<T, simd_abi::fixed_size<N>>;

    // casts \ref{sec:simd.casts}
    template <class T, class U, class Abi> @\emph{see below}@ simd_cast(const simd<U, Abi>&);
    template <class T, class U, class Abi> @\emph{see below}@ static_simd_cast(const simd<U, Abi>&);

    template <class T, class Abi>
    fixed_size_simd<T, simd_size_v<T, Abi>> to_fixed_size(const simd<T, Abi>&) noexcept;
    template <class T, class Abi>
    fixed_size_simd_mask<T, simd_size_v<T, Abi>> to_fixed_size(const simd_mask<T, Abi>&) noexcept;
    template <class T, size_t N> native_simd<T> to_native(const fixed_size_simd<T, N>&) noexcept;
    template <class T, size_t N> native_simd_mask<T> to_native(const fixed_size_simd_mask<T, N>&) noexcept;
    template <class T, size_t N> simd<T> to_compatible(const fixed_size_simd<T, N>&) noexcept;
    template <class T, size_t N> simd_mask<T> to_compatible(const fixed_size_simd_mask<T, N>&) noexcept;

    template <size_t... Sizes, class T, class Abi>
    tuple<simd<T, abi_for_size_t<T, Sizes>>...> split(const simd<T, Abi>&);
    template <size_t... Sizes, class T, class Abi>
    tuple<simd_mask<T, abi_for_size_t<T, Sizes>>...> split(const simd_mask<T, Abi>&);
    template <class V, class Abi>
    array<V, simd_size_v<typename V::value_type, Abi> / V::size()> split(
        const simd<typename V::value_type, Abi>&);
    template <class V, class Abi>
    array<V, simd_size_v<typename V::value_type, Abi> / V::size()> split(
        const simd_mask<typename V::value_type, Abi>&);

    template <class T, class... Abis>
    simd<T, abi_for_size_t<T, (simd_size_v<T, Abis> + ...)>> concat(const simd<T, Abis>&...);
    template <class T, class... Abis>
    simd_mask<T, abi_for_size_t<T, (simd_size_v<T, Abis> + ...)>> concat(const simd_mask<T, Abis>&...);

    // reductions \ref{sec:simd.mask.reductions}
    template <class T, class Abi> bool  all_of(const simd_mask<T, Abi>&) noexcept;
    template <class T, class Abi> bool  any_of(const simd_mask<T, Abi>&) noexcept;
    template <class T, class Abi> bool none_of(const simd_mask<T, Abi>&) noexcept;
    template <class T, class Abi> bool some_of(const simd_mask<T, Abi>&) noexcept;
    template <class T, class Abi> int popcount(const simd_mask<T, Abi>&) noexcept;
    template <class T, class Abi> int find_first_set(const simd_mask<T, Abi>&);
    template <class T, class Abi> int find_last_set(const simd_mask<T, Abi>&);

    bool  all_of(@\emph{see below}@) noexcept;
    bool  any_of(@\emph{see below}@) noexcept;
    bool none_of(@\emph{see below}@) noexcept;
    bool some_of(@\emph{see below}@) noexcept;
    int popcount(@\emph{see below}@) noexcept;
    int find_first_set(@\emph{see below}@) noexcept;
    int find_last_set(@\emph{see below}@) noexcept;

    // masked assignment \ref{sec:simd.whereexpr}
    template <class M, class T> class const_where_expression;
    template <class M, class T> class where_expression;

    // masked assignment \ref{sec:simd.mask.where}
    template <class T> struct nodeduce { using type = T; };            // exposition only
    template <class T> using nodeduce_t = typename nodeduce<T>::type;  // exposition only

    template <class T, class Abi>
    where_expression<simd_mask<T, Abi>, simd<T, Abi>> where(const typename simd<T, Abi>::mask_type&,
                                                            simd<T, Abi>&) noexcept;
    template <class T, class Abi>
    const_where_expression<simd_mask<T, Abi>, const simd<T, Abi>> where(
        const typename simd<T, Abi>::mask_type&, const simd<T, Abi>&) noexcept;

    template <class T, class Abi>
    where_expression<simd_mask<T, Abi>, simd_mask<T, Abi>> where(const nodeduce_t<simd_mask<T, Abi>>&,
                                                                 simd_mask<T, Abi>&) noexcept;
    template <class T, class Abi>
    const_where_expression<simd_mask<T, Abi>, const simd_mask<T, Abi>> where(
        const nodeduce_t<simd_mask<T, Abi>>&, const simd_mask<T, Abi>&) noexcept;

    template <class T> where_expression<bool, T> where(@\emph{see below}@ k, T& d) noexcept;
    template <class T>
    const_where_expression<bool, const T> where(@\emph{see below}@ k, const T& d) noexcept;

    // reductions \ref{sec:simd.reductions}
    template <class T, class Abi, class BinaryOperation = std::plus<>>
    T reduce(const simd<T, Abi>&, BinaryOperation = BinaryOperation());
    template <class M, class V, class BinaryOperation>
    typename V::value_type reduce(const const_where_expression<M, V>& x,
                                  typename V::value_type identity_element, BinaryOperation binary_op);
    template <class M, class V>
    typename V::value_type reduce(const const_where_expression<M, V>& x, plus<> binary_op = plus<>());
    template <class M, class V>
    typename V::value_type reduce(const const_where_expression<M, V>& x, multiplies<> binary_op);
    template <class M, class V>
    typename V::value_type reduce(const const_where_expression<M, V>& x, bit_and<> binary_op);
    template <class M, class V>
    typename V::value_type reduce(const const_where_expression<M, V>& x, bit_or<> binary_op);
    template <class M, class V>
    typename V::value_type reduce(const const_where_expression<M, V>& x, bit_xor<> binary_op);

    template <class T, class Abi> T hmin(const simd<T, Abi>&);
    template <class M, class V> typename V::value_type hmin(const const_where_expression<M, V>&);
    template <class T, class Abi> T hmax(const simd<T, Abi>&);
    template <class M, class V> typename V::value_type hmax(const const_where_expression<M, V>&);

    // algorithms \ref{sec:simd.alg}
    template <class T, class Abi> simd<T, Abi> min(const simd<T, Abi>&, const simd<T, Abi>&) noexcept;
    template <class T, class Abi> simd<T, Abi> max(const simd<T, Abi>&, const simd<T, Abi>&) noexcept;
    template <class T, class Abi>
    std::pair<simd<T, Abi>, simd<T, Abi>> minmax(const simd<T, Abi>&, const simd<T, Abi>&) noexcept;
    template <class T, class Abi>
    simd<T, Abi> clamp(const simd<T, Abi>& v, const simd<T, Abi>& lo, const simd<T, Abi>& hi);
  }
}
