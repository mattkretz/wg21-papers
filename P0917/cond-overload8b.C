// { dg-do compile }
// { dg-options "-std=c++20" }
//

struct A
{
  constexpr explicit
  operator int() { return 1; }
};

struct B
{
  constexpr explicit
  operator int() { return 2; }
};

template <typename T, typename U> int operator?:(bool, T, U) = default;

int test(A a, B b)
{
  auto r = true ? a : b;
  static_assert(__is_same(decltype(r), int), "");
  return r;
}
