namespace std {
  namespace experimental {
    template <class Abi> simd<int, Abi> abs(simd<int, Abi>);
    template <class Abi> simd<long, Abi> abs(simd<long, Abi>);
    template <class Abi> simd<long long, Abi> abs(simd<long long, Abi>);
    template <class Abi> simd<long, Abi> labs(simd<long, Abi>);
    template <class Abi> simd<long long, Abi> llabs(simd<long long, Abi>);

    template <class V> struct simd_div_t { V quot, rem; };
    template <class Abi> simd_div_t<simd<int, Abi>> div(simd<int, Abi>);
    template <class Abi> simd_div_t<simd<long, Abi>> ldiv(simd<long, Abi>);
    template <class Abi> simd_div_t<simd<long long, Abi>> lldiv(simd<long long, Abi>);
  }
}
