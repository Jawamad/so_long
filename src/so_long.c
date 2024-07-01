/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flmuller <flmuller@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 14:46:05 by flmuller          #+#    #+#             */
/*   Updated: 2024/07/01 13:17:46 by flmuller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	check_ext(char *file)
{
	int		i;
	int		j;
	char	*ext;

	ext = ".ber";
	i = 0;
	j = 0;
	while (file[i])
		i++;
	i = i - 4;
	while (file[i])
	{
		if (file[i] != ext[j])
			ft_error(1);
		j++;
		i++;
	}
}

int	render_frame(t_data *data)
{
	if (data->is_paused == 0 && data->map_data.m_count > 0)
	{
		data->loop++;
		if (data->loop % 5000 == 0)
			enemy_patrol(data);
		if (data->loop % 5000 == 0 && data->loop > 100000)
		{
			if (data->curr_frame < 4)
				next_frame(data);
			else if (data->curr_frame < 8)
				next_frame_re(data);
			else
				data->curr_frame = 0;
		}
	}
	return (data->loop);
}

void	next_frame(t_data *data)
{
	if (data->curr_frame == 0)
	{
		display_img(data, data->img.p_anim_f1,
			data->map_data.p_pos.y, data->map_data.p_pos.x);
	}
	else if (data->curr_frame == 1)
	{
		display_img(data, data->img.p_anim_f2,
			data->map_data.p_pos.y, data->map_data.p_pos.x);
	}
	else if (data->curr_frame == 2)
	{
		display_img(data, data->img.p_anim_f3,
			data->map_data.p_pos.y, data->map_data.p_pos.x);
	}
	else if (data->curr_frame == 3)
	{
		display_img(data, data->img.p_anim_f4,
			data->map_data.p_pos.y, data->map_data.p_pos.x);
	}
	data->curr_frame++;
}

void	next_frame_re(t_data *data)
{
	if (data->curr_frame == 4)
	{
		display_img(data, data->img.p_anim_f4,
			data->map_data.p_pos.y, data->map_data.p_pos.x);
	}
	else if (data->curr_frame == 5)
	{
		display_img(data, data->img.p_anim_f3,
			data->map_data.p_pos.y, data->map_data.p_pos.x);
	}
	else if (data->curr_frame == 6)
	{
		display_img(data, data->img.p_anim_f2,
			data->map_data.p_pos.y, data->map_data.p_pos.x);
	}
	else if (data->curr_frame == 7)
	{
		display_img(data, data->img.p_anim_f1,
			data->map_data.p_pos.y, data->map_data.p_pos.x);
	}
	data->curr_frame++;
}

int	main(int ac, char **av)
{
	t_data	data;

	if (ac != 2)
		ft_error(0);
	check_ext(av[1]);
	map_checker(av[1], &data);
	display_map(&data);
	data.loop = 0;
	data.is_paused = 0;
	data.patrol_dir = 0;
	data.curr_frame = 0;
	mlx_key_hook(data.mlx_win, handle_events, &data);
	mlx_loop_hook(data.mlx, render_frame, &data);
	mlx_hook(data.mlx_win, 17, 0, close_window, &data);
	mlx_loop(data.mlx);
	return (0);
}
