/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   record_fig.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inovykov <inovykov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 17:14:38 by inovykov          #+#    #+#             */
/*   Updated: 2017/11/30 17:17:31 by inovykov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

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
	// printf("arr[0] %d\n", arr[0]);
	// printf("arr[1] %d\n", arr[1]);
	// printf("arr[2] %d\n", arr[2]);
	// printf("arr[3] %d\n", arr[3]);
	while (arr[0] != 0 && arr[1] != 0 && arr[2] != 0 && arr[3] != 0 && (j = -1)) 
	{
		while (++j != 4)
			arr[j] = arr[j] - 1;
	}
	// printf("arr[0] %d\n", arr[0]);
	// printf("arr[1] %d\n", arr[1]);
	// printf("arr[2] %d\n", arr[2]);
	// printf("arr[3] %d\n", arr[3]);
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

t_figure		*ft_record_all_figures(char *str_figures, int figures)
{
	t_figure	*arr_figures; //array of structures, where one stracture stores info about one figure
	int			i; //iterates figures in arr of structures
	int			j;
	int			str_len;
	char		c;

	str_len = ft_strlen(str_figures);
	arr_figures = (t_figure*)malloc(sizeof(t_figure) * figures);
	if (!arr_figures)
		return (NULL);
	i = 0;
	j = 0;
	c = 'A';
	while (j < str_len)
	{
		arr_figures[i].x = put_x_cordinates(&str_figures[j]);
		arr_figures[i].y = put_y_cordinates(&str_figures[j]);
		arr_figures[i].c = c++;
		j = j + 21;
		i++;
	}
	return (arr_figures);
}
