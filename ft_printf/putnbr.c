/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putnbr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flmuller <flmuller@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 14:25:52 by flmuller          #+#    #+#             */
/*   Updated: 2024/05/28 13:53:49 by flmuller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr(int n, int *countchar)
{
	long int	number;

	number = n;
	if (number < 0)
	{
		number = -number;
		ft_putchar('-', countchar);
	}
	if (number > 9)
		ft_putnbr(number / 10, countchar);
	ft_putchar(number % 10 + '0', countchar);
}

void	ft_putnbr_base_uint(unsigned int nbr, char *base, int *countchar)
{
	int			base_len;

	base_len = 0;
	base_len = ft_strlen_printf(base);
	if ((ft_checkbase(base, base_len)) == 1)
	{
		if (nbr >= (unsigned int)base_len)
			ft_putnbr_base_uint((nbr / base_len), base, countchar);
		ft_putchar(base[nbr % base_len], countchar);
	}
}

void	ft_putnbr_base_ulong(unsigned long nbr, char *base, int *countchar)
{
	int			base_len;

	base_len = 0;
	base_len = ft_strlen_printf(base);
	if ((ft_checkbase(base, base_len)) == 1)
	{
		if (nbr >= (unsigned long)base_len)
			ft_putnbr_base_ulong((nbr / base_len), base, countchar);
		ft_putchar(base[nbr % base_len], countchar);
	}
}
