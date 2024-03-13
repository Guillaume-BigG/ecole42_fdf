/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization_part2.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbeaudoi <gbeaudoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 20:24:54 by gbeaudoi          #+#    #+#             */
/*   Updated: 2024/02/23 20:38:06 by gbeaudoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	initialize_hook(t_data *data)
{
	mlx_loop_hook(data->mlx_ptr, &render, data);
	mlx_hook(data->window_ptr, KeyPress, KeyPressMask, &key_press_event, data);
	mlx_hook(data->window_ptr, ButtonPress, ButtonPress, &mouse_press_event,
		data);
	mlx_hook(data->window_ptr, ButtonRelease, ButtonReleaseMask,
		&mouse_release_event, data);
	mlx_hook(data->window_ptr, DestroyNotify, NoEventMask, &end_program, data);
	mlx_loop(data->mlx_ptr);
}

void	initialize_original_coordonate(t_data *data)
{
	int	x;
	int	y;

	y = 0;
	while (y < data->map.height)
	{
		x = 0;
		while (x < data->map.width)
		{
			data->map.array[y][x].ori_x = x * data->zoom;
			data->map.array[y][x].ori_y = y * data->zoom;
			data->map.array[y][x].ori_z = data->map.array[y][x].z;
			data->map.array[y][x].max_z_pos = data->max_z_pos;
			data->map.array[y][x].min_z_neg = data->min_z_neg;
			x++;
		}
		y++;
	}
}

void	initialize_zoom_calc(t_data *data)
{
	float	zoom_width;
	float	zoom_heigth;
	float	zoom_avg;

	zoom_width = (float)data->map.width / WINDOW_WIDTH;
	zoom_heigth = (float)data->map.height / WINDOW_HEIGHT;
	zoom_avg = (zoom_width + zoom_heigth) / 4;
	data->zoom = (WINDOW_WIDTH * WINDOW_HEIGHT) / (data->map.height
			* data->map.width) * zoom_avg;
}

void	initialize_map_pixel_loc(t_data *data)
{
	data->angle_rot_z = PI_G / 4;
	data->angle_rot_x = atan(sqrt(2));
	data->angle_rot_y = 0;
	data->depth = 1;
	data->scaling = 1;
	data->shift_x = WINDOW_WIDTH / 9 * 4;
	data->shift_y = WINDOW_HEIGHT / 8 * 2;
	data->color_background = 0xFFCCCCCC;
	data->color_line = 0xFFAAAAAA;
	data->color_words = 0xFF333333;
	data->pos_color = 0xFFFF00FF;
	data->neg_color = 0xFF00AAFF;
	data->flat_color = 0xFF8B4513;
	data->flag_isometric = 1;
	min_z(data);
	max_z(data);
	initialize_zoom_calc(data);
	initialize_original_coordonate(data);
}
