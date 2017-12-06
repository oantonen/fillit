/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inovykov <inovykov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 17:48:29 by inovykov          #+#    #+#             */
/*   Updated: 2017/12/06 17:49:16 by inovykov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_sqrt(int nb)
{
	int i;

	i = 2;
	while (i * i < nb)
		i++;
	return (i);
}

int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strncpy(char *dst, char *src, int len)
{
	char *ptr;

	ptr = dst;
	while (len)
	{
		if (!*src)
			break ;
		else
			*ptr++ = *src++;
		len--;
	}
	while (len)
	{
		*ptr++ = '\0';
		len--;
	}
	return (dst);
}

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
