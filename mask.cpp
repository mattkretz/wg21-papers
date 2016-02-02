namespace std {
  namespace experimental {
    template <class T, class Target = datapar_target::compatible> class mask {
    public:
      typedef implementation_defined internal_type;
      typedef bool value_type;
      typedef implementation_defined register_value_type;
      typedef implementation_defined reference;
      typedef implementation_defined const_reference;
      typedef mask<T, Target> mask_type;
      typedef size_t size_type;
      typedef Target target_type;

      template <class U = T> static constexpr size_t memory_alignment = implementation_defined;

      static constexpr size_type size();

      mask() = default;

      mask(const mask &) = default;
      mask(mask &&) = default;
      mask &operator=(const mask &) = default;
      mask &operator=(mask &&) = default;

      // implicit broadcast constructor
      mask(value_type);

      // implicit type conversion constructor
      template <class U> mask(mask<U, Target>);

      // loads:
      static mask load(const value_type *);
      template <class Flags> static mask load(const value_type *, Flags);

      // stores:
      void store(value_type *);
      template <class Flags> void store(value_type *, Flags);

      // masked stores:
      void store(value_type *, mask);
      template <class Flags> void store(value_type *, mask, Flags);

      // scalar access:
      reference operator[](size_type);
      const_reference operator[](size_type) const;

      // unary operators (for integral T)
      mask operator!() const;
      mask operator~() const;
    };

    template <class T, class Target>
    template <class U>
    constexpr size_t mask<T, Target>::memory_alignment<U>;
  }
}
