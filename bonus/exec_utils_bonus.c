/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smounafi <smounafi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 17:00:47 by smounafi          #+#    #+#             */
/*   Updated: 2023/07/26 10:08:13 by smounafi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_bonus.h"

int	get_x(char **str)
{
	int		i;
	size_t	len;

	i = 1;
	len = ft_strlen(str[0]);
	while (str[i])
	{
		if (ft_strlen(str[i]) > len)
			len = ft_strlen(str[i]);
		i++;
	}
	return (len);
}

int	get_y(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	close_win_cross(void)
{
	printf("\033[0;33mYou closed the window!");
	exit(0);
}

void	exit_move(t_window window)
{
	mlx_hook(window.win, 17, 0, close_win_cross, &window);
}
