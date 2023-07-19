/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smounafi <smounafi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 15:23:57 by smounafi          #+#    #+#             */
/*   Updated: 2023/07/04 07:57:41 by smounafi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;
    if (x < 1800 && y < 1200)
    {
        dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
        *(unsigned int*)dst = color;
    }
}

int	render(s_map *t)
{
	double x = 0.0;
	double y = 0.0;
    char   side;
	int i = 0;
	int j = 0;
	int xcpy = 0;
	int ycpy = 0;

    if (t->g->img.img)
        mlx_destroy_image(t->g->mlx, t->g->img.img);
    t->g->img.img = mlx_new_image(t->g->mlx, t->g->w, t->g->h);
    t->g->img.addr = mlx_get_data_addr(t->g->img.img, &t->g->img.bits_per_pixel, &t->g->img.line_length, &t->g->img.endian);

    if (t->player_ang + t->ang_direc >= 360 || t->player_ang + t->ang_direc < 0)
        t->player_ang = fabs(360 - t->player_ang);
    else
        t->player_ang += t->ang_direc;
    t->up_x = t->move_step * cos(t->player_ang * PI / 180.0);
    t->up_y = t->move_step * sin(t->player_ang * PI / 180.0);
    if (t->direc == 1)
    {
        if (t->real_map[(int)(t->player_y + (t->y_direc * t->up_y)) / t->g->block_size][(int)t->player_x / t->g->block_size] != '1')
                t->player_y += t->y_direc * t->up_y;
        if (t->real_map[(int)t->player_y / t->g->block_size][(int)(t->player_x + (t->x_direc * t->up_x)) / t->g->block_size] != '1')
                t->player_x += t->x_direc * t->up_x;
    }
    if (t->direc == 0)
    {
        if (t->real_map[(int)((t->player_y) + (t->y_direc * t->up_x)) / t->g->block_size][(int)t->player_x / t->g->block_size] != '1')
            t->player_y += t->y_direc * t->up_x;
        if (t->real_map[(int)t->player_y / t->g->block_size][(int)((t->player_x) + (t->x_direc * t->up_y)) / t->g->block_size] != '1')
            t->player_x += t->x_direc * t->up_y;
    }
    double angle = 30.0;
    double pix_x = 0.0;
    double pix_y;
    while (angle >= -30.0)
    {
        y = t->player_y;
        x = t->player_x;
        while (1)
        {
            // my_mlx_pixel_put(&t->g->img, x, y, 0x000000);
            x += 1.0 * cos((angle + t->player_ang) * PI / 180.0);
            if (t->real_map[(int)(y / t->g->block_size)][(int)(x / t->g->block_size)] == '1')
            {
                side = 'e';
                if (x < t->player_x)
                    side = 'w';
                break ;
            }
            y -= 1.0 * sin((angle + t->player_ang) * PI / 180.0);
            if (t->real_map[(int)(y / t->g->block_size)][(int)(x / t->g->block_size)] == '1')
            {   
                side = 'n';
                if (y > t->player_y)
                    side = 's';
                break ;
            }
        }
        double dist = sqrt(pow(fabs(x - t->player_x), 2.0  ) + pow(fabs(y - t->player_y), 2.0)) * cos(angle * (PI / 180.0));
        double wall = (80.0 / dist) * t->g->h / 2;
        double wall_top = t->g->h_half - (wall / 2.0);
        wall_top = wall_top < 0.0 ? 0.0 : wall_top;
        double wall_down = t->g->h_half + (wall / 2);
        wall_down = wall_down > t->g->h ? t->g->h : wall_down;
        pix_y = 0.0;
        while (pix_y < t->g->h && pix_x < t->g->w)
        {
            if (pix_y < t->g->h_half && pix_y < wall_top)
                my_mlx_pixel_put(&t->g->img, pix_x, pix_y, t->c);
            else
                my_mlx_pixel_put(&t->g->img, pix_x, pix_y, t->f);
            if (pix_y >= wall_top && pix_y <= wall_down && side == 'e')
                my_mlx_pixel_put(&t->g->img, pix_x, pix_y, 0xDCDCDC);
            if (pix_y >= wall_top && pix_y <= wall_down && side == 'w')
                my_mlx_pixel_put(&t->g->img, pix_x, pix_y, 0x778899);
            if (pix_y >= wall_top && pix_y <= wall_down && side == 'n')
                my_mlx_pixel_put(&t->g->img, pix_x, pix_y, 0x4682B4);
            if (pix_y >= wall_top && pix_y <= wall_down && side == 's')
                my_mlx_pixel_put(&t->g->img, pix_x, pix_y, 0x1E90FF);
        
            pix_y += 1.0;
        }
        pix_x += 1.0;
        angle -= 0.05;
    }
    y = (t->g->h / 2.0) - 10.0;
    x = (t->g->w / 2.0) - 10.0;
    while (y <= (t->g->h / 2.0) + 10.0)
    {
        while (y >= (t->g->h / 2.0) - 7.0 && y <= (t->g->h / 2.0) + 7.0)
        {
            if (y > t->g->h / 2.0 && y <= t->g->h / 2)
                my_mlx_pixel_put(&t->g->img, x + 10.0, y, 0xffffff);
            y += 1.0;
        }
        my_mlx_pixel_put(&t->g->img, x + 10.0, y, 0xffffff);
        y += 1.0;
    }
    while (x <= (t->g->w / 2.0) + 10.0)
    {
        while (x >= (t->g->w / 2.0) - 7.0 && x <= (t->g->w / 2.0) + 7.0)
        {
            if (x >= t->g->w / 2.0 && x <= t->g->w / 2)
                my_mlx_pixel_put(&t->g->img, x, y - 10.0, 0xffffff);
            x += 1.0;
        }
        my_mlx_pixel_put(&t->g->img, x, y - 10.0, 0xffffff);
        x += 1.0;
    }
    j = 0;
    while(t->real_map[j])
	{
		i = 0;
		xcpy = 0;
		while (t->real_map[j][i])
		{
			y = ycpy;
			while (y <= t->g->block_size / 4 + ycpy)
			{
				x = xcpy;
				while (x <= t->g->block_size / 4 + xcpy)
				{
                    if (t->real_map[j][i] == '1')
					    my_mlx_pixel_put(&t->g->img, (int)x, (int)y, 0x000000);
					x++;
				} 
				y++;
			}
			i++;
			xcpy += t->g->block_size / 4;
		}
		j++;
		ycpy += t->g->block_size / 4;
	}
    y = 0;
    while (y <= t->g->block_size / 16)
    {
        x = 0;
        while (x <= t->g->block_size / 16)
        {
            my_mlx_pixel_put(&t->g->img, (t->player_x / 4) + x , (t->player_y / 4) + y, 0x000000);
            x++;
        }
        y++;
    }
    mlx_put_image_to_window(t->g->mlx, t->g->win, t->g->img.img, 0, 0);
	return 0;
}

int key_hook(int key_code, s_map *map)
{
    if (key_code == 53)
	{
		printf("\033[0;33mYou closed the window!");
		exit(0);
	}
    if (key_code == 124)
        map->ang_direc = -5.0;
    if (key_code == 123)
        map->ang_direc = +5.0;
    if (key_code == 13)
    {
        map->direc = 1;
        map->y_direc = -1.0;
        map->x_direc = 1.0;
    }
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

int key_release(int key_code, s_map *map)
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

int	main(int ac, char **av)
{
	char *extracted_map;
	t_window win;
    
	s_map map;
	map.g = &win;
	if(ac == 2)
	{
		extracted_map = setup_map(get_map(av[1], 0), &map);
        win.w = 1200;
		win.h = 1000;
		win.h_half = win.h / 2;
        win.dim_x = get_x(map.real_map);
        win.dim_y = get_y(map.real_map);
		win.block_size = win.w / get_x(map.real_map);
		win.mlx = mlx_init();
		win.win = mlx_new_window(win.mlx, win.w, win.h, "cub3D");
        map.player_x = win.block_size * get_player_x(map.real_map) + (win.block_size / 2);
        map.player_y = win.block_size * get_player_y(map.real_map) + (win.block_size / 2);
        if (get_player_direction(map.real_map) == 'N')
            map.player_ang = 90.0;
        else if (get_player_direction(map.real_map) == 'E')
            map.player_ang = 0.0;
        else if (get_player_direction(map.real_map) == 'S')
            map.player_ang = 270.0;
        else if (get_player_direction(map.real_map) == 'W')
            map.player_ang = 180.0;
        map.move_step = win.block_size / 5;
        map.up_x = 2.0 * cos(map.player_ang * PI / 180);
        map.up_y = 2.0 * sin(map.player_ang * PI / 180);
		mlx_loop_hook(win.mlx,render, &map);
        mlx_hook(win.win, 2, 0, key_hook, &map);
        mlx_hook(win.win, 3, 0, key_release, &map);
		exit_move(win);
		mlx_loop(win.mlx);
	}
	else
		errors(4);
	exit(0);
}