/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flmuller <flmuller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 14:42:47 by flmuller          #+#    #+#             */
/*   Updated: 2023/10/11 15:23:38 by flmuller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	unsigned int	i;
	unsigned int	k;
	unsigned int	j;

	i = 0;
	k = 0;
	j = 0;
	while (i < size && dst[i])
		i++;
	while (src[j])
		j++;
	if (i != size)
	{
		while (src[k] && i + k < size -1)
		{
			dst[i + k] = src[k];
			k++;
		}
		dst[i + k] = '\0';
	}
	return (i + j);
}
