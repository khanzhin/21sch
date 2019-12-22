/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_tetro.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcharlin <lcharlin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 10:09:44 by lcharlin          #+#    #+#             */
/*   Updated: 2019/11/09 14:03:13 by lcharlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_cpy_arr(t_tetro *head, int *arrcpy)
{
	int i;

	i = 0;
	while (i < 8)
	{
		arrcpy[i] = head->tetro_id[i];
		i++;
	}
}

int		ft_answer(char **map, t_tetro *head, int size_map)
{
	int *arrcpy;
	int x;
	int y;

	x = 0;
	y = 0;
	if (head == NULL)
		return (1);
	size_map = ft_strlen((map[x]));
	if (!(arrcpy = (int *)malloc(sizeof(int) * 8)))
		exit(EXIT_FAILURE);
	while (y < size_map)
	{
		x = 0;
		while (x < size_map)
		{
			ft_cpy_and_move(head, arrcpy, x, y);
			if (ft_answer2(map, arrcpy, head, size_map))
				return (1);
			x++;
		}
		y++;
	}
	free(arrcpy);
	return (0);
}

int		ft_answer2(char **map, int *arrcpy, t_tetro *head, int size_map)
{
	if (ft_check_border_cross(map, arrcpy) &&
		ft_check_figure_cross(map, arrcpy))
	{
		ft_place_figure(map, head->letter, arrcpy);
		if (ft_answer(map, head->next, size_map))
		{
			free(arrcpy);
			return (1);
		}
		ft_del_figure(map, arrcpy);
	}
	return (0);
}

void	ft_cpy_and_move(t_tetro *head, int *arrcpy, int x, int y)
{
	ft_cpy_arr(head, arrcpy);
	ft_move_tetro(arrcpy, x, y);
}
