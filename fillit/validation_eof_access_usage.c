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

void	ft_check_eof(int fd)
{
	char buf[1];

	while (read(fd, buf, 1))
	{
	}
	if (buf[0] != '\n')
	{
		ft_putendl("error");
		exit(EXIT_FAILURE);
	}
}

void	ft_usage(int argc)
{
	if (argc == 1 || argc > 2)
	{
		ft_putendl("usage: ./fillit source_file.fillit");
		exit(EXIT_SUCCESS);
	}
}

void	ft_check_access(int fd)
{
	if (fd == -1)
	{
		ft_putendl("error");
		exit(EXIT_FAILURE);
	}
}

void	ft_figures_counter(int count_figures)
{
	if (count_figures > 26)
	{
		ft_putendl("error");
		exit(EXIT_FAILURE);
	}
}
