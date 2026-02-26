#ifndef RESPONSE_HPP
# define RESPONSE_HPP

# include <iostream>
# include <string>
# include <sstream>

class Responde:  //      cmd [--option] [args]
        private:
                std::string     _cmd;
                std::string     _option;
                std::string     _args;

        public:
		Response();
		Response(const Response &obj);
		~Response();
		
		Response	&operator=(const Response &obj);

		
std::ostream	&operator<<(std::ostream &stream, const Response &obj);

#endif 
