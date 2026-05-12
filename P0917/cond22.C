// { dg-do run }
// { dg-options "-std=c++20" }
//
// Test user-defined operator?: with mixed arg2/arg3 types that is not
// defaulted.
//
// Because ?: is commutative between arg2/arg3 (with negated arg1), a single
// overload covers both orderings via the reversed-argument lookup mechanism.

struct i32 { int v; };
struct u32 { unsigned v; };
struct i64 { long long v; };

constexpr i64
operator?: (bool c, i32 a, u32 b)
{ return c ? i64{a.v} : i64{b.v}; }

int
main ()
{
  {
    i32 i = {42};
    u32 f = {99};
    i64 r = true ? i : f;
    if (r.v != 42)
      __builtin_abort ();
  }
  {
    i32 i = {42};
    u32 f = {99};
    i64 r = false ? i : f;
    if (r.v != 99)
      __builtin_abort ();
  }

  // Reversed order: matched by reversed-argument lookup
  {
    i32 i = {42};
    u32 f = {99};
    i64 r = true ? f : i;
    if (r.v != 99)
      __builtin_abort ();
  }
  {
    i32 i = {42};
    u32 f = {99};
    i64 r = false ? f : i;
    if (r.v != 42)
      __builtin_abort ();
  }

  return 0;
}

static_assert([] {
  constexpr i32 i = {42};
  constexpr u32 f = {99};
  constexpr i64 r = false ? f : i;
  return r.v == 42;
});
