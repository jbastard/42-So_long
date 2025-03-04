/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbastard <jbastard@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-02-11 07:25:02 by jbastard          #+#    #+#             */
/*   Updated: 2025-02-11 07:25:02 by jbastard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

int	get_height(char *argv1)
{
	char	*line;
	int		count_height;
	int		fd;

	fd = open(argv1, O_RDONLY);
	count_height = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		if (line[0] != '\n')
			count_height++;
		free(line);
	}
	close(fd);
	return (count_height);
}

void	put_bszero(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\n' && str[i])
		i++;
	str[i] = '\0';
}
