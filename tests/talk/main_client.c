#include "minitalk.h"

static volatile int	ack = 0;

static void	validate(int sig)
{
	(void)sig;
	ack = 1;
}

static void	message(int sig)
{
	if (sig == 1)
		ft_putstr("Bad number of arguments\n");
	if (sig == 2)
		ft_putstr("Not a PID\n");
	if (sig == 3)
		ft_putstr("Message sent !\n");
	if (sig == 4)
		ft_putstr("Problem sending messaged\n");
}

static void	send_char(char c, pid_t spid)
{
	int	i;

	i = 0;
	while (i < 8)
	{
		if ((c >> i) & 1)
		{
			if (kill(spid, SIGUSR2) == -1)
				return (message(4));
		}
		else
			if (kill(spid, SIGUSR1) == -1)
				return (message(4));
		while (!ack)
			usleep(10);
		i++;
	}
}

static void	send_message(char *m, int spid)
{
	int	i;

	i = 0;
	while (m[i])
		send_char(m[i++], spid);
	send_char('\0', spid);
}

int	main(int ac, char **av)
{
	int	spid;
	char	*m;

	if (ac != 3)
		return (message(1), 0);
	m = av[2];
	spid = ft_atoi(av[1]);
	if (spid <= 0 || kill(spid, 0) == -1)
		return (message(2), 1);
	signal(SIGUSR1, validate);
	send_message(m, spid);
	return (message(3), 1);
}
