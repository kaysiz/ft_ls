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

struct flags
{
    int using_a;
    int using_l;
    int using_r;
    int using_R;
    int using_t;
};

#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include "./printf/ft_printf.h"
#include <pwd.h>
#include <grp.h>
#include <time.h>

int	ft_strcmp(const char *str1, const char *str2);
void    ft_al(char c, char *d);
void print_permissions(mode_t mode);

#endif
