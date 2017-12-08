/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oantonen <oantonen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/22 15:24:13 by inovykov          #+#    #+#             */
/*   Updated: 2017/12/07 17:38:50 by oantonen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H

# define FILLIT_H
# define TRUE    1
# define FALSE   0

# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

typedef struct	s_figure
{
	int			*x;
	int			*y;
	char		c;
}				t_figure;

char			**g_map;

void			print_error(int n);
int				check_input(int str_len, char *str_figures);
int				ft_strlen(const char *str);
int				count_figures(char *str_figures);
t_figure		*ft_record_all_figures(char *str_figures, int figures);
void			free_willy(char **arr);
char			*ft_strncpy(char *dst, char *src, int len);
char			*ft_strnew(int size);
int				ft_sqrt(int nb);
int				check_all_same(t_figure current_fig, t_figure next_fig);
void			ft_render_map(int cell);
int				find_solution(t_figure *coordinates, int figures, int cells);
void			print_map(char	**map, int cells);

#endif
