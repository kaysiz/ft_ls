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
	g_check = 0;
	if (ac == 1)
		ft_al(' ', ".");
	else
	{
		if (av[1][0] == '-')
		{
			if(ft_strcmp(av[1], "-l") == 0)
			{
				//handle the -l flag
				if (ac > 2)
				{
					i = 2;
					while(i < ac)
					{
						ft_l(av[i]);
						i++;
					}
				}else
				{
					ft_l(".");
				}
			}
			else if(ft_strcmp(av[1], "-a") == 0)
			{
				//handle the -a flag
				if (ac > 2)
				{
					i = 2;
					while(i < ac)
					{
						ft_al('a',av[i]);
						i++;
					}
				}else
				{
					ft_al('a',".");
				}
			}
			else if(ft_strcmp(av[1], "-t") == 0)
			{
				//handle the -t flag
				ft_printf("Display time\n");
			}
			else if(ft_strcmp(av[1], "-r") == 0)
			{
				//handle the -r flag
				if (ac > 2)
				{
					i = 2;
					while(i < ac)
					{
						ft_r(av[i]);
						i++;
					}
				}else
					ft_r(".");
			}
			else if(ft_strcmp(av[1], "-R") == 0)
			{
				//handle the -R flag
				ft_printf("Recursive\n");
			}
			else
			{
				ft_printf("ft_ls: illegal option -- %c\n",av[1][1]);
				ft_printf("usage: ft_ls [-Ralrt] [file ...]");
			}
		}
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
	return(0);	
}
