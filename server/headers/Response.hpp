#ifndef RESPONSE_HPP
# define RESPONSE_HPP

# include <iostream>
# include <string>
# include <sstream>
# include "Request.hpp"

class Response {
        private:
		std::string	_status;
        public:
		Response();
		Response(const Request &obj);
		Response(const Response &obj);
		~Response();
		
		std::string	getstatus() const;
		
		Response	&operator=(const Response &obj);
};
		
std::ostream	&operator<<(std::ostream &stream, const Response &obj);

#endif 
