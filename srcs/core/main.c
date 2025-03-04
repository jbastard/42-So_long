/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbastard <jbastard@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-02-11 06:45:19 by jbastard          #+#    #+#             */
/*   Updated: 2025-02-11 06:45:19 by jbastard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

int	main(int argc, char **argv)
{
	t_solong	solong;

	if (argc != 2 || !argv[1][0])
		return (ft_printf("Error: Invalid arguments count\n"), 0);
	if (!is_dot_ber(argv[1]))
		return (ft_printf("Error: Use .ber file as map\n"), 0);
	init_win(&solong, argv[1]);
	display_map(&solong);
	claim_hook(&solong);
	mlx_loop(solong.mlx);
}
