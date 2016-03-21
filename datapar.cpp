namespace std {
  namespace experimental {
    template <class T, class Abi = datapar_abi::compatible> class datapar {
    public:
      typedef implementation_defined native_handle_type;
      typedef T value_type;
      typedef implementation_defined register_value_type;
      typedef implementation_defined reference;
      typedef implementation_defined const_reference;
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
      datapar(value_type);

      // implicit type conversion constructor
      template <class U> datapar(datapar<U, Abi>);

      // scalar access:
      reference operator[](size_type);
      const_reference operator[](size_type) const;

      // increment and decrement:
      datapar &operator++();
      datapar operator++(int);
      datapar &operator--();
      datapar operator--(int);

      // unary operators (for integral T)
      mask_type operator!() const;
      datapar operator~() const;

      // unary operators (for any T)
      datapar operator+() const;
      datapar operator-() const;

      // access to the internals for implementation-specific extensions
      native_handle_type &native_handle();
      const native_handle_type &native_handle() const;
    };
  }
}
