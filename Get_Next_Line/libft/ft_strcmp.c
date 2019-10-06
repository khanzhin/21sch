/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wtodd <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 08:52:13 by wtodd             #+#    #+#             */
/*   Updated: 2019/09/17 17:34:28 by wtodd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strcmp(const char *s1, const char *s2)
{
	int					i;
	unsigned const char *a1;
	unsigned const char *a2;

	a1 = (unsigned char *)s1;
	a2 = (unsigned char *)s2;
	i = 0;
	while ((a1[i] != '\0' || a2[i] != '\0') && a1[i] == a2[i])
	{
		i++;
	}
	return (a1[i] - a2[i]);
}
