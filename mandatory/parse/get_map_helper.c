/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map_helper.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smounafi <smounafi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 17:40:54 by smounafi          #+#    #+#             */
/*   Updated: 2023/08/03 09:46:40 by smounafi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

char	*ft_strjoinn(char *s1, char *s2)
{
	char	*p;
	size_t	i;
	size_t	j;

	if (!s1 || !s2)
		return (NULL);
	p = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!p)
		return (NULL);
	i = -1;
	while (s1[++i])
	{
		if (i <= ft_strlen(s1))
			p[i] = s1[i];
	}
	j = -1;
	while (s2[++j])
	{
		if (i < ft_strlen(s1) + ft_strlen(s2))
			p[i] = s2[j];
		i++;
	}
	p[i] = '\0';
	free(s1);
	return (p);
}

int	highest_len(char **str)
{
	int	i;
	int	len;
	int	len2;

	i = 1;
	len = ft_strlenn(str[0]);
	len2 = 0;
	while (str[i])
	{
		if (ft_strlenn(str[i]) > len)
			len2 = ft_strlenn(str[i]);
		i++;
	}
	return (len2);
}

char	*add_space(int size)
{
	char	*s;
	int		i;

	i = 0;
	if (size < 0)
		return (NULL);
	s = malloc(size + 1);
	while (i < size)
	{
		s[i] = 32;
		i++;
	}
	s[i] = '\0';
	return (s);
}
