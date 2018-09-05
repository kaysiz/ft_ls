/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_r.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksiziva <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/04 16:27:18 by ksiziva           #+#    #+#             */
/*   Updated: 2018/09/04 16:27:20 by ksiziva          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void    ft_r(char *d)
{
    DIR *dir;
	struct dirent *f_name;
	struct stat fileStat;
	int is_dir = 0;
    int i;
    char **r_list;

    i = 0;
    r_list = (char **)malloc(sizeof(char *) * (1024));
	//check if its a directory
	if (lstat(d, &fileStat) < 0)
    {
        perror(d);
        return;
    }

    (fileStat.st_mode & S_IFDIR) ? (is_dir = 1) : (is_dir = 0);

	if(is_dir)
	{
		dir = opendir(d);
		if (dir == NULL)
			exit(1);
		while ((f_name=readdir(dir)) != NULL)
		{
			
            if (f_name->d_name[0] != '.')
            {
                r_list[i] = ft_strdup(f_name->d_name);
                i++;
            }
		}
        r_list[i] = NULL;
        while (--i >= 0)
        {
            ft_printf("%s\n", r_list[i]);
            free(r_list[i]);
        }
        free(r_list);
		// Close directory stream
		closedir(dir);
	}else
    {
        ft_printf("%s\n", d);
    }
}