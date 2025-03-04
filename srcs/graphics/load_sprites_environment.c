/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_sprites_environment.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbastard <jbastard@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-02-11 07:47:56 by jbastard          #+#    #+#             */
/*   Updated: 2025-02-11 07:47:56 by jbastard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	load_water(t_solong *solong)
{
	int		i;
	char	*water[2];
	char	*door[3];

	i = 0;
	water[0] = "./textures/t/water0.xpm";
	water[1] = "./textures/t/water1.xpm";
	door[0] = "./textures/t/door0.xpm";
	door[1] = "./textures/t/door1.xpm";
	door[2] = "./textures/t/door2.xpm";
	while (i < 2)
	{
		solong->water[i] = mlx_xpm_file_to_image(solong->mlx,
				water[i], (int []){0}, (int []){0});
		solong->door[i] = mlx_xpm_file_to_image(solong->mlx,
				door[i], (int []){0}, (int []){0});
		if (!solong->water[i] || !solong->door[i])
			data_free(solong, "Unable to load water / door");
		i++;
	}
	solong->door[i] = mlx_xpm_file_to_image(solong->mlx,
			door[i], (int []){0}, (int []){0});
	if (!solong->door[i])
		data_free(solong, "Unable to load door");
}

void	load_environment(t_solong *solong)
{
	int		i;
	char	*ruins[4];

	i = 0;
	ruins[0] = "./textures/t/obstacle0.xpm";
	ruins[1] = "./textures/t/obstacle1.xpm";
	ruins[2] = "./textures/t/obstacle2.xpm";
	ruins[3] = "./textures/t/obstacle3.xpm";
	solong->comestibles[0] = mlx_xpm_file_to_image(solong->mlx,
			"./textures/p/comestible0.xpm", (int []){0}, (int []){0});
	solong->comestibles[1] = mlx_xpm_file_to_image(solong->mlx,
			"./textures/p/comestible1.xpm", (int []){0}, (int []){0});
	if (!solong->comestibles[0] || !solong->comestibles[1])
		data_free(solong, "Unable to load fried_chicken");
	while (i < 4)
	{
		solong->ruins[i] = mlx_xpm_file_to_image(solong->mlx,
				ruins[i], (int []){0}, (int []){0});
		if (!solong->ruins[i])
			data_free(solong, "Unable to load ruins");
		i++;
	}
}

void	load_border(t_solong *solong)
{
	int		i;
	char	*border[4];

	i = 0;
	border[0] = "./textures/t/up_border.xpm";
	border[1] = "./textures/t/right_border.xpm";
	border[2] = "./textures/t/left_border.xpm";
	border[3] = "./textures/t/down_border.xpm";
	while (i < 4)
	{
		solong->border[i] = mlx_xpm_file_to_image(solong->mlx,
				border[i], (int []){0}, (int []){0});
		if (!solong->border[i])
			data_free(solong, "Unable to load Border");
		i++;
	}
}

void	load_corner(t_solong *solong)
{
	int		i;
	char	*corner[4];

	i = 0;
	corner[0] = "./textures/t/up_left_corner.xpm";
	corner[1] = "./textures/t/up_right_corner.xpm";
	corner[2] = "./textures/t/down_right_corner.xpm";
	corner[3] = "./textures/t/down_left_corner.xpm";
	while (i < 4)
	{
		solong->corner[i] = mlx_xpm_file_to_image(solong->mlx,
				corner[i], (int []){0}, (int []){0});
		if (!solong->corner[i])
			data_free(solong, "Unable to load Corner");
		i++;
	}
}

void	load_ground(t_solong *solong)
{
	int		i;
	char	*grounds[4];

	i = 0;
	grounds[0] = "./textures/t/ground0.xpm";
	grounds[1] = "./textures/t/ground1.xpm";
	grounds[2] = "./textures/t/ground2.xpm";
	grounds[3] = "./textures/t/ground3.xpm";
	while (i < 4)
	{
		solong->ground[i] = mlx_xpm_file_to_image(solong->mlx,
				grounds[i], (int []){0}, (int []){0});
		if (!solong->ground[i])
			data_free(solong, "Unable to load ground");
		i++;
	}
}
