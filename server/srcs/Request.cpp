#include "Request.hpp"

Request::Request() :
        _cmd(""), _option(""), _args(""), _status("")
{
	return ;
}

Request::Request(int ac, char **av) :
	_cmd(""), _option(""), _args(""), _status("")
{
	switch (ac) 
	{
		case 3:
			this->_cmd = av[1];
			// fall through
		case 2:
			this->_option = av[2];
			// fall through
		case 1:
			this->_args = av[3];
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
	stream <<  "\nCMD    : " << obj.getcmd()
		<< "\nOPTION : " << obj.getoption()
		<< "\nARGS   : " << obj.getargs()
		<< "\nSTATUS : " << obj.getstatus();
	return stream;
}
