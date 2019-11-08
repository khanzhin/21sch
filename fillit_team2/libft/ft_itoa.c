/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wtodd <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 13:21:26 by wtodd             #+#    #+#             */
/*   Updated: 2019/09/21 10:46:47 by wtodd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_itoa(int n)
{
	int		i;
	char	*str;
	int		s;
	char	*m;

	i = 0;
	s = 1;
	m = "-2147483648";
	str = ft_strnew(ft_digitnumber(n));
	if (str == NULL)
		return (NULL);
	if (n == -2147483648)
		return (ft_strcpy(str, m));
	if (n < 0)
	{
		n = -n;
		str[i++] = '-';
		s = -1;
	}
	str[i++] = (n % 10) + '0';
	while ((n /= 10) > 0)
		str[i++] = (n % 10) + '0';
	ft_rev(str, s);
	return (str);
}
