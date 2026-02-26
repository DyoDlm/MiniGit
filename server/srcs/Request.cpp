#include "Request.hpp"

Request::Request() :
        _user(""), _pwd(""), _content(""), _cmd(""), _option(""), _args(""), _status("")
{
	return ;
}

Request::Request(int ac, char **av) :
	_user(""), _pwd(""), _content(""), _cmd(""), _option(""), _args(""), _status("")
{
	switch (ac) 
	{
		case 7:
			this->_args = av[6];
			// fall through
		case 6:
			this->_option = av[5];
			// fall through
		case 5:
			this->_cmd = av[4];
			// fall through
		case 4:
			this->_content = av[3];
			// fall through
		case 3:
			this->_pwd = av[2];
			// fall through
		case 2:
			this->_user = av[1];
			// fall trough
		default:
			break ;
	}
	std::cout << "Request initialized" << std::endl;
}

Request::Request(const Request &obj)
{
	(void)obj;
	return ;
}

Request::~Request()
{
	return ;
}

std::string	Request::getuser() const {
	return this->_user;
}

std::string	Request::getpwd() const {
	return this->_pwd;
}

std::string	Request::getcontent() const {
	return this->_content;
}

std::string	Request::getcmd() const {
	return this->_cmd;
}

std::string	Request::getoption() const {
	return this->_option;
}

std::string	Request::getargs() const {
	return this->_args;
}

std::string	Request::getstatus() const {
	return this->_status;
}

std::ostream	&operator<<(std::ostream &stream, const Request &obj)
{
	stream <<  "\nUSER    : " << obj.getuser()
		<< "\nPWD     : " << obj.getpwd()
		<< "\nCONTENT : " << obj.getcontent()
		<< "\nCMD     : " << obj.getcmd()
		<< "\nOPTION  : " << obj.getoption()
		<< "\nARGS    : " << obj.getargs()
		<< "\nSTATUS  : " << obj.getstatus();
	return stream;
}
