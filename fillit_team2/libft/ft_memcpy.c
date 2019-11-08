/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wtodd <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 13:05:12 by wtodd             #+#    #+#             */
/*   Updated: 2019/09/25 14:47:13 by wtodd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t		i;
	char		*d;
	const char	*s;

	if (dst == NULL && src == NULL && n != 0)
		return (NULL);
	i = 0;
	d = dst;
	s = src;
	while (n != 0)
	{
		d[i] = s[i];
		i++;
		n--;
	}
	return (dst);
}
