/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haouadia <haouadia@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 10:19:23 by haouadia          #+#    #+#             */
/*   Updated: 2023/07/30 10:19:26 by haouadia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_bonus.h"

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

void	ft_minimap_wall_x(t_map *t)
{
	while (t->x <= 8.0 + t->xcpy && (t->y >= 0.0 && t->y <= 240.0))
	{
		if (t->real_map[t->j][t->i] == '1' && (t->x >= 0.0 && t->x <= 240.0))
			my_mlx_pixel_put(&t->g->img, (int)t->x, (int)t->y, 0x000000);
		else if ((t->x >= 0.0 && t->x <= 240.0))
			my_mlx_pixel_put(&t->g->img, (int)t->x, (int)t->y, 0xe9e9e9);
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
				ft_minimap_wall_x(t);
				t->y += 1.0;
			}
			t->xcpy += 8.0;
		}
		t->ycpy += 8.0;
	}
}

void	ft_minimap_player(t_map *t)
{
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
	t->y = 0.0;
	t->x = 0.0;
	while ((t->x <= 5.0 && t->x >= -5.0) && (t->y <= 5.0 && t->y >= -5.0))
	{
		my_mlx_pixel_put(&t->g->img, t->x + 120.0, t->y + 120.0, 0xff0000);
		t->x += cos(t->player_ang * PI_R);
		t->y += -sin(t->player_ang * PI_R);
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
	ft_minimap_player(t);
}
