#include "User.hpp"

User::User() {
}

User::User(...) {
}

User::User(const User &obj) {
    (void)obj;
}

User::~User() { }

std::string         User::getname()     const   { return this->_name; }
std::string         User::getkey()      const   { return this->_key; }
std::string         User::getpwd()      const   { return this->pwd;  }
std::vector<Repo>   User::getrepos()    const   { return this->_repos; }



User    &User::operator=(const User &obj)
{
    (void)obj;
    return *this;
}

std::ostream    &operator<<(std::ostream &stream, const User &obj)
{
    (void)obj;
    return stream;
}
