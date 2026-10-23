// { dg-do compile }
// { dg-options "-std=c++20" }
//
// user-defined non-default operator?: overloads don't get reversed candidates
// if the first argument cannot be negated

struct mask {
  bool v[4];
};

template <typename T = int>
  struct vec { T v[4]; };

// can't reverse this one because !mask is not defined
vec<double>
operator?: (const mask& m, const vec<int>& a, vec<double> b);

void
test1()
{
  const mask m = {true, false, false, true};
  const vec x = {1, 2, 3, 4};
  const vec y = {5., 6., 7., 8.};
  const vec z1 = m ? y : x; // { dg-error "could not convert" }
}

// explicit reversed overload
vec<double>
operator?: (const mask& m, vec<double> b, const vec<int>& a);

void
test2()
{
  const mask m = {true, false, false, true};
  const vec x = {1, 2, 3, 4};
  const vec y = {5., 6., 7., 8.};
  const vec z1 = m ? y : x; // well-formed now
}
