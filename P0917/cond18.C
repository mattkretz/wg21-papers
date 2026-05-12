// { dg-do run }
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

int main()
{
  A a;
  B b;
  (true ? a : b).v = 1;
  (false ? a : b).v = 2;
  (true ? b : a).v += 1;
  (false ? b : a).v += 3;
  return (a.c.v == 4 && b.c.v == 3) ? 0 : 1;
}
