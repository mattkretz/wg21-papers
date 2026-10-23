// { dg-do compile }
// { dg-options "-std=c++20" }
//
// Test that operator?: with wrong arity is rejected.

struct mask { bool v; };
struct vec  { int v; };

vec operator?: (mask m, vec a);		// { dg-error "must have exactly three arguments" }
