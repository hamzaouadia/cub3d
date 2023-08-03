/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smounafi <smounafi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 15:22:29 by smounafi          #+#    #+#             */
/*   Updated: 2023/08/03 09:46:47 by smounafi         ###   ########.fr       */
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
# define PI 3.1415926535897932384626433832795
# define PI_R 0.01745329251
# define WALL '1'
# define EMPTY '0'

# define FLOOR "F "
# define CEILLING "C "

# define NORTH_TEXTURE "NO "
# define SOUTH_TEXTURE "SO "
# define EAST_TEXTURE "EA "
# define WEST_TEXTURE "WE "

/* ------- COLORS ------*/

typedef struct s_data
{
	void			*img;
	char			*addr;
	int				bits_per_pixel;
	int				line_length;
	int				endian;
}					t_data;

typedef struct window
{
	void			*mlx;
	void			*win;
	int				h;
	int				h_half;
	int				w;
	int				x;
	int				y;
	int				dim_x;
	int				dim_y;
	int				block_size;
	t_data			img;
}					t_window;

typedef struct texture
{
	int				width;
	int				height;
	int				color;
	t_data			data;
}					t_texture;

typedef struct t_utils
{
	int				no;
	int				so;
	int				we;
	int				ea;
	int				cc;
	int				ff;
	int				flag;
}					t_utils;

typedef struct map
{
	t_texture		no_texture;
	t_texture		so_texture;
	t_texture		we_texture;
	t_texture		ea_texture;
	int				direc;
	int				direc_s;
	double			shift;
	double			move_step;
	double			player_x;
	double			player_y;
	double			up_x;
	double			up_y;
	double			player_ang;
	double			ang_direc;
	double			x_direc;
	double			y_direc;
	char			*no;
	char			*so;
	char			*we;
	char			*ea;
	int				f;
	int				c;
	char			**map;
	char			**real_map;
	t_utils			utils;
	struct window	*g;
	int				sx;
	int				sy;
	int				i;
	int				j;
	double			x;
	double			y;
	char			side;
	double			angle;
	double			pix_x;
	double			x_texture;
	double			y_texture;
	double			xcpy;
	double			ycpy;
	double			dist;
	double			wall;
	double			wall_top;
	double			wall_down;
	double			pix_y;
	int				flag;
	char			**rgb;
	char			*p;
}					t_map;

/* ------------------------------ PARSING ----------------------------*/

/* ~~~~~~~~~~~~~~~~~~~~~~~ TEXTURES ~~~~~~~~~~~~~~~~~~~~~~~*/

int					char_pos(char *str, char c);
char				*path_extracter(char *str);
void				north_south_textures(char *str, t_map *map);
void				east_west_textures(char *str, t_map *map);
void				east_west_textures(char *str, t_map *map);
void				floor_ceiling_textures(char *str, t_map *map);
void				check_texture_name(char *str);
int					dbl_size_each(char **str);
int					all_digits(char **str);

/* ~~~~~~~~~~~~~~~~~~~~~~~ CONTENT ~~~~~~~~~~~~~~~~~~~~~~~*/

void				check_map_content(char *str);
void				check_map_walls(char **str);
void				check_map_textures(t_map *map);
int					zero_index(char *str);
int					ft_strlenn(const char *s);
int					is_a_space(char c);
void				check_map_content_help(char **str);
int					completed_wall(char *str);
int					comma_counter(char *str);
int					only_spaces(char *str);
int					not_null_termin(char **str);
char				*ft_strjoinn(char *s1, char *s2);
int					highest_len(char **str);
char				*add_space(int size);
int 				valid_start_pos(char c);

/* ~~~~~~~~~~~~~~~~~~~~~~~~~ MAP ~~~~~~~~~~~~~~~~~~~~~~~~~*/

char				*get_map(char *arg, int fd);
void				errors(int i);
void				errors_help(int i);
char				*setup_map(char *str, t_map *map);

/* -------------------------- EXECUTION -------------------------------*/

int					get_player_x(char **str);
int					get_player_y(char **str);
int					get_x(char **str);
int					get_y(char **str);
void				exit_move(t_window window);
char				get_player_direction(char **str);
void				my_mlx_pixel_put(t_data *data, int x, int y, int color);
int					get_color_w(t_texture *tex, double y, double x);
void				init_map_struct(t_map *t);
void				render_helper(t_map *t);
void				render_helper2(t_map *t);
void				render_3_helper(t_map *t);
void				render_helper3(t_map *t);
void				render_helper4(t_map *t);
int					render(t_map *t);
void				key_hook_helper(int key_code, t_map *map);
char				get_player_direction(char **str);
int					get_player_y(char **str);
int					get_player_x(char **str);
int					key_hook(int key_code, t_map *map);
void				key_release_helper(int key_code, t_map *map);
int					key_release(int key_code, t_map *map);
void				initialize_textures_helper(t_window *win, t_map *map);
void				initialize_textures(t_window *win, t_map *map);
int					render(t_map *t);
void				key_hook_helper(int key_code, t_map *map);
int					ft_check_radius(t_map *t, double player_x, double player_y);
void				extraction(t_map *map, char **str, char alphabet);
void				free_split(char **str);
int					double_len(char **str);
void				ft_y_texture(t_map *t);
#endif