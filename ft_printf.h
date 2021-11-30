/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josuna-t <josuna-t@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 19:45:39 by josuna-t          #+#    #+#             */
/*   Updated: 2021/11/30 19:03:31 by josuna-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
int		ft_printf(const char *str, ...);
int		ft_putstr_fd(char *s, int fd);
void	ft_putnbr_fd(long long int n, int fd, int base, int modifier);
#endif