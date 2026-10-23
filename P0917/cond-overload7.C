// { dg-do run }
// { dg-options "-std=c++20" }
//
// Test user-defined operator?: overload as hidden friend.

struct mask { bool v[4]; };

template <typename T = int>
  struct vec {
    T v[4];

    friend constexpr vec<T>
    operator?: (const mask& m, vec a, const vec& b)
    {
      for (int i = 0; i < 4; ++i)
	a.v[i] = m.v[i] ? a.v[i] : b.v[i];
      return a;
    }
  };

template <typename T>
  bool
  all_eq(const vec<T>& a, const vec<T>& b)
  {
    for (int i = 0; i < 4; ++i)
      if (a.v[i] != b.v[i])
	return false;
    return true;
  }

int
main ()
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

  return 0;
}
