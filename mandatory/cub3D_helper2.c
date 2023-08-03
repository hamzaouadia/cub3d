/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D_helper2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smounafi <smounafi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 10:17:48 by haouadia          #+#    #+#             */
/*   Updated: 2023/08/01 17:50:40 by smounafi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	render_3_helper(t_map *t)
{
	if (t->x < t->player_x)
	{
		t->side = 'w';
		t->x_texture = (((t->y / t->g->block_size) - (int)(t->y
						/ t->g->block_size))) * t->we_texture.width;
	}
}

void	render_helper3_helper(t_map *t)
{
	t->side = 'n';
	t->x_texture = (((t->x / t->g->block_size) - (int)(t->x
					/ t->g->block_size))) * t->no_texture.width;
	if (t->y > t->player_y)
	{
		t->side = 's';
		t->x_texture = (((t->x / t->g->block_size) - (int)(t->x
						/ t->g->block_size))) * t->so_texture.width;
	}
	t->flag = 1;
}

void	render_helper3(t_map *t)
{
	while (1)
	{
		t->x += cos((t->angle + t->player_ang) * PI_R);
		if (t->real_map[(int)(t->y / t->g->block_size)][(int)(t->x
				/ t->g->block_size)] == '1' ||
					t->real_map[(int)(t->y / t->g->block_size)][(int)(t->x
				/ t->g->block_size)] == ' ')
		{
			t->side = 'e';
			t->x_texture = (((t->y / t->g->block_size) - (int)(t->y
							/ t->g->block_size))) * t->ea_texture.width;
			render_3_helper(t);
			break ;
		}
		t->y += -sin((t->angle + t->player_ang) * PI_R);
		if (t->real_map[(int)(t->y / t->g->block_size)][(int)(t->x
				/ t->g->block_size)] == '1' ||
					t->real_map[(int)(t->y / t->g->block_size)][(int)(t->x
				/ t->g->block_size)] == ' ')
		{
			render_helper3_helper(t);
			if (t->flag == 1)
				break ;
		}
	}
}

void	render_helper4_helper(t_map *t)
{
	if (t->pix_y >= 0.0 && t->pix_y <= t->g->h && t->side == 'e')
		my_mlx_pixel_put(&t->g->img, t->pix_x, t->pix_y,
			get_color_w(&t->ea_texture, t->y_texture, t->x_texture));
	if (t->pix_y >= 0.0 && t->pix_y <= t->g->h && t->side == 'w')
		my_mlx_pixel_put(&t->g->img, t->pix_x, t->pix_y,
			get_color_w(&t->we_texture, t->y_texture, t->x_texture));
	if (t->pix_y >= 0.0 && t->pix_y <= t->g->h && t->side == 'n')
		my_mlx_pixel_put(&t->g->img, t->pix_x, t->pix_y,
			get_color_w(&t->no_texture, t->y_texture, t->x_texture));
	if (t->pix_y >= 0.0 && t->pix_y <= t->g->h && t->side == 's')
		my_mlx_pixel_put(&t->g->img, t->pix_x, t->pix_y,
			get_color_w(&t->so_texture, t->y_texture, t->x_texture));
}

void	render_helper4(t_map *t)
{
	t->dist = sqrt(pow(fabs(t->x - t->player_x), 2.0) + pow(fabs(t->y
					- t->player_y), 2.0));
	t->wall = (t->g->block_size * 2
			/ (t->dist * cos((t->angle) * PI_R))) * t->g->h_half;
	t->wall_top = t->g->h_half - (t->wall / 2.0);
	t->wall_down = t->g->h_half + (t->wall / 2.0);
	t->y_texture = 0.0;
	t->pix_y = 0.0;
	while (t->pix_y <= t->wall_top)
	{
		my_mlx_pixel_put(&t->g->img, t->pix_x, t->pix_y, t->c);
		t->pix_y += 1.0;
	}
	t->pix_y = t->wall_top;
	while (t->pix_y <= t->wall_down)
	{
		render_helper4_helper(t);
		t->pix_y += 1.0;
		t->y_texture += t->we_texture.height / t->wall;
	}
}
