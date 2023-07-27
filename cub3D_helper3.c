/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D_helper3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smounafi <smounafi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 10:15:53 by smounafi          #+#    #+#             */
/*   Updated: 2023/07/26 10:29:38 by smounafi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	key_hook(int key_code, t_map *map)
{
	key_hook_helper(key_code, map);
	if (key_code == 1)
	{
		map->direc = 1;
		map->y_direc = 1.0;
		map->x_direc = -1.0;
	}
	if (key_code == 0)
	{
		map->direc = 0;
		map->y_direc = -1.0;
		map->x_direc = -1.0;
	}
	if (key_code == 2)
	{
		map->direc = 0;
		map->y_direc = 1.0;
		map->x_direc = 1.0;
	}
	return (0);
}

void	key_release_helper(int key_code, t_map *map)
{
	if (key_code == 124)
	{
		map->ang_direc = 0;
	}
	if (key_code == 123)
	{
		map->ang_direc = 0;
	}
	if (key_code == 13)
	{
		map->y_direc = 0;
		map->x_direc = 0;
	}
}

int	key_release(int key_code, t_map *map)
{
	key_release_helper(key_code, map);
	if (key_code == 1)
	{
		map->y_direc = 0;
		map->x_direc = 0;
	}
	if (key_code == 0)
	{
		map->y_direc = 0;
		map->x_direc = 0;
	}
	if (key_code == 2)
	{
		map->y_direc = 0;
		map->x_direc = 0;
	}
	return (0);
}

void	initialize_textures_helper(t_window *win, t_map *map)
{
	map->no_texture.data.img = mlx_xpm_file_to_image(win->mlx, map->no,
			&map->no_texture.width, &map->no_texture.height);
	map->no_texture.data.addr = mlx_get_data_addr(map->no_texture.data.img,
			&map->no_texture.data.bits_per_pixel,
			&map->no_texture.data.line_length,
			&map->no_texture.data.endian);
	map->so_texture.data.img = mlx_xpm_file_to_image(win->mlx, map->so,
			&map->so_texture.width, &map->so_texture.height);
	map->so_texture.data.addr = mlx_get_data_addr(map->so_texture.data.img,
			&map->so_texture.data.bits_per_pixel,
			&map->so_texture.data.line_length,
			&map->so_texture.data.endian);
}

void	initialize_textures(t_window *win, t_map *map)
{
	initialize_textures_helper(win, map);
	map->we_texture.data.img = mlx_xpm_file_to_image(win->mlx, map->we,
			&map->we_texture.width, &map->we_texture.height);
	map->we_texture.data.addr = mlx_get_data_addr(map->we_texture.data.img,
			&map->we_texture.data.bits_per_pixel,
			&map->we_texture.data.line_length,
			&map->we_texture.data.endian);
	map->ea_texture.data.img = mlx_xpm_file_to_image(win->mlx, map->ea,
			&map->ea_texture.width, &map->ea_texture.height);
	map->ea_texture.data.addr = mlx_get_data_addr(map->ea_texture.data.img,
			&map->ea_texture.data.bits_per_pixel,
			&map->ea_texture.data.line_length,
			&map->ea_texture.data.endian);
}
