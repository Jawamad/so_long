/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flmuller <flmuller@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 15:36:37 by flmuller          #+#    #+#             */
/*   Updated: 2024/06/30 15:20:04 by flmuller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

unsigned int	ft_strlen_line(char *s)
{
	unsigned int	i;

	i = 0;
	while (s[i] && s[i] != '\n')
		i++;
	return (i);
}

void	display_black_rectangle(t_data *data, t_pos pos, int width, int height)
{
	int	x;
	int	y;
	int	min_x;
	int	max_x;
	int	max_y;

	x = pos.x;
	y = pos.y;
	max_y = y + height;
	min_x = x;
	max_x = x + width ;
	while (y < max_y)
	{
		x = min_x;
		while (x < max_x)
		{
			mlx_pixel_put(data->mlx, data->mlx_win, x, y, 0);
			x++;
		}
		y++;
	}
}
