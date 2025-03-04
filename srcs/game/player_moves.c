/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_moves.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbastard <jbastard@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-02-11 07:35:48 by jbastard          #+#    #+#             */
/*   Updated: 2025-02-11 07:35:48 by jbastard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	player_update(t_solong	*solong, int where)
{
	put_random_4(solong, solong->ground, solong->pposx, solong->pposy);
	if (solong->map[solong->pposy][solong->pposx] == 'E')
		mlx_put_image_to_window(solong->mlx, solong->win,
			solong->door[0], solong->pposx * SIZE, solong->pposy * SIZE);
	if (where == 0)
		solong->pposy += 1;
	if (where == 1)
		solong->pposy -= 1;
	if (where == 2)
		solong->pposx += 1;
	if (where == 3)
		solong->pposx -= 1;
	if (solong->map[solong->pposy][solong->pposx] != 'M')
		mlx_put_image_to_window(solong->mlx, solong->win,
			solong->playeridle[where],
			solong->pposx * SIZE, solong->pposy * SIZE);
	were_is_player(solong);
	solong->movecount += 1;
	update_move_count(solong);
}

void	player_mov(t_solong	*solong, int keycode)
{
	if ((keycode == SKEY || keycode == DOWNARROW)
		&& solong->pposy + 1 < solong->mapheight
		&& solong->map[solong->pposy + 1][solong->pposx] != '1')
		player_update(solong, 0);
	if ((keycode == WKEY || keycode == UPARROW) && solong->pposy - 1 >= 0
		&& solong->map[solong->pposy - 1][solong->pposx] != '1')
		player_update(solong, 1);
	if ((keycode == DKEY || keycode == RIGHTARROW)
		&& solong->pposy + 1 < solong->mapwidth
		&& solong->map[solong->pposy][solong->pposx + 1] != '1')
		player_update(solong, 2);
	if ((keycode == AKEY || keycode == LEFTARROW) && solong->pposx - 1 >= 0
		&& solong->map[solong->pposy][solong->pposx - 1] != '1')
		player_update(solong, 3);
}
