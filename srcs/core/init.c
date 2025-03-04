/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbastard <jbastard@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-02-11 06:51:47 by jbastard          #+#    #+#             */
/*   Updated: 2025-02-11 06:51:47 by jbastard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	set_zero(t_solong	*solong)
{
	srand(time(NULL));
	solong->mlx = NULL;
	solong->win = NULL;
	solong->map = NULL;
	solong->mapheight = 0;
	solong->mapwidth = 0;
	solong->frame_counter = 0;
	solong->movecount = 0;
	solong->end = 2;
	gettimeofday(&solong->last_frame_time, NULL);
}

void	init_map(t_solong	*solong, char *argv1)
{
	int	i;
	int	fd;

	i = 0;
	solong->mapheight = get_height(argv1);
	if (!solong->mapheight)
		data_free(solong, "Error: Map Empty\n");
	fd = open(argv1, O_RDONLY);
	if (fd < 0)
	{
		close(fd);
		data_free(solong, "Can't open the map file\n");
	}
	solong->map = malloc(sizeof(char *) * (solong->mapheight + 1));
	while (i < solong->mapheight)
	{
		solong->map[i] = get_next_line(fd);
		if (solong->map[i][0] == '\n')
			break ;
		put_bszero(solong->map[i++]);
	}
	close(fd);
	solong->mapwidth = (int)ft_strlen(solong->map[0]);
	solong->map[solong->mapheight] = NULL;
}

void	init_win(t_solong	*solong, char *argv1)
{
	set_zero(solong);
	init_map(solong, argv1);
	find_player(solong);
	if (!solong->map || !is_true_map(solong))
		free_map(solong->map, 1);
	solong->mlx = mlx_init();
	if (!solong->mlx)
		data_free(solong, "init_mlx");
	solong->win = mlx_new_window(solong->mlx, solong->mapwidth * 64,
			(solong->mapheight + 2) * 64, "Solong");
	if (!solong->win)
		data_free(solong, "init_win");
	load_sprites(solong);
}

// is_screen_sized(solong);
