namespace std::experimental {
  inline namespace parallelism_v2 {
    template <class T, class Abi> class simd_mask {
    public:
      using value_type = bool;
      using reference = @\emph{see below}@;
      using simd_type = simd<T, Abi>;
      using abi_type = Abi;

      static constexpr size_t size() noexcept;

      simd_mask() = default;

      // broadcast constructor
      explicit simd_mask(value_type) noexcept;

      // implicit type conversion constructor
      template <class U> simd_mask(const simd_mask<U, simd_abi::fixed_size<size()>>&) noexcept;

      // load constructor
      template <class Flags> simd_mask(const value_type* mem, Flags);

      // loads \ref{sec:simd.mask.copy}
      template <class Flags> void copy_from(const value_type* mem, Flags);
      template <class Flags> void copy_to(value_type* mem, Flags) const;

      // scalar access \ref{sec:simd.mask.subscr}
      reference operator[](size_t);
      value_type operator[](size_t) const;

      // unary operators \ref{sec:simd.mask.unary}
      simd_mask operator!() const noexcept;

      // simd_mask binary operators \ref{sec:simd.mask.binary}
      friend simd_mask operator&&(const simd_mask&, const simd_mask&) noexcept;
      friend simd_mask operator||(const simd_mask&, const simd_mask&) noexcept;
      friend simd_mask operator& (const simd_mask&, const simd_mask&) noexcept;
      friend simd_mask operator| (const simd_mask&, const simd_mask&) noexcept;
      friend simd_mask operator^ (const simd_mask&, const simd_mask&) noexcept;

      // simd_mask compound assignment \ref{sec:simd.mask.cassign}
      friend simd_mask& operator&=(simd_mask&, const simd_mask&) noexcept;
      friend simd_mask& operator|=(simd_mask&, const simd_mask&) noexcept;
      friend simd_mask& operator^=(simd_mask&, const simd_mask&) noexcept;

      // simd_mask compares \ref{sec:simd.mask.comparison}
      friend simd_mask operator==(const simd_mask&, const simd_mask&) noexcept;
      friend simd_mask operator!=(const simd_mask&, const simd_mask&) noexcept;
    };
  }
}
