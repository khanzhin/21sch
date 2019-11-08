/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recognition.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wtodd <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 15:00:33 by wtodd             #+#    #+#             */
/*   Updated: 2019/11/08 16:13:47 by wtodd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

t_tetro *ft_str_to_int(int fd, char *line)
{
	int coordinates[8];
	int x;
	int y;
	int k;
	t_tetro *head;

	x = 0;
	y = 0;
	k = 0;
	head = NULL;
	while (get_next_line(fd, &line))
	{
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
		x = 0;
		y++;
		if (y == 4)
		{
			y = -1; //y = 0; wtf ne 0?
			k = 0;
			head == NULL ? head = ft_create_node(ft_chr_min_x_y(coordinates)) : append(head, ft_chr_min_x_y(coordinates));
		}
		free(line);
	}
	free(line);
	return(head);
}

int	*ft_chr_min_x_y(int *coordinates)
{
	int i;
	int min_x;
	int min_y;

	i = 0;
	min_x = coordinates[i];
	while (i <= 4)
	{
		if (min_x > coordinates[i + 2])
			min_x = coordinates[i + 2];
		i += 2;
	}
	i = 1;
	min_y = coordinates[i];
	while (i <= 5) //  while maybe delete to respect norme
	{
		if (min_y > coordinates[i + 2])
			min_y = coordinates[i + 2];
		i += 2;
	}
	return (ft_to_the_left_corner(coordinates, min_x, min_y));
}

int	*ft_to_the_left_corner(int *coordinates, int x, int y)
{
	int i;
	int j;

	i = 0;
	while (i < 7)
	{
		j = i + 1;
		coordinates[i] = coordinates[i] - x;
		coordinates[j] = coordinates[j] - y;
		i += 2;
	}
	return(coordinates);
}

t_tetro *ft_create_node(int *nb)
{
	t_tetro *list;
	int i = 0;

	list = (t_tetro *) malloc(sizeof(t_tetro));
	if (list == NULL)
		exit(EXIT_FAILURE);
	while (i < 8)
	{
		list->tetro_id[i] = nb[i];
		i++;
	}
	list->letter = 'A';
	list->next = NULL;
	return (list);
}

t_tetro *append(t_tetro *head, int *nb)
{
	t_tetro *list;
	t_tetro *head_ptr;
	int i;

	i = 1;
	head_ptr = head;
	while (head_ptr->next != NULL)
	{
		head_ptr = head_ptr->next;
		i++;
	}
	list = ft_create_node(nb);
	list->letter = list->letter + i;
	head_ptr->next = list;
	return(head);
}
