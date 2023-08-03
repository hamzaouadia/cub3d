/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures_checks.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smounafi <smounafi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 12:47:14 by smounafi          #+#    #+#             */
/*   Updated: 2023/08/01 18:48:27 by smounafi         ###   ########.fr       */
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
	if (ft_strncmp(str, NORTH_TEXTURE, 3) == 0)
	{
		map->no = path_extracter(str);
		check_texture_name(map->no);
		map->utils.no++;
		map->utils.flag++;
	}
	if (ft_strncmp(str, SOUTH_TEXTURE, 3) == 0)
	{
		map->so = path_extracter(str);
		check_texture_name(map->so);
		map->utils.so++;
		map->utils.flag++;
	}
}

void	east_west_textures(char *str, t_map *map)
{
	if (ft_strncmp(str, WEST_TEXTURE, 3) == 0)
	{
		map->we = path_extracter(str);
		check_texture_name(map->we);
		map->utils.we++;
		map->utils.flag++;
	}
	if (ft_strncmp(str, EAST_TEXTURE, 3) == 0)
	{
		map->ea = path_extracter(str);
		check_texture_name(map->ea);
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
		if (ft_strncmp(map->rgb[0], "C", 1) == 0)
			errors(11);
		if (double_len(map->rgb) != 3 || comma_counter(map->p) != 2
			|| not_null_termin(map->rgb) || dbl_size_each(map->rgb)
			|| all_digits(map->rgb))
			errors_help(0);
		extraction(map, map->rgb, 'f');
		free_split(map->rgb);
	}
	if (ft_strncmp(str, CEILLING, 2) == 0)
	{
		map->rgb = ft_split(map->p, ',');
		if (double_len(map->rgb) != 3 || comma_counter(map->p) != 2
			|| not_null_termin(map->rgb) || dbl_size_each(map->rgb)
			|| all_digits(map->rgb))
			errors_help(0);
		extraction(map, map->rgb, 'c');
		free_split(map->rgb);
	}
	free(map->p);
}
