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

      // implicit broadcast constructor
      mask(value_type);

      // implicit type conversion constructor
      template <class U, class Abi2> mask(mask<U, Abi2>);

      // load constructor
      template <class Flags> mask(const value_type *mem, Flags);
      template <class Flags> mask(const value_type *mem, mask k, Flags);

      // loads [mask.load]
      template <class Flags> void copy_from(const value_type *mem, Flags);
      template <class Flags> void copy_from(const value_type *mem, mask k, Flags);

      // stores [mask.store]
      template <class Flags> void copy_to(value_type *mem, Flags) const;
      template <class Flags> void copy_to(value_type *mem, mask k, Flags) const;

      // scalar access:
      reference operator[](size_type);
      value_type operator[](size_type) const;

      // negation:
      mask operator!() const;
    };
  }
}
