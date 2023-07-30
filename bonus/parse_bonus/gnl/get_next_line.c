/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smounafi <smounafi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 23:56:03 by smounafi          #+#    #+#             */
/*   Updated: 2023/06/13 18:06:25 by smounafi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_readfile(int fd, char *static_stocker)
{
	char	*readed_line;
	int		n_readed;

	if (!static_stocker)
		static_stocker = alloc_me(1, 1);
	n_readed = 1;
	readed_line = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!readed_line)
		return (NULL);
	while (!find_me(static_stocker, '\n') && n_readed != 0)
	{
		n_readed = read(fd, readed_line, BUFFER_SIZE);
		if (n_readed == -1)
		{
			free(readed_line);
			free(static_stocker);
			return (NULL);
		}
		readed_line[n_readed] = '\0';
		static_stocker = join_strings(static_stocker, readed_line);
	}
	free(readed_line);
	return (static_stocker);
}

char	*ft_line(char *static_stocker)
{
	char	*line;
	int		i;

	i = 0;
	if (!static_stocker[i])
		return (NULL);
	while (static_stocker[i] && static_stocker[i] != '\n')
		i++;
	line = (char *)malloc((sizeof(char) * i + 2));
	if (!line)
		return (NULL);
	i = 0;
	while (static_stocker[i] && static_stocker[i] != '\n')
	{
		line[i] = static_stocker[i];
		i++;
	}
	if (static_stocker[i] == '\n')
	{
		line[i] = static_stocker[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*ft_nextline(char *static_stocker)
{
	char	*line;
	int		i;
	int		j;

	i = 0;
	while (static_stocker[i] && static_stocker[i] != '\n')
		i++;
	if (!static_stocker[i])
	{
		free(static_stocker);
		return (NULL);
	}
	line = (char *)malloc(sizeof(char) * (my_len(static_stocker) - i + 1));
	if (!line)
		return (NULL);
	j = 0;
	i++;
	while (static_stocker[i])
	{
		line[j++] = static_stocker[i++];
	}
	free(static_stocker);
	line[j] = '\0';
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*static_stocker;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	static_stocker = ft_readfile(fd, static_stocker);
	if (!static_stocker)
		return (NULL);
	line = ft_line(static_stocker);
	static_stocker = ft_nextline(static_stocker);
	return (line);
}
