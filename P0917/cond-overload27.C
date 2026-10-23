// { dg-do run }
// { dg-options "-std=c++23" }

#include <stdfloat>

// is_convertible_v<float16_t, float> is false while
// static_cast<float16_t>(float) is valid

struct X
{
  explicit operator std::float16_t()
  { return 2.f16; }
};

struct Y
{
  explicit operator std::float16_t()
  { return 2.f16; }
};

std::float16_t operator?:(bool, float, X) = default;

template <typename T>
  std::float16_t operator?:(bool, float, T) = default;

float a = 1.f;

int
main()
{
  auto b = true ? a : X();
  auto c = false ? a : X();
  if (b != 1)
    __builtin_abort();
  if (c != 2)
    __builtin_abort();

  b = true ? a : Y();
  c = false ? a : Y();
  if (b != 1)
    __builtin_abort();
  if (c != 2)
    __builtin_abort();

  return 0;
}
