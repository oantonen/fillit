/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oantonen <oantonen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/22 10:10:46 by inovykov          #+#    #+#             */
/*   Updated: 2017/11/24 12:36:48 by oantonen         ###   ########.fr       */
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
	int		i;
	char	buff;

	i = 0;
	while (read(fp, &buff, 1) > 0)
		i++;
	return (i);
}

int			main(int ac, char **av)
{
	char	buff;
	char	*str_figures;
	int		str_len;
	int		fp;
	int		i;

	fp = open(av[1], O_RDONLY);
	if (check_error(ac, fp) == FALSE)
		return(0);
	str_len = count_file_len(fp);
	close(fp);
	str_figures = (char*)malloc(sizeof(char) * (str_len + 2));
	// fp = open(av[1], O_RDONLY);
	if (check_error(ac, (open(av[1], O_RDONLY))) == FALSE)
		return(0);
	i = 0;
	while (read(fp, &buff, 1) > 0)
		str_figures[i++] = buff;
	str_figures[i] = '\0';
	close(fp);
	if (check_input(str_len, str_figures) == TRUE)
		printf("valid %d\n", check_input(str_len, str_figures));
	else
		printf("invalid input\n");
		/*print_solution(solve(str_figurs));
	else
		print_error(2);*/
	return (0);
}