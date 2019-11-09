/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcharlin <lcharlin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 10:09:44 by lcharlin          #+#    #+#             */
/*   Updated: 2019/10/24 10:09:46 by lcharlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_move_tetro(int *coordinates, int x, int y)
{
	int i;

	i = 0;
	while (i < 8)
	{
		coordinates[i] = coordinates[i] + x;
		coordinates[i + 1] = coordinates[i + 1] + y;
		i += 2;
	}
}

int		ft_find_max_x(int *arr)
{
	int i;
	int max_x;

	i = 0;
	max_x = arr[i];
	while (i <= 5)
	{
		if (max_x < arr[i + 2])
			max_x = arr[i + 2];
		i += 2;
	}
	return (max_x);
}

int		ft_find_max_y(int *arr)
{
	int i;
	int max_y;

	i = 1;
	max_y = arr[i];
	while (i <= 5)
	{
		if (max_y < arr[i + 2])
			max_y = arr[i + 2];
		i += 2;
	}
	return (max_y);
}

int		ft_check_border_cross(char **map, int *arr)
{
	int i;
	int size_map;
	int x_max;
	int y_max;

	i = 0;
	size_map = ft_strlen(map[i]);
	x_max = ft_find_max_x(arr);
	y_max = ft_find_max_y(arr);
	return ((x_max >= size_map || y_max >= size_map) ? 0 : 1);
}

int		ft_check_figure_cross(char **map, int *arr)
{
	int i;

	i = 0;
	while (i < 8)
	{
		if (map[arr[i + 1]][arr[i]] != '.')
			return (0);
		i += 2;
	}
	return (1);
}
