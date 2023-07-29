#include "cub3D.h"

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
		name = ft_strjoin("./maps/gun/gun", nbr);
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
