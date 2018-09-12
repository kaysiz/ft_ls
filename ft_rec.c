/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rec.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksiziva <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/04 16:27:52 by ksiziva           #+#    #+#             */
/*   Updated: 2018/09/04 16:27:55 by ksiziva          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ft_ls.h"

void ft_rec(char *path)
{
    //char path[1000];
    struct dirent *ptr;
    DIR *dir;

    // // Unable to open directory stream
    // if (!dir)
    //     return;

    // while ((dp = readdir(dir)) != NULL)
    // {
    //     if (dp->d_name[0] != '.')
    //     {
    //         printf("%s\n", dp->d_name);

    //         // Construct new path from our base path
    //         strcpy(path, basePath);
    //         strcat(path, "/");
    //         strcat(path, dp->d_name);

    //         ft_rec(path);
    //     }
    // }

    // closedir(dir);
    dir = opendir(path);

    while((ptr = readdir(dir)) != NULL)
    {
        // skip . and ..
        if(ptr->d_name[0] != '.')
        {
            // if directory
            if (ptr->d_type & DT_DIR)
            {
                printf("\n./%s: \n", ptr->d_name);
                // do recursively
                ft_rec(ptr->d_name);
            }
            else
                // print the name
                printf("%s\n", ptr->d_name);
        }
    }
}