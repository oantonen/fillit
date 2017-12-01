/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inovykov <inovykov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/22 17:11:26 by inovykov          #+#    #+#             */
/*   Updated: 2017/11/27 19:19:07 by inovykov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int	check_map_len(char *str_figures)
{
	size_t	len;

	len = ft_strlen(str_figures);
	if (len < 21 || len > 546) /*less 1 or more 26 figures*/
		return (FALSE);
	return (TRUE);
}

static int	check_figure_matrix(char *str_figures, int j)
{
	int		len;
	int		row;

	len = (int)ft_strlen(str_figures);
	//printf("len %d\n", len);
	row = 1;
	while (len > j)
	{
		//printf("curent cell %d\n", j);
		if (str_figures[j + 5] == '\n')
		{
			j = j + 5;
			row++;
			if ((row + 1) % 5 == 0)
			{
				//printf("now j is %d\n", j);
				if (str_figures[j + 1] != '\n' && str_figures[j + 1] != '\0')
				{
					//printf("now j is %d\n", j);
					printf("check betwin tetrimino\n");
					return (FALSE);
				}
				else
				{
					//printf("else: now j is %d\n", j);
					j = j + 1;
					//printf("else2: now j is %d\n", j);
				}
				row++;
			}					
		}
		else
			return (FALSE);
	}
	return (TRUE);
}

int			check_input(int str_len, char *str_figures)
{
	int		i;
	int		j;

	i = -1;
	printf("%d\n", str_len);
	printf("I am validating\n");
	while (str_len > ++i)
	{
		if (check_map_len(str_figures) == FALSE)
			return (FALSE);
		if (str_figures[i] != '#' && str_figures[i] != '.' && str_figures[i] != '\n')
		{
			printf("some chars not #.\n");
			return (FALSE);
		}
		if (i == 4)
		{
			j = i;
			if (str_figures[i] == '\n')
			{
				if (check_figure_matrix(str_figures, j) == FALSE)
				{
					printf("invalid matrix\n");
					return (FALSE);
				}
			}
			else
				return (FALSE);
		}
	}
	if (check_tetra(str_figures, str_len) == FALSE)
		return (FALSE);
	printf("allright!\n");
	return (TRUE);
}
























