/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wtodd <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/15 16:09:12 by wtodd             #+#    #+#             */
/*   Updated: 2019/09/23 13:50:22 by wtodd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_atoi(const char *str)
{
	int						i;
	unsigned long long int	n;
	int						sign;

	i = 0;
	n = 0;
	sign = 1;
	i = ft_prob(str, 0);
	if (str[i] == '-')
		sign = -1;
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (ft_isdigit(str[i]))
	{
		n = (10 * n) + (str[i++] - '0');
		if (n > 9223372036854775807 && sign > 0)
			return (-1);
		else if ((n / 10) >= 922337203685477580 &&
				(str[--i] + '0') > 8 && sign < 0)
			return (0);
	}
	return (n * sign);
}
