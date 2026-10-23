// { dg-do compile }
// { dg-options "-std=c++20" }

// Regression: the declaration-time re-check must test the return type
// against the branch's real value category (declval<param>), not an
// always-lvalue dummy.  A by-value parameter is an rvalue at the use site,
// so a lvalue-qualified reference conversion is not applicable and the
// defaulted operator?: is never selectable -- reject it at declaration.

struct A
{
  int x;
  explicit operator int&() & { return x; }
};

int& operator?:(bool, auto, int&) = default;

void
test0()
{
  A a{0};
  int b = 0;
  int& r = (true ? a : b); // { dg-error "operands to .* have different types" }
  (void)r;
}

// By-value A is an rvalue; operator int&() & is lvalue-only, so the branch
// is not directly-initializable to int& -- rejected at declaration.
int& operator?:(bool, A, int&) = default; // { dg-error "cannot convert.*A.*to.*int&" }

// By-reference A& is an lvalue; operator int&() & applies, so this one is
// still accepted -- the fix must not over-reject.
int& operator?:(bool, A&, int&) = default;
