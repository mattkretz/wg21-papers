# Finding the right names

## Overview / Brainstorm

* `datapar`

  An array of target-specific size with elements of type T and data parallel operation semantics.
  The actual memory layout and storage size is unspecified.
  The number of elements is influenced via the second template parameter.
  If the second template parameter is `fixed_size<N>` an exact number of `N` elements is used.
  Operations on objects of the type execute the operation component-wise and concurrently.
  This allows the user to communicate data parallelism inherent in the problem at hand.
  An implementation may translate the data parallelism into SIMD instructions, GPU parallelism (which is very SIMD like), serial execution, synchronized multi-core execution, or any mix thereof.
  The implementation is expected to provide guarantees about the resulting code gen depending on compiler flags and ABI parameter (second template parameter), e.g. "`datapar<int, datapar_abi::sse>` uses `xmm` registers for storage and .

  * `vector<T>`
  * `vec<T>`
  * `vecpar<T>`
  * `simd<T>`
  * `datapar<T>`
  * `pack<T>`
  * `simdarray<T>` / `simdvector<T>` / `vecarray<T>`
  * `vectorize<T>` / `simdize<T>` / `vectize<T>` / `vectorized<T>` / `simdized<T>` / `vectized<T>`

* `mask`

  An array of target-specific size with elements of boolean value.
  The actual memory layout and storage size is unspecified.
  This type is the equivalence of `bool` for the `datapar<T>` types.
  It acts as the return type of `datapar` comparisons and can be used for write-masking, masked loads & stores, and reductions to `bool`.

  * `mask<T>`
  * `vecmask<T>`
  * `boolvec<T>`
  * `simdmask<T>`
  * `simdbool<T>`
  * `parmask<T>`
  * `boolpack<T>`

* `where`

  This function wraps a `mask` object and a reference to a `datapar` or `mask` object to implement write-masking, and masked loads & stores.
  The function acts as special syntax to express that e.g. assignment shall only happen at the element indexes where the mask object is `true`.
  The where function returns a temporary object that implements the write-masked operations.

  * `where`
  * `masked`
  * `withmask`
  * `maskedval`
  * `maskedref`

* `memload`, `memstore`

  Loads and stores are the conversions between arrays of `T` and objects of `datapar<T>`.
  Converting loads and stores additionally perform widening or narrowing conversions to/from arrays of `U`, which is convertible to/from `T`.
  `std::atomic` has member functions called `atomic::load` and `atomic::store`: `load` returns the value of the `atomic` with a given `memory_order`; `store` replaces the value of `atomic` with the given value using the given `memory_order`.
  `datapar::load` does the reverse of `atomic::load`: it loads `datapar::size()` consecutive values starting from the given pointer into the `datapar` object.
  `datapar::store` does the reverse of `atomic::store`: it stores `datapar::size()` values from the `datapar` object to the given pointer.

  * `memload  (const U*, Flags), memstore(U*, Flags)`
  * `load     (const U*, Flags), store   (U*, Flags)`
  * `load_from(const U*, Flags), store_to(U*, Flags)`
  * `copy_from(const U*, Flags), copy_to (U*, Flags)`

## Renaming `datapar`

### `vector<T>`
- **pro:**
  1. term-of-art in the industry. We talk about "vectorization", "vector unit", "vector registers", ...
  1. does work as a mathematical vector, e.g. `std::reduce<std::plus>(x*y)` is the scalar product
- **con:**
  1. **[name collision]** `std::vector`: the name is taken. Using a different namespace won't help: Too much confusion/conflict with `std::vector`, which is not constant-size.
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

### `vecpar<T>`
- **pro:**
  1. short
  1. pronounceable
  1. term-of-art in the industry. We talk about "vectorization", "vector unit", "vector registers", ...
  1. resolves ambiguity with math vector
- **con:**
  1. abbreviation ("vector parallel")
  1. (`par_vec` - it's `par_unseq` now, so we should be fine)

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
  1. usage is somewhat idiomatic. (@jensmaurer: why? is this objective?)
- **con:**
  1. **[name collision]** Conflicts with "template parameter pack" usage in variadic templates. These tend to appear in the same context: "You can have a [template parameter] pack of packs [types]." (what?)
  1. no hint about concurrently executing operations in the name

### `simdarray<T>`
- **pro:**
  1. matches constant-length `std:array` and math-style of `std::valarray`.
  1. pronounceable
- **con:**
  1. a bit long for daily use
- **variations:**
  - `simdvector<T>`: "vector" suggests `std::vector` behavior - prefer `simdarray<T>`
  - `vecarray<T>`: abbreviation ("vectorized array", *not* "vector array"); "vector array" misleading

### `vectorize<T>`
- **pro:**
  1. pronounceable
  1. clear meaning: produces a type that is a *vectorized* `T`
  1. clear meaning if proposal is extended to support `std::tuple` for `T` (and structs/classes once we get enough reflection into the language)
- **con:**
  1. not a noun (`vectorization<T>`?)
  1. a bit long for daily use
- **variations:**
  - `simdize<T>`: shorter; downsides of `simd` - see above
  - `vectize<T>`: shorter; abbreviation
  - `-ized<T>`: adjective, still not a noun
