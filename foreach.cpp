void for_each(DataparPolicy, ContiguousIterator first, ContiguousIterator last,
              UnaryFunction f) {
  using V = datapar<ContiguousIterator::value_type>;
  using V1 = datapar<ContiguousIterator::value_type, datapar_abi::scalar>;
  for (; distance(first, last) >= V::size(); first += V::size()) {
    V tmp = load<V>(std::addressof(*first), flags::unaligned);
    f(tmp);
    if (Traits::is_functor_argument_mutable<UnaryFunction, V>::value) {
      store(tmp, std::addressof(*first), flags::unaligned);
    }
  }
  for (; first != last; ++first) {
    V1 tmp =load<V1>(std::addressof(*first), flags::unaligned);
    f(tmp);
    if (Traits::is_functor_argument_mutable<UnaryFunction, V1>::value) {
      store(tmp, std::addressof(*first), flags::unaligned);
    }
  }
}
