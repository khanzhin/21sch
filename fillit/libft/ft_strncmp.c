/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wtodd <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/15 11:09:35 by wtodd             #+#    #+#             */
/*   Updated: 2019/09/18 13:21:16 by wtodd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	int					i;
	unsigned const char *a1;
	unsigned const char *a2;

	a1 = (unsigned char *)s1;
	a2 = (unsigned char *)s2;
	i = 0;
	if (!n)
		return (0);
	while ((a1[i] != '\0' || a2[i] != '\0') && a1[i] == a2[i] && n - 1)
	{
		i++;
		n--;
	}
	return (a1[i] - a2[i]);
}
