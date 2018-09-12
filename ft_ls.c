/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksiziva <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/30 15:22:25 by ksiziva           #+#    #+#             */
/*   Updated: 2018/08/30 15:27:34 by ksiziva          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int	main(int ac, char **av)
{
	int i;

	i = 0;
	if (ac == 1)
		ft_a(".");
	else
	{
		if (av[1][0] == '-')
			handle_flags(ac, av);
		else
		{
			i = 1;
			while (i < ac)
			{
				ft_noflags(av[i]);
				i++;
			}
		}
	}
	return (0);
}
