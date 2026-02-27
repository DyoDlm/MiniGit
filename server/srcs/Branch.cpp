#include "Branch.hpp"

Branch::Branch()
{
    return ;
}

Branch::Branch(...)
{
    return ;
}

Branch::Branch(const Branch &obj)
{
    (void)obj;
    return ;
}

Branch::~Branch()
{
    return ;
}

Branch  &Branch::operator=(const Branch &obj)
{
    (void)obj;
    return obj;
}

std::ostream    &operator<<(std::ostream &stream, const Branch &obj)
{
    (void)obj;
    return stream;
}

