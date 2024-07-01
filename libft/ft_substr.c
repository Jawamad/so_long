/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flmuller <flmuller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 15:59:24 by flmuller          #+#    #+#             */
/*   Updated: 2023/10/12 13:02:56 by flmuller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned int		i;
	char				*str;

	if (!s)
		return (NULL);
	i = 0;
	if (start >= ft_strlen((char *)s))
		return (ft_strdup(""));
	if (len > (ft_strlen((char *) s) - start))
		str = malloc(sizeof(char) * (ft_strlen((char *) s) - start + 1));
	else
		str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	i = 0;
	while (s[start + i] && i < len)
	{
		str[i] = s[start + i];
		i++;
	}
	str[i] = '\0';
	return (str);
}
