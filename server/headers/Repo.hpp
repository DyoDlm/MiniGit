#ifndef REPOSITORY_HPP
# define REPOSITORY_HPP

# include <string>
# include <iostream>
# include <vector>
# include "Branch.hpp"


class Repo {
	private:
		std::vector<Branch>		_branches;
		std::vector<std::string>	_owners;
		bool				_private;
	public:
		Repo();
		Repo(...);
		Repo(const Repo &obj);
		~Repo();

		Repo	&operator=(const Repo &obj);
};

std::ostream	&operator<<(std::ostream &stream, const Repo &obj);

#endif
