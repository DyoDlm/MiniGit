#include "Request.hpp"
#include "Response.hpp"

static short int	exec(Response &obj)
{
	return ;
}

int	main(int ac, char **av)
{
	Request		request(ac, av);
	std::cout << request << std::endl;

	Response	response(request);
	std::cout << response << std::endl;

	if (!exec(response))
		std::cout << "

	return 0;
}
