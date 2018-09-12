/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksiziva <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/30 15:00:38 by ksiziva           #+#    #+#             */
/*   Updated: 2018/06/17 15:42:49 by ksiziva          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_getlen(char const *s1, char const *s2)
{
	return (ft_strlen(s1) + ft_strlen(s2));
}

char		*ft_strjoin(char const *s1, char const *s2)
{
	char	*res;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (s1 && s2)
	{
		if (!(res = (char *)malloc((ft_getlen(s1, s2) + 1) * sizeof(char))))
			return (NULL);
		while (s1[i] != '\0')
		{
			res[i] = s1[i];
			i++;
		}
		while (s2[j] != '\0')
		{
			res[i + j] = s2[j];
			j++;
		}
		res[i + j] = '\0';
		return (res);
	}
	return (NULL);
}
