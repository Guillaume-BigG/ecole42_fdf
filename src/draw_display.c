/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_display.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbeaudoi <gbeaudoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 16:57:35 by gbeaudoi          #+#    #+#             */
/*   Updated: 2024/01/27 15:27:09 by gbeaudoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw_upper_line(t_data *data, int color)
{
	int	i;
	int	j;

	i = 0;
	while (i < WINDOW_HEIGHT / 9)
	{
		j = 0;
		while (j < WINDOW_WIDTH)
		{
			my_mlx_pixel_put(data, j++, i, color);
		}
		i++;
	}
}

void	draw_lower_line(t_data *data, int color)
{
	int	i;
	int	j;

	i = WINDOW_HEIGHT / 9 * 8;
	while (i < WINDOW_HEIGHT)
	{
		j = 0;
		while (j < WINDOW_WIDTH)
		{
			my_mlx_pixel_put(data, j++, i, color);
		}
		i++;
	}
}

void	reset_background(t_data *data, int color)
{
	int	i;
	int	j;

	i = WINDOW_HEIGHT / 9;
	while (i < WINDOW_HEIGHT / 9 * 8)
	{
		j = 0;
		while (j < WINDOW_WIDTH)
		{
			my_mlx_pixel_put(data, j++, i, color);
		}
		i++;
	}
}
