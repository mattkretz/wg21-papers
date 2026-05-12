// { dg-do run }
// { dg-options "-std=c++20 -foverloadable-conditional" }
//
// P2600 scenario: with -fno-overloadable-conditional, ADL for operator?:
// is not performed, so Wrap<Incomplete> is not instantiated and the code
// is well-formed. With -foverloadable-conditional (default), ADL would
// attempt to instantiate Wrap<Incomplete>, which is ill-formed.

struct Incomplete;
template <typename T> struct Wrap { T t; };

template <typename Unused>
  struct Testable
  {
    explicit operator bool () const { return true; }
  };

struct A
{
  operator int() const { return 1; }
};

struct B
{
  explicit operator int() const { return 2; }
};

int operator?:(bool, A, B) = default;

int
main ()
{
  Testable<Wrap<Incomplete>> l;
  // If the following ?: triggers lookup -> ADL -> Testable<Incomplete> would
  // make the program ill-formed
  int x = l ? A() : 2;
  if (x != 1)
    __builtin_abort ();

  x = true ? A() : B();
  if (x != 1)
    __builtin_abort ();
  return 0;
}
