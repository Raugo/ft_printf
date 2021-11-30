/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josuna-t <josuna-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 17:16:27 by josuna-t          #+#    #+#             */
/*   Updated: 2021/11/30 19:05:20 by josuna-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdio.h>
#include "ft_printf.h"

void	printp(unsigned long int n)
{
	char		temp;

	if (n >= 16)
	{
		printp(n / 16);
		if (n % 16 < 10)
			temp = (n % 16) + '0';
		else
			temp = n % 16 + 87;
		write(1, &temp, 1);
	}
	else
	{
		if (n < 10)
			temp = n + 48;
		else
			temp = n + 87;
		write(1, &temp, 1);
	}
}

int	countp(unsigned long int n)
{
	int	count;

	printp(n);
	count = 0;
	while (n >= 16)
	{
		n = n / 16;
		count++;
	}
	return (count);
}

int	numberlength(long long int value, int base, int modifier)
{
	int				count;
	long long int	tvalue;

	count = 1;
	tvalue = value;
	if (tvalue < 0)
	{
		tvalue = -tvalue;
		count++;
	}
	while (tvalue >= base)
	{
		tvalue = tvalue / base;
		count++;
	}
	ft_putnbr_fd(value, 1, base, modifier);
	return (count);
}

int	stringchecker(const char val, va_list arg)
{
	char	c;

	if (val == 's')
		return (ft_putstr_fd((char *)va_arg(arg, char *), 1));
	if (val == 'd' || val == 'i')
		return (numberlength(va_arg(arg, int), 10, 0));
	if (val == 'u')
		return (numberlength((unsigned int)va_arg(arg, unsigned int), 10, 0));
	if (val == 'x')
		return (numberlength((unsigned int)va_arg(arg, unsigned int), 16, 87));
	if (val == 'X')
		return (numberlength((unsigned int)va_arg(arg, unsigned int), 16, 55));
	if (val == 'p')
	{
		write(1, "0x", 2);
		return (3 + countp((unsigned long int)va_arg(arg, unsigned long int)));
	}
	if (val == 'c')
	{
		c = (char)va_arg(arg, int);
		write(1, &c, 1);
	}
	else
		write(1, &val, 1);
	return (1);
}

int	ft_printf(const char *str, ...)
{
	va_list	arguments;
	int		index;
	int		count;

	index = 0;
	count = 0;
	va_start (arguments, str);
	while (str[index] != 0)
	{
		if (str[index] == '%')
		{
			index++;
			count += stringchecker(str[index], arguments);
		}
		else
		{
			write(1, &str[index], 1);
			count++;
		}
		index++;
	}
	va_end(arguments);
	return (count);
}
