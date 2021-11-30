/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printfutils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josuna-t <josuna-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 17:53:45 by josuna-t          #+#    #+#             */
/*   Updated: 2021/11/30 19:03:22 by josuna-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
void	ft_putnbr_fd(long long int n, int fd, int base, int modifier)
{
	char	temp;
	{
		if (n < 0)
		{
			write(fd, "-", 1);
			ft_putnbr_fd(-n, fd, base, modifier);
		}
		else if (n > base - 1)
		{
			ft_putnbr_fd(n / base, fd, base, modifier);
			if (n % base < 10)
				temp = (n % base) + '0';
			else
				temp = n % base + modifier;
			write(fd, &temp, 1);
		}
		else
		{
			if (n < 10)
				temp = n + 48;
			else
				temp = n + modifier;
			write(fd, &temp, 1);
		}
	}
}

int	ft_putstr_fd(char *s, int fd)
{
	int	count;

	count = 0;
	if (!s)
	{
		write(1, "(null)", 6);
		return (6);
	}
	else
	{
		while (*s != 0)
		{
			write (fd, s, 1);
			s++;
			count++;
		}
	}
	return (count);
}
