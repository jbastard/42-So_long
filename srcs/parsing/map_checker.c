/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbastard <jbastard@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-02-11 07:27:35 by jbastard          #+#    #+#             */
/*   Updated: 2025-02-11 07:27:35 by jbastard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

int	is_rectangle(char **map)
{
	int	i;
	int	prev_len;

	i = 1;
	prev_len = ft_strlen(map[0]);
	while (map[i])
	{
		if (prev_len != (int)ft_strlen(map[i]))
			return (0);
		prev_len = ft_strlen(map[i]);
		i++;
	}
	return (1);
}

int	is_walled(t_solong	solong)
{
	int	i;
	int	height;

	i = 0;
	height = solong.mapheight;
	while (solong.map[0][i] && solong.map[solong.mapheight - 1][i])
	{
		if (solong.map[0][i] != BORDER
			|| solong.map[solong.mapheight - 1][i] != BORDER)
			return (0);
		i++;
	}
	i = 0;
	while (i < height)
	{
		if (solong.map[i][0] != BORDER
				|| solong.map[i][ft_strlen(solong.map[i]) - 1] != BORDER)
			return (0);
		i++;
	}
	return (1);
}

int	is_full(char **map, char c)
{
	int	i;
	int	j;
	int	count;

	i = 1;
	count = 0;
	while (map[i + 1])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == c)
				count += 1;
			j++;
		}
		i++;
	}
	return (count);
}

int	is_all_valid_char(t_solong	solong)
{
	int	x;
	int	y;

	y = 0;
	while (y < solong.mapheight)
	{
		x = 0;
		while (x < solong.mapwidth)
		{
			if (solong.map[y][x] != 'C'
				&& solong.map[y][x] != 'P'
				&& solong.map[y][x] != 'E'
				&& solong.map[y][x] != 'M'
				&& solong.map[y][x] != '0'
				&& solong.map[y][x] != '1')
				return (0);
			x++;
		}
		y++;
	}
	return (1);
}

int	is_true_map(t_solong *solong)
{
	if (!is_rectangle(solong->map) || !is_walled(*solong))
	{
		ft_printf("The map must be rectangular and surrounded by walls.\n");
		return (0);
	}
	if (!is_all_valid_char(*solong))
		return (ft_printf("Invalid map character\n"), 0);
	if (is_full(solong->map, 'E') != 1
		|| is_full(solong->map, 'P') != 1
		|| is_full(solong->map, 'C') < 1)
	{
		ft_printf("The map must contain 1 ");
		ft_printf("character, 1 exit, and at least 1 collectible.\n");
		return (0);
	}
	solong->collectibles = is_full(solong->map, 'C');
	if (!is_valid_path(*solong))
		return (ft_printf("The map's configuration"
				" makes it impossible to complete.\n"), 0);
	return (1);
}
