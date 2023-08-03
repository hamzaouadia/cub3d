/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_utils_helper.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smounafi <smounafi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 10:07:49 by smounafi          #+#    #+#             */
/*   Updated: 2023/07/26 10:09:19 by smounafi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	ft_y_texture(t_map *t)
{
	if (t->side == 'e')
		t->y_texture += t->ea_texture.height / t->wall;
	if (t->side == 'w')
		t->y_texture += t->we_texture.height / t->wall;
	if (t->side == 'n')
		t->y_texture += t->no_texture.height / t->wall;
	if (t->side == 's')
		t->y_texture += t->so_texture.height / t->wall;
}

char	get_player_direction(char **str)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	while (str[i])
	{
		j = 0;
		while (str[i][j])
		{
			if (str[i][j] == 'N' || str[i][j] == 'E' || str[i][j] == 'S'
				|| str[i][j] == 'W')
				return (str[i][j]);
			j++;
		}
		i++;
	}
	return (str[i][j]);
}

int	get_player_y(char **str)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	while (str[i])
	{
		j = 0;
		while (str[i][j])
		{
			if (str[i][j] == 'N' || str[i][j] == 'E' || str[i][j] == 'S'
				|| str[i][j] == 'W')
				return (i);
			j++;
		}
		i++;
	}
	return (i);
}

int	get_player_x(char **str)
{
	int	i;
	int	j;

	i = 1;
	while (str[i])
	{
		j = 0;
		while (str[i][j])
		{
			if (str[i][j] == 'N' || str[i][j] == 'E' || str[i][j] == 'S'
				|| str[i][j] == 'W')
				return (j);
			j++;
		}
		i++;
	}
	return (j);
}
