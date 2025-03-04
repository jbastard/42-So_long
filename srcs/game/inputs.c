/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inputs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbastard <jbastard@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-02-11 07:34:50 by jbastard          #+#    #+#             */
/*   Updated: 2025-02-11 07:34:50 by jbastard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

int	hook_handler(int keycode, t_solong	*solong)
{
	if (solong->end == 2 && ((keycode == WKEY || keycode == AKEY
				|| keycode == SKEY || keycode == DKEY)
			|| (keycode == LEFTARROW || keycode == UPARROW
				|| keycode == RIGHTARROW || keycode == DOWNARROW)))
		player_mov(solong, keycode);
	if (keycode == ESCKEY)
		close_window(solong);
	return (0);
}

void	claim_hook(t_solong	*solong)
{
	mlx_hook(solong->win, 17, 0, close_window, solong);
	mlx_hook(solong->win, 2, 1L << 0, hook_handler, solong);
	mlx_loop_hook(solong->mlx, animate, solong);
}
