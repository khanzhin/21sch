/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wtodd <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/30 11:01:20 by wtodd             #+#    #+#             */
/*   Updated: 2019/10/03 15:22:06 by wtodd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

char	*chek_str(char *str, char **line)
{
	char *p;

	p = NULL;
	if (str)
	{
		if ((p = ft_strchr(str, '\n')))
		{
			*p = '\0';
			*line = ft_strdup(str);
			p++;
			ft_strcpy(str, p);
		}
		else
		{
			*line = ft_strdup(str);
			ft_bzero(str, ft_strlen(str));
		}
	}
	else
		*line = ft_strnew(1);
	return (p);
}

int		get_next_line(const int fd, char **line)
{
	static char	*str;
	char		buf[BUFF_SIZE + 1];
	int			d;
	char		*p;
	char		*tmp;

	if (fd < 0 || line == NULL ||
			read(fd, NULL, 0) == -1 || BUFF_SIZE <= 0)
		return (-1);
	p = chek_str(str, line);
	while (!p && (d = read(fd, buf, BUFF_SIZE)))
	{
		buf[d] = '\0';
		if ((p = ft_strchr(buf, '\n')))
		{
			*p = '\0';
			p++;
			str = ft_strdup(p);
		}
		tmp = *line;
		*line = ft_strjoin(*line, buf);
		free(tmp);
	}
	return (d || ft_strlen(str) || ft_strlen(*line)) ? 1 : 0;
}

int		main(void)
{
	int		fd;
	char	*line;

	fd = open("file.txt", O_RDONLY);
	while (get_next_line(fd, &line))
		printf("%s\n", line);
	return (0);
}
