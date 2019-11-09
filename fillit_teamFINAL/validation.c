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

int		ft_check_for_symbols(char *line)
{
	char	*tmp;
	int		i;

	i = 0;
	tmp = line;
	while (*tmp)
	{
		if ((*tmp != (char)'.') && (*tmp != (char)'#'))
		{
			ft_putendl("error");
			free(line);
			exit(EXIT_FAILURE);
		}
		else if (*tmp == (char)'#')
			i++;
		tmp++;
	}
	return (i);
}

void	ft_check_connection(char *str)
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
		ft_putendl("error");
		exit(EXIT_FAILURE);
	}
}

void	ft_check_horizontal_line(char *str)
{
	if ((str[3] == '#' && str[4] == '#')
		|| (str[7] == '#' && str[8] == '#')
		|| (str[11] == '#' && str[12] == '#'))
	{
		ft_putendl("error");
		exit(EXIT_FAILURE);
	}
}
