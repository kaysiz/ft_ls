/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_noflags.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksiziva <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/05 12:17:24 by ksiziva           #+#    #+#             */
/*   Updated: 2018/09/05 12:17:27 by ksiziva          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_noflags(char *d)
{
	DIR				*dir;
	struct dirent	*f_name;
	struct stat		stats;
	int				is_dir;

	if (lstat(d, &stats) < 0)
	{
		perror(d);
		exit(1);
	}
	is_dir = (stats.st_mode & S_IFDIR) ? 1 : 0;
	if (is_dir)
	{
		dir = opendir(d);
		if (dir == NULL)
			exit(1);
		while ((f_name = readdir(dir)) != NULL)
		{
			if (f_name->d_name[0] != '.')
				ft_printf("%s\n", f_name->d_name);
		}
		closedir(dir);
	}
	else
		ft_printf("%s\n", d);
}
