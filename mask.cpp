namespace std {
  namespace experimental {
    template <typename T, typename Target = implementation_defined> class mask {
    public:
      typedef implementation_defined internal_type;
      typedef bool value_type;
      typedef implementation_defined register_value_type;
      typedef implementation_defined reference;
      typedef implementation_defined const_reference;
      typedef mask<T, Target> mask_type;
      typedef size_t size_type;
      typedef Target target_type;

      template <typename U = T> static constexpr size_t memory_alignment = implementation_defined;

      static constexpr size_type size();

      mask() = default;

      mask(const mask &) = default;
      mask(mask &&) = default;
      mask &operator=(const mask &) = default;
      mask &operator=(mask &&) = default;

      // implicit broadcast constructor
      mask(value_type);

      // implicit type conversion constructor
      template <typename U> mask(mask<U, Target>);

      // loads:
      static mask load(const value_type *);
      template <typename Flags> static mask load(const value_type *, Flags);

      // stores:
      void store(value_type *);
      template <typename Flags> void store(value_type *, Flags);

      // masked stores:
      void store(value_type *, mask);
      template <typename Flags> void store(value_type *, mask, Flags);

      // scalar access:
      reference operator[](size_type);
      const_reference operator[](size_type) const;

      // unary operators (for integral T)
      mask operator!() const;
      mask operator~() const;
    };
  }
}
