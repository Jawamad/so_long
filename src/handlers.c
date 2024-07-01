/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handlers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flmuller <flmuller@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 18:36:29 by flmuller          #+#    #+#             */
/*   Updated: 2024/06/30 18:15:37 by flmuller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	handle_events(int keycode, t_data *data)
{
	if (keycode == 65307)
		quit_game(data);
	if ((keycode >= 65361 && keycode <= 65364) || keycode == 119
		|| keycode == 115 || keycode == 97 || keycode == 100)
	{
		if (data->is_paused == 0)
		{
			data->loop = 0;
			data->curr_frame = 0;
			move(data, keycode);
		}
	}
	if (keycode == 32 && data->is_paused != 2)
		pause_game(data);
	check_loose(data);
	if (data->map_data.c_collected == data->map_data.c_count
		&& data->is_paused == 0)
	{
		display_img(data, data->img.exit_opened, data->map_data.e_pos.y,
			data->map_data.e_pos.x);
		if (data->map_data.e_pos.x == data->map_data.p_pos.x
			&& data->map_data.e_pos.y == data->map_data.p_pos.y)
			win(data);
	}
	return (0);
}

int	close_window(t_data *data)
{
	quit_game(data);
	exit(0);
}

void	quit_game(t_data *data)
{
	int	i;

	destroy_img(data);
	i = 0;
	while (data->map_data.map[i])
		free(data->map_data.map[i++]);
	free(data->map_data.map);
	mlx_destroy_window(data->mlx, data->mlx_win);
	mlx_destroy_display(data->mlx);
	free(data->mlx);
	exit (0);
}

void	count_move(t_data *data)
{
	char	*moves;
	t_pos	pos;

	pos.x = 10;
	pos.y = data->map_data.nb_row * 64 - 30;
	data->nb_moves++;
	ft_printf("nb noves : %d\n", data->nb_moves);
	moves = ft_itoa(data->nb_moves);
	display_black_rectangle(data, pos, 30, 20);
	mlx_string_put(data->mlx, data->mlx_win, 15,
		data->map_data.nb_row * 64 - 15, 0xFFFFFF, moves);
	free(moves);
}

void	pause_game(t_data *data)
{
	int		text_x;
	int		text_y;
	int		i;
	t_pos	pos;

	data->is_paused = !data->is_paused;
	if (data->is_paused == 1)
	{
		text_x = (data->map_data.nb_column * 64 - 100) / 2;
		text_y = 30;
		pos.x = text_x - 30;
		pos.y = 0;
		display_black_rectangle(data, pos, 128, 60);
		mlx_string_put(data->mlx, data->mlx_win, text_x, text_y,
			0xFFFFFF, "Game Paused");
	}
	else
	{
		i = 0;
		while (data->map_data.map[0][i])
			display_img(data, data->img.wall, i++, 0);
	}
}
