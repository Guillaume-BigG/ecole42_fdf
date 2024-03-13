/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_projection.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbeaudoi <gbeaudoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 14:49:53 by gbeaudoi          #+#    #+#             */
/*   Updated: 2024/01/27 15:22:00 by gbeaudoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	max_z(t_data *data)
{
	int	x;
	int	y;

	data->max_z_pos = 1;
	y = 0;
	while (y < data->map.height)
	{
		x = 0;
		while (x < data->map.width)
		{
			if (data->map.array[y][x].z > data->max_z_pos)
				data->max_z_pos = data->map.array[y][x].z;
			x++;
		}
		y++;
	}
}

void	min_z(t_data *data)
{
	int	x;
	int	y;

	data->min_z_neg = -1;
	y = 0;
	while (y < data->map.height)
	{
		x = 0;
		while (x < data->map.width)
		{
			if (data->map.array[y][x].z < data->min_z_neg)
				data->min_z_neg = data->map.array[y][x].z;
			x++;
		}
		y++;
	}
}

void	isometric_projection(t_data *data, t_coordinate *coordinate)
{
	coordinate->proj_x = coordinate->ori_x * cos(data->angle_rot_z)
		- coordinate->ori_y * sin(data->angle_rot_z);
	coordinate->proj_y = coordinate->ori_x * sin(data->angle_rot_z)
		+ coordinate->ori_y * cos(data->angle_rot_z);
	coordinate->proj_z = coordinate->ori_z * data->depth;
	coordinate->proj_x = coordinate->proj_x;
	coordinate->proj_y = coordinate->proj_y * cos(data->angle_rot_x)
		- coordinate->proj_z * sin(data->angle_rot_x);
	coordinate->proj_z = coordinate->proj_y * sin(data->angle_rot_x)
		+ coordinate->proj_z * cos(data->angle_rot_x);
	coordinate->proj_x = coordinate->proj_x * cos(data->angle_rot_y)
		+ (coordinate->proj_z) * sin(data->angle_rot_y);
	coordinate->x = (int)(coordinate->proj_x * data->scaling + data->shift_x);
	coordinate->y = (int)(coordinate->proj_y * data->scaling + data->shift_y);
	coordinate->z = coordinate->ori_z * data->depth;
}

void	calc_cavalier(t_data *data, t_coordinate *coordinate, t_cav cav_coor)
{
	coordinate->proj_x = cav_coor.x + cav_coor.z * data->depth
		* cos(data->angle_rot_z);
	coordinate->proj_y = cav_coor.y + cav_coor.z * data->depth
		* sin(data->angle_rot_z);
	coordinate->x = (int)(coordinate->proj_x * data->scaling + data->shift_x);
	coordinate->y = (int)(coordinate->proj_y * data->scaling + data->shift_y);
	coordinate->z = coordinate->ori_z * data->depth;
}

void	cavalier_projection(t_data *data, t_coordinate *coordinate)
{
	t_cav	cav_coor;

	if (data->flag_cav == 1)
	{
		cav_coor.x = coordinate->ori_x;
		cav_coor.y = coordinate->ori_y;
		cav_coor.z = coordinate->ori_z;
		calc_cavalier(data, coordinate, cav_coor);
	}
	else if (data->flag_cav == 2)
	{
		cav_coor.x = coordinate->ori_y;
		cav_coor.y = coordinate->ori_z;
		cav_coor.z = coordinate->ori_z;
		calc_cavalier(data, coordinate, cav_coor);
	}
	else
	{
		cav_coor.x = coordinate->ori_x;
		cav_coor.y = coordinate->ori_z;
		cav_coor.z = coordinate->ori_z;
		calc_cavalier(data, coordinate, cav_coor);
	}
}
