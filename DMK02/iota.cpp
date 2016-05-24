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
    using V = datapar<ContiguousIterator::value_type, abi_for_size_t<N>>;
    const V init = sequence_from_zero<V>() + first_value;
    store(init, std::addressof(*first), flags::unaligned);
    first += V::size();
  }
  epilogue<V::size() / 2>(first, last, init[V::size() - 1] + 1);
}

void iota(/*!\dataparEPT{}*/, ContiguousIterator first, ContiguousIterator last,
          float first_value) {
  using V = datapar<ContiguousIterator::value_type, datapar_abi::native>;
  V init = sequence_from_zero<V>() + first_value;
  const V stride = static_cast<float>(V::size());
  for (; distance(first, last) >= V::size(); first += V::size(), init += stride) {
    store(init, std::addressof(*first), flags::unaligned);
  }
  epilogue<V::size() / 2>(first, last, init[V::size() - 1] + 1);
}
