#ifndef DIR_HPP
# define DIR_HPP

# include <iostream>
# include <string>
# include "File.hpp"

class Dir {
        private:
                std::vector<Dir>        _dirs;
                std::vector<File>       _files;
        public:
                Dir();
                Dir(std::string name);
                Dir(const Dir &obj);
                ~Dir();

                Dir     &operator=(const Dir &obj);
};

std::ostream    &operator<<(std::ostream &stream, const Dir &obj);


#endif
