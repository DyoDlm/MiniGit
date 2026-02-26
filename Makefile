SERVER = run_server
CLIENT = run_client

$DS = server/srcs
$DC = client/srcs

SRCS_SERVER = server/main_server.cpp \
	      $(DS)/Request.cpp \
	      $(DS)/Response.cpp \
	      $(DS)/ \
	      $(DS)/ \
	      $(DS)/

SRCS_CLIENT = client/main_client.c \
	      $(DC)/HttpRequest.cpp \
	      $(DC)/ \
	      $(DC)/ \
	      $(DC)/ \
	      $(DC)/

TOOLS = ./utils/Colors.cpp \
	./utils/Error.cpp \
	./utils/Debug.cpp \
	./utils/utils.cpp

INCLUDE_DIRS = utils \
	       server/headers \
	       client/headers

CC = c++
CFLAGS = -Wall -Werror -Wextra -I $(INCLUDE_DIRS)

OBJS_SERVER = $(SRCS_SERVER:.cpp=.o)
OBJS_CLIENT = $(SRCS_CLIENT:.cpp=.o)

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


