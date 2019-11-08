#include "fillit.h"
#include <stdio.h>

void ft_cpy_arr(t_tetro *head, int *arrcpy)
{
	int i = 0;
	while (i < 8) {
		arrcpy[i] = head->tetro_id[i];
		i++;
	}
}

void     ft_move_tetro(int *coordinates, int x, int y)
{
	int i;

	i = 0;
	while(i < 8)
	{
		coordinates[i] = coordinates[i] + x;
		coordinates[i + 1] = coordinates[i + 1] + y;
		i+=2;
	}
}

int	ft_find_max_x(int *arr)
{
	int i;
	int max_x;

	i = 0;
	max_x = arr[i];
	while (i <= 5)
	{
		if (max_x < arr[i + 2])
			max_x = arr[i + 2];
		i+=2;
	}
	return (max_x);
}

int	ft_find_max_y(int *arr)
{
	int i;
	int max_y;

	i = 1;
	max_y = arr[i];
	while (i <= 5)
	{
		if (max_y < arr[i + 2])
			max_y = arr[i + 2];
		i+=2;
	}
	return (max_y);
}


int	ft_check_border_cross(char **map, int *arr)
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

int	ft_check_figure_cross(char **map, int *arr)
{
	int i;

	i = 0;
	while (i < 8)
	{
		if (map[arr[i + 1]][arr[i]] != '.')
			return (0);
		i+=2;
	}
	return (1);
}


void	ft_del_figure(char **map, int *arrcpy)
{
	int x = 0;
	int y;
	int k;

	k = 0;
	while (k < 7) {
		x = arrcpy[k];
		y = arrcpy[k + 1];
		map[y][x] = '.';
		k+=2;
	}
}


int	ft_answer(char **map, t_tetro *head, int size_map)
{
	int *arrcpy;
	int x;
	int y;
//	int size_map;

	x = 0;
	y = 0;
	if (head == NULL)
		return (1);
	size_map = ft_strlen((map[x]));
	if (!(arrcpy = (int *) malloc(sizeof(int) * 8)))
		exit (EXIT_FAILURE);
	while (y < size_map)
	{
		x = 0;
		while (x < size_map)
		{
			ft_cpy_arr(head, arrcpy);
			ft_move_tetro(arrcpy, x, y);
			if (ft_check_border_cross(map, arrcpy) && ft_check_figure_cross(map, arrcpy))
			{
				ft_place_figure(map, head->letter, arrcpy);
				if (ft_answer(map, head->next, size_map))
				{
					free(arrcpy);
					return (1);
				}
				ft_del_figure(map, arrcpy);
			}
			x++;
		}
		y++;
	}
	free(arrcpy);
	return (0);
}