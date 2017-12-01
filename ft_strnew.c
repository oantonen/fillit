/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inovykov <inovykov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/31 17:41:35 by inovykov          #+#    #+#             */
/*   Updated: 2017/11/28 17:31:00 by inovykov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	*ft_strnew(int size)
{
	char	*str;
	int		i;

	i = 0;
	str = (char*)malloc(sizeof(char) * (size + 1));
	if (str)
	{
		while (i < size)
		{
			str[i] = '.';
			i++;
		}
		str[i] = '\0';
		return (str);
	}
	else
		return (NULL);
}
