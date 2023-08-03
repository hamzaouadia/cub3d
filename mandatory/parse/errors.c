/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smounafi <smounafi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 19:14:05 by smounafi          #+#    #+#             */
/*   Updated: 2023/08/03 09:44:29 by smounafi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

void	errors(int i)
{
	if (i == 0)
		printf("\033[1;31m🛑ERROR: map components error!\n");
	if (i == 1)
		printf("\033[1;31m🛑ERROR: uncompleted wall!\n");
	else if (i == 2)
		printf("\033[1;31m🛑ERROR: unavailable/duplicated start position!\n");
	else if (i == 3)
		printf("\033[1;31m🛑ERROR: invalid/missing map name!\n");
	else if (i == 4)
		printf("\033[1;31m🛑ERROR: Invalid/missing arg!\n");
	else if (i == 5)
		printf("\033[1;31m🛑ERROR: invalid/missing path(s)!\n");
	else if (i == 6)
		printf("\033[1;31m🛑ERROR: new line found!\n");
	else if (i == 7)
		printf("\033[1;31m🛑ERROR: different character found!\n");
	else if (i == 8)
		printf("\033[1;31m🛑ERROR: empty map!\n");
	else if (i == 9)
		printf("\033[1;31m🛑ERROR: fd error!\n");
	else if (i == 10)
		printf("\033[1;31m🛑ERROR: duplicated path!\n");
	else if (i == 11)
		printf("\033[1;31m🛑ERROR: unable to find texture!\n");
	exit(1);
}

void	errors_help(int i)
{
	if (i == 0)
		printf("\033[1;31m🛑ERROR: color given not valid!\n");
	exit(1);
}

int	ft_strlenn(const char *s)
{
	int	i;

	i = 0;
	while (s && s[i])
		i++;
	return (i);
}

int	all_digits(char **str)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[i])
	{
		j = 0;
		while (str[i][j])
		{
			if (!ft_isdigit(str[i][j]))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int valid_start_pos(char c)
{
	if(c == '0' || c == 'N' || c == 'E' || c == 'S' || c == 'W')
		return(1);
	return(0);
}
