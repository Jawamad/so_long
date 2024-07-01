/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flmuller <flmuller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 15:40:14 by flmuller          #+#    #+#             */
/*   Updated: 2023/10/16 16:30:37 by flmuller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*tmplp;

	if (!*lst)
		return ;
	while (*lst)
	{
		tmplp = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = tmplp;
	}
}
