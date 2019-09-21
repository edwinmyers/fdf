/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex_to_dec.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nparker <nparker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 14:32:48 by jblue-da          #+#    #+#             */
/*   Updated: 2019/03/06 15:59:37 by nparker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_hex(char c)
{
	if (c >= '0' && c <= '9')
		return (c - 48);
	if (c >= 'A' && c <= 'F')
		return (c - 55);
	return (c - 87);
}

int			ft_hex_to_dec(char *str)
{
	int		res;
	size_t	i;
	size_t	len;

	i = 0;
	res = 0;
	len = ft_strlen(str);
	if (len > 2 && str[0] == '0' && str[1] == 'x')
		i += 2;
	while (i < len)
	{
		res += ft_pow(16, len - i - 1) * ft_hex(str[i]);
		++i;
	}
	return (res);
}
