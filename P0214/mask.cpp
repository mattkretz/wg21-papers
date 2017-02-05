namespace std {
  namespace experimental {
    template <class T, class Abi> class mask {
    public:
      typedef bool value_type;
      typedef implementation_defined reference;
      typedef datapar<T, Abi> datapar_type;
      typedef size_t size_type;
      typedef Abi abi_type;

      static constexpr size_type size();

      mask() = default;

      mask(const mask &) = default;
      mask(mask &&) = default;
      mask &operator=(const mask &) = default;
      mask &operator=(mask &&) = default;

      // broadcast constructor
      explicit mask(value_type);

      // implicit type conversion constructor
      template <class U> mask(const mask<U, datapar_abi::fixed_size<size()>> &);

      // load constructor
      template <class Flags> mask(const value_type *mem, Flags);
      template <class Flags> mask(const value_type *mem, mask k, Flags);

      // loads [mask.load]
      template <class Flags> void memload(const value_type *mem, Flags);
      template <class Flags> void memload(const value_type *mem, mask k, Flags);

      // stores [mask.store]
      template <class Flags> void memstore(value_type *mem, Flags) const;
      template <class Flags> void memstore(value_type *mem, mask k, Flags) const;

      // scalar access:
      reference operator[](size_type);
      value_type operator[](size_type) const;

      // negation:
      mask operator!() const;

      // mask binary operators [mask.binary]
      friend mask operator&&(const mask &, const mask &);
      friend mask operator||(const mask &, const mask &);
      friend mask operator& (const mask &, const mask &);
      friend mask operator| (const mask &, const mask &);
      friend mask operator^ (const mask &, const mask &);

      // mask compound assignment [mask.cassign]
      friend mask &operator&=(mask &, const mask &);
      friend mask &operator|=(mask &, const mask &);
      friend mask &operator^=(mask &, const mask &);

      // mask compares [mask.comparison]
      friend bool operator==(const mask &, const mask &);
      friend bool operator!=(const mask &, const mask &);
    };
  }
}
