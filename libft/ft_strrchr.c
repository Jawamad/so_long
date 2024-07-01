/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flmuller <flmuller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 13:40:02 by flmuller          #+#    #+#             */
/*   Updated: 2023/10/12 14:51:05 by flmuller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*str;

	str = (char *) s;
	i = ft_strlen(str);
	if ((char)c == '\0')
		return (&str[i]);
	i--;
	while (i >= 0)
	{
		if (str[i] == (char) c)
			return (&str[i]);
		i--;
	}
	return (NULL);
}
