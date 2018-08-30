/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prints.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksiziva <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/30 15:45:43 by ksiziva           #+#    #+#             */
/*   Updated: 2018/08/30 15:48:29 by ksiziva          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void print_permissions(mode_t mode)
{
    ft_putchar((mode & S_IRUSR) ? 'r' : '-');
    ft_putchar((mode & S_IWUSR) ? 'w' : '-');
    ft_putchar((mode & S_IXUSR) ? 'x' : '-');
    ft_putchar((mode & S_IRGRP) ? 'r' : '-');
    ft_putchar((mode & S_IWGRP) ? 'w' : '-');
    ft_putchar((mode & S_IXGRP) ? 'x' : '-');
    ft_putchar((mode & S_IROTH) ? 'r' : '-');
    ft_putchar((mode & S_IWOTH) ? 'w' : '-');
    ft_putchar((mode & S_IXOTH) ? 'x' : '-');
}
