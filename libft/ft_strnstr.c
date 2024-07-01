/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flmuller <flmuller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 10:31:20 by flmuller          #+#    #+#             */
/*   Updated: 2023/10/12 15:06:58 by flmuller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	unsigned int	i;
	unsigned int	k;

	i = 0;
	k = 0;
	if (little[i])
	{
		while (big[i + k] && i + k < len)
		{
			if (big[i + k] == little[k])
				k++;
			else if (!little[k])
				return ((char *)big + i);
			else
			{
				i++;
				k = 0;
			}
		}
		if (!little[k])
			return ((char *)big + i);
		return (NULL);
	}
	return ((char *)big);
}
