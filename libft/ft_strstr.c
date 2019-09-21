/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nparker <nparker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 16:16:06 by nparker           #+#    #+#             */
/*   Updated: 2018/12/05 17:30:07 by nparker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strstr(const char *haystack, const char *needle)
{
	int		i;
	int		j;
	int		k;
	int		good;

	i = -1;
	good = 0;
	if (!ft_strlen(needle))
		return ((char *)haystack);
	while (*(haystack + ++i) && !good)
	{
		if (*(haystack + i) == *(needle + 0))
		{
			j = 0;
			k = i;
			good = 1;
			while (*(needle + j))
				if (*(needle + j++) != *(haystack + k++))
					good = 0;
			if (good)
				return ((char *)haystack + i);
		}
	}
	return (NULL);
}
