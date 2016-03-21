namespace std {
  namespace experimental {
    template <class T, class Abi = datapar_abi::compatible> class mask {
    public:
      typedef implementation_defined native_handle_type;
      typedef bool value_type;
      typedef implementation_defined register_value_type;
      typedef implementation_defined reference;
      typedef implementation_defined const_reference;
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
      template <class U> mask(mask<U, Abi>);

      // scalar access:
      reference operator[](size_type);
      const_reference operator[](size_type) const;

      // negation:
      mask operator!() const;

      // access to the internals for implementation-specific extensions
      native_handle_type &native_handle();
      const native_handle_type &native_handle() const;
    };
  }
}
