/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oantonen <oantonen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/22 10:10:46 by inovykov          #+#    #+#             */
/*   Updated: 2017/12/07 17:38:16 by oantonen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int	check_error(int ac, int fp)
{
	if (ac != 2)
	{
		print_error(1);
		return (FALSE);
	}
	if (fp == -1)
	{
		print_error(2);
		return (FALSE);
	}
	return (TRUE);
}

static int	count_file_len(int fp)
{
	int			i;
	char		buff;

	i = 0;
	while (read(fp, &buff, 1) > 0)
		i++;
	return (i);
}

static char	*record_file(int ac, char *file_name, int fp, int str_len)
{
	char		*str_figures;
	int			i;
	char		buff;

	str_figures = (char*)malloc(sizeof(char) * (str_len + 2));
	if (!str_figures)
	{
		free(str_figures);
		print_error(2);
		return (0);
	}
	if (check_error(ac, (open(file_name, O_RDONLY))) == FALSE)
		return (0);
	i = 0;
	while (read(fp, &buff, 1) > 0)
		str_figures[i++] = buff;
	str_figures[i] = '\0';
	close(fp);
	return (str_figures);
}

static void	solving(char *str_figures)
{
	int			figures;
	t_figure	*arr_figs;
	int			cells;

	figures = count_figures(str_figures);
	arr_figs = ft_record_all_figures(str_figures, figures);
	cells = ft_sqrt(figures * 4);
	ft_render_map(cells);
	if (find_solution(arr_figs, figures, cells) == TRUE)
		print_map(g_map, cells);
	else
	{
		free(g_map);
		ft_render_map(++cells);
		while (find_solution(arr_figs, figures, cells) == FALSE)
			ft_render_map(++cells);
		print_map(g_map, cells);
	}
}

int			main(int ac, char **av)
{
	char	*str_figures;
	int		str_len;
	int		fp;

	fp = open(av[1], O_RDONLY);
	if (check_error(ac, fp) == FALSE)
		return (0);
	str_len = count_file_len(fp);
	close(fp);
	if (str_len == 0)
	{
		print_error(2);
		return (0);
	}
	str_figures = record_file(ac, av[1], fp, str_len);
	if (check_input(str_len, str_figures) == TRUE)
		solving(str_figures);
	else
		print_error(2);
	return (0);
}
