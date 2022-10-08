SRC_SERVER = server.c 
SRC_CLIENT = client.c ft_atoi.c ft_putstr.c

NAME_SERVER = server
NAME_CLIENT = client

NAME_SERVER_BONUS = server_bonus
NAME_CLIENT_BONUS = client_bonus

OBJ_SRV = server.o
OBJ_CLIENT = client.o ft_atoi.o ft_putstr.o

OBJ_SRV_BONUS = server_bonus.o
OBJ_CLIENT_BONUS = client_bonus.o ft_atoi.o ft_putstr.o
CC = cc
CFLAGS = -Wall -Werror -Wextra -I.

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME_CLIENT) $(NAME_SERVER)

$(NAME_SERVER): $(OBJ_SRV)
	$(CC) $(CFLAGS) -o $@ $(OBJ_SRV)

$(NAME_CLIENT): $(OBJ_CLIENT)
	$(CC) $(CFLAGS) -o $@ $(OBJ_CLIENT)

$(NAME_SERVER_BONUS): $(OBJ_SRV_BONUS)
	$(CC) $(CFLAGS) -o $@ $(OBJ_SRV_BONUS)

$(NAME_CLIENT_BONUS): $(OBJ_CLIENT_BONUS)
	$(CC) $(CFLAGS) -o $@ $(OBJ_CLIENT_BONUS)

bonus: $(NAME_SERVER_BONUS) $(NAME_CLIENT_BONUS)

clean:
	rm -f $(OBJ_CLIENT) $(OBJ_SRV)

fclean:	clean
	rm -f $(OBJ_CLIENT) $(OBJ_SRV) $(NAME_SERVER) $(NAME_CLIENT) $(OBJ_SRV_BONUS) $(OBJ_CLIENT_BONUS) $(NAME_SERVER_BONUS) $(NAME_CLIENT_BONUS)

re: fclean all

.PHONY: all re fclean clean 