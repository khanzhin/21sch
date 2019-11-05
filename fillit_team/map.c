#include "fillit.h"
#include <stdio.h>

void ft_map_size(t_tetro head)
{
	int i;
	//char **map;
	t_tetro *head_ptr;

	i = 1;
	head_ptr = &head;
	while (head_ptr->next != NULL)
	{
		head_ptr = head_ptr->next;
		i++;
	}
	printf("\nколичество фигур %d\n", i);

	int number = i * 4;
	float temp, sqrt;
	sqrt = number / 2;
	temp = 0;
	while(sqrt != temp)
	{
		temp = sqrt;
		sqrt = (number/temp + temp) / 2;
	}
	int min_map_size = (int)(sqrt + 0.99);
	printf("\nThe square root of '%d' is '%d'\n", number, min_map_size);
	//map = ft_map_create(min_map_size); //delete?
	ft_place_figure(ft_map_create(min_map_size), &head);

}

char **ft_map_create(int map_size)
{
	char **map;
	int i;
	int j;

	i = 0;
	if (!(map = (char **)malloc(sizeof(char *) * (map_size + 1))))
		exit (EXIT_FAILURE);
	while (i < map_size)
	{
		if (!(map[i] = ft_strnew(map_size)))
			exit (EXIT_FAILURE);
		j = 0;
		while (j < map_size)
		{
			map[i][j] = '.';
			j++;
		}
		i++;
	}
	map[i] = NULL;

		for (i = 0; i < map_size; i++)
		{
			for (j = 0; j <map_size; j++)
			{
				printf("\t%c", map[i][j]);
			}
			printf("\n");
			printf("\n");
		}
		return(map);
}

void ft_place_figure(char **map_zero, t_tetro *head)
{
	int x = 0;
	int y;
	int k;
	t_tetro *head_ptr;
	int size_line;
	printf("\ndl %d\n", size_line = ft_strlen(map_zero[x]));

	head_ptr = head;
	k = 0;
	while (k < 7) {
		x = head_ptr->tetro_id[k];
		y = head_ptr->tetro_id[k + 1];
		map_zero[y][x+2] = head_ptr->letter;
		k+=2;
	}
	for (y = 0; y < 4; y++)
	{
		for (x = 0; x < 4; x++)
		{
			printf("\t%c ", map_zero[y][x]);
		}
		printf("\n");
	}

}

ft_tyty(map_zero, x, y, head, size_line)
{
	int i;
while (map_zero[size_line][] != size_line)
{
	
}
}