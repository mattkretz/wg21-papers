namespace std {
  namespace experimental {
    template <class Abi> datapar<int, Abi> abs(datapar<int, Abi>);
    template <class Abi> datapar<long, Abi> abs(datapar<long, Abi>);
    template <class Abi> datapar<long long, Abi> abs(datapar<long long, Abi>);
    template <class Abi> datapar<long, Abi> labs(datapar<long, Abi>);
    template <class Abi> datapar<long long, Abi> llabs(datapar<long long, Abi>);

    template <class V> struct datapar_div_t { V quot, rem; };
    template <class Abi> datapar_div_t<datapar<int, Abi>> div(datapar<int, Abi>);
    template <class Abi> datapar_div_t<datapar<long, Abi>> ldiv(datapar<long, Abi>);
    template <class Abi> datapar_div_t<datapar<long long, Abi>> lldiv(datapar<long long, Abi>);
  }
}
