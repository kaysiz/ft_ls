/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_a.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksiziva <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/04 16:27:11 by ksiziva           #+#    #+#             */
/*   Updated: 2018/09/08 13:19:51 by ksiziva          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_a(char *d)
{
	DIR				*dir;
	struct dirent	*f_name;
	struct stat		stats;
	int				is_dir;

	if (lstat(d, &stats) < 0)
		perror(d);
	is_dir = (stats.st_mode & S_IFDIR) ? 1 : 0;
	if (is_dir)
	{
		dir = opendir(d);
		if (dir == NULL)
			exit(1);
		while ((f_name = readdir(dir)) != NULL)
			ft_printf("%s\n", f_name->d_name);
		closedir(dir);
	}
	else
		ft_printf("%s\n", d);
}
