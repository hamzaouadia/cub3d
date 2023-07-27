/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smounafi <smounafi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 15:21:46 by smounafi          #+#    #+#             */
/*   Updated: 2023/07/26 10:21:19 by smounafi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

void	init_stuff(t_map *map)
{
	map->no = NULL;
	map->so = NULL;
	map->we = NULL;
	map->ea = NULL;
	map->f = 0;
	map->c = 0;
	map->utils.no = 0;
	map->utils.so = 0;
	map->utils.we = 0;
	map->utils.ea = 0;
	map->utils.cc = 0;
	map->utils.ff = 0;
	map->utils.flag = 0;
}

void	check_map_name(char *str)
{
	int	i;

	i = 0;
	i = ft_strlen(str);
	if (str)
	{
		if (ft_strncmp(ft_substr(str, i - 4, 4), ".cub", 4))
			errors(3);
	}
	else
		errors(4);
}

int	is_a_space(char c)
{
	int	i;

	i = 0;
	if ((c >= 9 && c <= 13) || c == 32)
		return (1);
	return (0);
}

char	*get_map(char *arg, int fd)
{
	char	*map_line;
	char	*str;
	int		i;

	i = 0;
	check_map_name(arg);
	str = ft_calloc(1, 1);
	fd = open(arg, O_RDONLY);
	if (fd < 0)
		errors(9);
	map_line = get_next_line(fd);
	while (map_line)
	{
		str = join_strings(str, map_line);
		free(map_line);
		map_line = get_next_line(fd);
	}
	return (str);
}

char	*setup_map(char *str, t_map *map)
{
	int	i;

	i = 0;
	init_stuff(map);
	if (!str || !str[0])
		errors(8);
	while (*str)
	{
		north_south_textures(str, map);
		east_west_textures(str, map);
		floor_ceiling_textures(str, map);
		str += char_pos(str, '\n');
		if (map->utils.flag == 6)
			break ;
		str++;
	}
	if (!str[0])
		errors(5);
	while (*str == '\n')
		str++;
	(check_map_textures(map), check_map_content(str));
	map->real_map = ft_split(str, '\n');
	check_map_walls(map->real_map);
	check_map_content_help(map->real_map);
	return (str);
}
