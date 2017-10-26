namespace std {
  namespace experimental {
    template <class Abi> using scharv = simd<signed char, Abi>;                  // exposition only
    template <class Abi> using shortv = simd<short, Abi>;                        // exposition only
    template <class Abi> using intv = simd<int, Abi>;                            // exposition only
    template <class Abi> using longv = simd<long int, Abi>;                      // exposition only
    template <class Abi> using llongv = simd<long long int, Abi>;                // exposition only
    template <class Abi> using floatv = simd<float, Abi>;                        // exposition only
    template <class Abi> using doublev = simd<double, Abi>;                      // exposition only
    template <class Abi> using ldoublev = simd<long double, Abi>;                // exposition only
    template <class T, class V> using samesize = fixed_size_simd<T, V::size()>;  // exposition only

    template <class Abi> floatv<Abi> acos(floatv<Abi> x);
    template <class Abi> doublev<Abi> acos(doublev<Abi> x);
    template <class Abi> ldoublev<Abi> acos(ldoublev<Abi> x);

    template <class Abi> floatv<Abi> asin(floatv<Abi> x);
    template <class Abi> doublev<Abi> asin(doublev<Abi> x);
    template <class Abi> ldoublev<Abi> asin(ldoublev<Abi> x);

    template <class Abi> floatv<Abi> atan(floatv<Abi> x);
    template <class Abi> doublev<Abi> atan(doublev<Abi> x);
    template <class Abi> ldoublev<Abi> atan(ldoublev<Abi> x);

    template <class Abi> floatv<Abi> atan2(floatv<Abi> y, floatv<Abi> x);
    template <class Abi> doublev<Abi> atan2(doublev<Abi> y, doublev<Abi> x);
    template <class Abi> ldoublev<Abi> atan2(ldoublev<Abi> y, ldoublev<Abi> x);

    template <class Abi> floatv<Abi> cos(floatv<Abi> x);
    template <class Abi> doublev<Abi> cos(doublev<Abi> x);
    template <class Abi> ldoublev<Abi> cos(ldoublev<Abi> x);

    template <class Abi> floatv<Abi> sin(floatv<Abi> x);
    template <class Abi> doublev<Abi> sin(doublev<Abi> x);
    template <class Abi> ldoublev<Abi> sin(ldoublev<Abi> x);

    template <class Abi> floatv<Abi> tan(floatv<Abi> x);
    template <class Abi> doublev<Abi> tan(doublev<Abi> x);
    template <class Abi> ldoublev<Abi> tan(ldoublev<Abi> x);

    template <class Abi> floatv<Abi> acosh(floatv<Abi> x);
    template <class Abi> doublev<Abi> acosh(doublev<Abi> x);
    template <class Abi> ldoublev<Abi> acosh(ldoublev<Abi> x);

    template <class Abi> floatv<Abi> asinh(floatv<Abi> x);
    template <class Abi> doublev<Abi> asinh(doublev<Abi> x);
    template <class Abi> ldoublev<Abi> asinh(ldoublev<Abi> x);

    template <class Abi> floatv<Abi> atanh(floatv<Abi> x);
    template <class Abi> doublev<Abi> atanh(doublev<Abi> x);
    template <class Abi> ldoublev<Abi> atanh(ldoublev<Abi> x);

    template <class Abi> floatv<Abi> cosh(floatv<Abi> x);
    template <class Abi> doublev<Abi> cosh(doublev<Abi> x);
    template <class Abi> ldoublev<Abi> cosh(ldoublev<Abi> x);

    template <class Abi> floatv<Abi> sinh(floatv<Abi> x);
    template <class Abi> doublev<Abi> sinh(doublev<Abi> x);
    template <class Abi> ldoublev<Abi> sinh(ldoublev<Abi> x);

    template <class Abi> floatv<Abi> tanh(floatv<Abi> x);
    template <class Abi> doublev<Abi> tanh(doublev<Abi> x);
    template <class Abi> ldoublev<Abi> tanh(ldoublev<Abi> x);

    template <class Abi> floatv<Abi> exp(floatv<Abi> x);
    template <class Abi> doublev<Abi> exp(doublev<Abi> x);
    template <class Abi> ldoublev<Abi> exp(ldoublev<Abi> x);

    template <class Abi> floatv<Abi> exp2(floatv<Abi> x);
    template <class Abi> doublev<Abi> exp2(doublev<Abi> x);
    template <class Abi> ldoublev<Abi> exp2(ldoublev<Abi> x);

    template <class Abi> floatv<Abi> expm1(floatv<Abi> x);
    template <class Abi> doublev<Abi> expm1(doublev<Abi> x);
    template <class Abi> ldoublev<Abi> expm1(ldoublev<Abi> x);

    template <class Abi> floatv<Abi> frexp(floatv<Abi> value, samesize<int, floatv<Abi>>* exp);
    template <class Abi> doublev<Abi> frexp(doublev<Abi> value, samesize<int, doublev<Abi>>* exp);
    template <class Abi> ldoublev<Abi> frexp(ldoublev<Abi> value, samesize<int, ldoublev<Abi>>* exp);

    template <class Abi> samesize<int, floatv<Abi>> ilogb(floatv<Abi> x);
    template <class Abi> samesize<int, doublev<Abi>> ilogb(doublev<Abi> x);
    template <class Abi> samesize<int, ldoublev<Abi>> ilogb(ldoublev<Abi> x);

    template <class Abi> floatv<Abi> ldexp(floatv<Abi> x, samesize<int, floatv<Abi>> exp);
    template <class Abi> doublev<Abi> ldexp(doublev<Abi> x, samesize<int, doublev<Abi>> exp);
    template <class Abi> ldoublev<Abi> ldexp(ldoublev<Abi> x, samesize<int, ldoublev<Abi>> exp);

    template <class Abi> floatv<Abi> log(floatv<Abi> x);
    template <class Abi> doublev<Abi> log(doublev<Abi> x);
    template <class Abi> ldoublev<Abi> log(ldoublev<Abi> x);

    template <class Abi> floatv<Abi> log10(floatv<Abi> x);
    template <class Abi> doublev<Abi> log10(doublev<Abi> x);
    template <class Abi> ldoublev<Abi> log10(ldoublev<Abi> x);

    template <class Abi> floatv<Abi> log1p(floatv<Abi> x);
    template <class Abi> doublev<Abi> log1p(doublev<Abi> x);
    template <class Abi> ldoublev<Abi> log1p(ldoublev<Abi> x);

    template <class Abi> floatv<Abi> log2(floatv<Abi> x);
    template <class Abi> doublev<Abi> log2(doublev<Abi> x);
    template <class Abi> ldoublev<Abi> log2(ldoublev<Abi> x);

    template <class Abi> floatv<Abi> logb(floatv<Abi> x);
    template <class Abi> doublev<Abi> logb(doublev<Abi> x);
    template <class Abi> ldoublev<Abi> logb(ldoublev<Abi> x);

    template <class Abi> floatv<Abi> modf(floatv<Abi> value, floatv<Abi>* iptr);
    template <class Abi> doublev<Abi> modf(doublev<Abi> value, doublev<Abi>* iptr);
    template <class Abi> ldoublev<Abi> modf(ldoublev<Abi> value, ldoublev<Abi>* iptr);

    template <class Abi> floatv<Abi> scalbn(floatv<Abi> x, samesize<int, floatv<Abi>> n);
    template <class Abi> doublev<Abi> scalbn(doublev<Abi> x, samesize<int, doublev<Abi>> n);
    template <class Abi> ldoublev<Abi> scalbn(ldoublev<Abi> x, samesize<int, ldoublev<Abi>> n);

    template <class Abi> floatv<Abi> scalbln(floatv<Abi> x, samesize<long int, floatv<Abi>> n);
    template <class Abi> doublev<Abi> scalbln(doublev<Abi> x, samesize<long int, doublev<Abi>> n);
    template <class Abi> ldoublev<Abi> scalbln(ldoublev<Abi> x, samesize<long int, ldoublev<Abi>> n);

    template <class Abi> floatv<Abi> cbrt(floatv<Abi> x);
    template <class Abi> doublev<Abi> cbrt(doublev<Abi> x);
    template <class Abi> ldoublev<Abi> cbrt(ldoublev<Abi> x);

    template <class Abi> scharv<Abi> abs(scharv<Abi> j);
    template <class Abi> shortv<Abi> abs(shortv<Abi> j);
    template <class Abi> intv<Abi> abs(intv<Abi> j);
    template <class Abi> longv<Abi> abs(longv<Abi> j);
    template <class Abi> llongv<Abi> abs(llongv<Abi> j);
    template <class Abi> floatv<Abi> abs(floatv<Abi> j);
    template <class Abi> doublev<Abi> abs(doublev<Abi> j);
    template <class Abi> ldoublev<Abi> abs(ldoublev<Abi> j);

    template <class Abi> floatv<Abi> hypot(floatv<Abi> x, floatv<Abi> y);
    template <class Abi> doublev<Abi> hypot(doublev<Abi> x, doublev<Abi> y);
    template <class Abi> ldoublev<Abi> hypot(doublev<Abi> x, doublev<Abi> y);

    template <class Abi> floatv<Abi> hypot(floatv<Abi> x, floatv<Abi> y, floatv<Abi> z);
    template <class Abi> doublev<Abi> hypot(doublev<Abi> x, doublev<Abi> y, doublev<Abi> z);
    template <class Abi> ldoublev<Abi> hypot(ldoublev<Abi> x, ldoublev<Abi> y, ldoublev<Abi> z);

    template <class Abi> floatv<Abi> pow(floatv<Abi> x, floatv<Abi> y);
    template <class Abi> doublev<Abi> pow(doublev<Abi> x, doublev<Abi> y);
    template <class Abi> ldoublev<Abi> pow(ldoublev<Abi> x, ldoublev<Abi> y);

    template <class Abi> floatv<Abi> sqrt(floatv<Abi> x);
    template <class Abi> doublev<Abi> sqrt(doublev<Abi> x);
    template <class Abi> ldoublev<Abi> sqrt(ldoublev<Abi> x);

    template <class Abi> floatv<Abi> erf(floatv<Abi> x);
    template <class Abi> doublev<Abi> erf(doublev<Abi> x);
    template <class Abi> ldoublev<Abi> erf(ldoublev<Abi> x);

    template <class Abi> floatv<Abi> erfc(floatv<Abi> x);
    template <class Abi> doublev<Abi> erfc(doublev<Abi> x);
    template <class Abi> ldoublev<Abi> erfc(ldoublev<Abi> x);

    template <class Abi> floatv<Abi> lgamma(floatv<Abi> x);
    template <class Abi> doublev<Abi> lgamma(doublev<Abi> x);
    template <class Abi> ldoublev<Abi> lgamma(ldoublev<Abi> x);

    template <class Abi> floatv<Abi> tgamma(floatv<Abi> x);
    template <class Abi> doublev<Abi> tgamma(doublev<Abi> x);
    template <class Abi> ldoublev<Abi> tgamma(ldoublev<Abi> x);

    template <class Abi> floatv<Abi> ceil(floatv<Abi> x);
    template <class Abi> doublev<Abi> ceil(doublev<Abi> x);
    template <class Abi> ldoublev<Abi> ceil(ldoublev<Abi> x);

    template <class Abi> floatv<Abi> floor(floatv<Abi> x);
    template <class Abi> doublev<Abi> floor(doublev<Abi> x);
    template <class Abi> ldoublev<Abi> floor(ldoublev<Abi> x);

    template <class Abi> floatv<Abi> nearbyint(floatv<Abi> x);
    template <class Abi> doublev<Abi> nearbyint(doublev<Abi> x);
    template <class Abi> ldoublev<Abi> nearbyint(ldoublev<Abi> x);

    template <class Abi> floatv<Abi> rint(floatv<Abi> x);
    template <class Abi> doublev<Abi> rint(doublev<Abi> x);
    template <class Abi> ldoublev<Abi> rint(ldoublev<Abi> x);

    template <class Abi> samesize<long int, floatv<Abi>> lrint(floatv<Abi> x);
    template <class Abi> samesize<long int, doublev<Abi>> lrint(doublev<Abi> x);
    template <class Abi> samesize<long int, ldoublev<Abi>> lrint(ldoublev<Abi> x);

    template <class Abi> samesize<long long int, floatv<Abi>> llrint(floatv<Abi> x);
    template <class Abi> samesize<long long int, doublev<Abi>> llrint(doublev<Abi> x);
    template <class Abi> samesize<long long int, ldoublev<Abi>> llrint(ldoublev<Abi> x);

    template <class Abi> floatv<Abi> round(floatv<Abi> x);
    template <class Abi> doublev<Abi> round(doublev<Abi> x);
    template <class Abi> ldoublev<Abi> round(ldoublev<Abi> x);

    template <class Abi> samesize<long int, floatv<Abi>> lround(floatv<Abi> x);
    template <class Abi> samesize<long int, doublev<Abi>> lround(doublev<Abi> x);
    template <class Abi> samesize<long int, ldoublev<Abi>> lround(ldoublev<Abi> x);

    template <class Abi> samesize<long long int, floatv<Abi>> llround(floatv<Abi> x);
    template <class Abi> samesize<long long int, doublev<Abi>> llround(doublev<Abi> x);
    template <class Abi> samesize<long long int, ldoublev<Abi>> llround(ldoublev<Abi> x);

    template <class Abi> floatv<Abi> trunc(floatv<Abi> x);
    template <class Abi> doublev<Abi> trunc(doublev<Abi> x);
    template <class Abi> ldoublev<Abi> trunc(ldoublev<Abi> x);

    template <class Abi> floatv<Abi> fmod(floatv<Abi> x, floatv<Abi> y);
    template <class Abi> doublev<Abi> fmod(doublev<Abi> x, doublev<Abi> y);
    template <class Abi> ldoublev<Abi> fmod(ldoublev<Abi> x, ldoublev<Abi> y);

    template <class Abi> floatv<Abi> remainder(floatv<Abi> x, floatv<Abi> y);
    template <class Abi> doublev<Abi> remainder(doublev<Abi> x, doublev<Abi> y);
    template <class Abi> ldoublev<Abi> remainder(ldoublev<Abi> x, ldoublev<Abi> y);

    template <class Abi> floatv<Abi> remquo(floatv<Abi> x, floatv<Abi> y, samesize<int, floatv<Abi>>* quo);
    template <class Abi>
    doublev<Abi> remquo(doublev<Abi> x, doublev<Abi> y, samesize<int, doublev<Abi>>* quo);
    template <class Abi>
    ldoublev<Abi> remquo(ldoublev<Abi> x, ldoublev<Abi> y, samesize<int, ldoublev<Abi>>* quo);

    template <class Abi> floatv<Abi> copysign(floatv<Abi> x, floatv<Abi> y);
    template <class Abi> doublev<Abi> copysign(doublev<Abi> x, doublev<Abi> y);
    template <class Abi> ldoublev<Abi> copysign(ldoublev<Abi> x, ldoublev<Abi> y);

    template <class Abi> doublev<Abi> nan(const char* tagp);
    template <class Abi> floatv<Abi> nanf(const char* tagp);
    template <class Abi> ldoublev<Abi> nanl(const char* tagp);

    template <class Abi> floatv<Abi> nextafter(floatv<Abi> x, floatv<Abi> y);
    template <class Abi> doublev<Abi> nextafter(doublev<Abi> x, doublev<Abi> y);
    template <class Abi> ldoublev<Abi> nextafter(ldoublev<Abi> x, ldoublev<Abi> y);

    template <class Abi> floatv<Abi> nexttoward(floatv<Abi> x, ldoublev<Abi> y);
    template <class Abi> doublev<Abi> nexttoward(doublev<Abi> x, ldoublev<Abi> y);
    template <class Abi> ldoublev<Abi> nexttoward(ldoublev<Abi> x, ldoublev<Abi> y);

    template <class Abi> floatv<Abi> fdim(floatv<Abi> x, floatv<Abi> y);
    template <class Abi> doublev<Abi> fdim(doublev<Abi> x, doublev<Abi> y);
    template <class Abi> ldoublev<Abi> fdim(ldoublev<Abi> x, ldoublev<Abi> y);

    template <class Abi> floatv<Abi> fmax(floatv<Abi> x, floatv<Abi> y);
    template <class Abi> doublev<Abi> fmax(doublev<Abi> x, doublev<Abi> y);
    template <class Abi> ldoublev<Abi> fmax(ldoublev<Abi> x, ldoublev<Abi> y);

    template <class Abi> floatv<Abi> fmin(floatv<Abi> x, floatv<Abi> y);
    template <class Abi> doublev<Abi> fmin(doublev<Abi> x, doublev<Abi> y);
    template <class Abi> ldoublev<Abi> fmin(ldoublev<Abi> x, ldoublev<Abi> y);

    template <class Abi> floatv<Abi> fma(floatv<Abi> x, floatv<Abi> y, floatv<Abi> z);
    template <class Abi> doublev<Abi> fma(doublev<Abi> x, doublev<Abi> y, doublev<Abi> z);
    template <class Abi> ldoublev<Abi> fma(ldoublev<Abi> x, ldoublev<Abi> y, ldoublev<Abi> z);

    template <class Abi> samesize<int, floatv<Abi>> fpclassify(floatv<Abi> x);
    template <class Abi> samesize<int, doublev<Abi>> fpclassify(doublev<Abi> x);
    template <class Abi> samesize<int, ldoublev<Abi>> fpclassify(ldoublev<Abi> x);

    template <class Abi> simd_mask<float, Abi> isfinite(floatv<Abi> x);
    template <class Abi> simd_mask<double, Abi> isfinite(doublev<Abi> x);
    template <class Abi> simd_mask<long double, Abi> isfinite(ldoublev<Abi> x);

    template <class Abi> simd_mask<float, Abi> isinf(floatv<Abi> x);
    template <class Abi> simd_mask<double, Abi> isinf(doublev<Abi> x);
    template <class Abi> simd_mask<long double, Abi> isinf(ldoublev<Abi> x);

    template <class Abi> simd_mask<float, Abi> isnan(floatv<Abi> x);
    template <class Abi> simd_mask<double, Abi> isnan(doublev<Abi> x);
    template <class Abi> simd_mask<long double, Abi> isnan(ldoublev<Abi> x);

    template <class Abi> simd_mask<float, Abi> isnormal(floatv<Abi> x);
    template <class Abi> simd_mask<double, Abi> isnormal(doublev<Abi> x);
    template <class Abi> simd_mask<long double, Abi> isnormal(ldoublev<Abi> x);

    template <class Abi> simd_mask<float, Abi> signbit(floatv<Abi> x);
    template <class Abi> simd_mask<double, Abi> signbit(doublev<Abi> x);
    template <class Abi> simd_mask<long double, Abi> signbit(ldoublev<Abi> x);

    template <class Abi> simd_mask<float, Abi> isgreater(floatv<Abi> x, floatv<Abi> y);
    template <class Abi> simd_mask<double, Abi> isgreater(doublev<Abi> x, doublev<Abi> y);
    template <class Abi> simd_mask<long double, Abi> isgreater(ldoublev<Abi> x, ldoublev<Abi> y);

    template <class Abi> simd_mask<float, Abi> isgreaterequal(floatv<Abi> x, floatv<Abi> y);
    template <class Abi> simd_mask<double, Abi> isgreaterequal(doublev<Abi> x, doublev<Abi> y);
    template <class Abi> simd_mask<long double, Abi> isgreaterequal(ldoublev<Abi> x, ldoublev<Abi> y);

    template <class Abi> simd_mask<float, Abi> isless(floatv<Abi> x, floatv<Abi> y);
    template <class Abi> simd_mask<double, Abi> isless(doublev<Abi> x, doublev<Abi> y);
    template <class Abi> simd_mask<long double, Abi> isless(ldoublev<Abi> x, ldoublev<Abi> y);

    template <class Abi> simd_mask<float, Abi> islessequal(floatv<Abi> x, floatv<Abi> y);
    template <class Abi> simd_mask<double, Abi> islessequal(doublev<Abi> x, doublev<Abi> y);
    template <class Abi> simd_mask<long double, Abi> islessequal(ldoublev<Abi> x, ldoublev<Abi> y);

    template <class Abi> simd_mask<float, Abi> islessgreater(floatv<Abi> x, floatv<Abi> y);
    template <class Abi> simd_mask<double, Abi> islessgreater(doublev<Abi> x, doublev<Abi> y);
    template <class Abi> simd_mask<long double, Abi> islessgreater(ldoublev<Abi> x, ldoublev<Abi> y);

    template <class Abi> simd_mask<float, Abi> isunordered(floatv<Abi> x, floatv<Abi> y);
    template <class Abi> simd_mask<double, Abi> isunordered(doublev<Abi> x, doublev<Abi> y);
    template <class Abi> simd_mask<long double, Abi> isunordered(ldoublev<Abi> x, ldoublev<Abi> y);

    template <class V> struct simd_div_t { V quot, rem; };
    template <class Abi> simd_div_t<scharv<Abi>> div(scharv<Abi> numer, scharv<Abi> denom);
    template <class Abi> simd_div_t<shortv<Abi>> div(shortv<Abi> numer, shortv<Abi> denom);
    template <class Abi> simd_div_t<intv<Abi>> div(intv<Abi> numer, intv<Abi> denom);
    template <class Abi> simd_div_t<longv<Abi>> div(longv<Abi> numer, longv<Abi> denom);
    template <class Abi> simd_div_t<llongv<Abi>> div(llongv<Abi> numer, llongv<Abi> denom);
  }
}
