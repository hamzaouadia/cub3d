/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures_checks.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smounafi <smounafi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 12:47:14 by smounafi          #+#    #+#             */
/*   Updated: 2023/07/29 18:01:19 by smounafi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

int	char_pos(char *str, char c)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (i);
		i++;
	}
	return (0);
}

char	*path_extracter(char *str)
{
	while (!is_a_space(*str))
		str++;
	while (is_a_space(*str))
		str++;
	return (ft_substr(str, 0, char_pos(str, '\n')));
}

void	north_south_textures(char *str, t_map *map)
{
	if (ft_strncmp(str, NORTH_TEXTURE, 3) == 0 && map->utils.no == 0)
	{
		map->no = path_extracter(str);
		map->utils.no++;
		map->utils.flag++;
	}
	if (ft_strncmp(str, SOUTH_TEXTURE, 3) == 0 && map->utils.so == 0)
	{
		map->so = path_extracter(str);
		map->utils.so++;
		map->utils.flag++;
	}
}

void	east_west_textures(char *str, t_map *map)
{
	if (ft_strncmp(str, WEST_TEXTURE, 3) == 0)
	{
		map->we = path_extracter(str);
		map->utils.we++;
		map->utils.flag++;
	}
	if (ft_strncmp(str, EAST_TEXTURE, 3) == 0)
	{
		map->ea = path_extracter(str);
		map->utils.ea++;
		map->utils.flag++;
	}
}

void	floor_ceiling_textures(char *str, t_map *map)
{
	map->p = path_extracter(str);
	if (ft_strncmp(str, FLOOR, 2) == 0)
	{
		map->rgb = ft_split(map->p, ',');
		extraction(map, map->rgb, 'f');
		free_split(map->rgb);
	}
	if (ft_strncmp(str, CEILLING, 2) == 0)
	{
		map->rgb = ft_split(map->p, ',');
		extraction(map, map->rgb, 'c');
		free_split(map->rgb);
	}
	free(map->p);
}
