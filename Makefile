NAME = cub3D

CC = cc

CFLAGS = -Wall -Wextra -Werror #-fsanitize=address

SRC =	./mandatory/cub3D.c ./mandatory/cub3D_helper.c ./mandatory/cub3D_helper2.c ./mandatory/cub3D_helper3.c ./mandatory/render_helper.c \
		./mandatory/parse/libft/ft_atoi.c ./mandatory/parse/libft/ft_calloc.c ./mandatory/parse/libft/ft_itoa.c ./mandatory/parse/libft/ft_split.c ./mandatory/parse/libft/ft_strcmp.c ./mandatory/parse/libft/ft_strdup.c \
		./mandatory/parse/libft/ft_strjoin.c ./mandatory/parse/libft/ft_strlen.c ./mandatory/parse/libft/ft_strncmp.c ./mandatory/parse/libft/ft_substr.c ./mandatory/parse/libft/ft_isalpha.c ./mandatory/parse/libft/ft_isdigit.c ./mandatory/parse/libft/ft_isalnum.c\
		./mandatory/parse/gnl/get_next_line.c ./mandatory/parse/gnl/get_next_line_utils.c \
		./mandatory/parse/get_map.c \
		./mandatory/parse/errors.c \
		./mandatory/parse/content_checks.c \
		./mandatory/parse/textures_checks.c ./mandatory/parse/textures_checks_helper.c\
		./mandatory/exec_utils.c ./mandatory/exec_utils_helper.c\

SRCB =	./bonus/cub3D_bonus.c ./bonus/cub3D_helper_bonus.c ./bonus/cub3D_helper2_bonus.c ./bonus/cub3D_helper3_bonus.c ./bonus/render_bonus.c ./bonus/render_helper_bonus.c ./bonus/gun_textures_bonus.c\
		./bonus/parse_bonus/libft/ft_atoi.c ./bonus/parse_bonus/libft/ft_calloc.c ./bonus/parse_bonus/libft/ft_itoa.c ./bonus/parse_bonus/libft/ft_split.c ./bonus/parse_bonus/libft/ft_strcmp.c ./bonus/parse_bonus/libft/ft_strdup.c \
		./bonus/parse_bonus/libft/ft_strjoin.c ./bonus/parse_bonus/libft/ft_strlen.c ./bonus/parse_bonus/libft/ft_strncmp.c ./bonus/parse_bonus/libft/ft_substr.c ./bonus/parse_bonus/libft/ft_isalpha.c ./bonus/parse_bonus/libft/ft_isdigit.c ./bonus/parse_bonus/libft/ft_isalnum.c\
		./bonus/parse_bonus/gnl/get_next_line.c ./bonus/parse_bonus/gnl/get_next_line_utils.c \
		./bonus/parse_bonus/get_map.c \
		./bonus/parse_bonus/errors.c \
		./bonus/parse_bonus/content_checks.c \
		./bonus/parse_bonus/textures_checks.c ./bonus/parse_bonus/textures_checks_helper.c\
		./bonus/exec_utils_bonus.c ./bonus/exec_utils_helper_bonus.c\

RM = rm -f

OBJ = $(SRC:.c=.o)

OBJB = $(SRCB:.c=.o)

all: $(NAME)

$(NAME) : $(OBJ)
	$(CC) $(CFLAGS) $^ -lmlx -framework OpenGL -framework AppKit -o $@

bonus : $(OBJB)
	$(CC) $(CFLAGS) $^ -lmlx -framework OpenGL -framework AppKit -o $(NAME)

clean:
	$(RM) $(OBJ) $(OBJB)

fclean: clean
	$(RM) $(NAME)

re: fclean all