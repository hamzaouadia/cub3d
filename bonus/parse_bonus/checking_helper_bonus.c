/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checking_helper_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smounafi <smounafi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 18:22:52 by smounafi          #+#    #+#             */
/*   Updated: 2023/08/01 18:50:51 by smounafi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D_bonus.h"

int	completed_wall_bonus(char *str)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] != '1' && str[i] != 32)
			return (0);
		i++;
	}
	return (1);
}

int	comma_counter_bonus(char *str)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] == ',')
			count++;
		i++;
	}
	return (count);
}

int	only_spaces_bonus(char *str)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (is_a_space(str[i]))
			count++;
		i++;
	}
	if (count == ft_strlenn(str))
		return (1);
	return (0);
}

int	not_null_termin(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (only_spaces_bonus(str[i]))
			return (1);
		i++;
	}
	return (0);
}

int	dbl_size_each(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (ft_strlenn(str[i]) > 3)
			return (1);
		i++;
	}
	return (0);
}
