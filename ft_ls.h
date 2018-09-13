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

# include <stdlib.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <dirent.h>
# include "./printf/ft_printf.h"
# include <pwd.h>
# include <grp.h>
# include <time.h>

void	ft_a(char *d);
void	ft_l(char *d);
void	ft_noflags(char *d);
void	ft_r(char *d);
void	print_permissions(mode_t mode);
void	ft_rec(char *path);
void	handle_flags(int ac, char **av);
void	ft_sort(char **str);
void	ft_islink(char *d, char *str);
void	print_dir_stats(char *d, char *str);
void	print_f_stats(char *str);
void	ft_print_list(char *d, char **r_list, int i);
void	ft_print_dir_l(char *d);
int		g_links;

#endif
