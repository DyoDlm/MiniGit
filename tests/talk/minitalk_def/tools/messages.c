#include "minitalk.h"

void	message_s(int sig)
{
	if (sig == 1)
		ft_putstr("No ack ??\n");
	if (sig == 2)
		ft_putstr("Waiting for a signal...\n");
	if (sig == 3)
		ft_putstr("\n");
	if (sig == 4)
	{
		ft_putstr("\n");
		ft_putstr("Waiting for a signal...\n");
	}
	if (sig == 5)
		ft_putstr("Kill process activated by client\n");
	if (sig == 8)
		ft_putstr("Bye Bye Bitch\n");
}

void	message_c(int sig)
{
	if (sig == 1)
		ft_putstr("Bad number of arguments\n");
	if (sig == 2)
		ft_putstr("Not a PID\n");
	if (sig == 3)
		ft_putstr("T'as trop raison\n");
	if (sig == 4)
		ft_putstr("Problem sending message\n");
	if (sig == 5)
		ft_putstr("Serveur took to long ?\n");
	if (sig == 6)
	{
		ft_putstr("Enter message to send (or type 'choucroute au");
		ft_putstr(" fromage' to quit): ");
	}
	if (sig == 7)
		ft_putstr("WTF ?\n");
	if (sig == 8)
		ft_putstr("Bye Bye Bitch \n");
}
