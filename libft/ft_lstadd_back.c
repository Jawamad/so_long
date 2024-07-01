/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flmuller <flmuller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 15:01:31 by flmuller          #+#    #+#             */
/*   Updated: 2023/10/16 15:26:14 by flmuller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*pl;

	if (!new)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	pl = *lst;
	while (pl->next)
		pl = pl->next;
	pl->next = new;
}
