/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smounafi <smounafi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 10:24:06 by smounafi          #+#    #+#             */
/*   Updated: 2023/07/26 10:27:22 by smounafi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	ft_aim_cross(t_map *t)
{
	t->y = (t->g->h / 2.0) - 10.0;
	t->x = (t->g->w / 2.0) - 10.0;
	while (t->y <= (t->g->h / 2.0) + 10.0)
	{
		while (t->y >= (t->g->h / 2.0) - 7.0 && t->y <= (t->g->h / 2.0) + 7.0)
		{
			if (t->y > t->g->h / 2.0 && t->y <= t->g->h / 2)
				my_mlx_pixel_put(&t->g->img, t->x + 10.0, t->y, 0xffffff);
			t->y += 1.0;
		}
		my_mlx_pixel_put(&t->g->img, t->x + 10.0, t->y, 0xffffff);
		t->y += 1.0;
	}
	while (t->x <= (t->g->w / 2.0) + 10.0)
	{
		while (t->x >= (t->g->w / 2.0) - 7.0 && t->x <= (t->g->w / 2.0) + 7.0)
		{
			if (t->x >= t->g->w / 2.0 && t->x <= t->g->w / 2)
				my_mlx_pixel_put(&t->g->img, t->x, t->y - 10.0, 0xffffff);
			t->x += 1.0;
		}
		my_mlx_pixel_put(&t->g->img, t->x, t->y - 10.0, 0xffffff);
		t->x += 1.0;
	}
}

void	ft_minimap_wall(t_map *t)
{
	t->ycpy = 120.0 - (((t->player_y) / t->g->block_size) * 8.0);
	while (t->real_map[++t->j])
	{
		t->i = -1;
		t->xcpy = 120.0 - (((t->player_x) / t->g->block_size) * 8.0);
		while (t->real_map[t->j][++t->i])
		{
			t->y = t->ycpy;
			while (t->y <= 8.0 + t->ycpy)
			{
				t->x = t->xcpy;
				while (t->x <= 8.0 + t->xcpy && (t->y >= 0.0 && t->y <= 240.0))
				{
                    if (t->real_map[t->j][t->i] == '1' && (t->x >= 0.0 && t->x <= 240.0))
						my_mlx_pixel_put(&t->g->img, (int)t->x, (int)t->y, 0x000000);
					else if ((t->x >= 0.0 && t->x <= 240.0))
						my_mlx_pixel_put(&t->g->img, (int)t->x, (int)t->y, 0xe9e9e9);
					t->x += 1.0;
				}
				t->y += 1.0;
			}
			t->xcpy += 8.0;
		}
		t->ycpy += 8.0;
	}
}

void	ft_minimap(t_map *t)
{
	ft_minimap_wall(t);
	t->y = 0.0;
	while (t->y <= 240.0)
	{
		t->x = 0.0;
		while (t->x <= 240.0)
		{
			if ((t->x <= 8.0 || t->x >= 232.0)
				|| (t->y <= 8.0 || t->y >= 232.0))
				my_mlx_pixel_put(&t->g->img, t->x, t->y, 0x000000);
			t->x += 1.0;
		}
		t->y += 1.0;
	}
	t->y = 118.0;
	while (t->y <= 122.0)
	{
		t->x = 118.0;
		while (t->x <= 122.0)
		{
			my_mlx_pixel_put(&t->g->img, t->x, t->y, 0xff0000);
			t->x += 1.0;
		}
		t->y += 1.0;
	}
}

int	render(t_map *t)
{
	init_map_struct(t);
	render_helper(t);
	render_helper2(t);
	while (t->angle >= -30.0)
	{
		t->y = t->player_y;
		t->x = t->player_x;
		render_helper3(t);
		render_helper4(t);
		while (t->pix_y <= t->g->h)
		{
			my_mlx_pixel_put(&t->g->img, t->pix_x, t->pix_y, t->f);
			t->pix_y += 1.0;
		}
		t->pix_x += 1.0;
		t->angle -= 0.05;
	}
	ft_aim_cross(t);
	ft_minimap(t);
	mlx_put_image_to_window(t->g->mlx, t->g->win, t->g->img.img, 0, 0);
	return (0);
}

void	key_hook_helper(int key_code, t_map *map)
{
	if (key_code == 53)
	{
		printf("\033[0;33mYou closed the window!");
		exit(0);
	}
	if (key_code == 124)
		map->ang_direc = -4.0;
	if (key_code == 123)
		map->ang_direc = +4.0;
	if (key_code == 13)
	{
		map->direc = 1;
		map->y_direc = -1.0;
		map->x_direc = 1.0;
	}
}
