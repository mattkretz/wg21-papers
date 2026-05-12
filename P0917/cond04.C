// { dg-do run }
// { dg-options "-std=c++20" }
//
// Test defaulted operator?: with non-boolean condition (Path 1 interaction).
// The condition type has an implicit bool conversion, triggering Path 1's
// user-defined lookup before reaching the defaulted operator.

struct mask { int v; explicit operator bool() const { return v != 0; } };

struct Vec2i { int x, y; };
struct Vec2f { float x, y; };
struct Vec2d
{
  double x, y;
  Vec2d (Vec2i v) : x(v.x), y(v.y) {}
  explicit Vec2d (Vec2f v) : x(v.x), y(v.y) {}
};

Vec2d operator?: (bool, Vec2i, Vec2f) = default;

int
main ()
{
  // Non-boolean condition via implicit conversion + defaulted operator
  {
    mask m = {1};
    Vec2i a = {1, 2};
    Vec2f b = {3.0f, 4.0f};
    Vec2d z = m ? a : b;
    if (z.x != 1 || z.y != 2)
      __builtin_abort ();
  }

  {
    mask m = {0};
    Vec2i a = {1, 2};
    Vec2f b = {3.0f, 4.0f};
    Vec2d z = m ? a : b;
    if (z.x != 3 || z.y != 4)
      __builtin_abort ();
  }

  return 0;
}
