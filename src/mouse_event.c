/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_event.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbeaudoi <gbeaudoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 15:49:31 by gbeaudoi          #+#    #+#             */
/*   Updated: 2024/01/27 21:03:17 by gbeaudoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	mouse_press_event(int button, int x, int y, t_data *data)
{
	data->prev_mouse_x = x;
	data->prev_mouse_y = y;
	if (button == WHEEL_UP)
		data->depth += 0.4;
	else if (button == WHEEL_DOWN)
		data->depth -= 0.4;
	return (0);
}

int	mouse_release_event(int button, int x, int y, t_data *data)
{
	if (button == MOUSE_LEFT)
	{
		data->shift_x += (x - data->prev_mouse_x);
		data->shift_y += (y - data->prev_mouse_y);
	}
	return (0);
}
