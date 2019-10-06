/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wtodd <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 11:56:42 by wtodd             #+#    #+#             */
/*   Updated: 2019/09/25 13:19:39 by wtodd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_free(char **s, int i)
{
	while (i >= 0)
	{
		free(s[i]);
		s[i] = NULL;
		i--;
	}
	free(s);
	s = NULL;
}

char		**ft_strsplit(char const *s, char c)
{
	int		i;
	char	**str;
	size_t	f;
	int		d;

	i = 0;
	d = 0;
	if (!s || !(str = (char **)malloc(sizeof(char *) * (ft_strword(s, c) + 1))))
		return (NULL);
	while (s[i] != '\0')
	{
		if (s[i] != c)
		{
			f = ft_adr(s, c, i);
			if ((str[d++] = ft_strsub(s, i, f)) == NULL)
			{
				ft_free(str, d - 1);
				return (NULL);
			}
			i = i + f - 1;
		}
		i++;
	}
	str[d] = NULL;
	return (str);
}
