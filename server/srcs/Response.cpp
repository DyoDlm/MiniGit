#include "Response.hpp"

Response::Response() :
	_status("")
{
	return ;
}

Response::Response(const Request &obj) :
	_status("")
{
	(void)obj;
}

Response::Response(const Response &obj)
{
	(void)obj;
	return ;
}

Response::~Response()
{
	return ;
}

std::string	Response::getstatus() const {
	return this->_status;
}

std::ostream	&operator<<(std::ostream &stream, const Response &obj)
{
	stream << "\nSTATUS : " << obj.getstatus();
	return stream;
}
