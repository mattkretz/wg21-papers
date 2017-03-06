# Finding the right names

## Overview / Brainstorm

* `datapar`

  An array of target-specific size with elements of type T and data parallel operation semantics.

  * `vector<T>`
  * `vec<T>`
  * `simd<T>`
  * `datapar<T>`
  * `pack<T>`
  * `simdarray<T>`
  * `simdvector<T>`
  * `vecarray<T>`
  * `vectorize<T>`
  * `simdize<T>`
  
* `mask`

  An array of target-specific size with elements of boolean value.

  * `mask<T>`
  * `vecmask<T>`
  * `simdmask<T>`
  * `boolvec<T>`
  
* `where`
* `memload`, `memstore`

## Renaming `datapar`

### `vector<T>`
- **pro:**
  1. term-of-art in the industry. We talk about "vectorization", "vector unit", "vector registers", ...
  1. does work as a mathematical vector, e.g. `std::reduce<std::plus>(x*y)` is the scalar product
- **con:**
  1. `std::vector`: the name is taken. Using a different namespace won't help: Too much confusion/conflict with `std::vector`, which is not constant-size.
  1. ambiguity with mathematically inclined people who may expect operators to behave differently (especially, I've heard feedback of users expecting `operator*` to be the dot-product)

### `vec<T>`
- **pro:**
  1. short
  1. pronounceable
  1. usage is somewhat idiomatic: vec<T> is a vector-lookalike of T.
  1. term-of-art in the industry. We talk about "vectorization", "vector unit", "vector registers", ...
- **con:**
  1. abbreviation
  1. close to `std::vector`
  1. ambiguity with mathematically inclined people who may expect operators to behave differently (especially, I've heard feedback of users expecting `operator*` to be the dot-product)

### `simd<T>`
- **pro:**
  1.  short
  1. pronounceable
  1. usage is idiomatic: simd<T> is the SIMD thing for T.
  1. Known term in the industry
  1. maybe even more to the point than "vector" (note variable-length vector units on traditional vector computers)
- **con:**
  1. acronym
  1. might suggest that the type is not usable for GPUs
  1. one `simd<T>` object could drive multiple SIMD registers, multiple partially synchronized threads, one or more non-SIMD registers, a mix of SIMD and non-SIMD registers.

### `datapar<T>`
- **pro:**
  1. pronounceable
  1. "data parallel" hints at the intended use: Code expresses inherent data parallelism (intent). Contrast that to "code that uses SIMD registers and operations" (implementation detail).
- **con:**
  1. abbreviation
  1. new term

### `pack<T>`
- **pro:**
  1. short
  1. pronounceable
  1. usage is somewhat idiomatic.
- **con:**
  1. Conflicts with "template parameter pack" usage in variadic templates. These tend to appear in the same context: "You can have a [template parameter] pack of packs [types]." (what?)
  1. no hint about concurrently executing operations

### `simdarray<T>`
- **pro:**
  1. matches constant-length `std:array` and math-style of `std::valarray`.
  1. pronounceable
- **con:**
  1. a bit long for daily use

### `vecarray<T>`
- **pro:**
  1. matches constant-length `std:array` and math-style of `std::valarray`.
  1. pronounceable
- **con:**
  1. abbreviation ("vectorized array", *not* "vector array")
  1. a bit long for daily use
  1. "vector array" misleading

### `vectorize<T>`
- **pro:**
  1. pronounceable
  1. clear meaning: produces a type that is a *vectorized* `T`
  1. clear meaning if proposal is extended to support `std::tuple` for `T` (and structs/classes once we get enough reflection into the language)
- **con:**
  1. not a noun (`vectorization<T>`?)
  1. a bit long for daily use
- **variation:** `simdize<T>` (shorter, downsides of `simd` - see above)

### `simdvector<T>`
- **con:**
  1. "vector" suggests `std::vector` behavior - prefer `simdarray<T>`
