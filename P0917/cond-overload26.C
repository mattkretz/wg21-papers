// { dg-do run }
// { dg-options "-std=c++20" }
//
// Regression test: a reference-returning DEFAULTED operator?: used as the
// target of an lvalue assignment --  (c ? a : b) = v;  -- used to crash the
// compiler (internal compiler error in cp_build_modify_expr, cp/typeck.cc):
// the defaulted operator?: lowered to a lazy COND_EXPR whose branches were
// reference-typed (int&), and the COND_EXPR case's recursion tripped
// gcc_assert (!TYPE_REF_P (lhstype)).  The branches are now lvalues of the
// referenced type (as in the built-in lvalue ?:), so the assignment compiles
// and writes through the selected reference.  The explicit conversion only
// keeps the built-in ?: from being viable, forcing the user-defined path.

struct A
{
  int x;
  explicit operator int&() { return x; }
};

int& operator?:(bool, A&, int&) = default;

int
main ()
{
  A a {111};
  int b = 222;

  // The selected A branch yields a reference to a.x; assign through it,
  // leaving the int branch (b) untouched.
  (true ? a : b) = 1;
  if (a.x != 1 || b != 222)
    __builtin_abort ();

  // The selected int branch yields a reference to b; assign through it,
  // leaving the A branch (a.x) untouched.
  (false ? a : b) = 2;
  if (a.x != 1 || b != 2)
    __builtin_abort ();

  return 0;
}
