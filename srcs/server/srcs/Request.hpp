#ifndef REQUEST_HPP
# define REQUEST_HPP

# include <iostream>
# include <string>
# include <sstream>

class Request:  //      cmd [--option] [args]
        private:
                std::string     _cmd;
                std::string     _option;
                std::string     _args;

        public:
		Request();
		Request(const Request &obj);
		~Request();
		
		Request	&operator=(const Request &obj);

		
std::ostream	&operator<<(std::ostream &stream, const Request &obj);

#endif 
