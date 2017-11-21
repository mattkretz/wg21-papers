namespace std::experimental {
  inline namespace parallelism_v2 {
    template <class T, class Abi> class simd {
    public:
      using value_type = T;
      using reference = @\emph{see below}@;
      using mask_type = simd_mask<T, Abi>;
      using abi_type = Abi;

      static constexpr size_t size() noexcept;

      simd() = default;

      // implicit type conversion constructor
      template <class U> simd(const simd<U, simd_abi::fixed_size<size()>>&);

      // implicit broadcast constructor (see below for constraints)
      template <class U> simd(U&& value);

      // generator constructor (see below for constraints)
      template <class G> explicit simd(G&& gen);

      // load constructor
      template <class U, class Flags> simd(const U* mem, Flags f);

      // loads [simd.load]
      template <class U, class Flags> void copy_from(const U* mem, Flags f);

      // stores [simd.store]
      template <class U, class Flags> void copy_to(U* mem, Flags f) const;

      // scalar access [simd.subscr]
      reference operator[](size_t);
      value_type operator[](size_t) const;

      // unary operators [simd.unary]
      simd& operator++();
      simd operator++(int);
      simd& operator--();
      simd operator--(int);
      mask_type operator!() const;
      simd operator~() const;  // see below
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
