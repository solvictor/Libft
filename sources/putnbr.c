/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putnbr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vegret <victor.egret.pro@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 20:30:40 by vegret            #+#    #+#             */
/*   Updated: 2023/02/07 21:52:06 by vegret           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	intlen(int n)
{
	int	len;

	len = 1;
	while (n > 9 || n < -9)
	{
		n /= 10;
		len++;
	}
	return (len);
}

static int	putint_aux(int fd, int n)
{
	if (n == -2147483648)
		return (putstr(fd, "2147483648", NULL));
	if (n < 10)
		return (putchar_c(fd, n + '0', NULL));
	return (putint_aux(fd, n / 10) + putint_aux(fd, n % 10));
}

static int	printinglen(int n, t_flag *flag)
{
	int	len;

	len = intlen(n);
	if (flag && flag->flags & DOT && flag->precision > len)
		len = flag->precision;
	if (n == 0 && flag && flag->flags & DOT && flag->precision == 0)
		len = 0;
	len += (n < 0 || flag->flags & SPACE || flag->flags & PLUS);
	return (len);
}

int	putint(int fd, int n, t_flag *flag)
{
	int	printed;

	printed = 0;
	if (flag && !(flag->flags & ZERO))
		printed = fill_before(fd, flag, printinglen(n, flag));
	if (n < 0)
	{
		printed += write(fd, "-", 1);
		printed += putzeros(fd, flag, intlen(n), printed) + putint_aux(fd, -n);
	}
	else
	{
		if (flag && flag->flags & SPACE)
			printed += write(fd, " ", 1);
		if (flag && flag->flags & PLUS)
			printed += write(fd, "+", 1);
		if (!(n == 0 && flag && flag->flags & DOT && flag->precision == 0))
		{
			printed += putzeros(fd, flag, intlen(n), printed);
			printed += putint_aux(fd, n);
		}
	}
	return (printed);
}
