/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wtodd <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 09:09:16 by wtodd             #+#    #+#             */
/*   Updated: 2019/09/18 11:22:35 by wtodd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	int		i;
	int		j;
	char	*str;

	if (!s)
		return (NULL);
	i = 0;
	str = NULL;
	j = ft_strlen(s);
	while ((s[i] == ' ' || s[i] == '\n' || s[i] == '\t') && s[i] != '\0')
		i++;
	while ((s[j - 1] == ' ' || s[j - 1] == '\n' || s[j - 1] == '\t') && j > i)
		j--;
	if (i >= j)
	{
		str = ft_strnew(0);
		return (str);
	}
	str = ft_strnew(j - i);
	if (str == NULL)
		return (NULL);
	ft_strncpy(str, &s[i], (j - i));
	return (str);
}
