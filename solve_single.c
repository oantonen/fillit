/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_single.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inovykov <inovykov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 17:06:03 by inovykov          #+#    #+#             */
/*   Updated: 2017/11/30 17:13:33 by inovykov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int	find_max_coord(t_figure	*figure)
{
	int		max_coord;
	int		i;

	i = 0;
	max_coord = 0;
	while (i < 4)
	{
		if (figure->x[i] > max_coord)
			max_coord = figure->x[i];
		else if (figure->y[i] > max_coord)
			max_coord = figure->y[i];
		else
			i++;
	}
	return (max_coord);
}

char		**put_single_fig(t_figure	*figure)
{
	char	**arr_map;
	int		max_coord;
	int		i;

	max_coord = find_max_coord(figure);
	arr_map = aloc_mem_for_map(max_coord);
	if (arr_map == 0)
		return (0);
	i = -1;
	while (++i < 4)
		arr_map[figure->y[i]][figure->x[i]] = figure->c;
	arr_map[max_coord + 1] = NULL;
	return (arr_map);
}
