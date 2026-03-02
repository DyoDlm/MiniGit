#ifndef BRANCH_HPP
# define BRANCH_HPP

# include <iostream>
# include <string>
# include "Dir.hpp"
# include "File.hpp"

class Branch {
    private:
	        std::vector<Branch> _branches;
            std::vector<Dir>    _dirs;
            std::vector<File>   _files;
            std::string         _user;
        	int			        _id;
		    bool			    _head;
		    bool			    _main;
	public:
            Branch();
            Branch(...);
            Branch(const Branch &obj);
            ~Branch();

            Branch    &operator=(const Branch &obj);
};

std::ostream    &operator<<(std::ostream &stream, const Branch &obj);


#endif
