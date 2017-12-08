/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oantonen <oantonen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/22 17:12:32 by inovykov          #+#    #+#             */
/*   Updated: 2017/12/06 19:20:12 by oantonen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		print_error(int n)
{
	if (n == 1)
		write(1, "usage: ./fillit source_file\n", 28);
	if (n == 2)
		write(1, "error\n", 6);
}

static void	ft_putendl(char const *s)
{
	int i;

	i = 0;
	if (!s)
		return ;
	while (s[i] != '\0')
	{
		write(1, &s[i], 1);
		i++;
	}
	write(1, "\n", 1);
}

void		print_map(char **map, int cells)
{
	int i;

	i = 0;
	while (i < cells)
	{
		ft_putendl(map[i]);
		i++;
	}
}
