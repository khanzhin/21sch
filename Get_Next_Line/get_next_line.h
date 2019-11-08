/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wtodd <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/30 11:05:46 by wtodd             #+#    #+#             */
/*   Updated: 2019/10/22 16:58:02 by wtodd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
<<<<<<< HEAD
# define BUFF_SIZE 1000
=======

>>>>>>> 8cde57745f28dbfa976e0436c22b0a6c4e512ace
# include "libft/libft.h"
# define BUFF_SIZE 100

<<<<<<< HEAD
typedef struct	get_next_line
{
	int			fd;
	char		*ost;
	struct		get_next_line *next;
}gnl;

int				get_next_line(const int fd, char **line);
=======
int							get_next_line(const int fd, char **line);
>>>>>>> 8cde57745f28dbfa976e0436c22b0a6c4e512ace

#endif
