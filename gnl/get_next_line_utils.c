/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flmuller <flmuller@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 13:44:05 by flmuller          #+#    #+#             */
/*   Updated: 2024/05/23 17:21:03 by flmuller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	unsigned char	*res;
	unsigned int	tsize;
	unsigned int	i;

	tsize = nmemb * size;
	if (!nmemb || !size)
		return (malloc(0));
	if (tsize / size != nmemb || tsize / nmemb != size)
		return (0);
	res = malloc(tsize);
	if (res)
	{
		i = 0;
		while (i < tsize)
		{
			res[i] = '\0';
			i++;
		}
	}
	return ((void *)res);
}

char	*ft_strjoin_gnl(char *s1, char *s2)
{
	char	*newstr;
	int		size;
	int		i;
	int		j;

	i = 0;
	j = 0;
	size = ft_strlen_gnl((char *) s1) + ft_strlen_gnl((char *)s2) + 1;
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
	free(s1);
	return (newstr);
}

size_t	ft_strlen_gnl(const char *s)
{
	long int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int	ft_strchr(char *s, int c)
{
	int	i;

	i = -1;
	if (!s || !c)
		return (0);
	while (s[++i])
		if (s[i] == c)
			return (1);
	return (0);
}

char	*free_stash(char **stash)
{
	if (*stash)
		free(*stash);
	*stash = NULL;
	return (0);
}
