/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wtodd <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/30 11:01:20 by wtodd             #+#    #+#             */
/*   Updated: 2019/10/29 12:57:15 by wtodd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	char	*chek_str(char *str, char **line)
{
	char *p;
	char *tmp;

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
			ft_strclr(str);
		}
	}
	else
		*line = ft_strnew(1);
	return (p);
}

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
{
	static char	*str;
	char		buf[BUFF_SIZE + 1];
	int			d = 1;
	char		*p;
	char		*tmp;

	if (fd < 0 || !line || fd > 10240 ||
<<<<<<< HEAD:Get_Next_Line/gnl_main.c
			read(fd, NULL, 0) == -1 || BUFF_SIZE <= 0)
=======
			read(fd, buf, 0) == -1 || BUFF_SIZE < 1)
>>>>>>> 8cde57745f28dbfa976e0436c22b0a6c4e512ace:fillit_team/libft/get_next_line.c
		return (-1);
	d = 1;
	p = chek_str(str, line);
	while (!p && (d = read(fd, buf, BUFF_SIZE)))
	{
		buf[d] = '\0';
		if ((p = ft_strchr(buf, '\n')))
			find_n(p, &str);
		tmp = *line;
		if (!(*line = ft_strjoin(*line, buf)) || d < 0)
			return (-1);
		free(tmp);
	}
<<<<<<< HEAD:Get_Next_Line/gnl_main.c
	return (d || ft_strlen(*line)) ? 1 : 0;
}

int		main(void)
{
	int		fd;
	char	*line;

	fd = open("2.txt", O_RDONLY);
	while (get_next_line(fd, &line))
		printf("%s\n", line);
	return (0);
=======
	return ((d || ft_strlen(*line)) ? 1 : 0);
>>>>>>> 8cde57745f28dbfa976e0436c22b0a6c4e512ace:fillit_team/libft/get_next_line.c
}
