/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_oct.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksiziva <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/22 15:15:50 by ksiziva           #+#    #+#             */
/*   Updated: 2018/08/23 10:51:58 by ksiziva          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putoct(va_list arg, char c)
{
	if (c == 'o')
		ft_printoct(va_arg(arg, unsigned int));
	else
		ft_printloct(va_arg(arg, unsigned long int));
}

void	ft_printoct(int n)
{
	unsigned int nb;

	nb = n;
	if (nb >= 8)
	{
		ft_printoct(nb / 8);
		ft_printoct(nb % 8);
	}
	else
		ft_putchar(nb + 48);
}

void	ft_printloct(long int n)
{
	unsigned long int nb;

	nb = n;
	if (nb >= 8)
	{
		ft_printloct(nb / 8);
		ft_printloct(nb % 8);
	}
	else
		ft_putchar(nb + 48);
}
