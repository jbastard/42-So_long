/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_all_sprites.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbastard <jbastard@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-02-11 07:46:16 by jbastard          #+#    #+#             */
/*   Updated: 2025-02-11 07:46:16 by jbastard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	set_null_array(void **array, int count)
{
	int	i;

	i = 0;
	while (i < count)
		array[i++] = NULL;
}

void	set_null_sprites(t_solong	*solong)
{
	set_null_array(solong->ground, 4);
	set_null_array(solong->border, 4);
	set_null_array(solong->corner, 4);
	set_null_array(solong->ruins, 4);
	set_null_array(solong->door, 3);
	set_null_array(solong->endbanner, 6);
	set_null_array(solong->tendbanner, 6);
	set_null_array(solong->downcount, 12);
	set_null_array(solong->num, 11);
	set_null_array(solong->water, 2);
	set_null_array(solong->playeridle, 4);
	set_null_array(solong->minos_ir, 4);
	set_null_array(solong->minos_il, 4);
	set_null_array(solong->minos_attack, 8);
	set_null_array(solong->comestibles, 2);
}

void	load_sprites(t_solong *solong)
{
	set_null_sprites(solong);
	load_player_idle(solong);
	load_environment(solong);
	load_minos_il(solong);
	load_minos_ir(solong);
	load_attack(solong);
	load_ground(solong);
	load_water(solong);
	load_border(solong);
	load_corner(solong);
	load_end_banner(solong);
	load_num(solong);
	load_count(solong);
	load_ground_end_banner(solong);
}
