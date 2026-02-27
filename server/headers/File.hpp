#ifndef FILE_HPP
# define FILE_HPP

# include <string>
# include <iostream>

class File {
	private:
		std::string	_name;
		std::string	_content;
		size_t		_length;
	public:
		File();
		File(std::string name);
		File(const File &obj);
		~File();

		File	&operator=(const File &obj);
};

std::ostream    &operator<<(std::ostream &stream, const File &obj);


#endif
