/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smounafi <smounafi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 15:22:29 by smounafi          #+#    #+#             */
/*   Updated: 2023/06/22 18:47:03 by smounafi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# include "./parse/gnl/get_next_line.h"
# include "./parse/libft/libft.h"
# include <fcntl.h>
# include <math.h>
# include <mlx.h>

/* -------- MAP -------- */

# define BUFF_SIZE 256
# define PI 3.14159265359
# define WALL '1'
# define EMPTY '0'

# define FLOOR "F "
# define CEILLING "C "

# define NORTH_TEXTURE "NO "
# define SOUTH_TEXTURE "SO "
# define EAST_TEXTURE "EA "
# define WEST_TEXTURE "WE "

/* ------- COLORS ------*/

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct window
{
	void		*mlx;
	void		*win;
	int			h;
    int         h_half;
	int			w;
	int			x;
	int			y;
	int			dim_x;
	int			dim_y;
    int         block_size;
    t_data      img;
}				t_window;

typedef struct t_utils
{
	int no;
	int so;
	int we;
	int ea;
	int cc;
	int ff;
	int flag;
}       s_utils;

typedef struct map
{
    int        direc;
    double     move_step;
    double     player_x;
    double     player_y;
    double     up_x;
    double     up_y;
    double     player_ang;
    double     ang_direc;
    double     x_direc;
    double     y_direc;
	char	*no;
	char	*so;
	char	*we;
	char	*ea;
	int		f;
	int		c;
	char	**map;
	char	**real_map;
	s_utils utils;
	struct window *g;
}			s_map;

/* ----------------------------------------------------------------- PARSING -----------------------------------------------------------------*/


/* ~~~~~~~~~~~~~~~~~~~~~~~ TEXTURES ~~~~~~~~~~~~~~~~~~~~~~~*/

int		char_pos(char *str, char c);
char	*path_extracter(char *str);
void	north_south_textures(char *str, s_map *map);
void	east_west_textures(char *str, s_map *map);
void	east_west_textures(char *str, s_map *map);
void	floor_ceiling_textures(char *str, s_map *map);


/* ~~~~~~~~~~~~~~~~~~~~~~~ CONTENT ~~~~~~~~~~~~~~~~~~~~~~~*/

void	check_map_content(char *str);
void	check_map_walls(char **str);
void	check_map_textures(s_map *map);
size_t	zero_index(char *str);
int			is_a_space(char c);
void	check_map_content_help(char **str);


/* ~~~~~~~~~~~~~~~~~~~~~~~~~ MAP ~~~~~~~~~~~~~~~~~~~~~~~~~*/

char		*get_map(char *arg, int fd);
void		errors(int i);
void		errors_help(int i);
char		*setup_map(char *str, s_map *map);





/* ---------------------------------------------------------------- EXECUTION -----------------------------------------------------------------*/

int	    get_player_x(char **str);
int	    get_player_y(char **str);
int		get_x(char **str);
int		get_y(char **str);
void	exit_move(t_window window);
char	get_player_direction(char **str);


#endif