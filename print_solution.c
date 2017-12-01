/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_solution.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inovykov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/22 17:12:32 by inovykov          #+#    #+#             */
/*   Updated: 2017/11/22 17:12:34 by inovykov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

print_solution(t_figure coordinates, char **map)
{
	int i = 0;
	int j = 0;
	while (i != 4)
	{
		map[i][j] = coordinates.x[i][j];
		i++;
	}
	printf("%s\n", map[i][0]);
}
