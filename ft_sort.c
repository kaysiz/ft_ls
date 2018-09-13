/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksiziva <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/13 08:00:40 by ksiziva           #+#    #+#             */
/*   Updated: 2018/09/13 17:11:18 by ksiziva          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_sort(char **str)
{
	int		n;
	int		j;
	int		i;
	char	*temp;

	n = 0;
	j = 0;
	while (str[n])
		n++;
	temp = (char *)malloc(sizeof(char *) * n);
	while (j < n - 1)
	{
		i = j + 1;
		while (i < n)
		{
			if (ft_strcmp(str[j], str[i]) > 0)
			{
				ft_strcpy(temp, str[j]);
				ft_strcpy(str[j], str[i]);
				ft_strcpy(str[i], temp);
			}
			i++;
		}
		j++;
	}
}
