#include "minitalk.h"
#include <stdio.h>

t_sdata	data;

static void	message(int n)
{
	if (n == 1)
		ft_putstr("Signal received\n");
	if (n == 2)
		ft_putstr("Exiting de program\n");
	if (n == 3)
		ft_putstr("Signal received\n");
	if (n == 4)
		ft_putstr("Signal received\n");
}

static void	print_char(void)
{
	if (data.bindex == 8)
	{
		if (data.c_char == '\0')
			write(1, "\n", 1);
		else
			write(1, &data.c_char, 1);
		data.bindex = 0;
		data.c_char = 0;
		kill(data.cpid, SIGUSR1);
	}
}

static void	full_handler(int sfull)
{
	(void)sfull;
	data.bindex++;
	print_char();
}

static void	null_handler(int snull)
{
	(void)snull;
	data.c_char |= (1 << data.bindex);
	data.bindex++;
	print_char();
}

int	main()
{
	ft_putstr("Look at my PID baby : ");
	printf("%d\n", getpid());
	signal(SIGUSR1, full_handler);
	signal(SIGUSR2, null_handler);
	while (1)
		pause();
	return (message(2), 0);
}
