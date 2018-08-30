/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksiziva <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/23 16:31:44 by ksiziva           #+#    #+#             */
/*   Updated: 2018/08/30 12:06:42 by ksiziva          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include "./printf/ft_printf.h"
#include <pwd.h>
#include <grp.h>
#include <time.h>

int	main(int ac, char **av)
{
	DIR *dir;
	struct dirent *f_name;
	struct stat fileStat;
	struct group *grp;
	struct passwd *pwd;
	char time[50];

	if (ac == 1)
		dir = opendir(".");
	else
		dir = opendir(av[1]);
	if (dir == NULL)
		exit(1);
	while ((f_name=readdir(dir)) != NULL)
	{
		if (f_name->d_name[0] != '.')
		{
			stat(f_name->d_name,&fileStat);
			grp = getgrgid(fileStat.st_gid);
			pwd = getpwuid(fileStat.st_uid);
			ft_printf( (S_ISDIR(fileStat.st_mode)) ? "d" : "-");
    		ft_printf( (fileStat.st_mode & S_IRUSR) ? "r" : "-");
    		ft_printf( (fileStat.st_mode & S_IWUSR) ? "w" : "-");
    		ft_printf( (fileStat.st_mode & S_IXUSR) ? "x" : "-");
    		ft_printf( (fileStat.st_mode & S_IRGRP) ? "r" : "-");
    		ft_printf( (fileStat.st_mode & S_IWGRP) ? "w" : "-");
    		ft_printf( (fileStat.st_mode & S_IXGRP) ? "x" : "-");
    		ft_printf( (fileStat.st_mode & S_IROTH) ? "r" : "-");
    		ft_printf( (fileStat.st_mode & S_IWOTH) ? "w" : "-");
    		ft_printf( (fileStat.st_mode & S_IXOTH) ? "x" : "-");
			ft_printf("\t");
			ft_printf("%u\t", ((long )fileStat.st_nlink));
			ft_printf("%s\t", pwd->pw_name);
			ft_printf("%s\t", grp->gr_name);
			ft_printf("%u\t", fileStat.st_size);
			strftime(time, 50, "%b %d %H:%M", localtime(&fileStat.st_mtime));
			ft_printf("%s\t", time);
			ft_printf("%s\n", f_name->d_name);
		}
	}
	return(0);
}
