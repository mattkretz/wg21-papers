// { dg-do compile }
// { dg-options "-std=c++20 -fno-overloadable-conditional" }
//
// Test that -fno-overloadable-conditional disables the extension:
// the macro is undefined and declarations are rejected.

#ifdef __GXX_CONDITIONAL_IS_OVERLOADABLE__
#error "macro should not be defined"
#endif

struct S1 { int v; };
struct S2 { int v; };

S1 operator?: (bool, S1, S2);		// { dg-error "does not allow overloading the conditional operator" }
S1 operator?: (bool, S1, S2) = default;	// { dg-error "does not allow overloading the conditional operator" }
