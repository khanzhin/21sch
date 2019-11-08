/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wtodd <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 16:44:06 by wtodd             #+#    #+#             */
/*   Updated: 2019/09/25 14:52:17 by wtodd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t				i;
	const unsigned char	*str;

	i = 0;
	str = s;
	while (n != 0)
	{
		if (str[i] == (unsigned char)c)
		{
			return ((void *)&((unsigned char*)str)[i]);
		}
		i++;
		n--;
	}
	return (NULL);
}
