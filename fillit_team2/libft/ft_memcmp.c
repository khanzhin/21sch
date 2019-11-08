/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wtodd <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 10:11:51 by wtodd             #+#    #+#             */
/*   Updated: 2019/09/25 14:52:33 by wtodd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t		i;
	const char	*str1;
	const char	*str2;

	str1 = s1;
	str2 = s2;
	i = 0;
	if (!n)
		return (0);
	while (((unsigned char*)str1)[i] == ((unsigned char*)str2)[i] && n != 0)
	{
		n--;
		if (n == 0)
			return (((unsigned char*)str1)[i] - ((unsigned char*)str2)[i]);
		i++;
	}
	return (((unsigned char*)str1)[i] - ((unsigned char*)str2)[i]);
}
