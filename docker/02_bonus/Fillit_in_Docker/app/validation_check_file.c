/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation_check_file.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcharlin <lcharlin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 10:09:44 by lcharlin          #+#    #+#             */
/*   Updated: 2019/11/09 14:04:20 by lcharlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_check_file2(char *full_line, char *line, int i)
{
	if (i <= 4)
		ft_strcat(full_line, line);
	if (i == 4)
	{
		ft_check_connection(full_line);
		ft_check_horizontal_line(full_line);
	}
}

void	ft_exit(char *line)
{
	ft_putendl("error");
	free(line);
	exit(EXIT_FAILURE);
}

int		ft_check_file3(int fd, char *line, int count_figures, char *full_line)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	while (get_next_line(fd, &line))
	{
		ft_check_file2(full_line, line, i);
		if (((j = j + ft_check_for_symbols(line)) > 4 || (i == 4 && j < 4)) ||
			(i <= 4 && ft_strlen(line) != 4) ||
			((i == 5 && (ft_strlen(line) != 0))))
			ft_exit(line);
		else if (i == 5)
		{
			i = 0;
			j = 0;
			count_figures = count_figures + 1;
			ft_bzero(full_line, ft_strlen(full_line));
		}
		i++;
		free(line);
	}
	free(line);
	ft_figures_counter(count_figures);
	return (i);
}

void	ft_check_file(int fd)
{
	int		i;
	int		count_figures;
	char	*line;
	char	full_line[16];

	count_figures = 1;
	line = NULL;
	i = ft_check_file3(fd, line, count_figures, full_line);
	if (i != 5)
	{
		ft_putendl("error");
		exit(EXIT_FAILURE);
	}
}
