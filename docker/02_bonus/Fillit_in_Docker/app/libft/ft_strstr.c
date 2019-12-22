/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wtodd <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/15 09:31:55 by wtodd             #+#    #+#             */
/*   Updated: 2019/09/18 11:59:42 by wtodd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	int i;

	i = 0;
	if (ft_strlen(needle) == 0)
	{
		return (&((char*)haystack)[i]);
	}
	while (haystack[i] != '\0')
	{
		if (ft_strncmp(&haystack[i], needle, ft_strlen(needle)) == 0)
		{
			return (&((char*)haystack)[i]);
		}
		i++;
	}
	return (NULL);
}
