/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksiziva <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/08 13:25:45 by ksiziva           #+#    #+#             */
/*   Updated: 2018/09/08 15:50:00 by ksiziva          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void	handle_l(int ac, char **av)
{
	int i;

	i = 0;
	if (ac > 2)
	{
		i = 2;
		while (i < ac)
		{
			ft_l(av[i]);
			i++;
		}
	}
	else
		ft_l(".");
}

static void	handle_a(int ac, char **av)
{
	int i;

	i = 0;
	if (ac > 2)
	{
		i = 2;
		while (i < ac)
		{
			ft_a(av[i]);
			i++;
		}
	}
	else
		ft_a(".");
}

static void	handle_r(int ac, char **av)
{
	int i;

	i = 0;
	if (ac > 2)
	{
		i = 2;
		while (i < ac)
		{
			ft_r(av[i]);
			i++;
		}
	}
	else
		ft_r(".");
}

static void	handle_rec(int ac, char **av)
{
	int i;

	i = 0;
	if (ac > 2)
	{
		i = 2;
		while (i < ac)
		{
			ft_rec(av[i]);
			i++;
		}
	}
	else
		ft_rec(".");
}

void		handle_flags(int ac, char **av)
{
	int i;

	i = 0;
	if (ft_strcmp(av[1], "-l") == 0)
		handle_l(ac, av);
	else if (ft_strcmp(av[1], "-a") == 0)
		handle_a(ac, av);
	else if (ft_strcmp(av[1], "-r") == 0)
		handle_r(ac, av);
	else if (ft_strcmp(av[1], "-R") == 0)
		handle_rec(ac, av);
	else
	{
		ft_printf("ft_ls: illegal option -- %c\n", av[1][1]);
		ft_printf("usage: ft_ls [-Ralrt] [file ...]");
	}
}
