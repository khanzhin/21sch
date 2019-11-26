/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wtodd <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 08:46:32 by wtodd             #+#    #+#             */
/*   Updated: 2019/09/25 11:14:25 by wtodd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char *str;

	if (!s1 || !s2)
		return (NULL);
	str = NULL;
	str = ft_strnew((ft_strlen(s1) + ft_strlen(s2)));
	if (str == NULL)
		return (NULL);
	str = ft_strcpy(str, s1);
	ft_strcat(str, s2);
	return (str);
}
