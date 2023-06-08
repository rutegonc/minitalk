# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rugoncal <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/03 21:10:57 by rugoncal          #+#    #+#              #
#    Updated: 2023/04/03 21:11:06 by rugoncal         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SERVER = server.c
CLIENT = client.c
SERVER_BONUS = server_bonus.c
CLIENT_BONUS = client_bonus.c
HELPERS = helpers.c

SERVEROBJ = $(SERVER:.c=.o)
CLIENTOBJ = $(CLIENT:.c=.o)
SERVEROBJ_BONUS = $(SERVER_BONUS:.c=.o)
CLIENTOBJ_BONUS = $(CLIENT_BONUS:.c=.o)
HELPERSOBJ = $(HELPERS:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror

all: server client

server: $(SERVEROBJ) $(HELPERSOBJ)
	$(CC) $(SERVEROBJ) $(HELPERSOBJ) -o server 
	
client: $(CLIENTOBJ) $(HELPERSOBJ)
	$(CC) $(CLIENTOBJ) $(HELPERSOBJ) -o client

bonus: $(CLIENTOBJ_BONUS) $(SERVEROBJ_BONUS) $(HELPERSOBJ)
	$(CC) $(CLIENTOBJ_BONUS) $(HELPERSOBJ) -o client
	$(CC) $(SERVEROBJ_BONUS) $(HELPERSOBJ) -o server 

clean: 
	rm -rf $(SERVEROBJ) $(CLIENTOBJ) $(SERVEROBJ_BONUS) $(CLIENTOBJ_BONUS) $(HELPERSOBJ)

fclean: clean
	rm -rf server client

re: fclean all
