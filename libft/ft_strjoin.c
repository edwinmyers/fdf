/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nparker <nparker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 17:30:55 by nparker           #+#    #+#             */
/*   Updated: 2018/12/06 18:01:32 by nparker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strjoin(char const *s1, char const *s2)
{
	char	*new_str;
	size_t	i;
	size_t	j;
	size_t	len1;
	size_t	len2;

	if (!s1 || !s2)
		return (0);
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	new_str = ft_strnew(len1 + len2);
	if (!new_str)
		return (0);
	i = -1;
	j = -1;
	while (++i < len1)
		*(new_str + i) = *(s1 + i);
	while (++j < len2)
		*(new_str + i++) = *(s2 + j);
	*(new_str + i) = '\0';
	return (new_str);
}
