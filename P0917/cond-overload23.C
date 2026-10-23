// { dg-do compile }
// { dg-options "-std=c++20" }

// an operator?: template by itself cannot be wrong

struct C
{
  int v;
};

struct B
{
  C c;
  explicit operator C&() & { return c; }
};

template <typename T>
  C& operator?:(bool, T&, B&) = default;
