namespace std {
  namespace experimental {
    template <class T, class Abi> class mask {
    public:
      using value_type = bool;
      using reference = implementation-defined;  // see datapar::reference
      using datapar_type = datapar<T, Abi>;
      using size_type = size_t;
      using abi_type = Abi;

      static constexpr size_type size() noexcept;

      mask() = default;

      mask(const mask&) = default;
      mask(mask&&) = default;
      mask& operator=(const mask&) = default;
      mask& operator=(mask&&) = default;

      // broadcast constructor
      explicit mask(value_type) noexcept;

      // implicit type conversion constructor
      template <class U> mask(const mask<U, datapar_abi::fixed_size<size()>>&) noexcept;

      // load constructor
      template <class Flags> mask(const value_type* mem, Flags);

      // loads [mask.load]
      template <class Flags> void memload(const value_type* mem, Flags);

      // stores [mask.store]
      template <class Flags> void memstore(value_type* mem, Flags) const;

      // scalar access [mask.subscr]
      reference operator[](size_type);
      value_type operator[](size_type) const;

      // unary operators [mask.unary]
      mask operator!() const noexcept;

      // mask binary operators [mask.binary]
      friend mask operator&&(const mask&, const mask&) noexcept;
      friend mask operator||(const mask&, const mask&) noexcept;
      friend mask operator& (const mask&, const mask&) noexcept;
      friend mask operator| (const mask&, const mask&) noexcept;
      friend mask operator^ (const mask&, const mask&) noexcept;

      // mask compound assignment [mask.cassign]
      friend mask& operator&=(mask&, const mask&) noexcept;
      friend mask& operator|=(mask&, const mask&) noexcept;
      friend mask& operator^=(mask&, const mask&) noexcept;

      // mask compares [mask.comparison]
      friend mask operator==(const mask&, const mask&) noexcept;
      friend mask operator!=(const mask&, const mask&) noexcept;
    };
  }
}
