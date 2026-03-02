#include "Branch.hpp"

Branch::Branch() :
    _user(""), _id(0), _head(false), _main(false)
{
    return ;
}

Branch::Branch(std::string user, int from_branch_id)
{
    //  find user in db
    //  
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

