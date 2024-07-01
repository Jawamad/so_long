/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flmuller <flmuller@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 13:28:49 by flmuller          #+#    #+#             */
/*   Updated: 2024/05/28 13:54:25 by flmuller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdio.h>
# include <stdarg.h>

int		ft_printf(const char *format, ...);

int		isconv(char c);

int		ft_checkbase(char *base, int base_len);

void	ft_putnbr_base(int nbr, char *base, int *countchar);

void	ft_putchar(char c, int *countchar);

void	ft_putnbr(int n, int *countchar);

void	print(char select, va_list paraminfo, int *countchar);

void	printpointer(unsigned long pointer, int *countchar);

void	ft_putstr(char *s, int *countchar);

void	ft_putnbr_base_uint(unsigned int nbr, char *base, int *countchar);

void	ft_putnbr_base_ulong(unsigned long nbr, char *base, int *countchar);

size_t	ft_strlen_printf(const char *s);

#endif