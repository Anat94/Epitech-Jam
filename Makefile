##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Makefile
##

NAME	=	my_binary

SRC		=	main.c \
			bdd.c
			#call_API.c

OBJ		=	$(SRC:.c=.o)

CWARNS	=	-Wall -Wextra

CPPFLAGS = -iquote./include/

CFLAGS = -lcsfml-system -lcsfml-window -lcsfml-graphics -lcsfml-audio -lcurl

$(NAME): $(OBJ)
	gcc $(OBJ) -o $(NAME) $(CFLAGS) $(CWARNS) $(CPPFLAGS) $(CSFMLFLASGS) -g

debug:
	gcc $(OBJ) -o $(NAME) $(CFLAGS) $(CWARNS) $(CPPFLAGS) $(CSFMLFLASGS) -g3


all: $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re debug