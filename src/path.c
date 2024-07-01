/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flmuller <flmuller@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 14:28:08 by flmuller          #+#    #+#             */
/*   Updated: 2024/06/30 16:44:05 by flmuller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	valid_path(char *file, t_data *data)
{
	char	**verif_map;
	t_pos	pos;
	int		i;

	init_entities_pos(data);
	verif_map = fill_map(file);
	pos = data->map_data.p_pos;
	flood_fill(verif_map, pos);
	i = 0;
	if (!check_path(verif_map))
	{
		while (verif_map[i])
			free(verif_map[i++]);
		free(verif_map);
		ft_error_data(data, 1);
	}
	i = 0;
	while (verif_map[i])
		free(verif_map[i++]);
	free(verif_map);
}

void	flood_fill(char **map, t_pos pos)
{
	if (map[pos.x][pos.y] == '1' || map[pos.x][pos.y] == 'F'
		|| map[pos.x][pos.y] == 'M')
		return ;
	if (map[pos.x][pos.y] == 'E')
	{
		map[pos.x][pos.y] = 'F';
		return ;
	}
	map[pos.x][pos.y] = 'F';
	flood_fill(map, (t_pos){pos.x, pos.y + 1});
	flood_fill(map, (t_pos){pos.x, pos.y - 1});
	flood_fill(map, (t_pos){pos.x + 1, pos.y});
	flood_fill(map, (t_pos){pos.x - 1, pos.y});
}

int	check_path(char **map)
{
	int	x;
	int	y;

	x = 0;
	while (map[x])
	{
		y = 0;
		while (map[x][y])
		{
			if (map[x][y] == 'C' || map[x][y] == 'E')
				return (0);
			y++;
		}
		x++;
	}
	return (1);
}
