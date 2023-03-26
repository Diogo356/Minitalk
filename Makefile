LIBFT = 		libft/libft.a
S_NAME =		server
C_NAME =		client

CFLAGS = 		-Wall -Wextra -Werror

S_SRC = 		server.c
S_OBJ =			$(S_SRC:.c=.o)
C_SRC =			client.c
C_OBJ =			$(C_SRC:.c=.o)

PATH_LIBFT =	./libft

all: 	$(S_NAME) $(C_NAME)

$(S_NAME):	$(S_OBJ) $(LIBFT)
	@cc $(CFLAGS) $(S_OBJ) -o $(S_NAME) $(LIBFT)

$(C_NAME):	$(C_OBJ) $(LIBFT)
	@cc $(CFLAGS) $(C_OBJ) -o $(C_NAME) $(LIBFT)

$(C_OBJS): $(C_SRC)
	@cc $(CFLAGS) -c $(C_SRC)

$(LIBFT):
	@make  --no-print-directory -C libft/


clean:
	@make  --no-print-directory -C libft/ clean 
	@rm -rf $(S_OBJ)
	@rm -rf $(C_OBJ)

fclean: clean
	@make  --no-print-directory -C libft/ fclean
	@rm -rf server
	@rm -rf client


re: fclean all

.PHONY: all fclean clean re