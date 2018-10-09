template <size_t N, class ContiguousIterator>
inline void epilogue(ContiguousIterator first, ContiguousIterator last,
                     typename ContiguousIterator::value_type first_value) {
  if constexpr (N > 0) {
    if (distance(first, last) >= N) {
      using T = ContiguousIterator::value_type;
      using V = simd<T, simd_abi::deduce_t<T, N>>;
      const V init = V([&](auto i) { return T(i); }) + first_value;
      store(init, std::addressof(*first), element_aligned);
      first += V::size();
    }
    epilogue<V::size() / 2>(first, last, init[V::size() - 1] + 1);
  }
}

template <class ContiguousIterator>
void iota(/*!\simdEPT{}*/, ContiguousIterator first, ContiguousIterator last,
          typename ContiguousIterator::value_type first_value) {
  using T = ContiguousIterator::value_type;
  using V = native_simd<T>;
  V init = V([&](auto i) { return T(i); }) + first_value;
  const V stride = T(V::size());
  for (; distance(first, last) >= V::size(); first += V::size(), init += stride) {
    store(init, std::addressof(*first), element_aligned);
  }
  epilogue<V::size() / 2>(first, last, init[V::size() - 1] + 1);
}
