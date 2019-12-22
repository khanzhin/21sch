/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcharlin <lcharlin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 13:07:04 by lcharlin          #+#    #+#             */
/*   Updated: 2019/11/09 14:03:51 by lcharlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <fcntl.h>

void	ft_validator(int argc, int fd)
{
	ft_usage(argc);
	ft_check_access(fd);
	ft_check_file(fd);
}

void	ft_print_me(char **map)
{
	int		x;
	int		y;

	x = 0;
	x = ft_strlen(map[x]);
	y = 0;
	while (y < x)
	{
		ft_putendl((map[y]));
		y++;
	}
}

int		main(int argc, char **argv)
{
	int		fd;
	char	*line;
	t_tetro	*head;
	char	**map;
	int		size_map;

	line = NULL;
	size_map = 0;
	fd = open(argv[1], O_RDONLY);
	ft_validator(argc, fd);
	close(fd);
	fd = open(argv[1], O_RDONLY);
	ft_check_eof(fd);
	close(fd);
	fd = open(argv[1], O_RDONLY);
	head = ft_str_to_int(fd, line);
	close(fd);
	map = ft_map_size(*head);
	while (!ft_answer(map, head, size_map))
	{
		size_map = ft_strlen(map[size_map]);
		map = ft_map_create(size_map + 1);
	}
	ft_print_me(map);
	exit(EXIT_SUCCESS);
}
