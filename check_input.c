/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oantonen <oantonen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/22 17:11:26 by inovykov          #+#    #+#             */
/*   Updated: 2017/12/07 13:36:01 by oantonen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int	check_map_len(char *str_figures)
{
	int		len;

	len = ft_strlen(str_figures);
	if (len < 20 || len > 545)
		return (FALSE);
	return (TRUE);
}

static int	check_figure_matrix(char *str_figures, int j)
{
	int		len;
	int		row;

	len = ft_strlen(str_figures);
	row = 1;
	while (len > j)
	{
		if (str_figures[j + 5] == '\n')
		{
			j = j + 5;
			row++;
			if ((row + 1) % 5 == 0)
			{
				if (str_figures[j + 1] != '\n' && str_figures[j + 1] != '\0')
					return (FALSE);
				else
					j = j + 1;
				row++;
			}
		}
		else
			return (FALSE);
	}
	return (TRUE);
}

static int	is_figure_valid(char *str)
{
	int		b;
	int		hash;
	int		tetra;

	b = 0;
	hash = 0;
	tetra = 0;
	while (b < 21)
	{
		if (str[b] == '#')
		{
			(b + 1 < 21 && str[b + 1] == '#') ? tetra++ : tetra;
			(b + 5 < 21 && str[b + 5] == '#') ? tetra++ : tetra;
			(b - 1 >= 0 && str[b - 1] == '#') ? tetra++ : tetra;
			(b - 5 >= 0 && str[b - 5] == '#') ? tetra++ : tetra;
			hash++;
		}
		b++;
		if ((tetra == 6 || tetra == 8) && hash == 4)
			return (TRUE);
	}
	return (FALSE);
}

static int	check_tetra(char *str_figures, int str_len)
{
	char	block[21];
	int		i;

	i = 0;
	while (i < str_len)
	{
		ft_strncpy(block, &str_figures[i], 20);
		if (is_figure_valid(block) == TRUE)
			i = i + 21;
		else
			return (FALSE);
	}
	return (TRUE);
}

int			check_input(int str_len, char *str_fig)
{
	int		i;
	int		j;

	i = -1;
	while (str_len > ++i)
	{
		if (check_map_len(str_fig) == FALSE)
			return (FALSE);
		if (str_fig[i] != '#' && str_fig[i] != '.' && str_fig[i] != '\n')
			return (FALSE);
		if (i == 4)
		{
			j = i;
			if (str_fig[i] == '\n')
			{
				if (check_figure_matrix(str_fig, j) == FALSE)
					return (FALSE);
			}
			else
				return (FALSE);
		}
	}
	if (check_tetra(str_fig, str_len) == FALSE)
		return (FALSE);
	return (TRUE);
}
