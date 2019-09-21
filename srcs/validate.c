/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vice-wra <vice-wra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/14 12:27:56 by nparker           #+#    #+#             */
/*   Updated: 2019/03/15 16:14:55 by vice-wra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		ft_validate_syms(char c)
{
	if (ft_isdigit(c))
		return (1);
	if ((c == ' ' || c == 'x' || c == ',' || c == '+' || c == '-'))
		return (1);
	if ((c >= 'A' && c <= 'F') || (c >= 'a' && c <= 'f'))
		return (1);
	return (0);
}

int		ft_valid_combos(char c, char i)
{
	if (c == '-' && (i == '-' || i == '+' || i == ',' || i == ' '))
		return (0);
	if (c == '+' && (i == '-' || i == '+' || i == ',' || i == ' '))
		return (0);
	if (c == ',' && i != '0')
		return (0);
	if (c == ' ' && i == ',')
		return (0);
	return (1);
}

int		ft_validate(char *str)
{
	unsigned long i;

	i = -1;
	while (++i < ft_strlen(str) - 1)
	{
		if (ft_validate_syms(str[i]) == 0)
			return (0);
		if (ft_isdigit(str[i]) && (str[i + 1] == '-' || str[i + 1] == '+'))
			return (0);
		if (ft_valid_combos(str[i], str[i + 1]) == 0)
			return (0);
		if ((i == 0 || str[i + 1] == ' ' ||
		(str[i + 1] == '-' && str[i + 1] == '+')) && str[i] == 'x')
			return (0);
	}
	if (str[i] == 'x' || str[i] == '-' || str[i] == '+' || str[i] == ',')
		return (0);
	return (1);
}
