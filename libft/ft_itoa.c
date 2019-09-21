/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nparker <nparker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/09 11:29:05 by nparker           #+#    #+#             */
/*   Updated: 2018/12/10 15:05:02 by nparker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int			str_len(int n)
{
	size_t			i;

	i = 1;
	while (n /= 10)
		i++;
	return (i);
}

char				*ft_itoa(int n)
{
	int				cpy_n;
	size_t			len;
	char			*new_str;

	len = str_len(n);
	cpy_n = n;
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (cpy_n < 0)
	{
		cpy_n = -n;
		len++;
	}
	if (!(new_str = ft_strnew(len)))
		return (0);
	new_str[--len] = cpy_n % 10 + '0';
	while (cpy_n /= 10)
		new_str[--len] = cpy_n % 10 + '0';
	if (n < 0)
		new_str[0] = '-';
	return (new_str);
}
