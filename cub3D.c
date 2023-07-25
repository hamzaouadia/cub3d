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
    if (x < 1200 && y < 1000)
    {
        dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
        *(unsigned int*)dst = color;
    }
}

int    get_color_w(t_texture *tex, double y, double x)
{
    char    *str;
    int        colore;

    // printf("x = %d\n", x);
    // printf("y = %d\n", y);
    if (y <= 0 || y >= tex->height || x <= 0 || x >= tex->width)
        return (0);
    str = tex->data.addr + ((int)(y) *tex->data.line_length)
        + ((int)(x) *(tex->data.bits_per_pixel / 8));
    colore = *(int *)str;
    return (colore);
}

int	render(s_map *t)
{
    /*---------------shof ila 9darti dakhel had les variables f shi struct--------------*/
	double x = 0.0;
	double y = 0.0;
    char   side;
    int    sx = 1;
    int    sy = 1;
	// int i = 0;
	// int j = 0;
	// int xcpy = 0;
	// int ycpy = 0;
    t->g->img.img = mlx_new_image(t->g->mlx, t->g->w, t->g->h);
    t->g->img.addr = mlx_get_data_addr(t->g->img.img, &t->g->img.bits_per_pixel, &t->g->img.line_length, &t->g->img.endian);

    if (t->player_ang + t->ang_direc > 360.0 || t->player_ang + t->ang_direc < 0.0)
        t->player_ang = fabs(360.0 - t->player_ang);
    else
        t->player_ang += t->ang_direc;
    if (t->player_ang > 90.0 && t->player_ang < 270.0)
        sx = -1;
    if (t->player_ang > 180.0)
        sy = -1;
    t->up_x = t->move_step * cos(t->player_ang * PI / 180.0);
    t->up_y = t->move_step * sin(t->player_ang * PI / 180.0);
    if (t->direc == 1)
    {
        if (t->real_map[(int)(t->player_y + (t->y_direc * sy * 15.0)) / t->g->block_size][(int)t->player_x / t->g->block_size] != '1')
                t->player_y += t->y_direc * t->up_y;
        if (t->real_map[(int)t->player_y / t->g->block_size][(int)(t->player_x + (t->x_direc * sx * 15.0)) / t->g->block_size] != '1')
                t->player_x += t->x_direc * t->up_x;
    }
    if (t->direc == 0)
    {
        if (t->real_map[(int)(t->player_y + (t->y_direc * sx * 15.0)) / t->g->block_size][(int)t->player_x / t->g->block_size] != '1')
            t->player_y += t->y_direc * t->up_x;
        if (t->real_map[(int)t->player_y / t->g->block_size][(int)(t->player_x + (t->x_direc * sy * 15.0)) / t->g->block_size] != '1')
            t->player_x += t->x_direc * t->up_y;
    }
    double angle = 30.0;
    double pix_x = 0.0;
    double x_texture = 0.0;
    double y_texture = 0.0;
    while (angle >= -30.0)
    {
        y = t->player_y;
        x = t->player_x;
        while (1)
        {
            x += 0.5 * cos((angle + t->player_ang) * PI / 180.0);
            if (t->real_map[(int)(y / t->g->block_size)][(int)(x / t->g->block_size)] == '1')
            {
                side = 'e';
                x_texture = (((y / t->g->block_size) - (int)(y / t->g->block_size))) * t->ea_texture.width;
                if (x < t->player_x)
                {
                    side = 'w';
                    x_texture = (((y / t->g->block_size) - (int)(y / t->g->block_size))) * t->we_texture.width;
                }
                break ;
            }
            y -= 0.5 * sin((angle + t->player_ang) * PI / 180.0);
            if (t->real_map[(int)(y / t->g->block_size)][(int)(x / t->g->block_size)] == '1')
            {
                side = 'n';
                x_texture = (((x / t->g->block_size) - (int)(x / t->g->block_size))) * t->no_texture.width;
                if (y > t->player_y)
                {
                    side = 's';
                    x_texture = (((x / t->g->block_size) - (int)(x / t->g->block_size))) * t->so_texture.width;
                }
                break ;
            }
        }
        double dist = sqrt(pow(fabs(x - t->player_x), 2.0  ) + pow(fabs(y - t->player_y), 2.0)) * cos(angle * PI / 180.0);
        double wall = (80.0 / dist) * t->g->h_half;
        double wall_top = t->g->h_half - (wall / 2.0);
        double wall_down = t->g->h_half + (wall / 2);
        y_texture = 0.0;
        double pix_y = 0.0;
        while (pix_y <= wall_top)
        {   
            my_mlx_pixel_put(&t->g->img, pix_x, pix_y, t->c);
            pix_y += 1.0;
        }
        pix_y = wall_top;
        while (pix_y <= wall_down)
        {
            if (pix_y >= 0.0 && pix_y <= t->g->h && side == 'e')
                my_mlx_pixel_put(&t->g->img, pix_x, pix_y, get_color_w(&t->ea_texture, y_texture, x_texture));
            if (pix_y >= 0.0 && pix_y <= t->g->h && side == 'w')
                my_mlx_pixel_put(&t->g->img, pix_x, pix_y, get_color_w(&t->we_texture, y_texture, x_texture));
            if (pix_y >= 0.0 && pix_y <= t->g->h && side == 'n')
                my_mlx_pixel_put(&t->g->img, pix_x, pix_y, get_color_w(&t->no_texture, y_texture, x_texture));
            if (pix_y >= 0.0 && pix_y <= t->g->h && side == 's')
                my_mlx_pixel_put(&t->g->img, pix_x, pix_y, get_color_w(&t->so_texture, y_texture, x_texture));
            pix_y += 1.0;
            y_texture += 500.0 / wall;
        }
        while (pix_y <= t->g->h)
        {   
            my_mlx_pixel_put(&t->g->img, pix_x, pix_y, t->f);
            pix_y += 1.0;
        }
        pix_x += 1.0;
        angle -= 0.05;
    }
    /*
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
    // j = 0;
    // while(t->real_map[j])
	// {
	// 	i = 0;
	// 	xcpy = 0;
	// 	while (t->real_map[j][i])
	// 	{
	// 		y = ycpy;
	// 		while (y <= t->g->block_size / 4 + ycpy)
	// 		{
	// 			x = xcpy;
	// 			while (x <= t->g->block_size / 4 + xcpy)
	// 			{
    //                 if (t->real_map[j][i] == '1')
	// 				    my_mlx_pixel_put(&t->g->img, (int)x, (int)y, 0x000000);
	// 				x++;
	// 			} 
	// 			y++;
	// 		}
	// 		i++;
	// 		xcpy += t->g->block_size / 4;
	// 	}
	// 	j++;
	// 	ycpy += t->g->block_size / 4;
	// }
    // y = 0;
    // while (y <= t->g->block_size / 16)
    // {
    //     x = 0;
    //     while (x <= t->g->block_size / 16)
    //     {
    //         my_mlx_pixel_put(&t->g->img, (t->player_x / 4) + x , (t->player_y / 4) + y, 0x000000);
    //         x++;
    //     }
    //     y++;
    // }
    */
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
    if (key_code == 49)
        map->shift = 40.0;
    if (key_code == 124)
        map->ang_direc = -8.0;
    if (key_code == 123)
        map->ang_direc = +8.0;
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
    if (key_code == 49)
        map->shift = 0.0;
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
		win.block_size = 40;
      
		win.mlx = mlx_init();
        win.win = mlx_new_window(win.mlx, win.w, win.h, "cub3D");
        map.player_x = win.block_size * get_player_x(map.real_map) + (win.block_size / 2);
        map.player_y = win.block_size * get_player_y(map.real_map) + (win.block_size / 2);
         
        map.no_texture.data.img = mlx_xpm_file_to_image(win.mlx, "./maps/no.xpm", &map.no_texture.width, &map.no_texture.height);
        map.no_texture.data.addr = mlx_get_data_addr(map.no_texture.data.img, &map.no_texture.data.bits_per_pixel, &map.no_texture.data.line_length, &map.no_texture.data.endian);
       
        map.so_texture.data.img = mlx_xpm_file_to_image(win.mlx, "./maps/so.xpm", &map.so_texture.width, &map.so_texture.height);
        map.so_texture.data.addr = mlx_get_data_addr(map.so_texture.data.img, &map.so_texture.data.bits_per_pixel, &map.so_texture.data.line_length, &map.so_texture.data.endian);
       
        map.we_texture.data.img = mlx_xpm_file_to_image(win.mlx, "./maps/we.xpm", &map.we_texture.width, &map.we_texture.height);
        map.we_texture.data.addr = mlx_get_data_addr(map.we_texture.data.img, &map.we_texture.data.bits_per_pixel, &map.we_texture.data.line_length, &map.we_texture.data.endian);
       
        map.ea_texture.data.img = mlx_xpm_file_to_image(win.mlx, "./maps/ea.xpm", &map.ea_texture.width, &map.ea_texture.height);
        map.ea_texture.data.addr = mlx_get_data_addr(map.ea_texture.data.img, &map.ea_texture.data.bits_per_pixel, &map.ea_texture.data.line_length, &map.ea_texture.data.endian);
       
        if (get_player_direction(map.real_map) == 'N')
            map.player_ang = 90.0;
        else if (get_player_direction(map.real_map) == 'E')
            map.player_ang = 0.0;
        else if (get_player_direction(map.real_map) == 'S')
            map.player_ang = 270.0;
        else if (get_player_direction(map.real_map) == 'W')
            map.player_ang = 180.0;
        map.move_step = 10.0;
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