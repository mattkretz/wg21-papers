template <size_t N>
epilogue(ContiguousIterator first, ContiguousIterator last,
         ContiguousIterator::value_type first_value);
template <>
inline void epilogue<1>(ContiguousIterator first, ContiguousIterator,
                        ContiguousIterator::value_type first_value) {
  *first = first_value;
}
template <size_t N>
inline void epilogue(ContiguousIterator first, ContiguousIterator last,
                     ContiguousIterator::value_type first_value) {
  if (distance(first, last) >= N) {
    using V = datapar<ContiguousIterator::value_type, datapar_abi::fixed_size<N>>;
    const V init = sequence_from_zero<V>() + first_value;
    store(init, &*first, flags::unaligned);
    first += V::size();
  }
  epilogue<V::size() / 2>(first, last, init[V::size() - 1] + 1);
}
void iota(DataparPolicy, ContiguousIterator first, ContiguousIterator last,
          float first_value) {
  using V = datapar<ContiguousIterator::value_type>;
  V init = sequence_from_zero<V>() + first_value;
  const V stride = static_cast<float>(V::size());
  for (; distance(first, last) >= V::size(); first += V::size(), init += stride) {
    store(init, &*first, flags::unaligned);
  }
  epilogue<V::size() / 2>(first, last, init[V::size() - 1] + 1);
}
