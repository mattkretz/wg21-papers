// { dg-do compile }
// { dg-options "-std=c++20" }
//
// Test that the feature macro is defined.

#if !defined(__GXX_CONDITIONAL_IS_OVERLOADABLE__)
#error "__GXX_CONDITIONAL_IS_OVERLOADABLE__ should be defined"
#endif
