#ifndef USER_HPP
# define USER_HPP

# include <string>
# include <vector>
# include <Repo.hpp>

class User {
	private:
		std::string		_name;
		std::string		_pwd;
		std::string		_publickey;
		std::string		_privatekey;
		std::vector<Repo>	_repos;
	public:
		User();
		User(...);
		User(const User &obj);
		~User();

		std::string	        getname() const;
		std::string	        getpwd() const;
		std::string	        getkey() const;
		std::vector<Repo>	getrepos() const;
		
		User	&operator=(const User &obj);
};

std::ostream	&operator<<(std::ostream &stream, const User &obj);




#endif
