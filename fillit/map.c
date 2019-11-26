/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcharlin <lcharlin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 13:50:35 by lcharlin          #+#    #+#             */
/*   Updated: 2019/11/08 14:03:20 by lcharlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char		**ft_map_size(t_tetro head)
{
	int		i;
	char	**map;
	t_tetro	*head_ptr;
	int		min_map_size;

	i = 1;
	head_ptr = &head;
	while (head_ptr->next != NULL)
	{
		head_ptr = head_ptr->next;
		i++;
	}
	min_map_size = ft_sqrt_map(i);
	map = ft_map_create(min_map_size);
	return (map);
}

int			ft_sqrt_map(int number_of_figures)
{
	int		number;
	float	temp;
	float	sqrt;
	int		result;

	number = number_of_figures * 4;
	sqrt = number / 2;
	temp = 0;
	while (sqrt != temp)
	{
		temp = sqrt;
		sqrt = (number / temp + temp) / 2;
	}
	result = (int)(sqrt + 0.99);
	return (result);
}

char		**ft_map_create(int map_size)
{
	char	**map;
	int		i;
	int		j;

	i = 0;
	if (!(map = (char **)malloc(sizeof(char *) * (map_size + 1))))
		exit(EXIT_FAILURE);
	while (i < map_size)
	{
		if (!(map[i] = ft_strnew(map_size)))
			exit(EXIT_FAILURE);
		j = 0;
		while (j < map_size)
		{
			map[i][j] = '.';
			j++;
		}
		i++;
	}
	map[i] = NULL;
	return (map);
}

void		ft_place_figure(char **map_zero, char letter, int *arrcpy)
{
	int		x;
	int		y;
	int		k;

	x = 0;
	k = 0;
	while (k < 7)
	{
		x = arrcpy[k];
		y = arrcpy[k + 1];
		map_zero[y][x] = letter;
		k += 2;
	}
}

void		ft_del_figure(char **map, int *arrcpy)
{
	int		x;
	int		y;
	int		k;

	x = 0;
	k = 0;
	while (k < 7)
	{
		x = arrcpy[k];
		y = arrcpy[k + 1];
		map[y][x] = '.';
		k += 2;
	}
}
