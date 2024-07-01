/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   finish.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flmuller <flmuller@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 16:48:10 by flmuller          #+#    #+#             */
/*   Updated: 2024/06/30 18:49:39 by flmuller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	win(t_data *data)
{
	t_pos	pos;

	pos.x = 0;
	pos.y = 0;
	data->is_paused = 2;
	display_black_rectangle(data, pos, data->map_data.nb_column * 64,
		data->map_data.nb_row * 64);
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->img.win,
		(data->map_data.width / 2 - 160), (data->map_data.height / 2 - 90));
	mlx_do_sync(data->mlx);
}

void	loose(t_data *data)
{
	t_pos	pos;

	pos.x = 0;
	pos.y = 0;
	data->is_paused = 2;
	display_black_rectangle(data, pos, data->map_data.nb_column * 64,
		data->map_data.nb_row * 64);
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->img.loose,
		(data->map_data.width / 2 - 160), (data->map_data.height / 2 - 32));
	mlx_do_sync(data->mlx);
}

void	check_loose(t_data *data)
{
	if (data->map_data.m_pos.x == data->map_data.p_pos.x
		&& data->map_data.m_pos.y == data->map_data.p_pos.y)
		loose(data);
}

void	destroy_img(t_data *data)
{
	mlx_destroy_image(data->mlx, data->img.collectible);
	mlx_destroy_image(data->mlx, data->img.enemy_f1);
	mlx_destroy_image(data->mlx, data->img.exit_closed);
	mlx_destroy_image(data->mlx, data->img.exit_opened);
	mlx_destroy_image(data->mlx, data->img.ground);
	mlx_destroy_image(data->mlx, data->img.p_back_f1);
	mlx_destroy_image(data->mlx, data->img.p_face_f1);
	mlx_destroy_image(data->mlx, data->img.p_left_f1);
	mlx_destroy_image(data->mlx, data->img.p_right_f1);
	mlx_destroy_image(data->mlx, data->img.wall);
	mlx_destroy_image(data->mlx, data->img.win);
	mlx_destroy_image(data->mlx, data->img.loose);
	mlx_destroy_image(data->mlx, data->img.p_anim_f1);
	mlx_destroy_image(data->mlx, data->img.p_anim_f2);
	mlx_destroy_image(data->mlx, data->img.p_anim_f3);
	mlx_destroy_image(data->mlx, data->img.p_anim_f4);
}
