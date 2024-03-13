/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbeaudoi <gbeaudoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 18:10:06 by gbeaudoi          #+#    #+#             */
/*   Updated: 2024/01/27 15:11:09 by gbeaudoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_find_value(char c, char *base)
{
	int	i;

	i = 0;
	while (base[i] != '\0')
	{
		if (c == base[i])
			return (i);
		i++;
	}
	return (-1);
}

int	ft_atoi_base_hex(char *str)
{
	int		i;
	int		nbr;
	char	*base;

	i = 0;
	base = "0123456789ABCDEF";
	while (str[i])
	{
		nbr = (nbr * 16) + ft_find_value(str[i], base);
		i++;
	}
	return (nbr);
}

int	absolute(int x)
{
	if (x >= 0)
		return (x);
	else
		return (-x);
}

int	sign(int x)
{
	if (x < 0)
		return (-1);
	else if (x > 0)
		return (1);
	else
		return (0);
}

int	maximun(int x, int y)
{
	if (x <= y)
		return (y);
	else
		return (x);
}
