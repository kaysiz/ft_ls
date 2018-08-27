/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksiziva <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/23 16:31:44 by ksiziva           #+#    #+#             */
/*   Updated: 2018/08/23 16:48:55 by ksiziva          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>

int	main(int ac, char **av)
{
	DIR *dir;
	struct dirent *f_name;
	struct stat fileStat;
    
	if (ac == 1)
		dir = opendir(".");
	else
		dir = opendir(av[1]);
	if (dir == NULL)
		exit(1);
	while ((f_name=readdir(dir)) != NULL)
	{
		stat(f_name->d_name,&fileStat);
		printf( (S_ISDIR(fileStat.st_mode)) ? "d" : "-");
    	printf( (fileStat.st_mode & S_IRUSR) ? "r" : "-");
    	printf( (fileStat.st_mode & S_IWUSR) ? "w" : "-");
    	printf( (fileStat.st_mode & S_IXUSR) ? "x" : "-");
    	printf( (fileStat.st_mode & S_IRGRP) ? "r" : "-");
    	printf( (fileStat.st_mode & S_IWGRP) ? "w" : "-");
    	printf( (fileStat.st_mode & S_IXGRP) ? "x" : "-");
    	printf( (fileStat.st_mode & S_IROTH) ? "r" : "-");
    	printf( (fileStat.st_mode & S_IWOTH) ? "w" : "-");
    	printf( (fileStat.st_mode & S_IXOTH) ? "x" : "-");
		printf("%s\n", f_name->d_name);
	}
	return(0);
printf( (S_ISDIR(fileStat.st_mode)) ? "d" : "-");
 35         printf( (fileStat.st_mode & S_IRUSR) ? "r" : "-");
 36         printf( (fileStat.st_mode & S_IWUSR) ? "w" : "-");
 37         printf( (fileStat.st_mode & S_IXUSR) ? "x" : "-");
 38         printf( (fileStat.st_mode & S_IRGRP) ? "r" : "-");
 39         printf( (fileStat.st_mode & S_IWGRP) ? "w" : "-");
 40         printf( (fileStat.st_mode & S_IXGRP) ? "x" : "-");
 41         printf( (fileStat.st_mode & S_IROTH) ? "r" : "-");
 42         printf( (fileStat.st_mode & S_IWOTH) ? "w" : "-");
 43         printf( (fileStat.st_mode & S_IXOTH) ? "x" : "-");}
