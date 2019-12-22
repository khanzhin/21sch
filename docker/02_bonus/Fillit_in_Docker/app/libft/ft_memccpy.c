/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wtodd <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 13:21:33 by wtodd             #+#    #+#             */
/*   Updated: 2019/09/17 17:38:25 by wtodd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t				i;
	unsigned char		*d;
	unsigned const char	*s;

	i = 0;
	d = (unsigned char*)dst;
	s = (unsigned char*)src;
	if (n == 0)
		return (NULL);
	while (n > i)
	{
		if (s[i] == (unsigned char)c)
		{
			d[i] = s[i];
			return (d + i + 1);
		}
		d[i] = s[i];
		i++;
	}
	return (NULL);
}
