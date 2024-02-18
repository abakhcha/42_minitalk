# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abakhcha <abakhcha@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/17 16:03:08 by abakhcha          #+#    #+#              #
#    Updated: 2024/02/18 14:42:55 by abakhcha         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAGS = -Wall -Werror -Wextra

CC = gcc

CLIENT = client
SERVER = server

CLIENT_BONUS = client_bonus
SERVER_BONUS = server_bonus

all: $(CLIENT) $(SERVER)

$(CLIENT) : client.c
		$(CC) $(CFLAGS) client.c utils.c ft_printf/libftprintf.a -o client
$(SERVER) : server.c
		$(CC) $(CFLAGS) server.c utils.c ft_printf/libftprintf.a -o server

bonus: $(CLIENT_BONUS) $(SERVER_BONUS)

$(CLIENT_BONUS) : client_bonus.c
		$(CC) $(CFLAGS) client_bonus.c utils.c ft_printf/libftprintf.a -o client_bonus
$(SERVER_BONUS) : server_bonus.c
		$(CC) $(CFLAGS) server_bonus.c utils.c ft_printf/libftprintf.a -o server_bonus
fclean:
	rm -rf $(CLIENT) $(SERVER) $(CLIENT_BONUS) $(SERVER_BONUS)

re: fclean all bonus

.PHONY: all clean fclean re