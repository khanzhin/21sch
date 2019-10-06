/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wtodd <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/15 12:40:55 by wtodd             #+#    #+#             */
/*   Updated: 2019/09/25 13:40:59 by wtodd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *dst, const char *src, size_t len)
{
	size_t i;

	i = 0;
	if (ft_strlen(src) == 0)
	{
		return (&((char*)dst)[i]);
	}
	while (dst[i] != '\0' && len >= ft_strlen(src))
	{
		if (ft_memcmp(&dst[i], src, ft_strlen(src)) == 0)
		{
			return (&((char*)dst)[i]);
		}
		i++;
		len--;
	}
	return (NULL);
}
