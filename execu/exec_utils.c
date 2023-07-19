/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smounafi <smounafi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 17:00:47 by smounafi          #+#    #+#             */
/*   Updated: 2023/06/22 18:12:01 by smounafi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../cub3D.h"

char	get_player_direction(char **str)
{
	int i;
	int j;
	i = 1;
	j = 0;
	while(str[i])
	{
        j = 0;
        while(str[i][j])
        {
		    if (str[i][j] == 'N' || str[i][j] == 'E' || str[i][j] == 'S' || str[i][j] == 'W')
                return (str[i][j]);
            j++;
        }
		i++;
	}
	return(str[i][j]);
}

int	get_player_y(char **str)
{
	int i;
	int j;
	i = 1;
	j = 0;
	while(str[i])
	{
        j = 0;
        while(str[i][j])
        {
		    if (str[i][j] == 'N' || str[i][j] == 'E' || str[i][j] == 'S' || str[i][j] == 'W')
                return (i);
            j++;
        }
		i++;
	}
	return(i);
}

int	get_player_x(char **str)
{
	int i;
	int j;
	i = 1;
	while(str[i])
	{
        j = 0;
        while(str[i][j])
        {
		    if (str[i][j] == 'N' || str[i][j] == 'E' || str[i][j] == 'S' || str[i][j] == 'W')
                return (j);
            j++;
        }
		i++;
	}
	return(j);
}

int	get_x(char **str)
{
	int i;
	size_t len;
	i = 1;
	len = ft_strlen(str[0]);
	while(str[i])
	{
		if(ft_strlen(str[i]) > len)
			len = ft_strlen(str[i]);
		i++;
	}
	return(len);
}

int	get_y(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	close_win_cross()
{
	printf("\033[0;33mYou closed the window!");
	exit(0);
}

void	exit_move(t_window window)
{
	mlx_hook(window.win, 17, 0, close_win_cross, &window);
}