/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard_event.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbeaudoi <gbeaudoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 16:40:08 by gbeaudoi          #+#    #+#             */
/*   Updated: 2024/01/27 17:49:35 by gbeaudoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	check_projection_cavalier(int keysym, t_data *data)
{
	if (keysym == Z)
	{
		data->flag_isometric = 1;
		data->angle_rot_z = PI_G / 4;
		data->angle_rot_x = atan(sqrt(2));
		data->angle_rot_y = 0;
	}
	else if (keysym == X)
	{
		data->flag_isometric = 0;
		data->flag_cav = 1;
		data->angle_rot_z = PI_G / 4;
	}
	else if (keysym == C)
	{
		data->flag_isometric = 0;
		data->flag_cav = 2;
		data->angle_rot_z = PI_G / 4;
	}
	else if (keysym == V)
	{
		data->flag_isometric = 0;
		data->flag_cav = 3;
		data->angle_rot_z = PI_G / 4;
	}
}

void	reassign_angle(t_data *data, float ang_x, float ang_y, float ang_z)
{
	data->angle_rot_x = ang_x;
	data->angle_rot_y = ang_y;
	data->angle_rot_z = ang_z;
}

void	check_projection_parallele(int keysym, t_data *data)
{
	if (keysym == Q)
	{
		data->flag_isometric = 1;
		reassign_angle(data, atan(sqrt(2)), 0, PI_G / 4);
	}
	else if (keysym == W)
	{
		data->flag_isometric = 1;
		reassign_angle(data, 0, 0, 0);
	}
	else if (keysym == E)
	{
		data->flag_isometric = 1;
		reassign_angle(data, PI_G / 2, 0, 0);
	}
	else if (keysym == R)
	{
		data->flag_isometric = 1;
		data->angle_rot_x = PI_G / 2;
		data->angle_rot_y = 0;
		data->angle_rot_z = PI_G / 2;
		reassign_angle(data, PI_G / 2, 0, PI_G / 2);
	}
}

void	check_palette(int keysym, t_data *data)
{
	if (keysym == A)
		white_palette(data);
	else if (keysym == S)
		black_palette(data);
	else if (keysym == D)
		ocean_blue_palette(data);
	else if (keysym == F)
		summer_sunset_palette(data);
	else if (keysym == G)
		lavender_palette(data);
}

int	key_press_event(int keysym, t_data *data)
{
	if (keysym == XK_Escape)
		end_program(data);
	else if (keysym == PLUS)
		data->scaling /= 0.9;
	else if (keysym == MINUS)
		data->scaling *= 0.9;
	else if (keysym == ARROW_LEFT)
		data->angle_rot_z += PI_G / 64;
	else if (keysym == ARROW_RIGHT)
		data->angle_rot_z -= PI_G / 64;
	else if (keysym == ARROW_UP)
		data->angle_rot_x += PI_G / 64;
	else if (keysym == ARROW_DOWN)
		data->angle_rot_x -= PI_G / 64;
	check_palette(keysym, data);
	check_projection_parallele(keysym, data);
	check_projection_cavalier(keysym, data);
	return (0);
}
