/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   content_checks.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smounafi <smounafi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 12:49:54 by smounafi          #+#    #+#             */
/*   Updated: 2023/07/26 10:21:19 by smounafi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

void	check_map_content(char *str)
{
	int		i;
	char	start_pos;
	int		count;

	count = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == 'N' || str[i] == 'E' || str[i] == 'S' || str[i] == 'W')
		{
			start_pos = str[i];
			if (count == 0)
				count++;
			else
				errors(2);
		}
		if (str[i] != '1' && str[i] != '0' && str[i] != 32 && str[i] != '\n'
			&& str[i] != start_pos)
			errors(7);
		if (str[i] == '\n' && str[i + 1] == '\n')
			errors(6);
		i++;
	}
	if (count == 0)
		errors(2);
}

void	check_map_walls(char **str)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[i])
	{
		j = 0;
		while (is_a_space(str[i][j]))
			j++;
		if (str[i][j] != '1' || str[i][ft_strlen(str[i]) - 1] != '1')
			errors(1);
		i++;
	}
}

void	check_map_textures(t_map *map)
{
	if (map->utils.no > 1 || map->utils.we > 1 || map->utils.so > 1
		|| map->utils.ea > 1 || map->utils.cc > 1 || map->utils.ff > 1)
		errors(10);
	if (open(map->no, O_RDONLY) < 0
		|| open(map->so, O_RDONLY) < 0
		|| open(map->ea, O_RDONLY) < 0
		|| open(map->we, O_RDONLY) < 0)
		errors(11);
}

size_t	zero_index(char *str)
{
	int	i;

	i = ft_strlen(str);
	while (i > 0)
	{
		if (str[i] == '0')
			return (i);
		i--;
	}
	return (-1);
}

void	check_map_content_help(char **str)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	while (str[i])
	{
		if (str[i + 1] && (zero_index(str[i]) > ft_strlen(str[i - 1])
				|| zero_index(str[i]) > ft_strlen(str[i + 1])))
			errors(0);
		j = 0;
		while (str[i][j])
		{
			if (str[i][j] == '0')
			{
				if (str[i + 1][j] == 32 || str[i - 1][j] == 32 || str[i][j
					+ 1] == 32 || str[i][j - 1] == 32)
					errors(0);
			}
			j++;
		}
		i++;
	}
}
