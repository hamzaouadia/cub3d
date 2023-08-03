/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures_checks_helper.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smounafi <smounafi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 18:01:41 by smounafi          #+#    #+#             */
/*   Updated: 2023/07/30 17:08:07 by smounafi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

void	free_split(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

void	extraction(t_map *map, char **str, char alphabet)
{
	if ((ft_atoi(str[0]) >= BUFF_SIZE || ft_atoi(str[0]) < 0)
		|| (ft_atoi(str[1]) >= BUFF_SIZE || ft_atoi(str[1]) < 0)
		|| (ft_atoi(str[2]) >= BUFF_SIZE || ft_atoi(str[2]) < 0))
		errors_help(0);
	if (alphabet == 'f')
	{
		map->f = (ft_atoi(str[0]) * 65536) + (ft_atoi(str[1]) * 256)
			+ ft_atoi(str[2]);
		map->utils.ff++;
	}
	else if (alphabet == 'c')
	{
		map->c = (ft_atoi(str[0]) * 65536) + (ft_atoi(str[1]) * 256)
			+ ft_atoi(str[2]);
		map->utils.cc++;
	}
	map->utils.flag++;
}

int	double_len(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	check_texture_name(char *str)
{
	int		i;
	char	*s;

	i = 0;
	i = ft_strlen(str);
	s = ft_substr(str, i - 4, 4);
	if (str)
	{
		if (ft_strncmp(s, ".xpm", 4))
			errors(11);
	}
	else
		errors(11);
	free(s);
}
