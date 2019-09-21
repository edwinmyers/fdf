/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nparker <nparker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 17:18:33 by nparker           #+#    #+#             */
/*   Updated: 2018/12/09 13:13:08 by nparker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*new_str;
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	new_str = ft_strnew(len);
	if (!new_str)
		return (0);
	while (i < len)
		*(new_str + i++) = *(s + start++);
	*(new_str + i) = '\0';
	return (new_str);
}
