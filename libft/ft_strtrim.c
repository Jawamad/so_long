/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flmuller <flmuller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 17:34:36 by flmuller          #+#    #+#             */
/*   Updated: 2023/10/12 14:25:02 by flmuller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isinset(char c, char const *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	unsigned int		i;
	unsigned int		j;
	unsigned int		k;
	char				*str;

	i = 0;
	j = ft_strlen((char *)s1) - 1;
	while (ft_isinset(s1[i], set))
		i++;
	if (i == ft_strlen((char *)s1))
		return (ft_strdup(""));
	while (ft_isinset(s1[j], set))
		j--;
	str = malloc(sizeof(char) * (j - i + 2));
	if (!str)
		return (NULL);
	k = 0;
	while (i <= j)
	{
		str[k] = s1[i];
		i++;
		k++;
	}
	str[k] = '\0';
	return (str);
}
