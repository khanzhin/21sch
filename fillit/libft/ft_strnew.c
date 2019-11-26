/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wtodd <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 13:29:32 by wtodd             #+#    #+#             */
/*   Updated: 2019/09/25 14:59:13 by wtodd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char *str;

	if (size > size + 1)
		return (NULL);
	str = NULL;
	str = (char *)malloc(size + 1);
	if (str == NULL)
	{
		return (NULL);
	}
	ft_bzero(str, size + 1);
	return (str);
}
