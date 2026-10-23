// { dg-do compile }
// { dg-options "-std=c++20" }

// Test: no viable conversion available — should produce a compile error at
// declaration time, not segfault or wrong code at call site.

struct C
{
  int v;
};

struct A
{
  int x;
};

struct A2
{
  int x;
};

struct B
{
  C c;
  explicit operator C&() & { return c; }
};

// A has no conversion to C& — rejected at declaration.
C& operator?:(bool, A&, B&) = default; // { dg-error "cannot convert.*A.*to.*C" }
