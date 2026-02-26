#include "minitalk.h"

static volatile int	g_ack = 0;

static void	validate(int sig)
{
	(void)sig;
	g_ack = 1;
}

static void	send_char(char c, pid_t spid)
{
	int	i;

	i = 0;
	while (i < 8)
	{
		g_ack = 0;
		if ((c >> i) & 1)
		{
			if (kill(spid, SIGUSR2) == -1)
				return (message_c(4), exit(1));
		}
		else
		{
			if (kill(spid, SIGUSR1) == -1)
				return (message_c(4), exit(1));
		}
		while (!g_ack)
			usleep(500);
		i++;
	}
}

static void	send_message(char *m, pid_t spid)
{
	int	i;

	i = 0;
	while (m[i])
		send_char(m[i++], spid);
	send_char('\0', spid);
	message_c(3);
}

int	main(int ac, char **av)
{
	pid_t	spid;
	char	*line;

	line = NULL;
	if (ac != 3)
		return (message_c(1), 0);
	spid = ft_atoi(av[1]);
	if (spid <= 0 || kill(spid, 0) == -1)
		return (message_c(2), 0);
	signal(SIGUSR1, validate);
	if (ft_strncmp(av[2], "sezamme!", 7))
		return (send_message(av[2], spid), EXIT_SUCCESS);
	while (1)
	{
		message_c(6);
		line = get_next_line(0);
		if (line == NULL)
			break ;
		if (ft_strncmp(line, "choucroute au fromage", 21) == 0)
			return (send_message(line, spid), message_c(8), 1);
		send_message(line, spid);
		free(line);
	}
	return (message_c(8), 1);
}
