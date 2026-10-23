// { dg-do run }
// { dg-options "-std=c++20" }
//
// Test defaulted operator?: with interconvertible types. No common type /
// built-in operator?: exists in that case.

struct B;

struct A
{
  int x;
  constexpr A (B);
  constexpr A (int v) : x(v) {}
};

struct B
{
  int x;
  constexpr B (A);
  constexpr B (int v) : x(v) {}
};

constexpr A::A (B f) : x(f.x) {}
constexpr B::B (A f) : x(f.x) {}

A operator?: (bool, A, B) = default;

int
main ()
{
  // true branch: A -> C
  {
    constexpr A a = 42;
    constexpr B b = 99;
    if ((true ? a : b).x != 42)
      __builtin_abort ();

    static_assert((true ? a : b).x == 42);
  }

  // false branch: B -> C
  {
    constexpr A a = {42};
    constexpr B b (99);
    if ((false ? a : b).x != 99)
      __builtin_abort ();

    static_assert((false ? a : b).x == 99);
  }

  return 0;
}
