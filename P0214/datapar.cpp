namespace std {
  namespace experimental {
    template <class T, class Abi> class datapar {
    public:
      typedef T value_type;
      typedef implementation_defined reference;
      typedef mask<T, Abi> mask_type;
      typedef size_t size_type;
      typedef Abi abi_type;

      static constexpr size_type size();

      datapar() = default;

      datapar(const datapar &) = default;
      datapar(datapar &&) = default;
      datapar &operator=(const datapar &) = default;
      datapar &operator=(datapar &&) = default;

      // implicit broadcast constructor
      template <class U> datapar(const U &);

      // implicit type conversion constructor
      template <class U> datapar(const datapar<U, datapar_abi::fixed_size<size()>> &);

      // generator constructor
      template <class G> datapar(G &&gen);

      // load constructor
      template <class U, class Flags> datapar(const U *mem, Flags);
      template <class U, class Flags> datapar(const U *mem, mask_type k, Flags);

      // loads [datapar.load]
      template <class U, class Flags> void memload(const U *mem, Flags);
      template <class U, class Flags> void memload(const U *mem, mask_type k, Flags);

      // stores [datapar.store]
      template <class U, class Flags> void memstore(U *mem, Flags) const;
      template <class U, class Flags> void memstore(U *mem, mask_type k, Flags) const;

      // scalar access [datapar.subscr]
      reference operator[](size_type);
      value_type operator[](size_type) const;

      // unary operators [datapar.unary]
      datapar &operator++();
      datapar operator++(int);
      datapar &operator--();
      datapar operator--(int);
      mask_type operator!() const;
      datapar operator~() const;
      datapar operator+() const;
      datapar operator-() const;

      // binary operators [datapar.binary]
      friend datapar operator+ (const datapar &, const datapar &);
      friend datapar operator- (const datapar &, const datapar &);
      friend datapar operator* (const datapar &, const datapar &);
      friend datapar operator/ (const datapar &, const datapar &);
      friend datapar operator% (const datapar &, const datapar &);
      friend datapar operator& (const datapar &, const datapar &);
      friend datapar operator| (const datapar &, const datapar &);
      friend datapar operator^ (const datapar &, const datapar &);
      friend datapar operator<<(const datapar &, const datapar &);
      friend datapar operator>>(const datapar &, const datapar &);

      // compound assignment [datapar.cassign]
      friend datapar &operator+= (datapar &, const datapar &);
      friend datapar &operator-= (datapar &, const datapar &);
      friend datapar &operator*= (datapar &, const datapar &);
      friend datapar &operator/= (datapar &, const datapar &);
      friend datapar &operator%= (datapar &, const datapar &);
      friend datapar &operator&= (datapar &, const datapar &);
      friend datapar &operator|= (datapar &, const datapar &);
      friend datapar &operator^= (datapar &, const datapar &);
      friend datapar &operator<<=(datapar &, const datapar &);
      friend datapar &operator>>=(datapar &, const datapar &);

      // compares [datapar.comparison]
      friend mask_type operator==(const datapar &, const datapar &);
      friend mask_type operator!=(const datapar &, const datapar &);
      friend mask_type operator>=(const datapar &, const datapar &);
      friend mask_type operator<=(const datapar &, const datapar &);
      friend mask_type operator> (const datapar &, const datapar &);
      friend mask_type operator< (const datapar &, const datapar &);
    };
  }
}
