/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flmuller <flmuller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 16:16:21 by flmuller          #+#    #+#             */
/*   Updated: 2023/10/12 13:27:48 by flmuller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*newstr;
	int		size;
	int		i;
	int		j;

	i = 0;
	j = 0;
	size = ft_strlen((char *) s1) + ft_strlen((char *)s2) + 1;
	newstr = malloc(sizeof(char) * size);
	if (newstr)
	{
		while (s1[i])
		{
			newstr[i] = s1[i];
			i++;
		}
		while (s2[j])
		{
			newstr[i + j] = s2[j];
			j++;
		}
		newstr[i + j] = '\0';
	}
	return (newstr);
}
