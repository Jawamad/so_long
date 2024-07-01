/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flmuller <flmuller@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 13:44:09 by flmuller          #+#    #+#             */
/*   Updated: 2024/05/23 17:21:03 by flmuller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*stash[1024];
	char		*line;

	if (read(fd, 0, 0) < 0 || fd < 0 || BUFFER_SIZE <= 0)
		return (free_stash(&stash[fd]));
	if (!stash[fd])
		stash[fd] = ft_calloc(1, 1);
	stash[fd] = readline(fd, stash[fd]);
	line = cutline(stash[fd]);
	if (line)
		stash[fd] = cutstash(stash[fd]);
	else
		free_stash(&stash[fd]);
	return (line);
}

char	*readline(int fd, char *stash)
{
	char	*buffer;
	int		nbcread;

	nbcread = 1;
	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	while (!ft_strchr(stash, '\n') && nbcread > 0)
	{
		nbcread = read(fd, buffer, BUFFER_SIZE);
		buffer[nbcread] = 0;
		stash = ft_strjoin_gnl(stash, buffer);
	}
	free(buffer);
	return (stash);
}

unsigned int	whereendline(char *stash)
{
	int	i;

	i = 0;
	while (stash[i] != '\n' && stash[i])
		i++;
	if (stash[i] == '\n')
		i++;
	return (i);
}

char	*cutline(char *stash)
{
	char			*line;
	unsigned int	i;

	i = 0;
	line = ft_calloc((whereendline(stash) + 1), sizeof(char));
	while (i < whereendline(stash))
	{
		line[i] = stash[i];
		i++;
	}
	if (ft_strlen_gnl(line) < 1)
	{
		free(line);
		line = NULL;
	}
	return (line);
}

char	*cutstash(char *stash)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	size;
	char			*temp;

	i = whereendline(stash);
	size = ft_strlen_gnl(&stash[i]);
	temp = ft_calloc((size + 1), sizeof(char));
	j = 0;
	while (j <= size)
		temp[j++] = stash[i++];
	free(stash);
	stash = NULL;
	if (size == 0)
		free(temp);
	else
		stash = temp;
	return (stash);
}

/* 
#include <fcntl.h>
#include <stdio.h> 
int main()
{
	int		fd;
	char	*content;

	fd = open("test.txt", O_RDONLY);
	content = get_next_line(fd);
	while (content)
	{
		printf("%s", content);
		free(content);
		content = get_next_line(fd);
	} 
	free(content);
	close(fd);
	return (0);
} */
/*i nt main(void)
{
	int	fd;
	char *str;

	fd = open("test.txt", 0);
	str = get_next_line(fd);
	printf("%s", str);
	free(str);
	str = get_next_line(fd);
	printf("%s", str);
	free(str);
	str = get_next_line(fd);
	printf("%s", str);
	free(str);
	str = get_next_line(fd);
	printf("%s", str);
	free(str);
	// str = get_next_line(fd);
	// printf("%s", str);
	// free(str);
	// str = get_next_line(fd);
	// printf("%s", str);
	// free(str);
	// str = get_next_line(fd);
	// printf("%s", str);
	// free(str);
	// str = get_next_line(fd);
	// printf("%s", str);
	// free(str);
	// str = get_next_line(fd);
	// printf("%s", str);
	// free(str);
	close(fd);
} */