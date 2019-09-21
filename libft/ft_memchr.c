/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nparker <nparker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 15:29:17 by nparker           #+#    #+#             */
/*   Updated: 2018/12/05 17:27:01 by nparker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			*ft_memchr(const void *s, int c, size_t n)
{
	size_t		i;
	const char	*cs;

	cs = (const char *)s;
	i = -1;
	while (++i < n)
		if (*(cs + i) == (char)c)
			return ((void*)cs + i);
	return (NULL);
}
