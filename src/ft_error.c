/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flmuller <flmuller@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 15:42:35 by flmuller          #+#    #+#             */
/*   Updated: 2024/06/02 14:46:20 by flmuller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	ft_error(int code)
{
	errno = 1;
	if (code == 0)
		perror("Error\nWrong number of arguments ");
	if (code == 1)
		perror("Error\nInvalid extension ");
	if (code == 2)
		perror("Error\nMap is empty file ");
	exit(1);
}

void	ft_error_data(t_data *data, int code)
{
	int	i;

	errno = 1;
	i = 0;
	while (data->map_data.map[i])
		free(data->map_data.map[i++]);
	free(data->map_data.map);
	if (code == 0)
		perror("Error\nMap is not a rectangle ");
	if (code == 1)
		perror("Error\nImpossible to finish the map ");
	if (code == 2)
		perror("Error\nUnknow entity in the map ");
	if (code == 3)
		perror("Error\nOpen field in map limit ");
	if (code == 4)
		perror("Error\nMap need atleast one collectible to work ");
	if (code == 5)
		perror("Error\nMap need exactly 1 main character ");
	if (code == 6)
		perror("Error\nMap need exactly 1 exit, not one less, not one more ");
	if (code == 7)
		perror("Error\nMap can only have one monster ");
	exit(1);
}
