/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbastard <jbastard@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-02-13 08:42:04 by jbastard          #+#    #+#             */
/*   Updated: 2025-02-13 08:42:04 by jbastard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	put_monsters(t_solong *solong, int spriteIndex, char c)
{
	int			x;
	int			y;
	static int	count;

	y = 0;
	count = 1;
	while (y < solong->mapheight)
	{
		x = 0;
		while (x < solong->mapwidth)
		{
			if (solong->map[y][x] == c && count % 2 == 0)
				put_image(solong, solong->minos_ir[spriteIndex],
					x * SIZE, y * SIZE);
			if (solong->map[y][x] == c && count % 2 == 1)
				put_image(solong, solong->minos_il[spriteIndex],
					x * SIZE, y * SIZE);
			if (solong->map[y][x] == c)
				count++;
			x++;
		}
		y++;
	}
}

int	update_frame(t_solong *solong, int target_fps)
{
	struct timeval	current_time;
	long			elapsed_time;

	gettimeofday(&current_time, NULL);
	elapsed_time = (current_time.tv_sec - solong->last_frame_time.tv_sec)
		* 1000 + (current_time.tv_usec
			- solong->last_frame_time.tv_usec) / 1000;
	if (elapsed_time >= (1000 / target_fps))
	{
		solong->last_frame_time = current_time;
		return (1);
	}
	return (0);
}

void	game_loop(t_solong *solong)
{
	int	frameindexmi;
	int	frameindexma;

	frameindexmi = solong->frame_counter % 4;
	frameindexma = solong->frame_counter % 8;
	if (update_frame(solong, 8))
	{
		if (solong->end == 2)
			put_monsters(solong, frameindexmi, 'M');
		else if (solong->end == 0)
			put_image(solong, solong->minos_attack[frameindexma],
				solong->pposx * SIZE, solong->pposy * SIZE);
		solong->frame_counter++;
	}
}

int	animate(t_solong *solong)
{
	game_loop(solong);
	return (0);
}
