/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbeaudoi <gbeaudoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 17:00:15 by gbeaudoi          #+#    #+#             */
/*   Updated: 2024/01/27 19:20:33 by gbeaudoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	horizontal_line(t_data *data, t_coordinate *start, t_coordinate *end)
{
	int	x;
	int	color;
	int	i;

	i = 0;
	x = start->x;
	while (x != end->x)
	{
		color = color_gradiant_pixel(i++, data->dx, start, end);
		my_mlx_pixel_put(data, x, start->y, color);
		x += data->inc_x;
	}
}

void	vertical_line(t_data *data, t_coordinate *start, t_coordinate *end)
{
	int	y;
	int	color;
	int	i;

	i = 0;
	y = start->y;
	while (y != end->y)
	{
		color = color_gradiant_pixel(i++, data->dy, start, end);
		my_mlx_pixel_put(data, start->x, y, color);
		y += data->inc_y;
	}
}

void	more_horizontal_line(t_data *data, t_coordinate *start,
		t_coordinate *end)
{
	int	x;
	int	y;
	int	error;
	int	color;
	int	i;

	i = 0;
	error = -data->dx;
	x = start->x;
	y = start->y;
	while (x != end->x)
	{
		color = color_gradiant_pixel(i++, data->dx, start, end);
		my_mlx_pixel_put(data, x, y, color);
		error += 2 * data->dy;
		if (error >= 0)
		{
			y += data->inc_y;
			error += -2 * data->dx;
		}
		x += data->inc_x;
	}
}

void	more_vertical_line(t_data *data, t_coordinate *start, t_coordinate *end)
{
	int	x;
	int	y;
	int	error;
	int	color;
	int	i;

	i = 0;
	error = -data->dy;
	x = start->x;
	y = start->y;
	while (y != end->y)
	{
		color = color_gradiant_pixel(i++, data->dy, start, end);
		my_mlx_pixel_put(data, x, y, color);
		error += 2 * data->dx;
		if (error >= 0)
		{
			x += data->inc_x;
			error += -2 * data->dy;
		}
		y += data->inc_y;
	}
}

void	line_bresenham(t_data *data, t_coordinate *start, t_coordinate *end)
{
	if (!data->flag_color_given)
	{
		start->color = data_color(data, start);
		end->color = data_color(data, end);
	}
	data->dx = end->x - start->x;
	data->dy = end->y - start->y;
	data->inc_x = sign(data->dx);
	data->inc_y = sign(data->dy);
	data->dx = absolute(data->dx);
	data->dy = absolute(data->dy);
	if (data->dy == 0)
		horizontal_line(data, start, end);
	else if (data->dx == 0)
		vertical_line(data, start, end);
	else if (data->dx >= data->dy)
		more_horizontal_line(data, start, end);
	else
		more_vertical_line(data, start, end);
}
