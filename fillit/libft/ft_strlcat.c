/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wtodd <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 17:22:26 by wtodd             #+#    #+#             */
/*   Updated: 2019/09/25 10:29:53 by wtodd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	l;
	size_t	n;

	i = 0;
	l = 0;
	if (size > ft_strlen(dst))
		n = ft_strlen(dst);
	else
		return (ft_strlen(src) + size);
	while (dst[i] != '\0' && size != 0)
	{
		i++;
		size--;
	}
	while (src[l] != '\0' && size != 1)
	{
		dst[i] = src[l];
		i++;
		size--;
		l++;
	}
	dst[i] = '\0';
	return (n + ft_strlen(src));
}
