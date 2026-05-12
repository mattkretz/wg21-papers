// { dg-do run }
// { dg-options "-std=c++20" }
//
// Test that defaulted operator?: preserves lazy evaluation semantics:
// only the selected branch is evaluated. User-defined (non-defaulted)
// operator?: evaluates both branches as function arguments.

static int true_evaluated = 0;
static int false_evaluated = 0;

struct S1 { int v; };
struct S2 { int v; };
struct S12
{
  int v;
  constexpr S12 (S1 s) : v(s.v) {}
  constexpr S12 (S2 s) : v(s.v) {}
};

// Defaulted operator?: -- should use built-in COND_EXPR internally,
// preserving lazy evaluation.
S12 operator?: (bool, S1, S2) = default;

// Track side effects in branch expressions
S1
get_true_branch ()
{
  true_evaluated++;
  return S1{42};
}

S2
get_false_branch ()
{
  false_evaluated++;
  return S2{99};
}

int
main ()
{
  {
    S12 result = true ? get_true_branch () : get_false_branch ();
    if (true_evaluated != 1 || false_evaluated != 0)
      __builtin_abort ();
    if (result.v != 42)
      __builtin_abort ();
  }
  {
    S12 result = false ? get_true_branch () : get_false_branch ();
    if (true_evaluated != 1 || false_evaluated != 1)
      __builtin_abort ();
    if (result.v != 99)
      __builtin_abort ();
  }

  return 0;
}
