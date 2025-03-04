/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_sprites_ui.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbastard <jbastard@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-02-11 07:54:20 by jbastard          #+#    #+#             */
/*   Updated: 2025-02-11 07:54:20 by jbastard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	load_end_banner(t_solong	*solong)
{
	int		i;
	char	*texture[6];

	i = 0;
	texture[0] = "./textures/ui/left_banner.xpm";
	texture[1] = "./textures/ui/right_banner.xpm";
	texture[2] = "./textures/ui/youWin0.xpm";
	texture[3] = "./textures/ui/youWin1.xpm";
	texture[4] = "./textures/ui/youLoose0.xpm";
	texture[5] = "./textures/ui/youLoose1.xpm";
	while (i < 6)
	{
		solong->endbanner[i] = mlx_xpm_file_to_image(solong->mlx,
				texture[i], (int []){0}, (int []){0});
		if (!solong->endbanner[i])
			data_free(solong, "Unable to load endBanner");
		i++;
	}
}

void	load_ground_end_banner(t_solong	*solong)
{
	int		i;
	char	*texture[6];

	i = 0;
	texture[0] = "./textures/ui/tleft_banner.xpm";
	texture[1] = "./textures/ui/tright_banner.xpm";
	texture[2] = "./textures/ui/tyouWin0.xpm";
	texture[3] = "./textures/ui/tyouWin1.xpm";
	texture[4] = "./textures/ui/tyouLoose0.xpm";
	texture[5] = "./textures/ui/tyouLoose1.xpm";
	while (i < 6)
	{
		solong->tendbanner[i] = mlx_xpm_file_to_image(solong->mlx,
				texture[i], (int []){0}, (int []){0});
		if (!solong->tendbanner[i])
			data_free(solong, "Unable to load tendBanner");
		i++;
	}
}

void	load_count(t_solong	*solong)
{
	int		i;
	char	*texture[12];

	i = 0;
	texture[0] = "./textures/ui/downTab0.xpm";
	texture[1] = "./textures/ui/downTab1.xpm";
	texture[2] = "./textures/ui/downTab2.xpm";
	texture[3] = "./textures/ui/downTab3.xpm";
	texture[4] = "./textures/ui/downTab4.xpm";
	texture[5] = "./textures/ui/downTab5.xpm";
	texture[6] = "./textures/ui/upChicken2.xpm";
	texture[7] = "./textures/ui/upChicken1.xpm";
	texture[8] = "./textures/ui/upChicken0.xpm";
	texture[9] = "./textures/ui/upMove0.xpm";
	texture[10] = "./textures/ui/upMove1.xpm";
	texture[11] = "./textures/ui/upMove2.xpm";
	while (i < 12)
	{
		solong->downcount[i] = mlx_xpm_file_to_image(solong->mlx,
				texture[i], (int []){0}, (int []){0});
		if (!solong->downcount[i])
			data_free(solong, "Unable to load endBanner");
		i++;
	}
}

void	load_num(t_solong	*solong)
{
	int		i;
	char	*texture[11];

	i = 0;
	texture[0] = "./textures/n/num0.xpm";
	texture[1] = "./textures/n/num1.xpm";
	texture[2] = "./textures/n/num2.xpm";
	texture[3] = "./textures/n/num3.xpm";
	texture[4] = "./textures/n/num4.xpm";
	texture[5] = "./textures/n/num5.xpm";
	texture[6] = "./textures/n/num6.xpm";
	texture[7] = "./textures/n/num7.xpm";
	texture[8] = "./textures/n/num8.xpm";
	texture[9] = "./textures/n/num9.xpm";
	texture[10] = "./textures/n/bar.xpm";
	while (i < 11)
	{
		solong->num[i] = mlx_xpm_file_to_image(solong->mlx,
				texture[i], (int []){0}, (int []){0});
		if (!solong->num[i])
			data_free(solong, "Unable to load Numbers");
		i++;
	}
}
