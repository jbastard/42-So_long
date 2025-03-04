/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbastard <jbastard@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-02-11 07:40:05 by jbastard          #+#    #+#             */
/*   Updated: 2025-02-11 07:40:05 by jbastard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	fill_down_water(t_solong *solong)
{
	int	x;
	int	y;

	x = solong->mapwidth;
	y = solong->mapheight;
	while (x >= 0)
	{
		put_image(solong, solong->water[0], x * 64, (y) * 64);
		put_image(solong, solong->water[1], x * 64, (y + 1) * 64);
		x--;
	}
}

void	put_random_4(t_solong	*solong, void	*img_ptr[4], int x, int y)
{
	int	texture_index;

	if (y != 0 && x != 0
		&& x != solong->mapwidth - 1
		&& y != solong->mapheight - 1)
	{
		texture_index = rand() % 3;
		mlx_put_image_to_window(solong->mlx, solong->win,
			img_ptr[texture_index], x * SIZE, y * SIZE);
	}
}

void	wich_one(t_solong	*solong, int x, int y)
{
	if (y == 0 && x == 0)
		mlx_put_image_to_window(solong->mlx, solong->win,
			solong->corner[0], x * SIZE, y * SIZE);
	else if (y == 0 && x != 0 && x != solong->mapwidth - 1)
		mlx_put_image_to_window(solong->mlx, solong->win,
			solong->border[0], x * SIZE, y * SIZE);
	else if (y == 0 && x == solong->mapwidth - 1)
		mlx_put_image_to_window(solong->mlx, solong->win,
			solong->corner[1], x * SIZE, y * SIZE);
	else if (y != solong->mapheight - 1 && y != 0 && x == solong->mapwidth - 1)
		mlx_put_image_to_window(solong->mlx, solong->win,
			solong->border[1], x * SIZE, y * SIZE);
	else if (y == solong->mapheight - 1 && x == solong->mapwidth - 1)
		mlx_put_image_to_window(solong->mlx, solong->win,
			solong->corner[2], x * SIZE, y * SIZE);
	else if (y != solong->mapheight - 1 && x == 0 && y != 0)
		mlx_put_image_to_window(solong->mlx, solong->win,
			solong->border[2], x * SIZE, y * SIZE);
	else if (y == solong->mapheight - 1 && x != solong->mapwidth - 1 && x != 0)
		mlx_put_image_to_window(solong->mlx, solong->win,
			solong->border[3], x * SIZE, y * SIZE);
	else if (y == solong->mapheight - 1 && x == 0)
		mlx_put_image_to_window(solong->mlx, solong->win,
			solong->corner[3], x * SIZE, y * SIZE);
	put_random_4(solong, solong->ruins, x, y);
}

static void	display_map_char(t_solong	*solong, int x, int y)
{
	int	r;

	r = rand();
	if (solong->map[y][x] == '1')
		wich_one(solong, x, y);
	if (solong->map[y][x] == '0')
		put_random_4(solong, solong->ground, x, y);
	if (solong->map[y][x] == 'P')
		mlx_put_image_to_window(solong->mlx, solong->win,
			solong->playeridle[3], x * SIZE, y * SIZE);
	if (solong->map[y][x] == 'E')
		mlx_put_image_to_window(solong->mlx, solong->win,
			solong->door[0], x * SIZE, y * SIZE);
	if (solong->map[y][x] == 'C')
		mlx_put_image_to_window(solong->mlx, solong->win,
			solong->comestibles[r % 2], x * SIZE, y * SIZE);
	if (solong->map[y][x] == 'M')
		mlx_put_image_to_window(solong->mlx, solong->win,
			solong->minos_ir[rand() % 2], x * SIZE, y * SIZE);
}

void	display_map(t_solong	*solong)
{
	int	x;
	int	y;

	y = 0;
	while (solong->map[y])
	{
		x = 0;
		while (solong->map[y][x])
		{
			display_map_char(solong, x, y);
			x++;
		}
		y++;
	}
	fill_down_water(solong);
	display_count(solong, 0, solong->mapheight + 2);
}
