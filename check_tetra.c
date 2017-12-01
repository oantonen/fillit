/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_tetra.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oantonen <oantonen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/24 14:51:57 by oantonen          #+#    #+#             */
/*   Updated: 2017/11/27 19:24:55 by oantonen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ternarcheck(char *str)
{
	int b;
	int hash;
	int tetra;

	b = 0;
	hash = 0;
	tetra = 0;
	while (b < 21)
	{
		if (str[b] == '#')
		{
			(b + 1 < 21 && str[b + 1] == '#') ? tetra++ : tetra;
			(b + 5 < 21 && str[b + 5] == '#') ? tetra++ : tetra;
			(b - 1 > 0 && str[b - 1] == '#') ? tetra++ : tetra;
			(b - 5 > 0 && str[b - 5] == '#') ? tetra++ : tetra;
			hash++;
		}
		b++;
		if ((tetra == 6 || tetra == 8) && hash == 4)
			return (1);
	}
	return (0);
}

int		check_tetra(char *str_figures, int str_len)
{
	char	block[21];
	int		i;
	int		ret;

	ret = 1;
	i = 0;
	while (i < str_len)
	{
		ft_strncpy(block, &str_figures[i], 20);
		if (ternarcheck(block) == 1)
			i = i + 21;
		else
			return (0);
	}
	return (ret);
}
