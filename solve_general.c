/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_general.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oantonen <oantonen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 16:25:50 by inovykov          #+#    #+#             */
/*   Updated: 2017/12/06 16:46:24 by oantonen         ###   ########.fr       */
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

void	ft_render_map(int cell)
{
	int	row;

	g_map = (char**)malloc(sizeof(char*) * (cell + 1));
	if (!g_map)
		print_error(2);
	else
	{
		row = -1;
		while (++row < cell)
		{
			g_map[row] = ft_strnew(cell);
			if (g_map[row] == NULL)
				free_willy(g_map);
		}
		g_map[row] = NULL;
	}
}

void	delfigure(t_figure coordinates, int x, int y)
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

int		possible_to_put(t_figure coordinates, int x, int y, int cells)
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

void	put_figureonmap(t_figure coordinates, int x, int y, char **g_map)
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

int		print_solution(t_figure *coordinates, int figures, int cells)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (y != cells)
	{
		if (possible_to_put(*coordinates, x, y, cells - 1) == 1)
		{
			put_figureonmap(*coordinates, x, y, g_map);
			if (figures - 1 != 0)
			{
				if (print_solution(++coordinates, figures - 1, cells) == 1)
					return (1);
				delfigure(*--coordinates, x, y);
			}
			else
				return (1);
		}
		x++;
		(x == cells) ? (x = -1, y = y + 1) : x;
	}
	return (0);
}
