# Done

- Idea: use "extended ABI tags" instead of "implementation-defined ABI tags"

- Remove const in template argument of const_where_expression

- Remove paragraph references in \ref macros.

- Recommend a new name for abi_for_size(_t)
  * rebind_abi<T, N>
  * abi_for<T, N>
  * best_abi_for<T, N>
  * best_abi<T, N>
  * simd_abi_for<T, N>
  * simd_abi::best<T, N>
  * simd_abi::deduce<T, N>

- Switch p3 and p4 in [simd.abi]
  (can I strike 'implementation-defined' in p3 "Additionally, for every supported ..."?)

- is is_simd_flag_type_v<overaligned_tag<N>> really true for arbitrary N? Or just for power-of-two N?

- copy more wording to 8.2.2 [execpol.type]p3 about user specialization -> UB

- 8.2.2 p6: drop most of the text after the bullets. Idea: `type` is implementation-defined, except for N=1 where type = scalar.

- 8.2.2 p5 , p7, and p9: invert logic (I don't like it; it seems even more confusing)
  p9: recheck whether I want "vectorizable type"

- 8.2.2 p10: move the fwd references to [simd.copy] into normative wording.

- 8.2.3 where_expression: add && qualifier everywhere.

- all copy_from/to specifications (\flagsRequires): steal from [ptr.align] p1

- 8.2.3 p13: One sentence "The function shall not participate in overload resolution unless <bullet points>"

- 8.2.3 p14: Rewrite.

- 8.2.3 p15: Restrict U.

- 8.2.3: reword 'selected elements' to 'selected indices'

- 8.2.3 p20: Turn the logic around if possible.

- 8.2.3 Add unary plus and operator~.

- replace "instantiation" with "specialization"

- Front matter: If I say "Flags" I mean a type  all load/store remarks require is_lo
  => resolved by repeating it everywhere instead

- flip logic of 8.3.1 p2

- 8.3.1 p2:
  - get rid of 32 - reference some other place that specifies it
  - move sentence after last bullet into a new bullet

- 8.3.1 p6: no note - reword (see notes)

- 8.3.2 p3: need to handle cv qualification

- 8.3.2 p7: copy more from unseq policy "vectorization unsafe functions may not be invoked"

- Use "\code{[mem, mem + size())} is a valid range." in all copy_from/to specifications

- 8.3.5 Replace "Is" in Effects: with something better.

- 8.4.4 Add Throws: to first to reduce functions.

- make simd::reference exposition only but spell out the class definition (cf. [container.node])

- @LEWG: (waiting for feedback) Put identity_element to last argument for reduce(const_where_expression, ...)
  => no change

# Todo
- Do I want to replace any more size() with width?

- Instruct the editor to reference the C standard (for cmath overloads).
- Reference the "domain, pole, and range error" wording in the C standard to say where the preconditions of the math functions are violated.

# Future improvement

- Consider exposition-only data member of simd/simd_mask (value_type data[size()])

# TS feedback issues

* Is std::memory_aligment too generic for std?

* @LEWG: Too much SFINAE on copy_from/to U parameter? Rather allow use of static_assert and provide a trait to detect whether it's usable
  - Actually, there's EWG feedback on this question:
    "use concepts: they give you correct SFINAE and readable error messages". (cf. N4186)

* Can we change simd::size() to simd::size? Do we need size_type?

* Consider a trait for "is_supported<T, Abi>"

* Broadcast ctor conversion alright?

* Allow reduce calls with fixed ABI binary_op?

# Issue List

* Shouldn't hmin and hmax return infinities in case of none_of(x.mask)?

* binary min/max should make NaN input unspecified (because of x86 minp[sd])
