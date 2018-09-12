/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_r.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksiziva <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/04 16:27:18 by ksiziva           #+#    #+#             */
/*   Updated: 2018/09/08 14:43:23 by ksiziva          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void	ft_print_dir(char *d)
{
	DIR             *dir;
	struct dirent   *f_name;
	int             i;
	char            **r_list;

	i = 0;
	r_list = (char **)malloc(sizeof(char *) * (1024));
	dir = opendir(d);
	if (dir == NULL)
		exit(1);
	while ((f_name=readdir(dir)) != NULL)
	{
		if (f_name->d_name[0] != '.')
			r_list[i++] = ft_strdup(f_name->d_name);
	}
	r_list[i] = NULL;
	while (--i >= 0)
	{
		ft_printf("%s\n", r_list[i]);
		free(r_list[i]);
	}
	free(r_list);
	closedir(dir);
}

void    ft_r(char *d)
{
	struct stat stats;
	int is_dir;

	if (lstat(d, &stats) < 0)
	{
		perror(d);
		return;
	}
	is_dir = (stats.st_mode & S_IFDIR) ? 1 : 0;
	if (is_dir)
		ft_print_dir(d);
	else
		ft_printf("%s\n", d);
}
