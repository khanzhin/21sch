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
#include <stdio.h>

void 	ft_check_eof(int fd)
{

	char buf[1];

	while(read(fd, buf, 1))
	{
	}
	if (buf[0] != '\n')
	{
		ft_putendl("Error NO NEW LINE EOF");
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
		ft_putendl("Error PERMISSION");
		exit(EXIT_FAILURE);
	}
}

int		ft_check_for_symbols(char *line)
{
	char *tmp;
	int i;

	i = 0;
	tmp = line;
	while (*tmp)
	{
		if ((*tmp != (char)'.') && (*tmp != (char)'#'))
		{
			ft_putendl("Error: wrong input file SYMBOLS");
			free(line);
			exit(EXIT_FAILURE);
		}
		else if (*tmp == (char)'#')
			i++;
		tmp++;
	}
	return (i);
}

void	ft_check_file(int fd)
{
	int i = 1;
	int j = 0; // to recognize figures
	int k = 1; // to count number of figures
	char *line = NULL;
	char full_line[16];

	while(get_next_line(fd, &line))
	{
		if (i <= 4)
			ft_strcat(full_line, line);
		if (i == 4)
		{
			ft_check_connection(full_line);
			ft_check_horizontal_line(full_line);
		}

		if ((j = j + ft_check_for_symbols(line)) > 4 || (i == 4 && j < 4))
		{
			ft_putendl("Error: wrong input file NUMBER OF #");
			free(line);
			exit(EXIT_FAILURE);
		}
		if (i <= 4 && ft_strlen(line) != 4)
		{
			ft_putendl("Error: wrong input file LENGTH");
			free(line);
			exit(EXIT_FAILURE);
		}
		if ((i == 5 && (ft_strlen(line) != 0)))
		{
			ft_putendl("Error: wrong input file NEW_LINE");
			free(line);
			exit(EXIT_FAILURE);
		}
		else if (i == 5)
		{
			i = 0;
			j = 0;
			k = k + 1;
			ft_bzero(full_line, ft_strlen(full_line));
		}
		i++;
		ft_putendl(line);
		free(line);
	}
	free(line);
	ft_figures_counter(k);
	if (i != 5)
	{
		ft_putendl("Error: wrong input file LINE_NUM");
		exit(EXIT_FAILURE);
	}
}

void		ft_figures_counter(int i) //to optimize in 100str
{
	if (i > 26)
	{
		ft_putendl("Error: wrong input file NUMBER OF FIGURES");
		exit(EXIT_FAILURE);
	}
	printf("Number of figures = %d\n", i);
}


void		ft_check_connection(char *str)
{
	int block;
	int i;

	block = 0;
	i = 0;
	while (i < 16)
	{
		if (str[i] == '#')
		{
			if ((i + 1) < 16 && str[i + 1] == '#')
				block++;
			if ((i - 1) >= 0 && str[i - 1] == '#')
				block++;
			if ((i + 4) < 16 && str[i + 4] == '#')
				block++;
			if ((i - 4) >= 0 && str[i - 4] == '#')
				block++;
		}
		i++;
	}
	if (block != 6 && block != 8)
	{
		ft_putendl("Error: wrong input file CONNECTIONS");
		exit(EXIT_FAILURE);
	}
}

void		ft_check_horizontal_line(char *str)
{
	if ((str[3] == '#' && str[4] == '#')
		|| (str[7] == '#' && str[8] == '#')
		|| (str[11] == '#' && str[12] == '#'))
	{
		ft_putendl("Error: wrong input file HORIZONTAL_LINE");
		exit(EXIT_FAILURE);
	}
}