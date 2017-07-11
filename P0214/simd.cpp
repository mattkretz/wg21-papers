namespace std {
  namespace experimental {
    template <class T, class Abi> class simd {
    public:
      using value_type = T;
      using reference = implementation-defined;  // see below
      using mask_type = simd_mask<T, Abi>;
      using size_type = size_t;
      using abi_type = Abi;

      static constexpr size_type size() noexcept;

      simd() = default;

      simd(const simd&) = default;
      simd(simd&&) = default;
      simd& operator=(const simd&) = default;
      simd& operator=(simd&&) = default;

      // implicit broadcast constructor
      template <class U> simd(U&&);

      // implicit type conversion constructor
      template <class U> simd(const simd<U, simd_abi::fixed_size<size()>>&);

      // generator constructor
      template <class G> simd(G&& gen);

      // load constructor
      template <class U, class Flags> simd(const U* mem, Flags);

      // loads [simd.load]
      template <class U, class Flags> void memload(const U* mem, Flags);

      // stores [simd.store]
      template <class U, class Flags> void memstore(U* mem, Flags) const;

      // scalar access [simd.subscr]
      reference operator[](size_type);
      value_type operator[](size_type) const;

      // unary operators [simd.unary]
      simd& operator++();
      simd operator++(int);
      simd& operator--();
      simd operator--(int);
      mask_type operator!() const;
      simd operator~() const;
      simd operator+() const;
      simd operator-() const;

      // binary operators [simd.binary]
      friend simd operator+ (const simd&, const simd&);
      friend simd operator- (const simd&, const simd&);
      friend simd operator* (const simd&, const simd&);
      friend simd operator/ (const simd&, const simd&);
      friend simd operator% (const simd&, const simd&);
      friend simd operator& (const simd&, const simd&);
      friend simd operator| (const simd&, const simd&);
      friend simd operator^ (const simd&, const simd&);
      friend simd operator<<(const simd&, const simd&);
      friend simd operator>>(const simd&, const simd&);
      friend simd operator<<(const simd&, int);
      friend simd operator>>(const simd&, int);

      // compound assignment [simd.cassign]
      friend simd& operator+= (simd&, const simd&);
      friend simd& operator-= (simd&, const simd&);
      friend simd& operator*= (simd&, const simd&);
      friend simd& operator/= (simd&, const simd&);
      friend simd& operator%= (simd&, const simd&);
      friend simd& operator&= (simd&, const simd&);
      friend simd& operator|= (simd&, const simd&);
      friend simd& operator^= (simd&, const simd&);
      friend simd& operator<<=(simd&, const simd&);
      friend simd& operator>>=(simd&, const simd&);
      friend simd& operator<<=(simd&, int);
      friend simd& operator>>=(simd&, int);

      // compares [simd.comparison]
      friend mask_type operator==(const simd&, const simd&);
      friend mask_type operator!=(const simd&, const simd&);
      friend mask_type operator>=(const simd&, const simd&);
      friend mask_type operator<=(const simd&, const simd&);
      friend mask_type operator> (const simd&, const simd&);
      friend mask_type operator< (const simd&, const simd&);
    };
  }
}
