#ifndef USER_HPP
# define USER_HPP

# include <string>
# include <vector>

class User {
	private:
		std::string	_name;
		std::string	_pwd;
		std::string	_key;
		std::vector	_repos;
	public:
		User();
		User(...);
		User(const User &obj);
		~User();

		std::string	getname() const;
		std::string	getpwd() const;
		std::string	getkey() const;
		std::vector	getrepos() const;
		
		User	&operator=(const User &obj);
};

std::ostream	&operator<<(std::ostream &stream, const User &obj);




#endif
