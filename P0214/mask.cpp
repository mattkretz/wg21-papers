namespace std {
  namespace experimental {
    template <class T, class Abi> class simd_mask {
    public:
      using value_type = bool;
      using reference = implementation-defined;  // see simd::reference
      using simd_type = simd<T, Abi>;
      using size_type = size_t;
      using abi_type = Abi;

      static constexpr size_type size() noexcept;

      simd_mask() = default;

      simd_mask(const simd_mask&) = default;
      simd_mask(simd_mask&&) = default;
      simd_mask& operator=(const simd_mask&) = default;
      simd_mask& operator=(simd_mask&&) = default;

      // broadcast constructor
      explicit simd_mask(value_type) noexcept;

      // implicit type conversion constructor
      template <class U> simd_mask(const simd_mask<U, simd_abi::fixed_size<size()>>&) noexcept;

      // load constructor
      template <class Flags> simd_mask(const value_type* mem, Flags);

      // loads [simd_mask.load]
      template <class Flags> void copy_from(const value_type* mem, Flags);

      // stores [simd_mask.store]
      template <class Flags> void copy_to(value_type* mem, Flags) const;

      // scalar access [simd_mask.subscr]
      reference operator[](size_type);
      value_type operator[](size_type) const;

      // unary operators [simd_mask.unary]
      simd_mask operator!() const noexcept;

      // simd_mask binary operators [simd_mask.binary]
      friend simd_mask operator&&(const simd_mask&, const simd_mask&) noexcept;
      friend simd_mask operator||(const simd_mask&, const simd_mask&) noexcept;
      friend simd_mask operator& (const simd_mask&, const simd_mask&) noexcept;
      friend simd_mask operator| (const simd_mask&, const simd_mask&) noexcept;
      friend simd_mask operator^ (const simd_mask&, const simd_mask&) noexcept;

      // simd_mask compound assignment [simd_mask.cassign]
      friend simd_mask& operator&=(simd_mask&, const simd_mask&) noexcept;
      friend simd_mask& operator|=(simd_mask&, const simd_mask&) noexcept;
      friend simd_mask& operator^=(simd_mask&, const simd_mask&) noexcept;

      // simd_mask compares [simd_mask.comparison]
      friend simd_mask operator==(const simd_mask&, const simd_mask&) noexcept;
      friend simd_mask operator!=(const simd_mask&, const simd_mask&) noexcept;
    };
  }
}
