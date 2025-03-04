/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_moves.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbastard <jbastard@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-02-11 07:44:16 by jbastard          #+#    #+#             */
/*   Updated: 2025-02-11 07:44:16 by jbastard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	were_is_player(t_solong *solong)
{
	char	playerpos;

	playerpos = solong->map[solong->pposy][solong->pposx];
	if (playerpos == 'C')
	{
		solong->collectibles -= 1;
		solong->map[solong->pposy][solong->pposx] = '0';
		if (solong->mapwidth >= 6)
			update_collectibles_count(solong);
	}
	if (solong->collectibles == 0)
		mlx_put_image_to_window(solong->mlx, solong->win,
			solong->door[1], solong->eposx * SIZE, solong->eposy * SIZE);
	if (playerpos == 'E' && 0 == solong->collectibles)
	{
		solong->end = 1;
		mlx_put_image_to_window(solong->mlx, solong->win,
			solong->door[2], solong->eposx * SIZE, solong->eposy * SIZE);
		end_of_game(solong);
	}
	if (playerpos == 'M')
	{
		solong->end = 0;
		end_of_game(solong);
	}
}

void	end_of_game(t_solong *solong)
{
	if (solong->mapwidth < 10)
		put_banner(solong, solong->tendbanner,
			(solong->mapwidth / 2 - 2) * SIZE,
			solong->mapheight / 2 * SIZE);
	else
		put_banner(solong, solong->endbanner,
			(solong->mapwidth / 2 - 2) * SIZE,
			solong->mapheight * SIZE + SIZE / 2);
}
