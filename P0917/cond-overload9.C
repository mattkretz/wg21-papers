// { dg-do run }
// { dg-options "-std=c++20" }
//
// Test defaulted operator?: with UDTs convertible to one third type.
// No common type exists between i32 and u32, so the built-in operator doesn't
// exist.

struct i32 { int v; };
struct u32 { unsigned v; };
struct i64 {
  unsigned long long v;
  i64(auto x) : v(x.v) {}
};

i64 operator?: (bool, i32, u32) = default;

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
