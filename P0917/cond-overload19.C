// { dg-do run }
// { dg-options "-std=c++20" }

struct A
{
  int x;
  explicit operator int&() & { return x; }
  explicit operator const int&() const & { return x; }
};

int& operator?:(bool, A&, int&) = default;

int
main ()
{
  bool failed = false;
  {
    A a = {1};
    int b = 2;
    int& c = false ? a : b;
    if (c != 2)
      {
	__builtin_printf("1");
	failed = true;
      }
    if (&c != &b)
      {
	__builtin_printf("2");
	failed = true;
      }
  }
  {
    A a = {1};
    int b = 2;
    int& c = true ? a : b;
    if (c != 1)
      {
	__builtin_printf("3");
	failed = true;
      }
    if (&c != &a.x)
      {
	__builtin_printf("4");
	failed = true;
      }
  }

  return failed ? -1 : 0;
}
