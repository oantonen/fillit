/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_general.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inovykov <inovykov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 16:25:50 by inovykov          #+#    #+#             */
/*   Updated: 2017/12/01 13:43:57 by inovykov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int		count_figures(char *str_figures)
{
	int			hash;
	int			count;

printf("lall\n");
	hash = 0;
	while (*str_figures)
	{
		if (*str_figures == '#')
			hash++;
		str_figures++;
	}
	count = hash / 4;
	return (count);
}

char			**ft_render_map(t_figure *arr_figures, int cells, int figures)
{
	char		**map;
	int			i;
	int			k;

	i = -1;
	map = aloc_mem_for_map(cells); //for y coordinates appropriate amount of strings
	i = 0;
	while (i < figures)
	{
		k = 0;
		while (k < 4)
		{
			map[arr_figures[i].y[k]][arr_figures[i].x[k]] = arr_figures[i].c;
			k++;
		}
		i++;
	}
	return (map);
}

int			comper_coord(t_figure *figure, t_figure *figure_next)
{
	int			i;

	i = 0;
	while (i < 4)
	{
		if (figure->x[i] == figure_next->x[i])
			return (TRUE);
		else
		{
			if (figure->y[i] == figure_next->y[i])
				return (TRUE);
		}
		i++;
	}
	return (FALSE);
}

t_figure	*move_fig(t_figure *figure, int min_s)
{
	int			i;

	i = 0;
	while ((figure->x[i] + 1) < min_s && i < 4)
		i++;
	if (i == 4)
	{
		while (--i > -1)
			figure->x[i] = figure->x[i] + 1;
		return (figure); //moved by x one cell right
	}
	else
	{
		i = 0;
		while ((figure->y[i] + 1) < min_s && i < 4)
			i++;
		if (i == 4)
		{
			while (--i > -1)
				figure->y[i] = figure->y[i] + 1;
			return (figure); //moved by y one cell down
		}
		else
			return (figure); // origin fig
	}
}

void		free_willy(char **arr)
{
	int		row;

	row = -1;
	while (arr[++row] != NULL)
		free(arr[row]);
	free(arr);
	print_error(2);
}



char		**aloc_mem_for_map(int cell)
{
	char	**arr_map;
	int		row;

	arr_map = malloc(sizeof(char*) * (cell + 2));
	if (!arr_map)
	{
		print_error(2);
		return (0);
	}
	row = -1;
	while (++row <= cell)
	{
		arr_map[row] = ft_strnew((cell + 1));//same story, but +1 for '\0'
		if (arr_map[row] == NULL)
		{
			free_willy(arr_map);
			return (0);
		}
	}
	return (arr_map);
}



void		solve(char *str_figures)
{
	int			figures;
	int			min_s;
	t_figure	*arr_figures;
	int			i;

printf("Hello\n");
	figures = count_figures(str_figures);
	min_s = figures * 4;
	arr_figures = ft_record_all_figures(str_figures, figures);
	i = 0;
	if (figures == 1)
		print_solution(put_single_fig(arr_figures));
	else
	{
		//printf("Hello\n");
		while (i < figures)
		{
			while (comper_coord(&arr_figures[i], &arr_figures[i + 1]) == TRUE)
	 			move_fig(&arr_figures[i + 1], min_s); // гдето тут надо увеличить мин квадрат, если у нас не влезло
	 		i++;
	 	}
		print_solution(ft_render_map(arr_figures, min_s, figures));
	}
	// while (i < (figures - 1))
	// {
	// 	while (comper_coord(&arr_figures[i], &arr_figures[i + 1]) == TRUE)
	// 		move_fig(&arr_figures[i + 1], min_s);
		
		// while (j < 4 && arr_figures[i].x[j] < min_s && arr_figures[i + 1].x[j] < min_s)
		// {
		// 	if (arr_figures[i].x[j] == arr_figures[i + 1].x[j]);
		// 	{
		// 		arr_figures[i + 1].x[0] = arr_figures[i + 1].x[0] + 1;
		// 		arr_figures[i + 1].x[0] = arr_figures[i + 1].x[1] + 1;
		// 		arr_figures[i + 1].x[0] = arr_figures[i + 1].x[2] + 1;
		// 		arr_figures[i + 1].x[0] = arr_figures[i + 1].x[3] + 1;
		// 	}
		// 	else
		// 		j++;
		// }
	// 	i++;
	// }
}
