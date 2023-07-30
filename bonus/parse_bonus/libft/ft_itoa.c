/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smounafi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 02:40:51 by smounafi          #+#    #+#             */
/*   Updated: 2022/10/20 18:50:21 by smounafi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	n_len(int n)
{
	long int	x;
	int			i;

	x = (long int)n;
	i = 0;
	if (x == 0)
	{
		return (1);
	}
	if (x < 0)
	{
		x *= -1;
		i++;
	}
	while (x > 0)
	{
		x = x / 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	long int	i;
	int			len;
	char		*p;

	i = (long int)n;
	len = n_len(n);
	p = (char *)malloc(len + 1);
	if (!p)
		return (NULL);
	p[len] = '\0';
	if (i == 0)
		p[0] = '0';
	if (i < 0)
	{
		p[0] = '-';
		i *= -1;
	}
	while (i > 0)
	{
		p[len - 1] = i % 10 + '0';
		i = i / 10;
		len--;
	}
	return (p);
}
