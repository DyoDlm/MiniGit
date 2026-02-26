#include "minitalk.h"

t_sdata	g_data = {0, 0, 0, 0, {0}, 0};

static void	shoot(int sig)
{
	if (!ft_strncmp(g_data.m_str, "choucroute au fromage", 21))
	{
		message_s(5);
		kill(g_data.cpid, SIGUSR1);
		exit(EXIT_FAILURE);
	}
	g_data.m_str[g_data.mindex] = '\0';
	ft_putstr(g_data.m_str);
	ft_memset(g_data.m_str, 0, BUFFER_SIZE);
	g_data.mindex = 0;
	if (sig == 0)
		message_s(4);
}

static void	print_char(void)
{
	if (g_data.bindex == 8)
	{
		if (g_data.c_char == '\0')
			shoot(0);
		else
		{
			if (g_data.mindex < BUFFER_SIZE - 1)
				g_data.m_str[g_data.mindex++] = g_data.c_char;
			else
				shoot(1);
		}
		g_data.bindex = 0;
		g_data.c_char = 0;
	}
}

static void	full_handler(int sig, siginfo_t *info, void *context)
{
	(void)sig;
	(void)context;
	if (g_data.cpid == 0)
		g_data.cpid = info->si_pid;
	g_data.bindex++;
	print_char();
	if (kill(g_data.cpid, SIGUSR1) == -1)
		return (message_s(1), exit(EXIT_FAILURE));
}

static void	null_handler(int sig, siginfo_t *info, void *context)
{
	(void)sig;
	(void)context;
	if (g_data.cpid == 0)
		g_data.cpid = info->si_pid;
	g_data.c_char |= (1 << g_data.bindex);
	g_data.bindex++;
	print_char();
	if (kill(g_data.cpid, SIGUSR1) == -1)
		return (message_s(1), exit(EXIT_FAILURE));
}

int	main(void)
{
	struct sigaction	sa_full;
	struct sigaction	sa_null;

	sa_full.sa_sigaction = full_handler;
	sa_null.sa_sigaction = null_handler;
	sa_full.sa_flags = SA_SIGINFO;
	sa_null.sa_flags = SA_SIGINFO;
	sigemptyset(&sa_full.sa_mask);
	sigemptyset(&sa_null.sa_mask);
	sigaction(SIGUSR1, &sa_full, NULL);
	sigaction(SIGUSR2, &sa_null, NULL);
	ft_putstr("Look at my PID baby : ");
	ft_putnbr_fd(getpid(), 1);
	ft_putstr("\n\n");
	message_s(2);
	while (1)
	{
		g_data.cpid = 0;
		sa_full.sa_flags = SA_SIGINFO;
		sa_null.sa_flags = SA_SIGINFO;
		sigemptyset(&sa_full.sa_mask);
		sigemptyset(&sa_null.sa_mask);
		pause();
	}
	return (message_s(8), 0);
}
