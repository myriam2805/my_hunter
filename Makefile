##
## EPITECH PROJECT, 2025
## Makefile
## File description:
## A Makefile to compile our library.
##

NAME = my_hunter

SRC = src/window.c \
	src/menu.c \
	src/game_loop.c \
	src/handle_events.c \
	src/handle_bird.c \
	src/sound.c \
	src/music.c \
	src/score.c \
	utils/my_strcmp.c \
	utils/my_putstr.c \
	main.c

OBJ = $(SRC:.c=.o)
CC = clang
CFLAGS = -I./include -Wall
LIBS = -lcsfml-graphics -lcsfml-system -lcsfml-window -lcsfml-audio


all: $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME) $(LIBS)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
