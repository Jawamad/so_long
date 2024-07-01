/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flmuller <flmuller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 15:40:38 by flmuller          #+#    #+#             */
/*   Updated: 2023/10/12 11:40:24 by flmuller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_countunit(long int n)
{
	int	count;

	count = 0;
	while (n > 9)
	{
		count++;
		n = n / 10;
	}
	count++;
	return (count);
}

char	*ft_itoa(int n)
{
	long int	number;
	int			unit;
	char		*res;

	number = n;
	if (n < 0)
		number = number * -1;
	unit = ft_countunit(number);
	if (n < 0)
		unit++;
	res = malloc(sizeof(char) * (unit + 1));
	if (!res)
		return (NULL);
	res[unit--] = '\0';
	while (number > 9)
	{
		res[unit--] = (number % 10) + '0';
		number = number / 10;
	}
	res[unit--] = number + '0';
	if (n < 0)
		res[unit] = '-';
	return (res);
}
