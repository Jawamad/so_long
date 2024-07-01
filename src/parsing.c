/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flmuller <flmuller@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 16:33:11 by flmuller          #+#    #+#             */
/*   Updated: 2024/06/28 17:25:00 by flmuller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	map_checker(char *file, t_data *data)
{
	init_map_data(data);
	data->map_data.map = fill_map(file);
	check_rectangle(data);
	count_map_tile(data);
	valid_path(file, data);
}

void	check_rectangle(t_data *data)
{
	int	i;

	i = 0;
	data->map_data.nb_column = ft_strlen_line(data->map_data.map[i]);
	while (data->map_data.map[++i])
	{
		if (data->map_data.nb_column != ft_strlen_line(data->map_data.map[i]))
			ft_error_data(data, 0);
	}
	data->map_data.nb_row = i;
	if (data->map_data.nb_column == data->map_data.nb_row)
		ft_error_data(data, 1);
}

void	count_tile(char c, t_data *data)
{
	if (c != '0' && c != '1' && c != 'P' && c != 'C' && c != 'E'
		&& c != 'M' && c != '\n')
		ft_error_data(data, 2);
	if (c == 'P')
		data->map_data.p_count += 1;
	if (c == 'C')
		data->map_data.c_count += 1;
	if (c == 'E')
		data->map_data.e_count += 1;
	if (c == 'M')
		data->map_data.m_count += 1;
}

void	count_map_tile(t_data *data)
{
	int	x;
	int	y;

	x = 0;
	while (data->map_data.map[x])
	{
		y = 0;
		while (data->map_data.map[x][y] && data->map_data.map[x][y] != '\n')
		{
			count_tile(data->map_data.map[x][y], data);
			if (data->map_data.map[0][y] != '1')
				ft_error_data(data, 3);
			if (data->map_data.map[data->map_data.nb_row - 1][y] != '1')
				ft_error_data(data, 3);
			if (data->map_data.map[x][0] != '1')
				ft_error_data(data, 3);
			if (data->map_data.map[x][data->map_data.nb_column - 1] != '1')
				ft_error_data(data, 3);
			y++;
		}
		x++;
	}
	check_tiles(data);
}

void	check_tiles(t_data *data)
{
	if (data->map_data.c_count < 1)
		ft_error_data(data, 4);
	if (data->map_data.p_count != 1)
		ft_error_data(data, 5);
	if (data->map_data.e_count != 1)
		ft_error_data(data, 6);
	if (data->map_data.m_count > 1)
		ft_error_data(data, 7);
}
