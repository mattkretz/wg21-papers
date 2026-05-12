// { dg-do compile }
// { dg-options "-std=c++20" }
//
// Test that member operator?: is rejected.

struct A {};

struct S {
  int operator?: (A, A);	// { dg-error "must not be a member function" }
};
