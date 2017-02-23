namespace std {
  namespace experimental {
    template <class T, class Abi> class datapar {
    public:
      using value_type = T;
      using reference = implementation_defined;  // see below
      using mask_type = mask<T, Abi>;
      using size_type = size_t;
      using abi_type = Abi;

      static constexpr size_type size() noexcept;

      datapar() = default;

      datapar(const datapar &) = default;
      datapar(datapar &&) = default;
      datapar &operator=(const datapar &) = default;
      datapar &operator=(datapar &&) = default;

      // implicit broadcast constructor
      template <class U> datapar(const U &) noexcept;

      // implicit type conversion constructor
      template <class U> datapar(const datapar<U, datapar_abi::fixed_size<size()>> &) noexcept;

      // generator constructor
      template <class G> datapar(G &&gen);

      // load constructor
      template <class U, class Flags> datapar(const U *mem, Flags) noexcept;
      template <class U, class Flags> datapar(const U *mem, mask_type k, Flags) noexcept;

      // loads [datapar.load]
      template <class U, class Flags> void memload(const U *mem, Flags) noexcept;

      // stores [datapar.store]
      template <class U, class Flags> void memstore(U *mem, Flags) const noexcept;

      // scalar access [datapar.subscr]
      reference operator[](size_type) noexcept;
      value_type operator[](size_type) const noexcept;

      // unary operators [datapar.unary]
      datapar &operator++() noexcept;
      datapar operator++(int) noexcept;
      datapar &operator--() noexcept;
      datapar operator--(int) noexcept;
      mask_type operator!() const noexcept;
      datapar operator~() const noexcept;
      datapar operator+() const noexcept;
      datapar operator-() const noexcept;

      // binary operators [datapar.binary]
      friend datapar operator+ (const datapar &, const datapar &) noexcept;
      friend datapar operator- (const datapar &, const datapar &) noexcept;
      friend datapar operator* (const datapar &, const datapar &) noexcept;
      friend datapar operator/ (const datapar &, const datapar &) noexcept;
      friend datapar operator% (const datapar &, const datapar &) noexcept;
      friend datapar operator& (const datapar &, const datapar &) noexcept;
      friend datapar operator| (const datapar &, const datapar &) noexcept;
      friend datapar operator^ (const datapar &, const datapar &) noexcept;
      friend datapar operator<<(const datapar &, const datapar &) noexcept;
      friend datapar operator>>(const datapar &, const datapar &) noexcept;
      friend datapar operator<<(const datapar &, int) noexcept;
      friend datapar operator>>(const datapar &, int) noexcept;

      // compound assignment [datapar.cassign]
      friend datapar &operator+= (datapar &, const datapar &) noexcept;
      friend datapar &operator-= (datapar &, const datapar &) noexcept;
      friend datapar &operator*= (datapar &, const datapar &) noexcept;
      friend datapar &operator/= (datapar &, const datapar &) noexcept;
      friend datapar &operator%= (datapar &, const datapar &) noexcept;
      friend datapar &operator&= (datapar &, const datapar &) noexcept;
      friend datapar &operator|= (datapar &, const datapar &) noexcept;
      friend datapar &operator^= (datapar &, const datapar &) noexcept;
      friend datapar &operator<<=(datapar &, const datapar &) noexcept;
      friend datapar &operator>>=(datapar &, const datapar &) noexcept;
      friend datapar &operator<<=(datapar &, int) noexcept;
      friend datapar &operator>>=(datapar &, int) noexcept;

      // compares [datapar.comparison]
      friend mask_type operator==(const datapar &, const datapar &) noexcept;
      friend mask_type operator!=(const datapar &, const datapar &) noexcept;
      friend mask_type operator>=(const datapar &, const datapar &) noexcept;
      friend mask_type operator<=(const datapar &, const datapar &) noexcept;
      friend mask_type operator> (const datapar &, const datapar &) noexcept;
      friend mask_type operator< (const datapar &, const datapar &) noexcept;
    };
  }
}
