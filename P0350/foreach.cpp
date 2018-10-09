template <size_t N, class ContiguousIterator, class UnaryFunction>
inline void epilogue(ContiguousIterator first, ContiguousIterator last,
                     UnaryFunction f) {
  if constexpr (N > 0) {
    using T = ContiguousIterator::value_type;
    using V = simd<T, simd_abi::deduce_t<T, N>>;
    if (distance(first, last) >= V::size()) {
      V tmp(std::addressof(*first), element_aligned);
      f(tmp);
      if constexpr (is_functor_argument_mutable_v<UnaryFunction, V>) {
        store(tmp, std::addressof(*first), element_aligned);
      }
    }
    epilogue<V::size() / 2>(first, last, f);
  }
}

template <class ContiguousIterator, class UnaryFunction>
void for_each(/*!\simdEPT            {}*/, ContiguousIterator first,
              ContiguousIterator last, UnaryFunction f) {
  using V = native_simd<ContiguousIterator::value_type>;
  for (; distance(first, last) >= V::size(); first += V::size()) {
    V tmp(std::addressof(*first), element_aligned);
    f(tmp);
    if constexpr (is_functor_argument_mutable_v<UnaryFunction, V>) {
      store(tmp, std::addressof(*first), element_aligned);
    }
  }
  epilogue<V::size() / 2>(first, last, f);
}
