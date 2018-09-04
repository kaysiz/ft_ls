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
	int i = 1;

	if (ac == 1)
		ft_al(' ', ".");
	else if(ac == 2)
	{
		if (av[1][0] == '-')
		{
			while (av[1][i])
			{
				if(ft_strcmp(av[1], "-l") == 0)
					//handle the -l flag
					ft_l(".");
				else if(ft_strcmp(av[1], "-a") == 0)
					//handle the -a flag
					ft_al('a', ".");
				else if(ft_strcmp(av[1], "-t") == 0)
					//handle the -t flag
					ft_printf("Display time\n");
				else if(ft_strcmp(av[1], "-r") == 0)
					//handle the -r flag
					ft_printf("Display reverse\n");
				else if(ft_strcmp(av[1], "-R") == 0)
					//handle the -R flag
					ft_printf("Recursive\n");
				else
					ft_printf(av[1]);
				i++;
			}
		}
		else
			ft_al(' ', av[1]);
	}
	return(0);	
}
