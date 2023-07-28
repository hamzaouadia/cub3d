/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D_helper.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smounafi <smounafi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 20:58:27 by smounafi          #+#    #+#             */
/*   Updated: 2023/07/26 10:23:23 by smounafi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	if (x < 1200 && y < 1000)
	{
		dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel
					/ 8));
		*(unsigned int *)dst = color;
	}
}

int	get_color_w(t_texture *tex, double y, double x)
{
	char	*str;
	int		colore;

	if (y <= 0 || y >= tex->height || x <= 0 || x >= tex->width)
		return (0);
	str = tex->data.addr + ((int)(y)*tex->data.line_length) + ((int)(x)
			*(tex->data.bits_per_pixel / 8));
	colore = *(int *)str;
	return (colore);
}

void	init_map_struct(t_map *t)
{
	t->i = -1;
	t->j = -1;
	t->sx = 1;
	t->sy = 1;
	t->x = 0.0;
	t->y = 0.0;
	t->angle = 30.0;
	t->pix_x = 0.0;
	t->x_texture = 0.0;
	t->y_texture = 0.0;
}

int	ft_check_radius(t_map *t, double player_x, double player_y)
{
	double	angle;
	double	x;
	double	y;

	angle = 0.0;
	x = 0.0;
	y = 0.0;
	while (angle <= 360)
	{
		x = 10.0 * cos(angle * PI_R) + player_x;
		y = 10.0 * -sin(angle * PI_R) + player_y;
		if (t->real_map[(int)y / t->g->block_size]
			[(int)x / t->g->block_size] == '1')
			return (0);
		angle += 0.5;
	}
	return (1);
}

void	render_helper(t_map *t)
{
	t->g->img.img = mlx_new_image(t->g->mlx, t->g->w, t->g->h);
	t->g->img.addr = mlx_get_data_addr(t->g->img.img, &t->g->img.bits_per_pixel,
			&t->g->img.line_length, &t->g->img.endian);
	if (t->player_ang + t->ang_direc > 360.0 || t->player_ang
		+ t->ang_direc < 0.0)
		t->player_ang = fabs(360.0 - t->player_ang);
	else
		t->player_ang += t->ang_direc;
	if (t->player_ang > 90.0 && t->player_ang < 270.0)
		t->sx = -1;
	if (t->player_ang > 180.0)
		t->sy = -1;
	t->up_x = t->move_step * cos(t->player_ang * PI_R);
	t->up_y = t->move_step * sin(t->player_ang * PI_R);
	if (t->direc == 1)
	{
		if (ft_check_radius(t, t->player_x, t->player_y
				+ (t->y_direc * t->sy * 8.0)))
			t->player_y += t->y_direc * t->up_y;
		if (ft_check_radius(t, t->player_x
				+ (t->x_direc * t->sx * 8.0), t->player_y))
			t->player_x += t->x_direc * t->up_x;
	}
}

void	render_helper2(t_map *t)
{
	if (t->direc == 0)
	{
		if (ft_check_radius(t, t->player_x,
				t->player_y + (t->y_direc * t->sx * 8.0)))
			t->player_y += t->y_direc * t->up_x;
		if (ft_check_radius(t, t->player_x
				+ (t->x_direc * t->sy * 8.0), t->player_y))
			t->player_x += t->x_direc * t->up_y;
	}
}
