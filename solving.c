/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solving.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oantonen <oantonen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 17:21:36 by inovykov          #+#    #+#             */
/*   Updated: 2017/12/07 17:42:10 by oantonen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	free_willy(char **arr)
{
	int	row;

	row = -1;
	while (arr[++row] != NULL)
		free(arr[row]);
	free(arr);
	print_error(2);
}

void	del_figure(t_figure coordinates, int x, int y)
{
	int x2;
	int i;
	int y2;

	i = 0;
	x2 = x;
	y2 = y;
	while (i != 4)
	{
		x = x2 + coordinates.x[i];
		y = y2 + coordinates.y[i];
		g_map[y][x] = '.';
		i++;
	}
}

int		is_possible_to_put(t_figure coordinates, int x, int y, int cells)
{
	int i;
	int x2;
	int y2;

	i = 0;
	x2 = x;
	y2 = y;
	while (i != 4)
	{
		x = x2 + coordinates.x[i];
		y = y2 + coordinates.y[i];
		if (x > cells || y > cells)
			return (FALSE);
		if (g_map[y][x] == '.')
			i++;
		else
			return (FALSE);
	}
	return (TRUE);
}

void	put_figure_on_map(t_figure coordinates, int x, int y, char **g_map)
{
	int i;
	int y2;
	int x2;

	i = 0;
	x2 = x;
	y2 = y;
	while (i != 4)
	{
		x = x2 + coordinates.x[i];
		y = y2 + coordinates.y[i];
		g_map[y][x] = coordinates.c;
		i++;
	}
}

int		find_solution(t_figure *coordinates, int figures, int cells)
{
	int	x;
	int	y;

	x = -1;
	y = 0;
	while (y != cells && ++x != -2)
	{
		if (is_possible_to_put(*coordinates, x, y, cells - 1) == TRUE)
		{
			put_figure_on_map(*coordinates, x, y, g_map);
			if (figures - 1 != 0)
			{
				if (find_solution(++coordinates, figures - 1, cells) == TRUE)
					return (TRUE);
				if (check_all_same(*coordinates, *(coordinates - 1)) == FALSE)
					del_figure(*--coordinates, x, y);
			}
			else
				return (TRUE);
		}
		(x == cells) ? (y = y + 1) : y;
		(x == cells) ? (x = -1) : x;
	}
	return (0);
}
