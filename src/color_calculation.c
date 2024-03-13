/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_calculation.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbeaudoi <gbeaudoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 16:35:46 by gbeaudoi          #+#    #+#             */
/*   Updated: 2024/01/29 15:02:01 by gbeaudoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	desassociate_color(t_coordinate *coordinate)
{
	coordinate->color_transparancy = ((coordinate->color >> 24) & 0xFF);
	coordinate->color_red = ((coordinate->color >> 16) & 0xFF);
	coordinate->color_green = ((coordinate->color >> 8) & 0xFF);
	coordinate->color_blue = (coordinate->color & 0xFF);
}

int	translate_color(t_color coordinate)
{
	int	color;

	color = (coordinate.color_transparancy << 24 | coordinate.color_red << 16 | \
			coordinate.color_green << 8 | coordinate.color_blue);
	return (color);
}

int	color_gradiant_pixel(int step, int num_steps, t_coordinate *start,
		t_coordinate *end)
{
	float	t;
	t_color	gradient;

	t = (float)step / (num_steps - 1);
	desassociate_color(start);
	desassociate_color(end);
	gradient.color_transparancy = (int)(start->color_transparancy * (1 - t)
			+ end->color_transparancy * t);
	gradient.color_red = (int)(start->color_red * (1 - t) + end->color_red * t);
	gradient.color_green = (int)(start->color_green * (1 - t) + end->color_green
			* t);
	gradient.color_blue = (int)(start->color_blue * (1 - t) + end->color_blue
			* t);
	gradient.color = translate_color(gradient);
	return (gradient.color);
}

int	color_coordinate_assign(int i, t_data *data, t_coordinate *point,
		float factor)
{
	t_color	color;

	if (i == 1)
	{
		point->color = data->pos_color;
		desassociate_color(point);
		color.color_red = (int)point->color_red * factor;
		color.color_green = (int)point->color_green * factor;
		color.color_blue = (int)point->color_blue * factor;
		return (translate_color(color));
	}
	else if (i == 2)
	{
		point->color = data->neg_color;
		desassociate_color(point);
		color.color_red = (int)point->color_red * factor;
		color.color_green = (int)point->color_green * factor;
		color.color_blue = (int)point->color_blue * factor;
		return (translate_color(color));
	}
	else
		return (data->flat_color);
}

int	data_color(t_data *data, t_coordinate *point)
{
	int		i;
	float	factor;

	if (point->z > 0)
		i = 1;
	else if (point->z < 0)
		i = 2;
	else
		i = 3;
	if (point->ori_z > 0)
		factor = point->ori_z / point->max_z_pos;
	else if (point->ori_z < 0)
		factor = point->ori_z / point->min_z_neg;
	else
		factor = 1;
	if (data->color_background == 0xFF008080)
		return (color_coordinate_assign(i, data, point, factor));
	else if (data->color_background == 0xFF991439)
		return (color_coordinate_assign(i, data, point, factor));
	else if (data->color_background == 0xFF9B59B6)
		return (color_coordinate_assign(i, data, point, factor));
	else if (data->color_background == 0xFF000000)
		return (color_coordinate_assign(i, data, point, factor));
	else
		return (color_coordinate_assign(i, data, point, factor));
}
