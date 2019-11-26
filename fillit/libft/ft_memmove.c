/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wtodd <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 14:50:30 by wtodd             #+#    #+#             */
/*   Updated: 2019/09/25 14:48:03 by wtodd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t		i;
	char		*d;
	const char	*s;

	i = 0;
	d = dst;
	s = src;
	if (d <= s || d >= (s + len))
	{
		ft_memcpy(d, s, len);
	}
	else
	{
		d = d + (len - 1);
		s = s + (len - 1);
		while (len != 0)
		{
			d[i] = s[i];
			i--;
			len--;
		}
	}
	return (dst);
}
