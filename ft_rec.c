/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rec.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksiziva <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/04 16:27:52 by ksiziva           #+#    #+#             */
/*   Updated: 2018/09/13 16:58:56 by ksiziva          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_rec(char *path)
{
	DIR				*dir;
	struct stat		stats;
	struct dirent	*ptr;

	if (lstat(path, &stats) < 0)
	{
		perror(path);
		return ;
	}
	dir = opendir(path);
	while ((ptr = readdir(dir)) != NULL)
	{
		if (ptr->d_name[0] != '.')
		{
			if (ptr->d_type & DT_DIR)
			{
				printf("\n./%s: \n", ptr->d_name);
				ft_rec(ptr->d_name);
			}
			else
				printf("%s\n", ptr->d_name);
		}
	}
}
