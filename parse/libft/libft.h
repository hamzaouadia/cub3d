/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smounafi <smounafi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 17:20:11 by smounafi          #+#    #+#             */
/*   Updated: 2023/06/14 17:45:38 by smounafi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

size_t	ft_strlen(const char *s);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int	    ft_strcmp(char *s1, char *s2);
int		ft_atoi(const char *str);
void	*ft_calloc(size_t count, size_t size);
char	*ft_strdup(const char *s1);
char	*ft_substr(char const *s, unsigned int start, size_t len);
int		ft_atoi(const char *str);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_itoa(int n);
char	**ft_split(char *s, char c);
int     ft_isalnum(int c);
int     ft_isalpha(int c);
int     ft_isdigit(int c);
#endif
