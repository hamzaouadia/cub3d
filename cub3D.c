/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smounafi <smounafi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 15:23:57 by smounafi          #+#    #+#             */
/*   Updated: 2023/07/26 10:21:19 by smounafi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	set_player_angle(t_map *map)
{
	if (get_player_direction(map->real_map) == 'N')
		map->player_ang = 90.0;
	else if (get_player_direction(map->real_map) == 'E')
		map->player_ang = 0.0;
	else if (get_player_direction(map->real_map) == 'S')
		map->player_ang = 270.0;
	else if (get_player_direction(map->real_map) == 'W')
		map->player_ang = 180.0;
}

void	run_game(t_window *win)
{
	mlx_loop(win->mlx);
}

void	initialize_window(t_window *win, t_map *map)
{
	map->move_step = 8.0;
	initialize_textures(win, map);
	set_player_angle(map);
	mlx_loop_hook(win->mlx, render, map);
	mlx_hook(win->win, 2, 0, key_hook, map);
	mlx_hook(win->win, 3, 0, key_release, map);
	run_game(win);
}

void	setup_game(int ac, char **av)
{
	char		*extracted_map;
	t_window	win;
	t_map		map;

	(void)ac;
	map.g = &win;
	extracted_map = setup_map(get_map(av[1], 0), &map);
	win.w = 1200;
	win.h = 1000;
	win.h_half = win.h / 2;
	win.dim_x = get_x(map.real_map);
	win.dim_y = get_y(map.real_map);
	win.block_size = 40;
	win.mlx = mlx_init();
	win.win = mlx_new_window(win.mlx, win.w, win.h, "cub3D");
	map.player_x = win.block_size * get_player_x(map.real_map) + (win.block_size
			/ 2);
	map.player_y = win.block_size * get_player_y(map.real_map) + (win.block_size
			/ 2);
	initialize_window(&win, &map);
}

int	main(int ac, char **av)
{
	if (ac == 2)
	{
		setup_game(ac, av);
	}
	else
	{
		errors(4);
	}
	return (0);
}

// int	main(int ac, char **av)
// {
// 	char *extracted_map;
// 	t_window win;

// 	t_map map;
// 	map.g = &win;
// 	if(ac == 2)
// 	{
// 		extracted_map = setup_map(get_map(av[1], 0), &map);
//         win.w = 1200;
// 		win.h = 1000;
// 		win.h_half = win.h / 2;
//         win.dim_x = get_x(map.real_map);
//         win.dim_y = get_y(map.real_map);
// 		win.block_size = 40;

// 		win.mlx = mlx_init();
//         win.win = mlx_new_window(win.mlx, win.w, win.h, "cub3D");
//         map.player_x = win.block_size * get_player_x(map.real_map)
// 	+ (win.block_size / 2);
// //         map.player_y = win.block_size * get_player_y(map.real_map)
// 	+ (win.block_size / 2);
// //         map.no_texture.data.img = mlx_xpm_file_to_image(win.mlx,
// 		"./maps/no.xpm", &map.no_texture.width, &map.no_texture.height);
//
	//         map.no_texture.data.addr = mlx_get_data_addr(map.no_texture.data.img,
// 		&map.no_texture.data.bits_per_pixel, &map.no_texture.data.line_length,
// 		&map.no_texture.data.endian);
// //         map.so_texture.data.img = mlx_xpm_file_to_image(win.mlx,
// 		"./maps/so.xpm", &map.so_texture.width, &map.so_texture.height);
//
	//         map.so_texture.data.addr = mlx_get_data_addr(map.so_texture.data.img,
// 		&map.so_texture.data.bits_per_pixel, &map.so_texture.data.line_length,
// 		&map.so_texture.data.endian);
// //         map.we_texture.data.img = mlx_xpm_file_to_image(win.mlx,
// 		"./maps/we.xpm", &map.we_texture.width, &map.we_texture.height);
//
	//         map.we_texture.data.addr = mlx_get_data_addr(map.we_texture.data.img,
// 		&map.we_texture.data.bits_per_pixel, &map.we_texture.data.line_length,
// 		&map.we_texture.data.endian);
// //         map.ea_texture.data.img = mlx_xpm_file_to_image(win.mlx,
// 		"./maps/ea.xpm", &map.ea_texture.width, &map.ea_texture.height);
//
	//         map.ea_texture.data.addr = mlx_get_data_addr(map.ea_texture.data.img,
// 		&map.ea_texture.data.bits_per_pixel, &map.ea_texture.data.line_length,
// 		&map.ea_texture.data.endian);
//         if (get_player_direction(map.real_map) == 'N')
//             map.player_ang = 90.0;
//         else if (get_player_direction(map.real_map) == 'E')
//             map.player_ang = 0.0;
//         else if (get_player_direction(map.real_map) == 'S')
//             map.player_ang = 270.0;
//         else if (get_player_direction(map.real_map) == 'W')
//             map.player_ang = 180.0;
//         map.move_step = 10.0;
// 		mlx_loop_hook(win.mlx,render, &map);
//         mlx_hook(win.win, 2, 0, key_hook, &map);
//         mlx_hook(win.win, 3, 0, key_release, &map);
// 		exit_move(win);
// 		mlx_loop(win.mlx);
// 	}
// 	else
// 		errors(4);
// 	exit(0);
// }