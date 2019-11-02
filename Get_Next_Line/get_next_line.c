<<<<<<< HEAD
=======
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wtodd <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/30 11:01:20 by wtodd             #+#    #+#             */
/*   Updated: 2019/10/22 16:57:51 by wtodd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

>>>>>>> 8cde57745f28dbfa976e0436c22b0a6c4e512ace
#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

static	char	*chek_str(char *str, char **line)
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
<<<<<<< HEAD
			ft_bzero(str, ft_strlen(str));
			//ft_strdel(&str);
=======
			ft_strclr(str);
>>>>>>> 8cde57745f28dbfa976e0436c22b0a6c4e512ace
		}
	}
	else
		*line = ft_strnew(1);
	return (p);
}

<<<<<<< HEAD
int		get_line(const int fd, char **line, char **ost)
=======
static void		find_n(char *p, char **str)
{
	char *tmp;

	*p = '\0';
	p++;
	tmp = *str;
	*str = ft_strdup(p);
	free(tmp);
}

int				get_next_line(const int fd, char **line)
>>>>>>> 8cde57745f28dbfa976e0436c22b0a6c4e512ace
{
	char		buf[BUFF_SIZE + 1];
	int			d;
	char		*p;
	char		*tmp;

<<<<<<< HEAD
	if (fd < 0 || line == NULL || fd > 10240 ||
			read(fd, NULL, 0) == -1 || BUFF_SIZE <= 0)
		return (-1);
	p = chek_str(*ost, line);
=======
	if (fd < 0 || !line || fd > 10240 ||
			read(fd, buf, 0) == -1 || BUFF_SIZE < 1)
		return (-1);
	d = 1;
	p = chek_str(str, line);
>>>>>>> 8cde57745f28dbfa976e0436c22b0a6c4e512ace
	while (!p && (d = read(fd, buf, BUFF_SIZE)))
	{
		buf[d] = '\0';
		if ((p = ft_strchr(buf, '\n')))
<<<<<<< HEAD
		{
			*p = '\0';
			p++;
			*ost = ft_strdup(p);
		}
=======
			find_n(p, &str);
>>>>>>> 8cde57745f28dbfa976e0436c22b0a6c4e512ace
		tmp = *line;
		if (!(*line = ft_strjoin(*line, buf)) || d < 0)
			return (-1);
		free(tmp);
	}
<<<<<<< HEAD
	return (d || ft_strlen(*line)) ? 1 : 0;
}

gnl		*new_lst(int fd)
{
	gnl *new;

	new = (gnl *)malloc(sizeof(gnl));
	new->fd = fd;
	new->ost = NULL;
	new->next = NULL;
	return (new);
}

int	get_next_line(int fd, char **line)
{
	static gnl *head;
	gnl *tmp;

	if (fd < 0 || line == NULL || fd > 10240 ||
			read(fd, NULL, 0) == -1 || BUFF_SIZE <= 0)
		return (-1);
	if (head == NULL)
		head = new_lst(fd);
	tmp = head;
	while (tmp->fd != fd)
	{
		if (tmp->next == NULL)
			tmp->next = new_lst(fd);
		tmp = tmp->next;
	}
	return (get_line(tmp->fd, line, &tmp->ost));
=======
	return ((d || ft_strlen(*line)) ? 1 : 0);
>>>>>>> 8cde57745f28dbfa976e0436c22b0a6c4e512ace
}

int		main(void)
{
	int		fd1;
//	int fd2;
	char	*line;
	int count;

	count = 0;
	fd1 = open("1.txt", O_RDONLY);
//	fd2 = open("2.txt", O_RDONLY);
	while (get_next_line(fd1, &line) && count < 3)
	{
		printf("%s\n", line);
		count++;
	}
/*	while (get_next_line(fd2, &line) && count < 6)
	{
		printf("%s\n", line);
		count++;
	}
	while (get_next_line(fd1, &line) && count < 9)
	{
		printf("%s\n", line);
		count++;
	}

*/
		return (0);
}

