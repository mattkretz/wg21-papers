namespace std {
  namespace experimental {
    template <class Abi> using intv = datapar<int, Abi>;  // exposition only
    template <class Abi> using longv = datapar<long int, Abi>;  // exposition only
    template <class Abi> using llongv = datapar<long long int, Abi>;  // exposition only
    template <class Abi> using floatv = datapar<float, Abi>;  // exposition only
    template <class Abi> using doublev = datapar<double, Abi>;  // exposition only
    template <class Abi> using ldoublev = datapar<long double, Abi>;  // exposition only
    template <class T, class V>
    using samesize = datapar<T, abi_for_size_t<V::size()>>;  // exposition only

    template <class Abi> floatv<Abi> acos(floatv<Abi> x);
    template <class Abi> doublev<Abi> acos(doublev<Abi> x);
    template <class Abi> ldoublev<Abi> acos(ldoublev<Abi> x);
    template <class Abi> floatv<Abi> acosf(floatv<Abi> x);
    template <class Abi> ldoublev<Abi> acosl(ldoublev<Abi> x);

    template <class Abi> floatv<Abi> asin(floatv<Abi> x);
    template <class Abi> doublev<Abi> asin(doublev<Abi> x);
    template <class Abi> ldoublev<Abi> asin(ldoublev<Abi> x);
    template <class Abi> floatv<Abi> asinf(floatv<Abi> x);
    template <class Abi> ldoublev<Abi> asinl(ldoublev<Abi> x);

    template <class Abi> floatv<Abi> atan(floatv<Abi> x);
    template <class Abi> doublev<Abi> atan(doublev<Abi> x);
    template <class Abi> ldoublev<Abi> atan(ldoublev<Abi> x);
    template <class Abi> floatv<Abi> atanf(floatv<Abi> x);
    template <class Abi> ldoublev<Abi> atanl(ldoublev<Abi> x);

    template <class Abi> floatv<Abi> atan2(floatv<Abi> y, floatv<Abi> x);
    template <class Abi> doublev<Abi> atan2(doublev<Abi> y, doublev<Abi> x);
    template <class Abi> ldoublev<Abi> atan2(ldoublev<Abi> y, ldoublev<Abi> x);
    template <class Abi> floatv<Abi> atan2f(floatv<Abi> y, floatv<Abi> x);
    template <class Abi> ldoublev<Abi> atan2l(ldoublev<Abi> y, ldoublev<Abi> x);

    template <class Abi> floatv<Abi> cos(floatv<Abi> x);
    template <class Abi> doublev<Abi> cos(doublev<Abi> x);
    template <class Abi> ldoublev<Abi> cos(ldoublev<Abi> x);
    template <class Abi> floatv<Abi> cosf(floatv<Abi> x);
    template <class Abi> ldoublev<Abi> cosl(ldoublev<Abi> x);

    template <class Abi> floatv<Abi> sin(floatv<Abi> x);
    template <class Abi> doublev<Abi> sin(doublev<Abi> x);
    template <class Abi> ldoublev<Abi> sin(ldoublev<Abi> x);
    template <class Abi> floatv<Abi> sinf(floatv<Abi> x);
    template <class Abi> ldoublev<Abi> sinl(ldoublev<Abi> x);

    template <class Abi> floatv<Abi> tan(floatv<Abi> x);
    template <class Abi> doublev<Abi> tan(doublev<Abi> x);
    template <class Abi> ldoublev<Abi> tan(ldoublev<Abi> x);
    template <class Abi> floatv<Abi> tanf(floatv<Abi> x);
    template <class Abi> ldoublev<Abi> tanl(ldoublev<Abi> x);

    template <class Abi> floatv<Abi> acosh(floatv<Abi> x);
    template <class Abi> doublev<Abi> acosh(doublev<Abi> x);
    template <class Abi> ldoublev<Abi> acosh(ldoublev<Abi> x);
    template <class Abi> floatv<Abi> acoshf(floatv<Abi> x);
    template <class Abi> ldoublev<Abi> acoshl(ldoublev<Abi> x);

    template <class Abi> floatv<Abi> asinh(floatv<Abi> x);
    template <class Abi> doublev<Abi> asinh(doublev<Abi> x);
    template <class Abi> ldoublev<Abi> asinh(ldoublev<Abi> x);
    template <class Abi> floatv<Abi> asinhf(floatv<Abi> x);
    template <class Abi> ldoublev<Abi> asinhl(ldoublev<Abi> x);

    template <class Abi> floatv<Abi> atanh(floatv<Abi> x);
    template <class Abi> doublev<Abi> atanh(doublev<Abi> x);
    template <class Abi> ldoublev<Abi> atanh(ldoublev<Abi> x);
    template <class Abi> floatv<Abi> atanhf(floatv<Abi> x);
    template <class Abi> ldoublev<Abi> atanhl(ldoublev<Abi> x);

    template <class Abi> floatv<Abi> cosh(floatv<Abi> x);
    template <class Abi> doublev<Abi> cosh(doublev<Abi> x);
    template <class Abi> ldoublev<Abi> cosh(ldoublev<Abi> x);
    template <class Abi> floatv<Abi> coshf(floatv<Abi> x);
    template <class Abi> ldoublev<Abi> coshl(ldoublev<Abi> x);

    template <class Abi> floatv<Abi> sinh(floatv<Abi> x);
    template <class Abi> doublev<Abi> sinh(doublev<Abi> x);
    template <class Abi> ldoublev<Abi> sinh(ldoublev<Abi> x);
    template <class Abi> floatv<Abi> sinhf(floatv<Abi> x);
    template <class Abi> ldoublev<Abi> sinhl(ldoublev<Abi> x);

    template <class Abi> floatv<Abi> tanh(floatv<Abi> x);
    template <class Abi> doublev<Abi> tanh(doublev<Abi> x);
    template <class Abi> ldoublev<Abi> tanh(ldoublev<Abi> x);
    template <class Abi> floatv<Abi> tanhf(floatv<Abi> x);
    template <class Abi> ldoublev<Abi> tanhl(ldoublev<Abi> x);

    template <class Abi> floatv<Abi> exp(floatv<Abi> x);
    template <class Abi> doublev<Abi> exp(doublev<Abi> x);
    template <class Abi> ldoublev<Abi> exp(ldoublev<Abi> x);
    template <class Abi> floatv<Abi> expf(floatv<Abi> x);
    template <class Abi> ldoublev<Abi> expl(ldoublev<Abi> x);

    template <class Abi> floatv<Abi> exp2(floatv<Abi> x);
    template <class Abi> doublev<Abi> exp2(doublev<Abi> x);
    template <class Abi> ldoublev<Abi> exp2(ldoublev<Abi> x);
    template <class Abi> floatv<Abi> exp2f(floatv<Abi> x);
    template <class Abi> ldoublev<Abi> exp2l(ldoublev<Abi> x);

    template <class Abi> floatv<Abi> expm1(floatv<Abi> x);
    template <class Abi> doublev<Abi> expm1(doublev<Abi> x);
    template <class Abi> ldoublev<Abi> expm1(ldoublev<Abi> x);
    template <class Abi> floatv<Abi> expm1f(floatv<Abi> x);
    template <class Abi> ldoublev<Abi> expm1l(ldoublev<Abi> x);

    template <class Abi> floatv<Abi> frexp(floatv<Abi> value, samesize<int, floatv<Abi>>* exp);
    template <class Abi> doublev<Abi> frexp(doublev<Abi> value, samesize<int, doublev<Abi>>* exp);
    template <class Abi> ldoublev<Abi> frexp(ldoublev<Abi> value, samesize<int, ldoublev<Abi>>* exp);
    template <class Abi> floatv<Abi> frexpf(floatv<Abi> value, samesize<int, floatv<Abi>>* exp);
    template <class Abi> ldoublev<Abi> frexpl(ldoublev<Abi> value, samesize<int, ldoublev<Abi>>* exp);

    template <class Abi> samesize<int, floatv<Abi>> ilogb(floatv<Abi> x);
    template <class Abi> samesize<int, doublev<Abi>> ilogb(doublev<Abi> x);
    template <class Abi> samesize<int, ldoublev<Abi>> ilogb(ldoublev<Abi> x);
    template <class Abi> samesize<int, floatv<Abi>> ilogbf(floatv<Abi> x);
    template <class Abi> samesize<int, ldoublev<Abi>> ilogbl(ldoublev<Abi> x);

    template <class Abi> floatv<Abi> ldexp(floatv<Abi> x, samesize<int, floatv<Abi>> exp);
    template <class Abi> doublev<Abi> ldexp(doublev<Abi> x, samesize<int, doublev<Abi>> exp);
    template <class Abi> ldoublev<Abi> ldexp(ldoublev<Abi> x, samesize<int, ldoublev<Abi>> exp);
    template <class Abi> floatv<Abi> ldexpf(floatv<Abi> x, samesize<int, floatv<Abi>> exp);
    template <class Abi> ldoublev<Abi> ldexpl(ldoublev<Abi> x, samesize<int, ldoublev<Abi>> exp);

    template <class Abi> floatv<Abi> log(floatv<Abi> x);
    template <class Abi> doublev<Abi> log(doublev<Abi> x);
    template <class Abi> ldoublev<Abi> log(ldoublev<Abi> x);
    template <class Abi> floatv<Abi> logf(floatv<Abi> x);
    template <class Abi> ldoublev<Abi> logl(ldoublev<Abi> x);

    template <class Abi> floatv<Abi> log10(floatv<Abi> x);
    template <class Abi> doublev<Abi> log10(doublev<Abi> x);
    template <class Abi> ldoublev<Abi> log10(ldoublev<Abi> x);
    template <class Abi> floatv<Abi> log10f(floatv<Abi> x);
    template <class Abi> ldoublev<Abi> log10l(ldoublev<Abi> x);

    template <class Abi> floatv<Abi> log1p(floatv<Abi> x);
    template <class Abi> doublev<Abi> log1p(doublev<Abi> x);
    template <class Abi> ldoublev<Abi> log1p(ldoublev<Abi> x);
    template <class Abi> floatv<Abi> log1pf(floatv<Abi> x);
    template <class Abi> ldoublev<Abi> log1pl(ldoublev<Abi> x);

    template <class Abi> floatv<Abi> log2(floatv<Abi> x);
    template <class Abi> doublev<Abi> log2(doublev<Abi> x);
    template <class Abi> ldoublev<Abi> log2(ldoublev<Abi> x);
    template <class Abi> floatv<Abi> log2f(floatv<Abi> x);
    template <class Abi> ldoublev<Abi> log2l(ldoublev<Abi> x);

    template <class Abi> floatv<Abi> logb(floatv<Abi> x);
    template <class Abi> doublev<Abi> logb(doublev<Abi> x);
    template <class Abi> ldoublev<Abi> logb(ldoublev<Abi> x);
    template <class Abi> floatv<Abi> logbf(floatv<Abi> x);
    template <class Abi> ldoublev<Abi> logbl(ldoublev<Abi> x);

    template <class Abi> floatv<Abi> modf(floatv<Abi> value, floatv<Abi>* iptr);
    template <class Abi> doublev<Abi> modf(doublev<Abi> value, doublev<Abi>* iptr);
    template <class Abi> ldoublev<Abi> modf(ldoublev<Abi> value, ldoublev<Abi>* iptr);
    template <class Abi> floatv<Abi> modff(floatv<Abi> value, floatv<Abi>* iptr);
    template <class Abi> ldoublev<Abi> modfl(ldoublev<Abi> value, ldoublev<Abi>* iptr);

    template <class Abi> floatv<Abi> scalbn(floatv<Abi> x, samesize<int, floatv<Abi>> n);
    template <class Abi> doublev<Abi> scalbn(doublev<Abi> x, samesize<int, doublev<Abi>> n);
    template <class Abi> ldoublev<Abi> scalbn(ldoublev<Abi> x, samesize<int, ldoublev<Abi>> n);
    template <class Abi> floatv<Abi> scalbnf(floatv<Abi> x, samesize<int, floatv<Abi>> n);
    template <class Abi> ldoublev<Abi> scalbnl(ldoublev<Abi> x, samesize<int, ldoublev<Abi>> n);

    template <class Abi> floatv<Abi> scalbln(floatv<Abi> x, samesize<long int, floatv<Abi>> n);
    template <class Abi> doublev<Abi> scalbln(doublev<Abi> x, samesize<long int, doublev<Abi>> n);
    template <class Abi> ldoublev<Abi> scalbln(ldoublev<Abi> x, samesize<long int, ldoublev<Abi>> n);
    template <class Abi> floatv<Abi> scalblnf(floatv<Abi> x, samesize<long int, floatv<Abi>> n);
    template <class Abi> ldoublev<Abi> scalblnl(ldoublev<Abi> x, samesize<long int, ldoublev<Abi>> n);

    template <class Abi> floatv<Abi> cbrt(floatv<Abi> x);
    template <class Abi> doublev<Abi> cbrt(doublev<Abi> x);
    template <class Abi> ldoublev<Abi> cbrt(ldoublev<Abi> x);
    template <class Abi> floatv<Abi> cbrtf(floatv<Abi> x);
    template <class Abi> ldoublev<Abi> cbrtl(ldoublev<Abi> x);

    template <class Abi> intv<Abi> abs(intv<Abi> j);
    template <class Abi> longv<Abi> abs(longv<Abi> j);
    template <class Abi> llongv<Abi> abs(llongv<Abi> j);
    template <class Abi> longv<Abi> labs(longv<Abi> j);
    template <class Abi> llongv<Abi> llabs(llongv<Abi> j);
    template <class Abi> floatv<Abi> abs(floatv<Abi> j);
    template <class Abi> doublev<Abi> abs(doublev<Abi> j);
    template <class Abi> ldoublev<Abi> abs(ldoublev<Abi> j);
    template <class Abi> floatv<Abi> fabs(floatv<Abi> x);
    template <class Abi> doublev<Abi> fabs(doublev<Abi> x);
    template <class Abi> ldoublev<Abi> fabs(ldoublev<Abi> x);
    template <class Abi> floatv<Abi> fabsf(floatv<Abi> x);
    template <class Abi> ldoublev<Abi> fabsl(ldoublev<Abi> x);

    template <class Abi> floatv<Abi> hypot(floatv<Abi> x, floatv<Abi> y);
    template <class Abi> doublev<Abi> hypot(doublev<Abi> x, doublev<Abi> y);
    template <class Abi> ldoublev<Abi> hypot(doublev<Abi> x, doublev<Abi> y);
    template <class Abi> floatv<Abi> hypotf(floatv<Abi> x, floatv<Abi> y);
    template <class Abi> ldoublev<Abi> hypotl(ldoublev<Abi> x, ldoublev<Abi> y);

    template <class Abi> floatv<Abi> hypot(floatv<Abi> x, floatv<Abi> y, floatv<Abi> z);
    template <class Abi> doublev<Abi> hypot(doublev<Abi> x, doublev<Abi> y, doublev<Abi> z);
    template <class Abi> ldoublev<Abi> hypot(ldoublev<Abi> x, ldoublev<Abi> y, ldoublev<Abi> z);

    template <class Abi> floatv<Abi> pow(floatv<Abi> x, floatv<Abi> y);
    template <class Abi> doublev<Abi> pow(doublev<Abi> x, doublev<Abi> y);
    template <class Abi> ldoublev<Abi> pow(ldoublev<Abi> x, ldoublev<Abi> y);
    template <class Abi> floatv<Abi> powf(floatv<Abi> x, floatv<Abi> y);
    template <class Abi> ldoublev<Abi> powl(ldoublev<Abi> x, ldoublev<Abi> y);

    template <class Abi> floatv<Abi> sqrt(floatv<Abi> x);
    template <class Abi> doublev<Abi> sqrt(doublev<Abi> x);
    template <class Abi> ldoublev<Abi> sqrt(ldoublev<Abi> x);
    template <class Abi> floatv<Abi> sqrtf(floatv<Abi> x);
    template <class Abi> ldoublev<Abi> sqrtl(ldoublev<Abi> x);

    template <class Abi> floatv<Abi> erf(floatv<Abi> x);
    template <class Abi> doublev<Abi> erf(doublev<Abi> x);
    template <class Abi> ldoublev<Abi> erf(ldoublev<Abi> x);
    template <class Abi> floatv<Abi> erff(floatv<Abi> x);
    template <class Abi> ldoublev<Abi> erfl(ldoublev<Abi> x);

    template <class Abi> floatv<Abi> erfc(floatv<Abi> x);
    template <class Abi> doublev<Abi> erfc(doublev<Abi> x);
    template <class Abi> ldoublev<Abi> erfc(ldoublev<Abi> x);
    template <class Abi> floatv<Abi> erfcf(floatv<Abi> x);
    template <class Abi> ldoublev<Abi> erfcl(ldoublev<Abi> x);

    template <class Abi> floatv<Abi> lgamma(floatv<Abi> x);
    template <class Abi> doublev<Abi> lgamma(doublev<Abi> x);
    template <class Abi> ldoublev<Abi> lgamma(ldoublev<Abi> x);
    template <class Abi> floatv<Abi> lgammaf(floatv<Abi> x);
    template <class Abi> ldoublev<Abi> lgammal(ldoublev<Abi> x);

    template <class Abi> floatv<Abi> tgamma(floatv<Abi> x);
    template <class Abi> doublev<Abi> tgamma(doublev<Abi> x);
    template <class Abi> ldoublev<Abi> tgamma(ldoublev<Abi> x);
    template <class Abi> floatv<Abi> tgammaf(floatv<Abi> x);
    template <class Abi> ldoublev<Abi> tgammal(ldoublev<Abi> x);

    template <class Abi> floatv<Abi> ceil(floatv<Abi> x);
    template <class Abi> doublev<Abi> ceil(doublev<Abi> x);
    template <class Abi> ldoublev<Abi> ceil(ldoublev<Abi> x);
    template <class Abi> floatv<Abi> ceilf(floatv<Abi> x);
    template <class Abi> ldoublev<Abi> ceill(ldoublev<Abi> x);

    template <class Abi> floatv<Abi> floor(floatv<Abi> x);
    template <class Abi> doublev<Abi> floor(doublev<Abi> x);
    template <class Abi> ldoublev<Abi> floor(ldoublev<Abi> x);
    template <class Abi> floatv<Abi> floorf(floatv<Abi> x);
    template <class Abi> ldoublev<Abi> floorl(ldoublev<Abi> x);

    template <class Abi> floatv<Abi> nearbyint(floatv<Abi> x);
    template <class Abi> doublev<Abi> nearbyint(doublev<Abi> x);
    template <class Abi> ldoublev<Abi> nearbyint(ldoublev<Abi> x);
    template <class Abi> floatv<Abi> nearbyintf(floatv<Abi> x);
    template <class Abi> ldoublev<Abi> nearbyintl(ldoublev<Abi> x);

    template <class Abi> floatv<Abi> rint(floatv<Abi> x);
    template <class Abi> doublev<Abi> rint(doublev<Abi> x);
    template <class Abi> ldoublev<Abi> rint(ldoublev<Abi> x);
    template <class Abi> floatv<Abi> rintf(floatv<Abi> x);
    template <class Abi> ldoublev<Abi> rintl(ldoublev<Abi> x);

    template <class Abi> samesize<long int, floatv<Abi>> lrint(floatv<Abi> x);
    template <class Abi> samesize<long int, doublev<Abi>> lrint(doublev<Abi> x);
    template <class Abi> samesize<long int, ldoublev<Abi>> lrint(ldoublev<Abi> x);
    template <class Abi> samesize<long int, floatv<Abi>> lrintf(floatv<Abi> x);
    template <class Abi> samesize<long int, ldoublev<Abi>> lrintl(ldoublev<Abi> x);

    template <class Abi> samesize<long long int, floatv<Abi>> llrint(floatv<Abi> x);
    template <class Abi> samesize<long long int, doublev<Abi>> llrint(doublev<Abi> x);
    template <class Abi> samesize<long long int, ldoublev<Abi>> llrint(ldoublev<Abi> x);
    template <class Abi> samesize<long long int, floatv<Abi>> llrintf(floatv<Abi> x);
    template <class Abi> samesize<long long int, ldoublev<Abi>> llrintl(ldoublev<Abi> x);

    template <class Abi> floatv<Abi> round(floatv<Abi> x);
    template <class Abi> doublev<Abi> round(doublev<Abi> x);
    template <class Abi> ldoublev<Abi> round(ldoublev<Abi> x);
    template <class Abi> floatv<Abi> roundf(floatv<Abi> x);
    template <class Abi> ldoublev<Abi> roundl(ldoublev<Abi> x);

    template <class Abi> samesize<long int, floatv<Abi>> lround(floatv<Abi> x);
    template <class Abi> samesize<long int, doublev<Abi>> lround(doublev<Abi> x);
    template <class Abi> samesize<long int, ldoublev<Abi>> lround(ldoublev<Abi> x);
    template <class Abi> samesize<long int, floatv<Abi>> lroundf(floatv<Abi> x);
    template <class Abi> samesize<long int, ldoublev<Abi>> lroundl(ldoublev<Abi> x);

    template <class Abi> samesize<long long int, floatv<Abi>> llround(floatv<Abi> x);
    template <class Abi> samesize<long long int, doublev<Abi>> llround(doublev<Abi> x);
    template <class Abi> samesize<long long int, ldoublev<Abi>> llround(ldoublev<Abi> x);
    template <class Abi> samesize<long long int, floatv<Abi>> llroundf(floatv<Abi> x);
    template <class Abi> samesize<long long int, ldoublev<Abi>> llroundl(ldoublev<Abi> x);

    template <class Abi> floatv<Abi> trunc(floatv<Abi> x);
    template <class Abi> doublev<Abi> trunc(doublev<Abi> x);
    template <class Abi> ldoublev<Abi> trunc(ldoublev<Abi> x);
    template <class Abi> floatv<Abi> truncf(floatv<Abi> x);
    template <class Abi> ldoublev<Abi> truncl(ldoublev<Abi> x);

    template <class Abi> floatv<Abi> fmod(floatv<Abi> x, floatv<Abi> y);
    template <class Abi> doublev<Abi> fmod(doublev<Abi> x, doublev<Abi> y);
    template <class Abi> ldoublev<Abi> fmod(ldoublev<Abi> x, ldoublev<Abi> y);
    template <class Abi> floatv<Abi> fmodf(floatv<Abi> x, floatv<Abi> y);
    template <class Abi> ldoublev<Abi> fmodl(ldoublev<Abi> x, ldoublev<Abi> y);

    template <class Abi> floatv<Abi> remainder(floatv<Abi> x, floatv<Abi> y);
    template <class Abi> doublev<Abi> remainder(doublev<Abi> x, doublev<Abi> y);
    template <class Abi> ldoublev<Abi> remainder(ldoublev<Abi> x, ldoublev<Abi> y);
    template <class Abi> floatv<Abi> remainderf(floatv<Abi> x, floatv<Abi> y);
    template <class Abi> ldoublev<Abi> remainderl(ldoublev<Abi> x, ldoublev<Abi> y);

    template <class Abi> floatv<Abi> remquo(floatv<Abi> x, floatv<Abi> y, samesize<int, floatv<Abi>>* quo);
    template <class Abi>
    doublev<Abi> remquo(doublev<Abi> x, doublev<Abi> y, samesize<int, doublev<Abi>>* quo);
    template <class Abi>
    ldoublev<Abi> remquo(ldoublev<Abi> x, ldoublev<Abi> y, samesize<int, ldoublev<Abi>>* quo);
    template <class Abi> floatv<Abi> remquof(floatv<Abi> x, floatv<Abi> y, samesize<int, floatv<Abi>>* quo);
    template <class Abi>
    ldoublev<Abi> remquol(ldoublev<Abi> x, ldoublev<Abi> y, samesize<int, ldoublev<Abi>>* quo);

    template <class Abi> floatv<Abi> copysign(floatv<Abi> x, floatv<Abi> y);
    template <class Abi> doublev<Abi> copysign(doublev<Abi> x, doublev<Abi> y);
    template <class Abi> ldoublev<Abi> copysign(ldoublev<Abi> x, ldoublev<Abi> y);
    template <class Abi> floatv<Abi> copysignf(floatv<Abi> x, floatv<Abi> y);
    template <class Abi> ldoublev<Abi> copysignl(ldoublev<Abi> x, ldoublev<Abi> y);

    template <class Abi> doublev<Abi> nan(const char* tagp);
    template <class Abi> floatv<Abi> nanf(const char* tagp);
    template <class Abi> ldoublev<Abi> nanl(const char* tagp);

    template <class Abi> floatv<Abi> nextafter(floatv<Abi> x, floatv<Abi> y);
    template <class Abi> doublev<Abi> nextafter(doublev<Abi> x, doublev<Abi> y);
    template <class Abi> ldoublev<Abi> nextafter(ldoublev<Abi> x, ldoublev<Abi> y);
    template <class Abi> floatv<Abi> nextafterf(floatv<Abi> x, floatv<Abi> y);
    template <class Abi> ldoublev<Abi> nextafterl(ldoublev<Abi> x, ldoublev<Abi> y);

    template <class Abi> floatv<Abi> nexttoward(floatv<Abi> x, ldoublev<Abi> y);
    template <class Abi> doublev<Abi> nexttoward(doublev<Abi> x, ldoublev<Abi> y);
    template <class Abi> ldoublev<Abi> nexttoward(ldoublev<Abi> x, ldoublev<Abi> y);
    template <class Abi> floatv<Abi> nexttowardf(floatv<Abi> x, ldoublev<Abi> y);
    template <class Abi> ldoublev<Abi> nexttowardl(ldoublev<Abi> x, ldoublev<Abi> y);

    template <class Abi> floatv<Abi> fdim(floatv<Abi> x, floatv<Abi> y);
    template <class Abi> doublev<Abi> fdim(doublev<Abi> x, doublev<Abi> y);
    template <class Abi> ldoublev<Abi> fdim(ldoublev<Abi> x, ldoublev<Abi> y);
    template <class Abi> floatv<Abi> fdimf(floatv<Abi> x, floatv<Abi> y);
    template <class Abi> ldoublev<Abi> fdiml(ldoublev<Abi> x, ldoublev<Abi> y);

    template <class Abi> floatv<Abi> fmax(floatv<Abi> x, floatv<Abi> y);
    template <class Abi> doublev<Abi> fmax(doublev<Abi> x, doublev<Abi> y);
    template <class Abi> ldoublev<Abi> fmax(ldoublev<Abi> x, ldoublev<Abi> y);
    template <class Abi> floatv<Abi> fmaxf(floatv<Abi> x, floatv<Abi> y);
    template <class Abi> ldoublev<Abi> fmaxl(ldoublev<Abi> x, ldoublev<Abi> y);

    template <class Abi> floatv<Abi> fmin(floatv<Abi> x, floatv<Abi> y);
    template <class Abi> doublev<Abi> fmin(doublev<Abi> x, doublev<Abi> y);
    template <class Abi> ldoublev<Abi> fmin(ldoublev<Abi> x, ldoublev<Abi> y);
    template <class Abi> floatv<Abi> fminf(floatv<Abi> x, floatv<Abi> y);
    template <class Abi> ldoublev<Abi> fminl(ldoublev<Abi> x, ldoublev<Abi> y);

    template <class Abi> floatv<Abi> fma(floatv<Abi> x, floatv<Abi> y, floatv<Abi> z);
    template <class Abi> doublev<Abi> fma(doublev<Abi> x, doublev<Abi> y, doublev<Abi> z);
    template <class Abi> ldoublev<Abi> fma(ldoublev<Abi> x, ldoublev<Abi> y, ldoublev<Abi> z);
    template <class Abi> floatv<Abi> fmaf(floatv<Abi> x, floatv<Abi> y, floatv<Abi> z);
    template <class Abi> ldoublev<Abi> fmal(ldoublev<Abi> x, ldoublev<Abi> y, ldoublev<Abi> z);

    template <class Abi> samesize<int, floatv<Abi>> fpclassify(floatv<Abi> x);
    template <class Abi> samesize<int, doublev<Abi>> fpclassify(doublev<Abi> x);
    template <class Abi> samesize<int, ldoublev<Abi>> fpclassify(ldoublev<Abi> x);

    template <class Abi> mask<float, Abi> isfinite(floatv<Abi> x);
    template <class Abi> mask<double, Abi> isfinite(doublev<Abi> x);
    template <class Abi> mask<long double, Abi> isfinite(ldoublev<Abi> x);

    template <class Abi> samesize<int, floatv<Abi>> isinf(floatv<Abi> x);
    template <class Abi> samesize<int, doublev<Abi>> isinf(doublev<Abi> x);
    template <class Abi> samesize<int, ldoublev<Abi>> isinf(ldoublev<Abi> x);

    template <class Abi> mask<float, Abi> isnan(floatv<Abi> x);
    template <class Abi> mask<double, Abi> isnan(doublev<Abi> x);
    template <class Abi> mask<long double, Abi> isnan(ldoublev<Abi> x);

    template <class Abi> mask<float, Abi> isnormal(floatv<Abi> x);
    template <class Abi> mask<double, Abi> isnormal(doublev<Abi> x);
    template <class Abi> mask<long double, Abi> isnormal(ldoublev<Abi> x);

    template <class Abi> mask<float, Abi> signbit(floatv<Abi> x);
    template <class Abi> mask<double, Abi> signbit(doublev<Abi> x);
    template <class Abi> mask<long double, Abi> signbit(ldoublev<Abi> x);

    template <class Abi> mask<float, Abi> isgreater(floatv<Abi> x, floatv<Abi> y);
    template <class Abi> mask<double, Abi> isgreater(doublev<Abi> x, doublev<Abi> y);
    template <class Abi> mask<long double, Abi> isgreater(ldoublev<Abi> x, ldoublev<Abi> y);

    template <class Abi> mask<float, Abi> isgreaterequal(floatv<Abi> x, floatv<Abi> y);
    template <class Abi> mask<double, Abi> isgreaterequal(doublev<Abi> x, doublev<Abi> y);
    template <class Abi> mask<long double, Abi> isgreaterequal(ldoublev<Abi> x, ldoublev<Abi> y);

    template <class Abi> mask<float, Abi> isless(floatv<Abi> x, floatv<Abi> y);
    template <class Abi> mask<double, Abi> isless(doublev<Abi> x, doublev<Abi> y);
    template <class Abi> mask<long double, Abi> isless(ldoublev<Abi> x, ldoublev<Abi> y);

    template <class Abi> mask<float, Abi> islessequal(floatv<Abi> x, floatv<Abi> y);
    template <class Abi> mask<double, Abi> islessequal(doublev<Abi> x, doublev<Abi> y);
    template <class Abi> mask<long double, Abi> islessequal(ldoublev<Abi> x, ldoublev<Abi> y);

    template <class Abi> mask<float, Abi> islessgreater(floatv<Abi> x, floatv<Abi> y);
    template <class Abi> mask<double, Abi> islessgreater(doublev<Abi> x, doublev<Abi> y);
    template <class Abi> mask<long double, Abi> islessgreater(ldoublev<Abi> x, ldoublev<Abi> y);

    template <class Abi> mask<float, Abi> isunordered(floatv<Abi> x, floatv<Abi> y);
    template <class Abi> mask<double, Abi> isunordered(doublev<Abi> x, doublev<Abi> y);
    template <class Abi> mask<long double, Abi> isunordered(ldoublev<Abi> x, ldoublev<Abi> y);

    template <class V> struct datapar_div_t { V quot, rem; };
    template <class Abi> datapar_div_t<intv<Abi>> div(intv<Abi> numer, intv<Abi> denom);
    template <class Abi> datapar_div_t<longv<Abi>> div(longv<Abi> numer, longv<Abi> denom);
    template <class Abi> datapar_div_t<llongv<Abi>> div(llongv<Abi> numer, llongv<Abi> denom);
    template <class Abi> datapar_div_t<longv<Abi>> ldiv(longv<Abi> numer, longv<Abi> denom);
    template <class Abi> datapar_div_t<llongv<Abi>> lldiv(llongv<Abi> numer, llongv<Abi> denom);
  }
}
