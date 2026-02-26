#ifndef REPOSITORY_HPP
# define REPOSITORY_HPP

# include <string>
# include <iostream>

class File {
	private:
		std::string	_content;

	public:
		File();
		~File();
};

std::ostream    &operator<<(std::ostream &stream, const File &obj);



class Dir {
	private:
		std::vector<Dir>	_dirs;
		std::vector<File>	_files;
	public:
		Dir();
		Dir(...);
		Dir(const Dir &obj);
		~Dir();

		Dir	&operator=(const Dir &obj);	
};

std::ostream    &operator<<(std::ostream &stream, const Dir &obj);



class Repo {
	private:
		std::vector<Dir>	_dirs;
		std::vector<File>	_files;
		std::string		_user;
		bool			_private;
	public:
		Repo();
		Repo(...);
		Repo(const Repo &obj);
		~Repo();

		Repo	&operator=(const Repo &obj);
};

std::ostream	&operator<<(std::ostream &stream, const Repo &obj);

#endif
