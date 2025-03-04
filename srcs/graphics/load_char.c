/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_char.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbastard <jbastard@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-02-11 08:04:50 by jbastard          #+#    #+#             */
/*   Updated: 2025-02-11 08:04:50 by jbastard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	load_minos_ir(t_solong *solong)
{
	int		i;
	char	*textures[4];

	i = 0;
	textures[0] = "./textures/minos/minos_ir0.xpm";
	textures[1] = "./textures/minos/minos_ir1.xpm";
	textures[2] = "./textures/minos/minos_ir2.xpm";
	textures[3] = "./textures/minos/minos_ir3.xpm";
	while (i < 4)
	{
		solong->minos_ir[i] = mlx_xpm_file_to_image(solong->mlx,
				textures[i], (int []){0}, (int []){0});
		if (!solong->minos_ir[i])
			data_free(solong, "Unable to load minos_ir");
		i++;
	}
}

void	load_minos_il(t_solong *solong)
{
	int		i;
	char	*textures[4];

	i = 0;
	textures[0] = "./textures/minos/minos_il0.xpm";
	textures[1] = "./textures/minos/minos_il1.xpm";
	textures[2] = "./textures/minos/minos_il2.xpm";
	textures[3] = "./textures/minos/minos_il3.xpm";
	while (i < 4)
	{
		solong->minos_il[i] = mlx_xpm_file_to_image(solong->mlx,
				textures[i], (int []){0}, (int []){0});
		if (!solong->minos_il[i])
			data_free(solong, "Unable to load minos_il");
		i++;
	}
}

void	load_attack(t_solong *solong)
{
	int		i;
	char	*textures[8];

	i = 0;
	textures[0] = "./textures/minos/attack0.xpm";
	textures[1] = "./textures/minos/attack1.xpm";
	textures[2] = "./textures/minos/attack2.xpm";
	textures[3] = "./textures/minos/attack3.xpm";
	textures[4] = "./textures/minos/attack4.xpm";
	textures[5] = "./textures/minos/attack5.xpm";
	textures[6] = "./textures/minos/attack6.xpm";
	textures[7] = "./textures/minos/attack7.xpm";
	while (i < 8)
	{
		solong->minos_attack[i] = mlx_xpm_file_to_image(solong->mlx,
				textures[i], (int []){0}, (int []){0});
		if (!solong->minos_attack[i])
			data_free(solong, "Unable to load minos_attack");
		i++;
	}
}

void	load_player_idle(t_solong *solong)
{
	int		i;
	char	*p_idle[4];

	i = 0;
	p_idle[0] = "./textures/p/p_idle_s.xpm";
	p_idle[1] = "./textures/p/p_idle_n.xpm";
	p_idle[2] = "./textures/p/p_idle_e.xpm";
	p_idle[3] = "./textures/p/p_idle_w.xpm";
	while (i < 4)
	{
		solong->playeridle[i] = mlx_xpm_file_to_image(solong->mlx,
				p_idle[i], (int []){0}, (int []){0});
		if (!solong->playeridle[i])
			data_free(solong, "Unable to load player_idle");
		i++;
	}
}
