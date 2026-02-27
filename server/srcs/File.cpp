#include "File.hpp"

File::File()
{
    return ;
}

File::File(std::string name)
{
    return ;
}

File::File(const File &obj)
{
    (void)obj;
    return ;
}

File::~File()
{
    return ;
}

File   &File::operator=(const File &obj)
{
    (void)obj;
    return File;
}

std::ostream    &operator<<(std::ostream &stream, const File &obj)
{
    (void)obj;
    return stream;
}
