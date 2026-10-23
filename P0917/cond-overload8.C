// { dg-do compile }
// { dg-options "-std=c++20" }
//

template <typename T, typename U> T operator?:(bool, T, U) = default;

auto test(int a, double* b)
{
  // does not consider user-defined operator?:
  return true ? a : b; // { dg-error "operands to .* have different types" }
}

struct A { int x; };
struct B : A {};

auto test2(A a, B b)
{
  // does not consider user-defined operator?: (built-in)
  return true ? a : b;
}

struct C
{
  int x;
  C() = default;
  C(A);
};

void test3(A a, C c)
{
  // uses built-in, not user-defined operator?:
  auto r = true ? a : c;
  static_assert(__is_same(decltype(r), C), "");
}

struct D
{
  int x;
  D() = default;
  explicit D(A);
};

void test4(A a, D d)
{
  // instantiates template operator?: above (no built-in exists)
  auto r = true ? d : a;
  static_assert(__is_same(decltype(r), D), "");

  // use the reversed operator?: template
  auto r2 = true ? a : d;
  static_assert(__is_same(decltype(r2), D), "");
}
