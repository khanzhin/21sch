/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wtodd <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 16:09:18 by wtodd             #+#    #+#             */
/*   Updated: 2019/09/25 15:03:20 by wtodd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*str;

	if (!s)
		return (NULL);
	i = 0;
	str = NULL;
	str = ft_strnew(len);
	if (str == NULL)
		return (NULL);
	ft_strncpy(&str[i], &s[start], len);
	return (str);
}
