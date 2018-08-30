/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksiziva <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/04 17:41:19 by ksiziva           #+#    #+#             */
/*   Updated: 2018/08/23 11:34:08 by ksiziva          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		print_hex(int n, char c)
{
	unsigned int	nb;
	char			*lower_x;
	char			*upper_x;

	lower_x = "0123456789abcdef";
	upper_x = "0123456789ABCDEF";
	nb = n;
	if (nb >= 16)
	{
		print_hex(nb / 16, c);
		print_hex(nb % 16, c);
	}
	else
	{
		if (c == 'x')
			ft_putchar(lower_x[nb]);
		else
			ft_putchar(upper_x[nb]);
	}
}

void		ft_printaddr(unsigned long int n)
{
	char *base;

	base = "0123456789abcdef";
	if (n >= 16)
	{
		ft_printaddr(n / 16);
		ft_printaddr(n % 16);
	}
	else
		ft_putchar(base[n]);
}

void		ft_print_hex(va_list arg, char c)
{
	if (c == 'x' || c == 'X')
		print_hex((va_arg(arg, unsigned int)), c);
	else
	{
		ft_putstr("0x");
		ft_printaddr(va_arg(arg, unsigned long int));
	}
}
