/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_to_int2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcharlin <lcharlin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 15:00:33 by wtodd             #+#    #+#             */
/*   Updated: 2019/11/09 14:03:43 by lcharlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_tetro		*ft_str_to_int(int fd, char *line)
{
	int		k;
	t_tetro	*head;

	k = 0;
	head = NULL;
	head = ft_str_to_int2(fd, line, head, k);
	return (head);
}

t_tetro		*ft_str_to_int2(int fd, char *line, t_tetro *head, int k)
{
	int		coordinates[8];
	int		y;

	y = 0;
	while (get_next_line(fd, &line))
	{
		k = ft_str_to_int3(coordinates, line, y, k);
		y++;
		if (y == 4)
		{
			y = -1;
			k = 0;
			head == NULL ? head = ft_create_node(ft_chr_min_x_y(coordinates)) :
					append(head, ft_chr_min_x_y(coordinates));
		}
		free(line);
	}
	free(line);
	return (head);
}

int			ft_str_to_int3(int *coordinates, char *line, int y, int k)
{
	int x;

	x = 0;
	while (line[x] != '\0')
	{
		if (line[x] == '#')
		{
			coordinates[k] = x;
			coordinates[k + 1] = y;
			k += 2;
		}
		x++;
	}
	return (k);
}
