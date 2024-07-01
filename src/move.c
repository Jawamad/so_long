/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flmuller <flmuller@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 15:55:35 by flmuller          #+#    #+#             */
/*   Updated: 2024/06/30 15:04:23 by flmuller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	move(t_data *data, int keycode)
{
	t_pos	*new_pos;
	void	*m_sprite;

	count_move(data);
	new_pos = gen_new_pos(data, keycode);
	m_sprite = select_move_sprite(data, new_pos);
	if (data->map_data.map[new_pos->x][new_pos->y] == '1'
		|| (data->map_data.map[new_pos->x][new_pos->y] == 'E'
		&& data->map_data.c_collected != data->map_data.c_count))
		display_img(data, m_sprite, data->map_data.p_pos.y,
			data->map_data.p_pos.x);
	else
	{
		if (data->map_data.map[new_pos->x][new_pos->y] == 'C')
		{
			data->map_data.c_collected++;
			data->map_data.map[new_pos->x][new_pos->y] = '0';
		}
		display_img(data, m_sprite, new_pos->y, new_pos->x);
		display_img(data, data->img.ground, data->map_data.p_pos.y,
			data->map_data.p_pos.x);
		data->map_data.p_pos.x = new_pos->x;
		data->map_data.p_pos.y = new_pos->y;
	}
	free(new_pos);
}

void	*select_move_sprite(t_data *data, t_pos *new_pos)
{
	void	*sprite;

	if (data->map_data.p_pos.x < new_pos->x)
		sprite = data->img.p_face_f1;
	else if (data->map_data.p_pos.x > new_pos->x)
		sprite = data->img.p_back_f1;
	else if (data->map_data.p_pos.y < new_pos->y)
		sprite = data->img.p_right_f1;
	else if (data->map_data.p_pos.y > new_pos->y)
		sprite = data->img.p_left_f1;
	return (sprite);
}

t_pos	*gen_new_pos(t_data *data, int keycode)
{
	t_pos	*new;

	new = malloc(sizeof(t_pos));
	new->x = data->map_data.p_pos.x;
	new->y = data->map_data.p_pos.y;
	if (keycode == 65362 || keycode == 119)
		new->x--;
	else if (keycode == 65364 || keycode == 115)
		new->x++;
	else if (keycode == 65361 || keycode == 97)
		new->y--;
	else if (keycode == 65363 || keycode == 100)
		new->y++;
	return (new);
}

void	enemy_patrol(t_data *data)
{
	int		x;
	int		y;

	x = data->map_data.m_pos.x;
	y = data->map_data.m_pos.y;
	if (check_patrol_path(x, y, data) != x)
	{
		display_img(data, data->img.ground, y, x);
		data->map_data.map[x][y] = '0';
		x = check_patrol_path(x, y, data);
		data->map_data.m_pos.x = x;
		data->map_data.map[x][y] = 'M';
		display_img(data, data->img.enemy_f1, y, x);
	}
	check_loose(data);
}

int	check_patrol_path(int x, int y, t_data *data)
{
	char	c_up;
	char	c_down;

	c_up = data->map_data.map[x + 1][y];
	c_down = data->map_data.map[x - 1][y];
	if (c_up != '1' && c_up != 'E' && c_up != 'C' && !data->patrol_dir)
		x++;
	else if (c_down != '1' && c_down != 'E' && c_down != 'C'
		&& data->patrol_dir)
		x--;
	else
		data->patrol_dir = !data->patrol_dir;
	return (x);
}
