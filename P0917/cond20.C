// { dg-do compile }
// { dg-options "-std=c++20" }
//
// Test that operator?: with default arguments is rejected.

struct mask { bool v; };
struct vec  { int v; };

vec operator?: (mask m, vec a, vec b = vec{0});	// { dg-error "cannot have default arguments" }
