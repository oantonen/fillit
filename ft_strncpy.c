/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inovykov <inovykov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 16:28:15 by oantonen          #+#    #+#             */
/*   Updated: 2017/11/28 16:55:45 by inovykov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	*ft_strncpy(char *dst, char *src, size_t len)
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
