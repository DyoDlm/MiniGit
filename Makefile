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

INCLUDE_GENERAL = -Iutils
INCLUDE_SERVER = -Iserver/headers $(INCLUDE_GENERAL)
INCLUDE_CLIENT = -Iclient/headers $(INCLUDE_GENERAL)

CC = c++
CFLAGS = -Wall -Werror -Wextra -std=c++98

OBJS_SERVER = $(SRCS_SERVER:.cpp=.o)
OBJS_CLIENT = $(SRCS_CLIENT:.cpp=.o)

all: $(SERVER) $(CLIENT)

$(SERVER): $(OBJS_SERVER) $(TOOLS)
	$(CC) $(CFLAGS) $(OBJS_SERVER) $(TOOLS) -o $(SERVER) $(INCLUDE_SERVER)

$(CLIENT): $(OBJS_CLIENT) $(TOOLS)
	$(CC) $(CFLAGS) $(OBJS_CLIENT) $(TOOLS) -o $(CLIENT) $(INCLUDE_CLIENT)

%.o: %.cpp
	$(CC) $(CFLAGS) $(INCLUDE_SERVER) $(INCLUDE_CLIENT) -c $< -o $@


clean:
	rm -f $(OBJS_SERVER) $(OBJS_CLIENT)

fclean: clean
	rm -f $(SERVER) $(CLIENT)

re: fclean all


