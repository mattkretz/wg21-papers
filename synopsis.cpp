namespace std {
  namespace experimental {
    namespace target {
      struct scalar {};  // always present
      // implementation-defined tag types
      typedef implementation_defined widest;  // always present
    }

    struct unaligned_tag {};
    struct aligned_tag {};

    template <size_t> struct target_for_width {
      typedef implementation_defined type;
    };
    template <size_t N> using target_for_width_t = typename target_for_width<N>::type;

    template <typename T, typename Target = implementation_defined> class datapar {
    public:
      typedef implementation_defined internal_type;
      typedef T value_type;
      typedef implementation_defined reference;
      typedef implementation_defined const_reference;
      typedef mask<T, Target> mask_type;

      template <typename U = T> static constexpr size_t memory_alignment = implementation_defined;

      static constexpr int size();

      datapar() = default;

      datapar(const datapar &) = default;
      datapar(datapar &&) = default;
      datapar &operator=(const datapar &) = default;
      datapar &operator=(datapar &&) = default;

      // implicit broadcast constructor
      datapar(value_type);

      // implicit type conversion constructor
      template <typename U> datapar(datapar<U, Target>);

      // loads:
      static datapar load(const value_type *);
      template <typename Flags> static datapar load(const value_type *, Flags);
      template <typename U, typename Flags = unaligned_tag> static datapar load(const U *, Flags = Flags());

      // stores:
      void store(value_type *);
      template <typename Flags> void store(value_type *, Flags);
      template <typename U, typename Flags = unaligned_tag> void store(value_type *, Flags = Flags());

      // masked stores:
      void store(value_type *, mask_type);
      template <typename Flags> void store(value_type *, mask_type, Flags);
      template <typename U, typename Flags = unaligned_tag>
      void store(value_type *, mask_type, Flags = Flags());

      // shuffles:
      auto operator[](std::initializer_list<int> shuffle_pattern)
          -> datapar<T, target_for_width_t<shuffle_pattern.size()>> const;

      // scalar access:
      reference operator[](int);
      const_reference operator[](int) const;

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
    };

    template <typename T, typename Target>
    datapar<T, Target> &operator+=(datapar<T, Target> &, const datapar<T, Target> &);
    template <typename T, typename Target>
    datapar<T, Target> &operator-=(datapar<T, Target> &, const datapar<T, Target> &);
    template <typename T, typename Target>
    datapar<T, Target> &operator*=(datapar<T, Target> &, const datapar<T, Target> &);
    template <typename T, typename Target>
    datapar<T, Target> &operator/=(datapar<T, Target> &, const datapar<T, Target> &);
    template <typename T, typename Target>
    datapar<T, Target> &operator%=(datapar<T, Target> &, const datapar<T, Target> &);
    template <typename T, typename Target>
    datapar<T, Target> &operator&=(datapar<T, Target> &, const datapar<T, Target> &);
    template <typename T, typename Target>
    datapar<T, Target> &operator|=(datapar<T, Target> &, const datapar<T, Target> &);
    template <typename T, typename Target>
    datapar<T, Target> &operator^=(datapar<T, Target> &, const datapar<T, Target> &);
    template <typename T, typename Target>
    datapar<T, Target> &operator<<=(datapar<T, Target> &, const datapar<T, Target> &);
    template <typename T, typename Target>
    datapar<T, Target> &operator>>=(datapar<T, Target> &, const datapar<T, Target> &);

    template <typename T, typename Target>
    datapar<T, Target> operator+(const datapar<T, Target> &, const datapar<T, Target> &);
    template <typename T, typename Target>
    datapar<T, Target> operator-(const datapar<T, Target> &, const datapar<T, Target> &);
    template <typename T, typename Target>
    datapar<T, Target> operator*(const datapar<T, Target> &, const datapar<T, Target> &);
    template <typename T, typename Target>
    datapar<T, Target> operator/(const datapar<T, Target> &, const datapar<T, Target> &);
    template <typename T, typename Target>
    datapar<T, Target> operator%(const datapar<T, Target> &, const datapar<T, Target> &);
    template <typename T, typename Target>
    datapar<T, Target> operator&(const datapar<T, Target> &, const datapar<T, Target> &);
    template <typename T, typename Target>
    datapar<T, Target> operator|(const datapar<T, Target> &, const datapar<T, Target> &);
    template <typename T, typename Target>
    datapar<T, Target> operator^(const datapar<T, Target> &, const datapar<T, Target> &);
    template <typename T, typename Target>
    datapar<T, Target> operator<<(const datapar<T, Target> &, const datapar<T, Target> &);
    template <typename T, typename Target>
    datapar<T, Target> operator>>(const datapar<T, Target> &, const datapar<T, Target> &);

    template <typename T, typename Target>
    mask<T, Target> operator==(const datapar<T, Target> &, const datapar<T, Target> &);
    template <typename T, typename Target>
    mask<T, Target> operator!=(const datapar<T, Target> &, const datapar<T, Target> &);
    template <typename T, typename Target>
    mask<T, Target> operator>=(const datapar<T, Target> &, const datapar<T, Target> &);
    template <typename T, typename Target>
    mask<T, Target> operator<=(const datapar<T, Target> &, const datapar<T, Target> &);
    template <typename T, typename Target>
    mask<T, Target> operator>(const datapar<T, Target> &, const datapar<T, Target> &);
    template <typename T, typename Target>
    mask<T, Target> operator<(const datapar<T, Target> &, const datapar<T, Target> &);

    template <typename T, typename Target>
    template <typename U>
    constexpr size_t datapar<T, Target>::memory_alignment<U>;

    template <typename T, typename U, typename Target> T datapar_cast(datapar<U, Target>);
  }
}
