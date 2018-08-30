/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksiziva <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/22 15:16:59 by ksiziva           #+#    #+#             */
/*   Updated: 2018/08/23 11:14:02 by ksiziva          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <stdarg.h>
# include <wchar.h>

int		g_chars;

void	ft_putchar(char c);
void	ft_putwchar(wchar_t c);
void	ft_putstr(char *s);
void	ft_putwstr(wchar_t *str);
void	ft_print_nbr(va_list arg, char c);
void	ft_putnbr(int n);
void	ft_putlnbr(long int n);
void	ft_putoct(va_list arg, char c);
void	ft_printoct(int n);
void	ft_printloct(long int n);
void	ft_printuloct(unsigned long long int n);
void	print_hex(int n, char c);
void	ft_print_hex(va_list arg, char c);
void	ft_printaddr(unsigned long int n);
void	ft_print(char c, va_list arg);
void	ft_conversion(char c, va_list va);
int		ft_check(char c);
int		ft_printf(const char *format, ...);
#endif
