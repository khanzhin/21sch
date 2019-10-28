/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wtodd <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 14:20:35 by wtodd             #+#    #+#             */
/*   Updated: 2019/10/25 14:24:41 by wtodd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *listok;

	if (f != NULL && lst != NULL)
	{
		listok = f(lst);
		if (listok != NULL && lst->next != NULL)
			listok->next = ft_lstmap(lst->next, f);
		return (listok);
	}
	return (NULL);
}
