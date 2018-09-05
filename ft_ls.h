/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksiziva <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/28 09:41:45 by ksiziva           #+#    #+#             */
/*   Updated: 2018/08/30 15:45:32 by ksiziva          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include "./printf/ft_printf.h"
#include <pwd.h>
#include <grp.h>
#include <time.h>

int     g_check;

int	    ft_strcmp(const char *str1, const char *str2);
void    ft_al(char c, char *d);
void    ft_l(char *d);
void    ft_noflags(char *d);
void    ft_r(char *d);
void    print_permissions(mode_t mode);
size_t	ft_strlen(const char *str);
char	*ft_strncpy(char *dest, const char *src, size_t n);
char	*ft_strdup(const char *s);

#endif
