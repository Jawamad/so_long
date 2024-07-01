/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftmpf.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flmuller <flmuller@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 12:51:47 by flmuller          #+#    #+#             */
/*   Updated: 2024/05/28 13:53:49 by flmuller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_checkbase(char *base, int base_len)
{
	int	i;
	int	j;

	i = 0;
	if (base[i] != '\0' && base_len > 1)
	{
		while (base[i] != '\0' && base[i] != '-' && base[i] != '+')
		{
			j = 0;
			while (base[j] != '\0' && (base[i] != base[j] || i == j))
				j++;
			if (j != base_len)
				return (0);
			i++;
		}
		if (i != base_len)
			return (0);
		return (1);
	}
	return (0);
}

void	ft_putchar(char c, int *countchar)
{
	*countchar += write(1, &c, 1);
}

void	ft_putstr(char *s, int *countchar)
{
	int	i;

	if (!s)
	{
		ft_putstr("(null)", countchar);
		return ;
	}
	i = 0;
	while (s[i])
	{
		ft_putchar(s[i], countchar);
		i++;
	}
}

size_t	ft_strlen_printf(const char *s)
{
	long int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}
