/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nparker <nparker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 13:17:15 by nparker           #+#    #+#             */
/*   Updated: 2018/12/14 13:17:09 by nparker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strtrim(char const *s)
{
	size_t	len;
	size_t	i;
	char	*new_str;

	if (s == NULL)
		return (NULL);
	len = ft_strlen(s);
	i = 0;
	while ((s[i] == ' ' || s[i] == '\n' || s[i] == '\t') && s[i] != '\0')
		i++;
	while ((s[len - 1] == ' ' || s[len - 1] == '\n' ||
			s[len - 1] == '\t') && s[i] != '\0')
		len--;
	if (len <= 0)
		len = 0;
	new_str = ft_strsub(s, i, len - i);
	if (new_str == NULL)
		return (NULL);
	return (new_str);
}
