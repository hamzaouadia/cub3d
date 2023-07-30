/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smounafi <smounafi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 02:47:26 by smounafi          #+#    #+#             */
/*   Updated: 2022/10/27 04:37:53 by smounafi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

char	*ft_strdup(const char *s1)
{
	char	*ptr_s1;
	char	*ptr;
	int		i;
	int		len;

	ptr_s1 = (char *)s1;
	i = 0;
	len = ft_strlen(s1);
	ptr = (char *)malloc(len + 1);
	if (!ptr)
		return (0);
	while (ptr_s1[i] && i < len)
	{
		ptr[i] = ptr_s1[i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}
