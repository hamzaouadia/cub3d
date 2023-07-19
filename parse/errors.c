/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smounafi <smounafi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 19:14:05 by smounafi          #+#    #+#             */
/*   Updated: 2023/06/21 12:35:50 by smounafi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../cub3D.h"

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

void errors_help(int i)
{
	if (i == 0)
		printf("\033[1;31m🛑ERROR: color given not valid!\n");
	exit(1);
}
