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

#include "cub3D_bonus.h"

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
