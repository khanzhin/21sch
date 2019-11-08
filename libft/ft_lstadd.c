<<<<<<< HEAD

#include "libft.h"

void			ft_lstadd(t_list **alst, t_list *new)
{
	new->next = (*alst);
	*alst = new;
=======
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wtodd <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 16:02:46 by wtodd             #+#    #+#             */
/*   Updated: 2019/10/25 11:07:49 by wtodd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd(t_list **alst, t_list *new)
{
	if (new != NULL)
	{
		new->next = *alst;
		*alst = new;
	}
>>>>>>> 8cde57745f28dbfa976e0436c22b0a6c4e512ace
}
