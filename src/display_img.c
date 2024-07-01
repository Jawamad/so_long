/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_img.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flmuller <flmuller@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 22:24:03 by flmuller          #+#    #+#             */
/*   Updated: 2024/06/30 18:48:40 by flmuller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	*convert_img(t_data *data, char *path)
{
	void	*img;

	img = mlx_xpm_file_to_image(data->mlx, path, &(data->img.size),
			&(data->img.size));
	return (img);
}

void	set_img(t_data *data)
{
	data->img.collectible = convert_img(data, "./assets/img/Collectible.xpm");
	data->img.enemy_f1 = convert_img(data, "./assets/img/Enemy_F1.xpm");
	data->img.exit_closed = convert_img(data, "./assets/img/Exit_Closed.xpm");
	data->img.exit_opened = convert_img(data, "./assets/img/Exit_Opened.xpm");
	data->img.ground = convert_img(data, "./assets/img/Ground.xpm");
	data->img.p_back_f1 = convert_img(data, "./assets/img/P_Back_F1.xpm");
	data->img.p_face_f1 = convert_img(data, "./assets/img/P_Face_F1.xpm");
	data->img.p_left_f1 = convert_img(data, "./assets/img/P_Left_F1.xpm");
	data->img.p_right_f1 = convert_img(data, "./assets/img/P_Right_F1.xpm");
	data->img.wall = convert_img(data, "./assets/img/Wall.xpm");
	data->img.win = convert_img(data, "./assets/img/win.xpm");
	data->img.loose = convert_img(data, "./assets/img/loose.xpm");
	data->img.p_anim_f1 = convert_img(data, "./assets/img/p_anim_f1.xpm");
	data->img.p_anim_f2 = convert_img(data, "./assets/img/p_anim_f2.xpm");
	data->img.p_anim_f3 = convert_img(data, "./assets/img/p_anim_f3.xpm");
	data->img.p_anim_f4 = convert_img(data, "./assets/img/p_anim_f4.xpm");
}

void	put_img_to_map(t_data *data)
{
	int	x;
	int	y;

	x = 0;
	while (data->map_data.map[x])
	{
		y = 0;
		while (data->map_data.map[x][y])
		{
			if (data->map_data.map[x][y] == '1')
				display_img(data, data->img.wall, y, x);
			if (data->map_data.map[x][y] == '0')
				display_img(data, data->img.ground, y, x);
			if (data->map_data.map[x][y] == 'P')
				display_img(data, data->img.p_face_f1, y, x);
			if (data->map_data.map[x][y] == 'C')
				display_img(data, data->img.collectible, y, x);
			if (data->map_data.map[x][y] == 'E')
				display_img(data, data->img.exit_closed, y, x);
			if (data->map_data.map[x][y] == 'M')
				display_img(data, data->img.enemy_f1, y, x);
			y++;
		}
		x++;
	}
}

void	display_img(t_data *data, void *img, int y, int x)
{
	mlx_put_image_to_window(data->mlx, data->mlx_win, img,
		y * SIZE, x * SIZE);
}

void	display_map(t_data *data)
{
	data->map_data.height = data->map_data.nb_row * SIZE;
	data->map_data.width = data->map_data.nb_column * SIZE;
	data->mlx = mlx_init();
	if (data->mlx == NULL)
		return ;
	data->img.size = SIZE;
	set_img(data);
	data->mlx_win = mlx_new_window(data->mlx, data->map_data.width,
			data->map_data.height, "so_long");
	if (!data->mlx_win)
	{
		free(data->mlx);
		return ;
	}
	put_img_to_map(data);
}
