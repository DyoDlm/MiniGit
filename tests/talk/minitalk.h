#ifndef MINITALK_H
# define MINITAL_H

# include <unistd.h>
# include <signal.h>
# include <sys/types.h>

# define BS 1024 

typedef struct	s_sdata
{
	int		bindex;
	int		cindex;
	char	c_char;
	pid_t	cpid;
}	t_sdata;

void	ft_putstr(char *s);
int	ft_atoi(const char *str);

#endif
