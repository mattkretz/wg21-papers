template <size_t N>
void epilogue(ContiguousIterator first, ContiguousIterator last,
              ContiguousIterator::value_type first_value);

template <>
inline void epilogue<0>(ContiguousIterator, ContiguousIterator,
                        ContiguousIterator::value_type) {}

template <size_t N>
inline void epilogue(ContiguousIterator first, ContiguousIterator last,
                     ContiguousIterator::value_type first_value) {
  if (distance(first, last) >= N) {
    using T = ContiguousIterator::value_type;
    using V = simd<T, abi_for_size_t<N>>;
    const V init = V([&](auto i) { return T(i); }) + first_value;
    store(init, std::addressof(*first), flags::element_aligned);
    first += V::size();
  }
  epilogue<V::size() / 2>(first, last, init[V::size() - 1] + 1);
}

void iota(/*!\simdEPT{}*/, ContiguousIterator first, ContiguousIterator last,
          float first_value) {
  using T = ContiguousIterator::value_type;
  using V = simd<T, simd_abi::native>;
  V init = V([&](auto i) { return T(i); }) + first_value;
  const V stride = T(V::size());
  for (; distance(first, last) >= V::size(); first += V::size(), init += stride) {
    store(init, std::addressof(*first), flags::element_aligned);
  }
  epilogue<V::size() / 2>(first, last, init[V::size() - 1] + 1);
}
