/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksiziva <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/22 15:16:40 by ksiziva           #+#    #+#             */
/*   Updated: 2018/08/23 11:39:18 by ksiziva          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf(const char *format, ...)
{
	int		i;
	int		j;
	va_list	args;

	i = 0;
	j = 0;
	g_chars = 0;
	va_start(args, format);
	while (format[j] != '\0')
	{
		if (format[j] == '%')
		{
			j++;
			ft_conversion(format[j], args);
		}
		else
		{
			ft_putchar(format[j]);
		}
		j++;
	}
	va_end(args);
	return (g_chars);
}
