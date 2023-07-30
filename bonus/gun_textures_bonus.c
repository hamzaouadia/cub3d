/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gun_textures.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smounafi <smounafi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 17:21:18 by smounafi          #+#    #+#             */
/*   Updated: 2023/07/29 17:21:21 by smounafi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_bonus.h"

void	gun_textures(t_texture *gun, t_window *mlx)
{
	char	*textur;
	char	*name;
	char	*nbr;
	int		i;
	int		j;

	i = -1;
	j = 1;
	while (++i < 25)
	{
		nbr = ft_itoa(j);
		name = ft_strjoin("./bonus/maps_bonus/gun/gun", nbr);
		textur = ft_strjoin(name, ".xpm");
		free(nbr);
		free(name);
		gun[i].data.img = mlx_xpm_file_to_image(mlx->mlx, textur,
				&gun[i].width, &gun[i].height);
		free(textur);
		if (i % 2 == 0)
			j++;
	}
}
