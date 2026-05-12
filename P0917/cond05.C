// { dg-do run }
// { dg-options "-std=c++20" }
//
// Test elvis operator `a ?: b` where `a` has explicit operator bool()

struct A
{
  int x;
  explicit operator bool() const { return x != 0; }
};

struct B { float x; };

struct Res
{
  double x;
  Res (A v) : x(v.x) {}
  Res (B v) : x(v.x) {}
};

Res operator?: (bool, B, A) = default;

int
main ()
{
  {
    A a = {3};
    B b = {99.0f};
    Res z = a ?: b;
    if (z.x != 3)
      __builtin_abort ();
  }
  {
    A a = {0};
    B b = {5.0f};
    Res z = a ?: b;
    if (z.x != 5)
      __builtin_abort ();
  }

  return 0;
}
