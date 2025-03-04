/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_ui.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbastard <jbastard@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-02-11 07:41:10 by jbastard          #+#    #+#             */
/*   Updated: 2025-02-11 07:41:10 by jbastard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	update_collectibles_count(t_solong *solong)
{
	static int	collectible;
	int			total_collectibles;

	collectible += 1;
	total_collectibles = collectible + solong->collectibles;
	put_image(solong, solong->num[collectible % 10],
		(solong->mapwidth - 2) * SIZE, (solong->mapheight + 1) * SIZE - 10);
	if (collectible > 9)
		put_image(solong, solong->num[collectible / 10 % 10],
			(solong->mapwidth - 2) * SIZE - 30,
			(solong->mapheight + 1) * SIZE - 10);
}

void	update_move_count(t_solong	*solong)
{
	put_image(solong, solong->num[solong->movecount % 10],
		2 * SIZE, (solong->mapheight + 1) * SIZE - 10);
	if (solong->movecount > 9)
		put_image(solong, solong->num[solong->movecount / 10 % 10],
			2 * SIZE - 30, (solong->mapheight + 1) * SIZE - 10);
	if (solong->movecount > 99)
		put_image(solong, solong->num[solong->movecount / 100 % 10],
			2 * SIZE - 60, (solong->mapheight + 1) * SIZE - 10);
	if (solong->movecount > 999)
		put_image(solong, solong->num[solong->movecount / 10000 % 10],
			1 * SIZE + 28, (solong->mapheight + 1) * SIZE - 10);
}

void	display_move_count(t_solong *solong, int x, int y)
{
	int	i;

	i = 3;
	while (--i >= 0)
	{
		put_image(solong, solong->downcount[i],
			(x + i) * SIZE, (y - 1) * SIZE);
		put_image(solong, solong->downcount[i + 9],
			(x + i) * SIZE, (y - 2) * SIZE);
		if (solong->mapwidth < 6)
			put_image(solong, solong->water[1],
				(solong->mapwidth - 1) * SIZE, (y - 2) * SIZE);
	}
	put_image(solong, solong->num[solong->movecount % 10],
		2 * SIZE, (solong->mapheight + 1) * SIZE - 10);
}

void	display_count(t_solong *solong, int x, int y)
{
	int	i;

	display_move_count(solong, 0, y);
	i = 3;
	x = solong->mapwidth - 1;
	if (solong->mapwidth < 6)
		return ;
	while (--i >= 0)
	{
		put_image(solong, solong->downcount[i + 3],
			(x - i) * SIZE, (y - 1) * SIZE);
		put_image(solong, solong->downcount[i + 6],
			(x - i) * SIZE, (y - 2) * SIZE);
	}
	put_image(solong, solong->num[solong->collectibles % 10],
		(solong->mapwidth - 1) * SIZE + 10, (solong->mapheight + 1)
		* SIZE - 10);
	if (solong->collectibles > 9)
		put_image(solong, solong->num[solong->collectibles / 10 % 10],
			(solong->mapwidth - 1) * SIZE - 20,
			(solong->mapheight + 1) * SIZE - 10);
	put_image(solong, solong->num[10], (solong->mapwidth - 1)
		* SIZE - 35, (solong->mapheight + 1) * SIZE - 10);
}

void	put_banner(t_solong *solong, void **texture, int x, int y)
{
	int	temp;

	temp = 0;
	if (solong->mapwidth % 2)
		temp = SIZE / 2;
	put_image(solong, texture[0], x + temp, y);
	put_image(solong, texture[1], x + 3 * SIZE + temp, y);
	if (solong->end == 1)
	{
		put_image(solong, texture[2], x + 1 * SIZE + temp, y);
		put_image(solong, texture[3], x + 2 * SIZE + temp, y);
	}
	else if (solong->end == 0)
	{
		put_image(solong, texture[4], x + 1 * SIZE + temp, y);
		put_image(solong, texture[5], x + 2 * SIZE + temp, y);
	}
}
