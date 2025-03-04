/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbastard <jbastard@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-02-11 08:07:05 by jbastard          #+#    #+#             */
/*   Updated: 2025-02-11 08:07:05 by jbastard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	put_image(t_solong	*solong, void	*img, int x, int y)
{
	mlx_put_image_to_window(solong->mlx, solong->win, img, x, y);
}

void	find_player(t_solong	*solong)
{
	int	y;
	int	x;

	y = 0;
	while (solong->mapheight > y)
	{
		x = 0;
		while (solong->mapwidth > x)
		{
			if (solong->map[y][x] == 'P')
			{
				solong->pposy = y;
				solong->pposx = x;
			}
			if (solong->map[y][x] == 'E')
			{
				solong->eposy = y;
				solong->eposx = x;
			}
			x++;
		}
		y++;
	}
}

int	is_dot_ber(char	*path)
{
	int		fd;
	int		i;
	int		len;
	char	*ber;

	len = ft_strlen(path);
	ber = ".ber";
	i = 4;
	fd = open(path, O_RDONLY);
	if (fd < 0)
	{
		ft_printf("Unable to open %s\n", path);
		exit(1);
	}
	close(fd);
	while (path[len] == 32)
		len--;
	while (i > 0)
	{
		if (path[len] != ber[i])
			return (0);
		len--;
		i--;
	}
	return (1);
}

void	is_screen_sized(t_solong	*solong)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	mlx_get_screen_size(solong->mlx, &x, &y);
	if (y > (solong->mapheight) * SIZE)
		return (ft_printf("Map too large"), data_free(solong, ""));
	if (x > (solong->mapwidth + 2) * SIZE)
		return (ft_printf("Map too high"), data_free(solong, ""));
	return ;
}
