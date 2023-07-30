/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_helper.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haouadia <haouadia@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 10:17:05 by haouadia          #+#    #+#             */
/*   Updated: 2023/07/30 10:17:11 by haouadia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	render_helper2(t_map *t)
{
	if (t->direc == 0)
	{
		if (ft_check_radius(t, t->player_x
				+ (t->x_direc * t->sy * 5.0),
				t->player_y + (t->y_direc * t->sx * 5.0)))
		{
			t->player_y += t->y_direc * t->up_x;
			t->player_x += t->x_direc * t->up_y;
		}
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
		t->pix_x += 0.834;
		t->angle -= 0.05;
	}
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
