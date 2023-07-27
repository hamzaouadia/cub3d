NAME = cub3D

CC = cc

CFLAGS = -Wall -Wextra -Werror #-fsanitize=address

SRC =	cub3D.c cub3D_helper.c cub3D_helper2.c cub3D_helper3.c render.c\
		./parse/libft/ft_atoi.c ./parse/libft/ft_calloc.c ./parse/libft/ft_itoa.c ./parse/libft/ft_split.c ./parse/libft/ft_strcmp.c ./parse/libft/ft_strdup.c \
		./parse/libft/ft_strjoin.c ./parse/libft/ft_strlen.c ./parse/libft/ft_strncmp.c ./parse/libft/ft_substr.c ./parse/libft/ft_isalpha.c ./parse/libft/ft_isdigit.c ./parse/libft/ft_isalnum.c\
		./parse/gnl/get_next_line.c ./parse/gnl/get_next_line_utils.c \
		./parse/get_map.c \
		./parse/errors.c \
		./parse/content_checks.c \
		./parse/textures_checks.c \
		./execu/exec_utils.c ./execu/exec_utils_helper.c\

RM = rm -f

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME) : $(OBJ)
	$(CC) $(CFLAGS) $^ -Ofast -lmlx -framework OpenGL -framework AppKit -o $@

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all