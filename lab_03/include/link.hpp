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

    size_t getBegin() const;
    size_t getEnd() const;

    void setBegin(size_t begin);
    void setEnd(size_t end);

private:
    size_t begin;
    size_t end;
};

inline std::istream &operator>>(std::istream &is, Link &link)
{
    size_t p1, p2;
    is >> p1 >> p2;
    link.setBegin(p1);
    link.setEnd(p2);

    return is;
}

#endif