/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcharlin <lcharlin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 13:07:04 by lcharlin          #+#    #+#             */
/*   Updated: 2019/10/22 17:44:26 by lcharlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>
#include <fcntl.h>


int		main(int argc, char **argv)
{
	int fd;
	char *line;
	//char buf[5];
	t_tetro *head;
	line = NULL;

	fd = open(argv[1], O_RDONLY);
	ft_usage(argc);
	ft_check_access(fd);
	ft_check_file(fd);
	close(fd);

	///////////////////////// It works and we can do it (read again)
	fd = open(argv[1], O_RDONLY);
	ft_check_eof(fd);
	close(fd);
	fd = open(argv[1], O_RDONLY);
	head = ft_str_to_int(fd, line);

	write(1, "\n", 1);
	int k = 0;
	while (k < 8)
	{
		ft_print_result2(head->tetro_id[k++]);
		write(1, " ", 1);
	}

	close(fd);
	ft_map_size(*head);



//	while (k < 8)
//	{
//	ft_print_result2(head->tetro_id[k++]);
//	write(1, " ", 1);
//	}

	return (0);
}
