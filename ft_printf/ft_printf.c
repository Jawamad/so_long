/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flmuller <flmuller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 15:02:58 by flmuller          #+#    #+#             */
/*   Updated: 2023/10/24 18:11:19 by flmuller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	va_list	paraminfo;
	int		countchar;

	countchar = 0;
	va_start(paraminfo, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (isconv(*format))
				print(*format, paraminfo, &countchar);
		}
		else
			ft_putchar(*format, &countchar);
		format++;
	}
	va_end(paraminfo);
	return (countchar);
}

void	print(char select, va_list paraminfo, int *countchar)
{
	if (select == 's')
		ft_putstr(va_arg(paraminfo, char *), countchar);
	else if (select == 'c')
		ft_putchar(va_arg(paraminfo, int), countchar);
	else if (select == 'x')
		ft_putnbr_base_uint(va_arg(paraminfo, unsigned int),
			"0123456789abcdef", countchar);
	else if (select == 'X')
		ft_putnbr_base_uint(va_arg(paraminfo, unsigned int),
			"0123456789ABCDEF", countchar);
	else if (select == 'p')
		printpointer(va_arg(paraminfo, unsigned long), countchar);
	else if (select == 'd' || select == 'i')
		ft_putnbr(va_arg(paraminfo, int), countchar);
	else if (select == 'u')
		ft_putnbr_base_uint(va_arg(paraminfo, unsigned int),
			"0123456789", countchar);
	else if (select == '%')
		ft_putchar(select, countchar);
}

int	isconv(char c)
{
	return (c == 'c' || c == 's' || c == 'p' || c == 'd' || c == 'i'
		|| c == 'u' || c == 'x' || c == 'X' || c == '%');
}

void	printpointer(unsigned long pointer, int *countchar)
{
	if (!pointer)
		ft_putstr("(nil)", countchar);
	else
	{
		ft_putstr("0x", countchar);
		ft_putnbr_base_ulong(pointer, "0123456789abcdef", countchar);
	}
}

/*
int    main(void)
{
    ft_printf("ma fonction : %c\n", '0');
    printf("la vraie fonction : %c\n", '0');
    ft_printf("ma fonction : %s\n", "bonjour");
    printf("la vraie fonction : %s\n", "bonjour");
    ft_printf("ma fonction : %d\n", 123456);
    printf("la vraie fonction : %d\n", 123456);
    ft_printf("ma fonction : %i\n", 123456);
    printf("la vraie fonction : %i\n", 123456);
    ft_printf("ma fonction : %u\n", -123456);
    printf("la vraie fonction : %u\n", -123456);
    ft_printf("ma fonction : %x\n", 123456);
    printf("la vraie fonction : %x\n", 123456);
    ft_printf("ma fonction : %X\n", 123456);
    printf("la vraie fonction : %X\n", 123456);
    ft_printf("ma fonction : %%\n");
    printf("la vraie fonction : %%\n");
    ft_printf("ma fonction : %p\n", "bonjour");
    printf("la vraie fonction : %p\n", "bonjour");
    return (0);
}
*/
