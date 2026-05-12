// { dg-do run }
// { dg-options "-std=c++20" }
//
// Test that taking the address of a defaulted operator?: and calling it
// directly produces correct results (not a trap).

struct B;

struct A
{
  int x;
  A (int v) : x(v) {}
  A (const B&);
};

struct B
{
  int x;
  B (int v) : x(v) {}
};

struct C
{
  int x;
  C (int v) : x(v) {}
  C (const B& b) : x(b.x) {}
};

A::A (const B& b) : x(b.x) {}

A operator?: (bool, A, B) = default;
C operator?: (bool, C, B) = default;

int
main ()
{
  {
    using fn_t = A (*)(bool, A, B);
    fn_t f = &operator?:;

    A a = 42;
    B b = 99;

    A r1 = f (true, a, b);
    if (r1.x != 42)
      __builtin_abort ();

    A r2 = f (false, a, b);
    if (r2.x != 99)
      __builtin_abort ();
  }
  {
    using fn_t = C (*)(bool, C, B);
    fn_t f = &operator?:;

    C c = 42;
    B b = 99;

    C r1 = f (true, c, b);
    if (r1.x != 42)
      __builtin_abort ();

    C r2 = f (false, c, b);
    if (r2.x != 99)
      __builtin_abort ();
  }

  return 0;
}
