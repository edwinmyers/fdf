/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nparker <nparker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 13:45:15 by nparker           #+#    #+#             */
/*   Updated: 2018/12/05 17:26:51 by nparker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t	i;
	char	*cdst;

	i = -1;
	cdst = dst;
	while (++i < n)
	{
		*(cdst + i) = *((unsigned char*)src + i);
		if (*((unsigned char *)cdst + i) == ((unsigned char)c))
			return (dst + i + 1);
	}
	return (NULL);
}
