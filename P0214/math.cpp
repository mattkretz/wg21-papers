namespace std {
  namespace experimental {
    template <class Abi> using floatv = datapar<float, Abi>;  // exposition only
    template <class Abi> using doublev = datapar<double, Abi>;  // exposition only
    template <class Abi> using ldoublev = datapar<long double, Abi>;  // exposition only
    template <class T, class V>
    using samesize = datapar<T, abi_for_size_t<V::size()>>;  // exposition only

    template <class Abi> floatv<Abi> abs(floatv<Abi>);
    template <class Abi> floatv<Abi> cbrt(floatv<Abi>);
    template <class Abi> floatv<Abi> ceil(floatv<Abi>);
    template <class Abi> floatv<Abi> copysign(floatv<Abi>, floatv<Abi>);
    template <class Abi> floatv<Abi> fdim(floatv<Abi>, floatv<Abi>);
    template <class Abi> floatv<Abi> floor(floatv<Abi>);
    template <class Abi> floatv<Abi> fma(floatv<Abi>, floatv<Abi>, floatv<Abi>);
    template <class Abi> floatv<Abi> fmax(floatv<Abi>, floatv<Abi>);
    template <class Abi> floatv<Abi> fmin(floatv<Abi>, floatv<Abi>);
    template <class Abi> floatv<Abi> fmod(floatv<Abi>, floatv<Abi>);
    template <class Abi> floatv<Abi> frexp(floatv<Abi>, samesize<int, floatv<Abi>> *);
    template <class Abi> floatv<Abi> hypot(floatv<Abi>, floatv<Abi>);
    template <class Abi> floatv<Abi> hypot(floatv<Abi>, floatv<Abi>, floatv<Abi>);
    template <class Abi> samesize<int, floatv<Abi>> ilogb(floatv<Abi>);
    template <class Abi> floatv<Abi> ldexp(floatv<Abi>, samesize<int, floatv<Abi>>);
    template <class Abi> floatv<Abi> logb(floatv<Abi>);
    template <class Abi> samesize<long, floatv<Abi>> lrint(floatv<Abi>);
    template <class Abi> samesize<long, floatv<Abi>> lround(floatv<Abi>);
    template <class Abi> floatv<Abi> modf(floatv<Abi>, floatv<Abi> *);
    template <class Abi> floatv<Abi> nan(floatv<Abi>);
    template <class Abi> floatv<Abi> nanf(floatv<Abi>);
    template <class Abi> floatv<Abi> nanl(floatv<Abi>);
    template <class Abi> floatv<Abi> nearbyint(floatv<Abi>);
    template <class Abi> floatv<Abi> nextafter(floatv<Abi>, floatv<Abi>);
    template <class Abi> floatv<Abi> nexttoward(floatv<Abi>, samesize<long double, floatv<Abi>>);
    template <class Abi> floatv<Abi> remainder(floatv<Abi>, floatv<Abi>);
    template <class Abi> floatv<Abi> remquo(floatv<Abi>, floatv<Abi>, samesize<int, floatv<Abi>> *);
    template <class Abi> floatv<Abi> rint(floatv<Abi>);
    template <class Abi> floatv<Abi> round(floatv<Abi>);
    template <class Abi> floatv<Abi> scalbln(floatv<Abi>, samesize<long, floatv<Abi>>);
    template <class Abi> floatv<Abi> scalbn(floatv<Abi>, samesize<int, floatv<Abi>>);
    template <class Abi> floatv<Abi> sqrt(floatv<Abi>);
    template <class Abi> floatv<Abi> trunc(floatv<Abi>);

    template <class Abi> doublev<Abi> abs(doublev<Abi>);
    template <class Abi> doublev<Abi> cbrt(doublev<Abi>);
    template <class Abi> doublev<Abi> ceil(doublev<Abi>);
    template <class Abi> doublev<Abi> copysign(doublev<Abi>, doublev<Abi>);
    template <class Abi> doublev<Abi> fdim(doublev<Abi>, doublev<Abi>);
    template <class Abi> doublev<Abi> floor(doublev<Abi>);
    template <class Abi> doublev<Abi> fma(doublev<Abi>, doublev<Abi>, doublev<Abi>);
    template <class Abi> doublev<Abi> fmax(doublev<Abi>, doublev<Abi>);
    template <class Abi> doublev<Abi> fmin(doublev<Abi>, doublev<Abi>);
    template <class Abi> doublev<Abi> fmod(doublev<Abi>, doublev<Abi>);
    template <class Abi> doublev<Abi> frexp(doublev<Abi>, samesize<int, doublev<Abi>> *);
    template <class Abi> doublev<Abi> hypot(doublev<Abi>, doublev<Abi>);
    template <class Abi> doublev<Abi> hypot(doublev<Abi>, doublev<Abi>, doublev<Abi>);
    template <class Abi> samesize<int, doublev<Abi>> ilogb(doublev<Abi>);
    template <class Abi> doublev<Abi> ldexp(doublev<Abi>, samesize<int, doublev<Abi>>);
    template <class Abi> doublev<Abi> logb(doublev<Abi>);
    template <class Abi> samesize<long, doublev<Abi>> lrint(doublev<Abi>);
    template <class Abi> samesize<long, doublev<Abi>> lround(doublev<Abi>);
    template <class Abi> doublev<Abi> modf(doublev<Abi>, doublev<Abi> *);
    template <class Abi> doublev<Abi> nan(doublev<Abi>);
    template <class Abi> doublev<Abi> nanf(doublev<Abi>);
    template <class Abi> doublev<Abi> nanl(doublev<Abi>);
    template <class Abi> doublev<Abi> nearbyint(doublev<Abi>);
    template <class Abi> doublev<Abi> nextafter(doublev<Abi>, doublev<Abi>);
    template <class Abi> doublev<Abi> nexttoward(doublev<Abi>, samesize<long double, doublev<Abi>>);
    template <class Abi> doublev<Abi> remainder(doublev<Abi>, doublev<Abi>);
    template <class Abi> doublev<Abi> remquo(doublev<Abi>, doublev<Abi>, samesize<int, doublev<Abi>> *);
    template <class Abi> doublev<Abi> rint(doublev<Abi>);
    template <class Abi> doublev<Abi> round(doublev<Abi>);
    template <class Abi> doublev<Abi> scalbln(doublev<Abi>, samesize<long, doublev<Abi>>);
    template <class Abi> doublev<Abi> scalbn(doublev<Abi>, samesize<int, doublev<Abi>>);
    template <class Abi> doublev<Abi> sqrt(doublev<Abi>);
    template <class Abi> doublev<Abi> trunc(doublev<Abi>);

    template <class Abi> ldoublev<Abi> abs(ldoublev<Abi>);
    template <class Abi> ldoublev<Abi> cbrt(ldoublev<Abi>);
    template <class Abi> ldoublev<Abi> ceil(ldoublev<Abi>);
    template <class Abi> ldoublev<Abi> copysign(ldoublev<Abi>, ldoublev<Abi>);
    template <class Abi> ldoublev<Abi> fdim(ldoublev<Abi>, ldoublev<Abi>);
    template <class Abi> ldoublev<Abi> floor(ldoublev<Abi>);
    template <class Abi> ldoublev<Abi> fma(ldoublev<Abi>, ldoublev<Abi>, ldoublev<Abi>);
    template <class Abi> ldoublev<Abi> fmax(ldoublev<Abi>, ldoublev<Abi>);
    template <class Abi> ldoublev<Abi> fmin(ldoublev<Abi>, ldoublev<Abi>);
    template <class Abi> ldoublev<Abi> fmod(ldoublev<Abi>, ldoublev<Abi>);
    template <class Abi> ldoublev<Abi> frexp(ldoublev<Abi>, samesize<int, ldoublev<Abi>> *);
    template <class Abi> ldoublev<Abi> hypot(ldoublev<Abi>, ldoublev<Abi>);
    template <class Abi> ldoublev<Abi> hypot(ldoublev<Abi>, ldoublev<Abi>, ldoublev<Abi>);
    template <class Abi> samesize<int, ldoublev<Abi>> ilogb(ldoublev<Abi>);
    template <class Abi> ldoublev<Abi> ldexp(ldoublev<Abi>, samesize<int, ldoublev<Abi>>);
    template <class Abi> ldoublev<Abi> logb(ldoublev<Abi>);
    template <class Abi> samesize<long, ldoublev<Abi>> lrint(ldoublev<Abi>);
    template <class Abi> samesize<long, ldoublev<Abi>> lround(ldoublev<Abi>);
    template <class Abi> ldoublev<Abi> modf(ldoublev<Abi>, ldoublev<Abi> *);
    template <class Abi> ldoublev<Abi> nan(ldoublev<Abi>);
    template <class Abi> ldoublev<Abi> nanf(ldoublev<Abi>);
    template <class Abi> ldoublev<Abi> nanl(ldoublev<Abi>);
    template <class Abi> ldoublev<Abi> nearbyint(ldoublev<Abi>);
    template <class Abi> ldoublev<Abi> nextafter(ldoublev<Abi>, ldoublev<Abi>);
    template <class Abi> ldoublev<Abi> nexttoward(ldoublev<Abi>, ldoublev<Abi>);
    template <class Abi> ldoublev<Abi> remainder(ldoublev<Abi>, ldoublev<Abi>);
    template <class Abi> ldoublev<Abi> remquo(ldoublev<Abi>, ldoublev<Abi>, samesize<int, ldoublev<Abi>> *);
    template <class Abi> ldoublev<Abi> rint(ldoublev<Abi>);
    template <class Abi> ldoublev<Abi> round(ldoublev<Abi>);
    template <class Abi> ldoublev<Abi> scalbln(ldoublev<Abi>, samesize<long, ldoublev<Abi>>);
    template <class Abi> ldoublev<Abi> scalbn(ldoublev<Abi>, samesize<int, ldoublev<Abi>>);
    template <class Abi> ldoublev<Abi> sqrt(ldoublev<Abi>);
    template <class Abi> ldoublev<Abi> trunc(ldoublev<Abi>);

    template <class Abi> samesize<int, floatv<Abi>> fpclassify(floatv<Abi>);
    template <class Abi> mask<float, Abi> isfinite(floatv<Abi>);
    template <class Abi> mask<float, Abi> isgreater(floatv<Abi>);
    template <class Abi> mask<float, Abi> isgreaterequal(floatv<Abi>);
    template <class Abi> mask<float, Abi> isinf(floatv<Abi>);
    template <class Abi> mask<float, Abi> isless(floatv<Abi>);
    template <class Abi> mask<float, Abi> islessequal(floatv<Abi>);
    template <class Abi> mask<float, Abi> islessgreater(floatv<Abi>);
    template <class Abi> mask<float, Abi> isnan(floatv<Abi>);
    template <class Abi> mask<float, Abi> isnormal(floatv<Abi>);
    template <class Abi> mask<float, Abi> isunordered(floatv<Abi>);
    template <class Abi> mask<float, Abi> signbit(floatv<Abi>);

    template <class Abi> samesize<int, doublev<Abi>> fpclassify(doublev<Abi>);
    template <class Abi> mask<double, Abi> isfinite(doublev<Abi>);
    template <class Abi> mask<double, Abi> isgreater(doublev<Abi>);
    template <class Abi> mask<double, Abi> isgreaterequal(doublev<Abi>);
    template <class Abi> mask<double, Abi> isinf(doublev<Abi>);
    template <class Abi> mask<double, Abi> isless(doublev<Abi>);
    template <class Abi> mask<double, Abi> islessequal(doublev<Abi>);
    template <class Abi> mask<double, Abi> islessgreater(doublev<Abi>);
    template <class Abi> mask<double, Abi> isnan(doublev<Abi>);
    template <class Abi> mask<double, Abi> isnormal(doublev<Abi>);
    template <class Abi> mask<double, Abi> isunordered(doublev<Abi>);
    template <class Abi> mask<double, Abi> signbit(doublev<Abi>);

    template <class Abi> samesize<int, ldoublev<Abi>> fpclassify(ldoublev<Abi>);
    template <class Abi> mask<long double, Abi> isfinite(ldoublev<Abi>);
    template <class Abi> mask<long double, Abi> isgreater(ldoublev<Abi>);
    template <class Abi> mask<long double, Abi> isgreaterequal(ldoublev<Abi>);
    template <class Abi> mask<long double, Abi> isinf(ldoublev<Abi>);
    template <class Abi> mask<long double, Abi> isless(ldoublev<Abi>);
    template <class Abi> mask<long double, Abi> islessequal(ldoublev<Abi>);
    template <class Abi> mask<long double, Abi> islessgreater(ldoublev<Abi>);
    template <class Abi> mask<long double, Abi> isnan(ldoublev<Abi>);
    template <class Abi> mask<long double, Abi> isnormal(ldoublev<Abi>);
    template <class Abi> mask<long double, Abi> isunordered(ldoublev<Abi>);
    template <class Abi> mask<long double, Abi> signbit(ldoublev<Abi>);
  }
}
