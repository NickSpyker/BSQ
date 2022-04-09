##
## EPITECH PROJECT, 2021
## B-CPE-110-MPL-1-1-BSQ-nicolas.spijkerman
## File description:
## Makefile
##

CC			= 	gcc

CFLAGS		= 	-g3 -W -Wall -Werror -Wextra -c -Iinclude/

SRC 		=	main.c \
				bsq.c \
				verif.c \
				verif_forma.c \
				print_map.c \
				lib/my/my_getnbr.c \
				lib/my/mem_alloc_2d_array.c \
				lib/my/mem_dup_2d_array.c \
				lib/my/my_put_nbr.c \
				lib/my/my_putchar.c \
				lib/my/my_putstr.c \
				lib/my/my_strlen.c \
				lib/my/my_swap.c \

OBJ 		= 	main.o \
				bsq.o \
				verif.o \
				verif_forma.o \
				print_map.o \
				lib/my/mem_alloc_2d_array.o \
				lib/my/mem_dup_2d_array.o \
				lib/my/my_getnbr.o \
				lib/my/my_put_nbr.o \
				lib/my/my_putchar.o \
				lib/my/my_putstr.o \
				lib/my/my_strlen.o \
				lib/my/my_swap.o \

TARGET		= 	bsq \

all: $(TARGET)

$(TARGET): $(OBJ)
	@make -C lib/
	@$(CC) -o $(TARGET) $(OBJ) -Llib/
	@echo "Build OK"

clean :
	@make clean -C lib/
	@rm -rf $(OBJ)
	@echo "Clean OK"

fclean : clean
	@make fclean -C lib/
	@rm -rf $(TARGET)
	@echo "Fclean OK"

re : fclean all
