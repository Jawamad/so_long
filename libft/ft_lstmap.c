/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flmuller <flmuller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 16:38:54 by flmuller          #+#    #+#             */
/*   Updated: 2023/10/16 17:38:54 by flmuller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*nlist;

	if (!lst)
		return (NULL);
	new = ft_lstnew((*f)(lst->content));
	if (!new)
		return (NULL);
	nlist = new;
	lst = lst->next;
	while (lst)
	{
		new->next = ft_lstnew((*f)(lst->content));
		if (!new)
		{
			ft_lstclear(&nlist, (*del));
			return (0);
		}
		new = new->next;
		lst = lst->next;
	}
	return (nlist);
}
