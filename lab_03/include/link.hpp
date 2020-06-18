#ifndef LINK_HPP
#define LINK_HPP

#include <istream>

class Link
{
public:
    Link();
    Link(const size_t begin, const size_t end);
    explicit Link(const Link &link);

    ~Link();

    Link &operator=(const Link &link);

    size_t GetBegin() const;
    size_t GetEnd() const;

    void SetBegin(size_t begin);
    void SetEnd(size_t end);

private:
    size_t begin;
    size_t end;
};

inline std::istream &operator>>(std::istream &is, Link &link)
{
    size_t p1, p2;
    is >> p1 >> p2;
    link.SetBegin(p1);
    link.SetEnd(p2);

    return is;
}

#endif