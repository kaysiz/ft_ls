/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prints.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksiziva <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/30 15:45:43 by ksiziva           #+#    #+#             */
/*   Updated: 2018/09/13 18:16:44 by ksiziva          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	print_permissions(mode_t mode)
{
	if (S_ISLNK(mode))
		ft_printf((S_ISLNK(mode)) ? "l" : "d");
	else
		ft_printf((S_ISDIR(mode)) ? "d" : "-");
	ft_printf((mode & S_IRUSR) ? "r" : "-");
	ft_printf((mode & S_IWUSR) ? "w" : "-");
	ft_printf((mode & S_IXUSR) ? "x" : "-");
	ft_printf((mode & S_IRGRP) ? "r" : "-");
	ft_printf((mode & S_IWGRP) ? "w" : "-");
	ft_printf((mode & S_IXGRP) ? "x" : "-");
	ft_printf((mode & S_IROTH) ? "r" : "-");
	ft_printf((mode & S_IWOTH) ? "w" : "-");
	ft_printf((mode & S_IXOTH) ? "x" : "-");
}
