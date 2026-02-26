#ifndef MINITALK_H
# define MINITALK_H

# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>
# include <signal.h>
# include <sys/types.h>

# define BUFFER_SIZE 1024 

typedef struct s_sdata
{
	int		bindex;
	int		cindex;
	int		mindex;
	char	c_char;
	char	m_str[BUFFER_SIZE];
	pid_t	cpid;
}	t_sdata;

void	ft_putstr(char *s);
int		ft_atoi(const char *str);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
void	ft_putnbr_fd(int nb, int fd);
void	*ft_memset(void *s, int c, size_t n);
void	message_s(int sig);
void	message_c(int sig);
//void    shoot(int sig);
//void    print_char(void);
//void    full_handler(int sig, siginfo_t *info, void *context);
//void    null_handler(int sig, siginfo_t *info, void *context);

//	FOR GNL
void	free_data(char **s);
char	*get_next_line(int fd);
size_t	ft_strlen(const char *s);
char	*ft_strchr(const char *s, int c);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
size_t	ft_strlcat(char *dst, const char *src, size_t size);
char	*ft_strjoin(char *s1, const char *s2);

#endif
