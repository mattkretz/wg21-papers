class reference  // exposition only
{
public:
    reference() = delete;
    reference(const reference &) = delete;

    operator value_type() const noexcept;

    template <class U> reference operator=(U&& x) &&;

    template <class U> reference operator+=(U&& x) &&;
    template <class U> reference operator-=(U&& x) &&;
    template <class U> reference operator*=(U&& x) &&;
    template <class U> reference operator/=(U&& x) &&;
    template <class U> reference operator%=(U&& x) &&;
    template <class U> reference operator|=(U&& x) &&;
    template <class U> reference operator&=(U&& x) &&;
    template <class U> reference operator^=(U&& x) &&;
    template <class U> reference operator<<=(U&& x) &&;
    template <class U> reference operator>>=(U&& x) &&;

    reference  operator++() &&;
    value_type operator++(int) &&;
    reference  operator--() &&;
    value_type operator--(int) &&;

    friend void swap(reference&& a, reference&& b) noexcept;
    friend void swap(value_type& a, reference&& b) noexcept;
    friend void swap(reference&& a, value_type& b) noexcept;
};
