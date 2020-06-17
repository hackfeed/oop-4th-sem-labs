#pragma once

template <class T1, class T2>
class pair
{
public:
    explicit pair();
    explicit pair(const T1 &, const T2 &);
    ~pair() = default;

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
pair<T1, T2>::pair() : first(T1()), second(T2())
{
}

template <class T1, class T2>
pair<T1, T2>::pair(const T1 &first, const T2 &second) : first(first), second(second)
{
}

template <class T1, class T2>
T1 &pair<T1, T2>::get_first()
{
    return this->first;
}

template <class T1, class T2>
const T1 &pair<T1, T2>::get_first() const
{
    return this->first;
}

template <class T1, class T2>
T2 &pair<T1, T2>::get_second()
{
    return this->second;
}

template <class T1, class T2>
const T2 &pair<T1, T2>::get_second() const
{
    return this->second;
}

template <class T1, class T2>
void pair<T1, T2>::set_first(const T1 &first)
{
    this->first = first;
}

template <class T1, class T2>
void pair<T1, T2>::set_second(const T2 &second)
{
    this->second = second;
}

template <class T1, class T2>
void pair<T1, T2>::set_both(const T1 &first, const T2 &second)
{
    this->first = first;
    this->second = second;
}
