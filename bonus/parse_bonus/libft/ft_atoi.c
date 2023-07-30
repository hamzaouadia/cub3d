/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smounafi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 01:13:12 by smounafi          #+#    #+#             */
/*   Updated: 2022/10/25 04:08:05 by smounafi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"
#include <limits.h>

int	ft_atoi(const char *str)
{
	size_t					i;
	int						sign;
	unsigned long long		op;

	i = 0;
	sign = 1;
	op = 0;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-')
		sign *= -1;
	if (str[i] == '-' || str[i] == '+')
	i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		op = op * 10 + (str[i] - '0');
		if (op > LONG_MAX && sign > 0)
			return (-1);
		if (op > LONG_MAX && sign < 0)
			return (0);
		i++;
	}
	return (op * sign);
}
