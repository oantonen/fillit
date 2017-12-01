/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inovykov <inovykov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/22 15:24:13 by inovykov          #+#    #+#             */
/*   Updated: 2017/11/28 19:33:32 by inovykov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H

# define FILLIT_H
# define TRUE    1
# define FALSE   0

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

typedef struct	s_figure
{
	int		*x;
	int		*y;
	char	c;
	
}				t_figure;

void	print_error(int n);
int		check_input(int str_len, char *str_figures);
size_t	ft_strlen(const char *str);
int 	check_tetra(char *str_figures, int str_len);
char	*ft_strncpy(char *dst, char *src, size_t len);
char	*ft_strnew(int size);
int		ft_sqrt(int nb);

#endif
