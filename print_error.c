/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oantonen <oantonen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/22 15:29:45 by inovykov          #+#    #+#             */
/*   Updated: 2017/11/24 12:44:01 by oantonen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	print_error(int n)
{
	if (n == 1)
		write(1, "usage: ./fillit source_file\n", 28); /*to many or to few arguments*/
	if (n == 2)
		write(1, "error\n", 6); /*error opening file, invalid tetrimino, no solution*/
}

