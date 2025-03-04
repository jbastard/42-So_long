/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbastard <jbastard@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-02-11 08:08:55 by jbastard          #+#    #+#             */
/*   Updated: 2025-02-11 08:08:55 by jbastard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	destroy_image_iterate(t_solong *solong, void **images, int count)
{
	int	i;

	i = 0;
	while (i < count)
	{
		if (images[i])
			mlx_destroy_image(solong->mlx, images[i]);
		i++;
	}
}

void	free_textures(t_solong *solong)
{
	destroy_image_iterate(solong, solong->door, 3);
	destroy_image_iterate(solong, solong->ground, 4);
	destroy_image_iterate(solong, solong->border, 4);
	destroy_image_iterate(solong, solong->corner, 4);
	destroy_image_iterate(solong, solong->ruins, 4);
	destroy_image_iterate(solong, solong->water, 2);
	destroy_image_iterate(solong, solong->minos_ir, 4);
	destroy_image_iterate(solong, solong->minos_il, 4);
	destroy_image_iterate(solong, solong->minos_attack, 8);
	destroy_image_iterate(solong, solong->playeridle, 4);
	destroy_image_iterate(solong, solong->endbanner, 6);
	destroy_image_iterate(solong, solong->tendbanner, 6);
	destroy_image_iterate(solong, solong->num, 11);
	destroy_image_iterate(solong, solong->downcount, 12);
	destroy_image_iterate(solong, solong->comestibles, 2);
}

void	free_map(char **str, int bexit)
{
	int		i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
	if (bexit == 1)
		exit(1);
}

void	data_free(t_solong	*solong, char *error)
{
	if (solong->map)
		free_map(solong->map, 0);
	if (ft_strncmp(error, "Error: Map Empty", 9))
		free_textures(solong);
	if (solong->win)
		mlx_destroy_window(solong->mlx, solong->win);
	if (solong->mlx)
	{
		mlx_destroy_display(solong->mlx);
		free(solong->mlx);
	}
	if (error[0] && ft_strncmp(error, "Error: Map Empty", 9))
		perror(error);
	else
		ft_printf("%s", error);
	exit(1);
}

int	close_window(t_solong *solong)
{
	data_free(solong, "");
	exit(0);
}
