// { dg-do compile }
// { dg-options "-std=c++20" }
//
// Test that defaulted operator?: is ill-formed when one UDT implicitly
// converts to the other (common type / built-in operator?: already exists).

struct Base { int x; };
struct Derived : Base { int y; };

Base operator?: (bool, Base, Derived) = default; // { dg-error "built-in operator\\?: already exists" }

Base operator?: (bool, Base, Derived) // { dg-error "built-in operator\\?: already exists" }
{ return Base{0}; };

namespace foo
{
  struct A { int x; };
  struct B : A {};

  template <typename T, typename U>
    T operator?: (bool, T, U) = default; // no error

  A test(A a, B b)
  { return true ? a : b; } // uses built-in, ignores the template
}
