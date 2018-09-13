/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksiziva <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/13 17:40:30 by ksiziva           #+#    #+#             */
/*   Updated: 2018/09/13 17:40:32 by ksiziva          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		ft_print_dir_l(char *d)
{
	DIR				*dir;
	struct dirent	*f_name;
	struct stat		stats;
	char			**r_list;
	int				i;

	i = 0;
	r_list = (char **)malloc(sizeof(char *) * (1024));
	dir = opendir(d);
	if (dir == NULL)
		exit(1);
	while ((f_name = readdir(dir)) != NULL)
	{
		if (f_name->d_name[0] != '.')
		{
			lstat(ft_strjoin(ft_strjoin(d, "/"), f_name->d_name), &stats);
			r_list[i++] = ft_strdup(f_name->d_name);
			g_links += (long)stats.st_blocks;
		}
	}
	closedir(dir);
	ft_printf("total   %d\n", g_links);
	ft_print_list(d, r_list, i);
	free(r_list);
}