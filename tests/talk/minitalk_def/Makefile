SERVER = server
CLIENT = client

SRCS_SERVER = main_server.c
SRCS_CLIENT = main_client.c

TOOLS = ./tools/ft_atoi.c \
	./tools/ft_putstr.c \
	./tools/get_next_line.c \
	./tools/get_next_line_utils.c \
	./tools/ft_strncmp.c \
	./tools/ft_putnbr_fd.c \
	./tools/ft_memset.c \
	./tools/messages.c 

CC = cc
CFLAGS = -Wall -Werror -Wextra $(INCLUDE_DIRS)

OBJS_SERVER = $(SRCS_SERVER:.c=.o)
OBJS_CLIENT = $(SRCS_CLIENT:.c=.o)

all: $(SERVER) $(CLIENT)

$(SERVER): $(OBJS_SERVER)
	$(CC) $(CFLAGS) $(OBJS_SERVER) $(TOOLS) -o $(SERVER)

$(CLIENT): $(OBJS_CLIENT)
	$(CC) $(CFLAGS) $(OBJS_CLIENT) $(TOOLS) -o $(CLIENT)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS_SERVER) $(OBJS_CLIENT)

fclean: clean
	rm -f $(SERVER) $(CLIENT)

re: fclean all

