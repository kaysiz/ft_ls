/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksiziva <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/22 15:16:16 by ksiziva           #+#    #+#             */
/*   Updated: 2018/08/23 10:38:38 by ksiziva          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print(char c, va_list arg)
{
	if (c == 'd' || c == 'i' || c == 'D' || c == 'u' || c == 'U')
		ft_print_nbr(arg, c);
	else if (c == 'o' || c == 'O')
		ft_putoct(arg, c);
	else if (c == 'x' || c == 'X' || c == 'p')
		ft_print_hex(arg, c);
	else if (c == 's')
		ft_putstr(va_arg(arg, char *));
	else if (c == 'S')
		ft_putwstr(va_arg(arg, wchar_t *));
	else if (c == 'c' || c == '%')
		ft_putchar((char)va_arg(arg, int));
	else if (c == 'C')
		ft_putwchar(va_arg(arg, wchar_t));
}
