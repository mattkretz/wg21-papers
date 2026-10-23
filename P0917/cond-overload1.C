// { dg-do run }
// { dg-options "-std=c++20" }
//
// Test user-defined non-default operator?: overloads
// a) as template (same type)
// b) non-template different args -> reversed calls with mask negation
// c) explicit overload of reversed arguments

struct mask {
  bool v[4];
  friend constexpr mask
  operator!(mask m) {
    for (int i = 0; i < 4; ++i)
      m.v[i] = !m.v[i];
    return m;
  }
};

namespace foo
{
  template <typename T = int>
    struct vec { T v[4]; };

  // found via ADL
  template <typename T>
    vec<T>
    operator?:(const mask& m, vec<T> a, const vec<T>& b)
    {
      for (int i = 0; i < 4; ++i)
	a.v[i] = m.v[i] ? a.v[i] : b.v[i];
      return a;
    }

  // found via ADL
  vec<double>
  operator?:(const mask& m, const vec<int>& a, vec<double> b)
  {
    for (int i = 0; i < 4; ++i)
      b.v[i] = m.v[i] ? a.v[i] : b.v[i];
    return b;
  }
}

using foo::vec;

template <typename T>
  bool
  all_eq(const vec<T>& a, const vec<T>& b)
  {
    for (int i = 0; i < 4; ++i)
      if (a.v[i] != b.v[i])
	return false;
    return true;
  }

// call the vec<T> template
void
test0()
{
  const vec x = {1, 2, 3, 4};
  const vec y = {5, 6, 7, 8};
  {
    const mask m = {true, false, false, true};
    const vec expect = {1, 6, 7, 4};
    const vec z = m ? x : y;
    if (!all_eq(z, expect))
      __builtin_abort ();
  }
  {
    const mask m = {false, false, true, true};
    const vec expect = {5, 6, 3, 4};
    const vec z = m ? x : y;
    if (!all_eq(z, expect))
      __builtin_abort ();
  }
}

// call the vec<int>, vec<double> overload
void
test1()
{
  const vec x = {1, 2, 3, 4};
  const vec y = {5., 6., 7., 8.};
  {
    const mask m = {true, false, false, true};
    const vec expect0 = {1., 6., 7., 4.};
    const vec z0 = m ? x : y;
    if (!all_eq(z0, expect0))
      __builtin_abort ();

    // call with implicit arg2/arg3 reversal and !m
    const vec expect1 = {5., 2., 3., 8.};
    const vec z1 = m ? y : x;
    if (!all_eq(z1, expect1))
      __builtin_abort ();
  }
  {
    const mask m = {false, false, true, true};
    const vec expect0 = {5., 6., 3., 4.};
    const vec z0 = m ? x : y;
    if (!all_eq(z0, expect0))
      __builtin_abort ();

    // call with implicit arg2/arg3 reversal and !m
    const vec expect1 = {1., 2., 7., 8.};
    const vec z1 = m ? y : x;
    if (!all_eq(z1, expect1))
      __builtin_abort ();
  }
}

// this has higher precedence over the reversed candidate from the overload
// above
// Note the different namespace.
vec<double>
operator?:(const mask& m, vec<double> b, const vec<int>& a)
{
  // gives the "wrong" result to ensure we call the right overload
  for (int i = 0; i < 4; ++i)
    b.v[i] = m.v[i] ? a.v[i] : b.v[i];
  return b;
}

void
test2()
{
  const vec x = {1, 2, 3, 4};
  const vec y = {5., 6., 7., 8.};
  {
    const mask m = {true, false, false, true};
    const vec expect0 = {1., 6., 7., 4.};
    const vec z0 = m ? x : y;
    if (!all_eq(z0, expect0))
      __builtin_abort ();

    // call with implicit arg2/arg3 reversal and !m
    const vec z1 = m ? y : x;
    if (!all_eq(z1, expect0))
      __builtin_abort ();
  }
  {
    const mask m = {false, false, true, true};
    const vec expect0 = {5., 6., 3., 4.};
    const vec z0 = m ? x : y;
    if (!all_eq(z0, expect0))
      __builtin_abort ();

    // call with implicit arg2/arg3 reversal and !m
    const vec z1 = m ? y : x;
    if (!all_eq(z1, expect0))
      __builtin_abort ();
  }
}

int
main ()
{
  test0();
  test1();
  test2();
  return 0;
}
