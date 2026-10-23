// { dg-do compile }
// { dg-options "-std=c++20" }
//
// A non-explicit reference-returning conversion makes the built-in conditional
// viable, so the no-breakage gate rejects the defaulted operator?:.  Given A
// with operator int&, the pair (A, int) has common type int: the A branch
// binds through the conversion to an int lvalue, and the int branch is already
// an int lvalue.  The gate uses the standard "convert one operand to the type
// of the other" rule, which catches this reference binding (a bare
// can_convert_arg, which does not bridge A -> int& -> int, would not).

struct A
{
  int x;
  operator int&() { return x; }   // non-explicit: built-in ?: is viable for (A, int)
};

int& operator?:(bool, A&, int&) = default;  // { dg-error "already exists" }
