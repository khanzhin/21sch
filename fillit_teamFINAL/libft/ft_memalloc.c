/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wtodd <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 10:37:04 by wtodd             #+#    #+#             */
/*   Updated: 2019/09/25 14:43:56 by wtodd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	char *str;

	if (size == 0)
		return (NULL);
	str = NULL;
	str = malloc(size);
	if (str == NULL)
		return (NULL);
	ft_bzero(str, size);
	return (str);
}
