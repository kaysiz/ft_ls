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

void	ft_islink(char *d, char *str)
{
	char			*buf;
	struct stat		stats;
	size_t			nbytes;
	size_t			bufsiz;

	lstat(ft_strjoin(ft_strjoin(d, "/"), str), &stats);
	bufsiz = stats.st_size + 1;
	if (stats.st_size == 0)
		bufsiz = 0;
	buf = (char *)malloc(sizeof(char *) * bufsiz);
	nbytes = readlink(ft_strjoin(ft_strjoin(d, "/"), str), buf, bufsiz);
	ft_printf("%s -> %s\n", str, buf);
}

void	print_dir_stats(char *d, char *str)
{
	struct stat		stats;
	struct group	*grp;
	struct passwd	*pwd;
	char			time[50];

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
		ft_islink(d, str);
	else
		ft_printf("%s\n", str);
}

void	print_f_stats(char *str)
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

void	ft_print_list(char *d, char **r_list, int i)
{
	int				j;

	j = 0;
	ft_sort(r_list);
	while (j < i)
		print_dir_stats(d, r_list[j++]);
}

void	ft_l(char *d)
{
	struct stat		stats;

	if (lstat(d, &stats) < 0)
		perror(d);
	if (stats.st_mode & S_IFDIR)
		ft_print_dir_l(d);
	else
		print_f_stats(d);
}
