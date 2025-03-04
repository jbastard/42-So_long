/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbastard <jbastard@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-02-11 07:29:15 by jbastard          #+#    #+#             */
/*   Updated: 2025-02-11 07:29:15 by jbastard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

int	is_valid_path(t_solong solong)
{
	char	**copy;

	map_dup(solong.map, &copy);
	map_flood_fill(copy, solong.pposy, solong.pposx);
	if (!map_compare(solong.map, copy))
		return (free_map(copy, 0), 0);
	return (free_map(copy, 0), 1);
}

int	map_compare(char **map, char **copy)
{
	int	y;
	int	x;

	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if ((map[y][x] == 'C' || map[y][x] == 'P' || map[y][x] == 'E')
				&& copy[y][x] != 'V')
				return (0);
			x++;
		}
		y++;
	}
	return (1);
}

void	map_dup(char **map, char ***copy)
{
	int	i;
	int	height;

	height = 0;
	while (map[height])
		height++;
	*copy = malloc(sizeof(char *) * (height + 1));
	if (!*copy)
		return ;
	i = 0;
	while (map[i])
	{
		(*copy)[i] = ft_strdup(map[i]);
		if (!(*copy)[i])
		{
			*copy = NULL;
			return ;
		}
		i++;
	}
	(*copy)[i] = NULL;
}

void	map_flood_fill(char **map, int y, int x)
{
	if (y < 0 || x < 0 || !map[y][x] || map[y][x] == '1')
		return ;
	if (map[y][x] == 'V' || map[y][x] == 'M')
		return ;
	map[y][x] = 'V';
	map_flood_fill(map, y - 1, x);
	map_flood_fill(map, y + 1, x);
	map_flood_fill(map, y, x - 1);
	map_flood_fill(map, y, x + 1);
}
