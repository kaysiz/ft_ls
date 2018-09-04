/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_a.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksiziva <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/04 16:27:11 by ksiziva           #+#    #+#             */
/*   Updated: 2018/09/04 16:27:13 by ksiziva          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void    ft_al(char c, char *d)
{
    DIR *dir;
	struct dirent *f_name;
	struct stat fileStat;
	struct group *grp;
	struct passwd *pwd;
	char time[50];
	int is_dir = 0;

	//check if its a directory
	if (lstat(d, &fileStat) < 0)
        perror(d);

    (fileStat.st_mode & S_IFDIR) ? (is_dir = 1) : (is_dir = 0);

	if(is_dir)
	{
		dir = opendir(d);
		if (dir == NULL)
			exit(1);
		while ((f_name=readdir(dir)) != NULL)
		{
			if (c == 'a')
				ft_printf("%s\n", f_name->d_name);
			else if(c == 'l')
			{
				if (f_name->d_name[0] != '.')
				{
					stat(f_name->d_name,&fileStat);
					grp = getgrgid(fileStat.st_gid);
					pwd = getpwuid(fileStat.st_uid);
					print_permissions(fileStat.st_mode);
					ft_printf("\t");
					ft_printf("%u\t", ((long )fileStat.st_nlink));
					ft_printf("%s\t", pwd->pw_name);
					ft_printf("%s\t", grp->gr_name);
					ft_printf("%u\t", fileStat.st_size);
					strftime(time, 50, "%e %b %H:%M", localtime(&fileStat.st_mtime));
					ft_printf("%s\t", time);
					ft_printf("%s\n", f_name->d_name);
				}
			}
			else
			{
				if (f_name->d_name[0] != '.')
				{
					ft_printf("%s\n", f_name->d_name);
				}
			}
		}
		// Close directory stream
		closedir(dir);
	}else
		ft_printf(d);
}
