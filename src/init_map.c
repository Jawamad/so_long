/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flmuller <flmuller@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 14:22:41 by flmuller          #+#    #+#             */
/*   Updated: 2024/06/02 15:33:33 by flmuller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

char	**fill_map(char *file)
{
	int		i;
	int		fd;
	char	**map;
	int		verif;

	if (!check_nb_line(file))
		ft_error(2);
	map = malloc(sizeof(char *) * (check_nb_line(file) + 1));
	if (!map)
		return (NULL);
	i = 0;
	verif = 1;
	fd = open(file, O_RDONLY);
	while (verif)
	{
		map[i] = get_next_line(fd);
		if (map[i])
			i++;
		else
			verif = 0;
	}
	close(fd);
	map[i] = 0;
	return (map);
}

void	init_map_data(t_data *data)
{
	data->map_data.nb_column = 0;
	data->map_data.nb_row = 0;
	data->map_data.c_count = 0;
	data->map_data.e_count = 0;
	data->map_data.p_count = 0;
	data->map_data.m_count = 0;
	data->map_data.c_collected = 0;
	data->map_data.width = 0;
	data->map_data.height = 0;
	data->nb_moves = 0;
}

void	init_entities_pos(t_data *data)
{
	int	x;
	int	y;

	x = 0;
	while (data->map_data.map[x])
	{
		y = 0;
		while (data->map_data.map[x][y])
		{
			set_pos(data, x, y);
			y++;
		}
		x++;
	}
}

void	set_pos(t_data *data, int x, int y)
{
	if (data->map_data.map[x][y] == 'P')
	{
		data->map_data.p_pos.x = x;
		data->map_data.p_pos.y = y;
	}
	if (data->map_data.map[x][y] == 'E')
	{
		data->map_data.e_pos.x = x;
		data->map_data.e_pos.y = y;
	}
	if (data->map_data.map[x][y] == 'M')
	{
		data->map_data.m_pos.x = x;
		data->map_data.m_pos.y = y;
	}
}

int	check_nb_line(char *file)
{
	int		i;
	int		fd;
	char	*line;
	int		verif;

	verif = 1;
	i = 0;
	fd = open(file, O_RDONLY);
	while (verif)
	{
		line = get_next_line(fd);
		if (line)
			i++;
		else
			verif = 0;
		free(line);
	}
	close(fd);
	return (i);
}
