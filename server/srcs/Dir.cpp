#include "Dir.hpp"

Dir::Dir()
{
    return ;
}

Dir::Dir(std::string name) :
    _name(name)
{
    return ;
}

Dir::Dir(const Dir &obj)
{
    (void)obj;
    return ;
}

Dir::~Dir()
{
    return ;
}

Dir &Dir::operator=(const Dir &obj)
{
    (void)obj;
    return obj;
}

std::ostream    &operator<<(std::ostream &stream, const Dir &obj)
{
    (void)obj;
    return stream;
}
