/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_l.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksiziva <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/04 18:23:44 by ksiziva           #+#    #+#             */
/*   Updated: 2018/09/08 15:54:07 by ksiziva          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void	print_dir_stats(char *d, char *str)
{
	struct stat		stats;
	struct group	*grp;
	struct passwd	*pwd;
	char			time[50];
	char 			*buf;
    size_t 			nbytes;
	size_t 			bufsiz;

	lstat(ft_strjoin(ft_strjoin(d, "/"), str), &stats);
	grp = getgrgid(stats.st_gid);
	pwd = getpwuid(stats.st_uid);
	print_permissions(stats.st_mode);
	ft_printf("\t");
	ft_printf("%u\t", ((long)stats.st_nlink));
	ft_printf("%s\t", pwd->pw_name);
	ft_printf("%s\t", grp->gr_name);
	ft_printf("%u\t", stats.st_size);
	strftime(time, 50, "%e %b %H:%M", localtime(&stats.st_mtime));
	ft_printf("%s\t", time);
	if (S_ISLNK(stats.st_mode))
	{
		bufsiz = stats.st_size + 1;
		if (stats.st_size == 0)
               bufsiz = 0;

           buf = malloc(bufsiz);
           if (buf == NULL) {
               perror("malloc");
               exit(EXIT_FAILURE);
           }

           nbytes = readlink(ft_strjoin(ft_strjoin(d, "/"), str), buf, bufsiz);
           if (nbytes == (unsigned long)-1) {
               perror("readlink");
               exit(EXIT_FAILURE);
           }

           ft_printf("%s -> %s\n", str, buf);
	}
	else
		ft_printf("%s\n", str);
	
	g_links += (long)stats.st_blocks;
}

static void	print_f_stats(char *str)
{
	struct stat		stats;
	struct group	*grp;
	struct passwd	*pwd;
	char			time[50];

	stat(str, &stats);
	grp = getgrgid(stats.st_gid);
	pwd = getpwuid(stats.st_uid);
	print_permissions(stats.st_mode);
	ft_printf("\t");
	ft_printf("%u\t", ((long)stats.st_nlink));
	ft_printf("%s\t", pwd->pw_name);
	ft_printf("%s\t", grp->gr_name);
	ft_printf("%u\t", stats.st_size);
	strftime(time, 50, "%e %b %H:%M", localtime(&stats.st_mtime));
	ft_printf("%s\t", time);
	ft_printf("%s\n", str);
}

void		ft_l(char *d)
{
	DIR				*dir;
	struct dirent	*f_name;
	struct stat		stats;
	int				is_dir;

	if (lstat(d, &stats) < 0)
	{
		perror(d);
		return ;
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
				print_dir_stats(d, f_name->d_name);
		}
		closedir(dir);
		ft_printf("total   %d\n", g_links);
	}
	else
		print_f_stats(d);
}
