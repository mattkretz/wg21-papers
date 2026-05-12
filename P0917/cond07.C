// { dg-do compile }
// { dg-options "-std=c++20" }
//
// Test that defaulted operator?: with non-bool first parameter is rejected.

struct S1 { int v; };
struct S2 { int v; };

S1 operator?: (int, S1, S2) = default;	// { dg-error "first parameter of defaulted.*must be .bool." }
