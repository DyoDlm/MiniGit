#ifndef REQUEST_HPP
# define REQUEST_HPP

# include <iostream>
# include <string>
# include <sstream>
# include <stddef.h>

class Request {//      cmd [--option] [args]
        private:
		std::string	_user;
		std::string	_pwd;
		std::string	_content;

		std::string     _cmd;
                std::string     _option;
                std::string     _args;
		
		std::string	_status;
        public:
		Request();
		Request(int ac, char **av);
		Request(const Request &obj);
		~Request();
		
		std::string	getuser() const;
		std::string	getpwd() const;
		std::string	getcontent() const;
		std::string	getcmd() const;
		std::string	getoption() const;
		std::string	getargs() const;
		std::string	getstatus() const;

		Request	&operator=(const Request &obj);
};
		
std::ostream	&operator<<(std::ostream &stream, const Request &obj);

#endif 
