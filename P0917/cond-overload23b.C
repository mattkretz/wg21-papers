// { dg-do compile }
// { dg-options "-std=c++20" }

// an operator?: template by itself cannot be wrong

struct C
{
  int v = 0;
};

struct A
{
  C c;

  constexpr explicit
  operator C&() & { return c; }
};

struct B
{
  C c;

  constexpr explicit
  operator C&() & { return c; }
};

template <typename T>
  C& operator?:(bool, T&, B&) = default;

auto test(int &a, B& b)
{
  return true ? a : b; // { dg-error "have different types" }
}
