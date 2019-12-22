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

int		*ft_chr_min_x_y(int *coordinates)
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
	while (i <= 5)
	{
		if (min_y > coordinates[i + 2])
			min_y = coordinates[i + 2];
		i += 2;
	}
	return (ft_to_the_left_corner(coordinates, min_x, min_y));
}

int		*ft_to_the_left_corner(int *coordinates, int x, int y)
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
	return (coordinates);
}

t_tetro	*ft_create_node(int *nb)
{
	t_tetro	*list;
	int		i;

	i = 0;
	list = (t_tetro *)malloc(sizeof(t_tetro));
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

t_tetro	*append(t_tetro *head, int *nb)
{
	t_tetro	*list;
	t_tetro	*head_ptr;
	int		i;

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
	return (head);
}
