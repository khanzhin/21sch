/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wtodd <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/30 11:05:46 by wtodd             #+#    #+#             */
/*   Updated: 2019/10/02 13:57:54 by wtodd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFF_SIZE 1000
# include "libft/libft.h"

typedef struct	get_next_line
{
	int			fd;
	char		*ost;
	struct		get_next_line *next;
}gnl;

int				get_next_line(const int fd, char **line);

#endif
