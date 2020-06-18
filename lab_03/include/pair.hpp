#ifndef PAIR_HPP
#define PAIR_HPP

template <class T1, class T2>
class Pair
{
public:
    explicit Pair();
    explicit Pair(const T1 &, const T2 &);
    ~Pair() = default;

    T1 &get_first();
    const T1 &get_first() const;
    T2 &get_second();
    const T2 &get_second() const;

    void set_first(const T1 &);
    void set_second(const T2 &);
    void set_both(const T1 &, const T2 &);

private:
    T1 first;
    T2 second;
};

template <class T1, class T2>
Pair<T1, T2>::Pair() : first(T1()), second(T2())
{
}

template <class T1, class T2>
Pair<T1, T2>::Pair(const T1 &first, const T2 &second) : first(first), second(second)
{
}

template <class T1, class T2>
T1 &Pair<T1, T2>::get_first()
{
    return this->first;
}

template <class T1, class T2>
const T1 &Pair<T1, T2>::get_first() const
{
    return this->first;
}

template <class T1, class T2>
T2 &Pair<T1, T2>::get_second()
{
    return this->second;
}

template <class T1, class T2>
const T2 &Pair<T1, T2>::get_second() const
{
    return this->second;
}

template <class T1, class T2>
void Pair<T1, T2>::set_first(const T1 &first)
{
    this->first = first;
}

template <class T1, class T2>
void Pair<T1, T2>::set_second(const T2 &second)
{
    this->second = second;
}

template <class T1, class T2>
void Pair<T1, T2>::set_both(const T1 &first, const T2 &second)
{
    this->first = first;
    this->second = second;
}

#endif