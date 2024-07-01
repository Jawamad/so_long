/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flmuller <flmuller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 11:30:04 by flmuller          #+#    #+#             */
/*   Updated: 2023/10/11 16:17:08 by flmuller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*res;

	if (!nmemb || !size)
		return (malloc(1));
	if (nmemb * size > 2147483647)
		return (0);
	res = malloc(nmemb * size);
	if (res)
		ft_bzero(res, nmemb * size);
	return (res);
}
