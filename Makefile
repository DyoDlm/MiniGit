SERVER = run_server
CLIENT = run_client

DS = server/srcs
DC = client/srcs

SRCS_SERVER = server/main_server.cpp \
              $(DS)/Request.cpp \
              $(DS)/Response.cpp

SRCS_CLIENT = client/main_client.cpp \
              $(DC)/HttpRequest.cpp

TOOLS = ./utils/Colors.cpp \
        ./utils/Error.cpp \
        ./utils/Debug.cpp \
        ./utils/utils.cpp

INCLUDE_GENERAL = -Iutils
INCLUDE_SERVER = -Iserver/headers
INCLUDE_CLIENT = -Iclient/headers

CC = c++
CFLAGS = -Wall -Werror -Wextra -std=c++98

OBJS_DIR_CLIENT = objs/client
OBJS_DIR_SERVER = objs/server
OBJS_DIR_GENERAL = objs/general

# Génération des chemins complets pour les fichiers objets
OBJS_GENERAL = $(addprefix $(OBJS_DIR_GENERAL)/, $(notdir $(TOOLS:.cpp=.o)))
OBJS_SERVER = $(addprefix $(OBJS_DIR_SERVER)/, $(notdir $(SRCS_SERVER:.cpp=.o)))
OBJS_CLIENT = $(addprefix $(OBJS_DIR_CLIENT)/, $(notdir $(SRCS_CLIENT:.cpp=.o)))

# Création des dossiers si nécessaire
$(shell mkdir -p $(OBJS_DIR_CLIENT) $(OBJS_DIR_SERVER) $(OBJS_DIR_GENERAL))

all: $(SERVER) $(CLIENT)

$(SERVER): $(OBJS_SERVER) $(OBJS_GENERAL)
	$(CC) $(CFLAGS) $^ -o $@ $(INCLUDE_SERVER) $(INCLUDE_GENERAL)

$(CLIENT): $(OBJS_CLIENT) $(OBJS_GENERAL)
	$(CC) $(CFLAGS) $^ -o $@ $(INCLUDE_CLIENT) $(INCLUDE_GENERAL)

# Règles pour générer les fichiers objets dans les bons dossiers
$(OBJS_DIR_SERVER)/%.o: server/%.cpp
	$(CC) $(CFLAGS) $(INCLUDE_SERVER) $(INCLUDE_GENERAL) -c $< -o $@

$(OBJS_DIR_SERVER)/%.o: $(DS)/%.cpp
	$(CC) $(CFLAGS) $(INCLUDE_SERVER) $(INCLUDE_GENERAL) -c $< -o $@

$(OBJS_DIR_CLIENT)/%.o: client/%.cpp
	$(CC) $(CFLAGS) $(INCLUDE_CLIENT) $(INCLUDE_GENERAL) -c $< -o $@

$(OBJS_DIR_CLIENT)/%.o: $(DC)/%.cpp
	$(CC) $(CFLAGS) $(INCLUDE_CLIENT) $(INCLUDE_GENERAL) -c $< -o $@

$(OBJS_DIR_GENERAL)/%.o: utils/%.cpp
	$(CC) $(CFLAGS) $(INCLUDE_GENERAL) -c $< -o $@

clean:
	rm -rf $(OBJS_DIR_CLIENT) $(OBJS_DIR_SERVER) $(OBJS_DIR_GENERAL)
	rmdir objs
fclean: clean
	rm -f $(SERVER) $(CLIENT)

re: fclean all

