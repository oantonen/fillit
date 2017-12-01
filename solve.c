/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inovykov <inovykov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/22 17:12:19 by inovykov          #+#    #+#             */
/*   Updated: 2017/11/29 12:02:54 by inovykov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int		count_figures(char *str_figures)
{
	int			hash;
	int			count;

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

static int		*put_x_cordinates(char *str_figures)
{
	int			*arr;
	int			i;
	int			j;
	int			x;

	i = -1;
	j = -1;
	x = 0;
	if (!(arr = (int*)malloc(sizeof(int) * 4)))
		return (NULL);
	while (++i < 21)
	{
		(str_figures[i] == '#') ? arr[++j] = x : j;
		(str_figures[i] == '\n') ? x = -1 : x;
		x++;
	}
	while (arr[0] != 0 && arr[1] != 0 && arr[2] != 0 && arr[3] != 0 && (j = -1))
		while (++j != 4)
			arr[j] = arr[j] - 1;
	return (arr);
}

static int		*put_y_cordinates(char *str_figures)
{
	int			*arr;
	int			i;
	int			j;
	int			y;

	i = 0;
	j = 0;
	y = 0;
	if (!(arr = (int*)malloc(sizeof(int) * 4)))
		return (NULL);
	while (i < 21)
	{
		(str_figures[i] == '#') ? arr[j] = y : j;
		(str_figures[i] == '#') ? j++ : j;
		(str_figures[i] == '\n') ? y++ : y;
		i++;
	}
	while (arr[0] != 0 && arr[1] != 0 && arr[2] != 0 && arr[3] != 0 && (j = -1))
		while (++j != 4)
			arr[j] = arr[j] - 1;
	return (arr);
}

t_figure		*ft_record_all_figures(char *str_figures, int str_len)
{
	t_figure	*arr_figures; //array of structures, where one stracture stores info about one figure
	int			figures;
	int			i; //iterates figures in arr of structures
	int			j;
	char		c;

	figures = count_figures(str_figures);
	arr_figures = (t_figure*)malloc(sizeof(t_figure) * figures);
	i = 0;
	j = 0;
	c = 'A';
	while (j < str_len)
	{
		arr_figures[i].x = put_x_cordinates(&str_figures[j]);
		// printf("%d\n", (arr_figures[i].x)[0]);
		arr_figures[i].y = put_y_cordinates(&str_figures[j]);
		arr_figures[i].c = c++;
		j = j + 21;
		i++;
	}
	return (arr_figures);
}

char			**ft_render_map(char *str_figures)
{
	char		**map;
	int			figures;
	int			hashes;
	int			cells;
	int			i;

	figures = count_figures(str_figures);
	hashes = figures * 4;
	i = 0;
	if (ft_sqrt(hashes) == FALSE)
	{
		while (ft_sqrt(hashes) == FALSE)
		{
			hashes++;
			cells++;
		}
	}
	cells = ft_sqrt(hashes);
	map = (char**)malloc(sizeof(char*) * cells); //for y coordinates appropriate amount of strings
	while (i < cells)
	{
		map[i] = ft_strnew(cells); //for x coordinates appropriate amount of cells
		i++;
	}
	return (map);
}

char map[5][5] = {"....", "....", "....", "...."};

int		possible_to_put(t_figure coordinates, int x, int y)
{
	int i = 0;
	int x2 = x;
	int y2 = y;
	while (i != 4)
	{
		x = x2 + coordinates.x[i];
		y = y2 + coordinates.y[i];
		if (map[y][x] == '.')
			i++;
		else
			return (0);
	}
	return (1);
}

void	put_figureonmap(t_figure coordinates, int x, int y) //задефайнить переменную , когда нужна 4 вместо int i = 0< while i != 4
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
		map[y][x] = coordinates.c;
		i++;
	}

}

int		print_solution(t_figure *coordinates, int figures)
{
	int x = 0;
	int y = 0;

	if (figures == 0)
		return (1);
	while (y != 4)
	{
		if (map[y][x] == '.' && possible_to_put(*coordinates, x, y) == 1)
		{
			put_figureonmap(*coordinates, x, y);
			printf("%s\n", map[0]);
			printf("%s\n", map[1]);
			printf("%s\n", map[2]);
			printf("%s\n", map[3]);
			// if (figures - 1 != 0)
			// {
				if (print_solution(++coordinates, figures - 1) == 1)
					return (1);
				// delfig(coordinates, x, y);	
			// }
		}
		x++;
		if (x == 4)
		{
			x = 0;
			y = y + 1;
		}
	}

	return (0);
}

int	main(void)
{
	int	k = 0;
	char *str2 = "....\n..##\n..##\n....\n\n....\n...#\n..##\n..#.\n\n....\n..##\n..##\n....\n";
	// char *str2 = "...#\n...#\n...#\n...#\n"; // вертикальная палка справа
	// printf("%d\n", ((ft_record_all_figures(str2, 21))[0].x)[0]);
	// printf("%c\n", ft_record_all_figures(str2, 42)[1].c);
	print_solution(ft_record_all_figures(str2, 63), 3);
	// while (count_figures(str2) >= k)
	// {
	// 	printf("%s\n", ft_render_map(str2)[k]);
	// 	k++;
	// }
	return (0);
}



