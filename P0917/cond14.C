// { dg-do run }
// { dg-options "-std=c++20" }

// Test: both arg2 and arg3 need different conversions to the reference return type.
// A -> C& and B -> C& are different conversion operators.

struct C
{
  int v;
};

struct A
{
  C c;
  explicit operator C&() & { return c; }
};

struct B
{
  C c;
  explicit operator C&() & { return c; }
};

C& operator?:(bool, A&, B&) = default;

int
main ()
{
  bool failed = false;
  A a; a.c.v = 42;
  B b; b.c.v = 99;

  C& r1 = true ? a : b;
  if (r1.v != 42)
    {
      __builtin_printf("1");
      failed = true;
    }
  if (&r1 != &a.c)
    {
      __builtin_printf("2");
      failed = true;
    }

  C& r2 = false ? a : b;
  if (r2.v != 99)
    {
      __builtin_printf("3");
      failed = true;
    }
  if (&r2 != &b.c)
    {
      __builtin_printf("4");
      failed = true;
    }

  return failed ? -1 : 0;
}
