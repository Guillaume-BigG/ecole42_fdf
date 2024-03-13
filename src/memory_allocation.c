/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory_allocation.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbeaudoi <gbeaudoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 20:40:49 by gbeaudoi          #+#    #+#             */
/*   Updated: 2024/02/23 20:19:35 by gbeaudoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	array_allocation(t_data *data)
{
	data->map.array = (t_coordinate **)malloc(sizeof(t_coordinate *)
			* (data->map.height + 1));
	if (data->map.array == NULL)
	{
		ft_printf("Memory allocation error");
		return (0);
	}
	data->map.array[data->map.height] = NULL;
	return (1);
}

int	array_allocation_decimal(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (i < data->map.height)
	{
		data->map.array[i] = (t_coordinate *)malloc(sizeof(t_coordinate)
				* (data->map.width + 1));
		if (data->map.array[i] == NULL)
		{
			j = 0;
			while (j < i)
			{
				free(data->map.array[j]);
				j++;
			}
			ft_printf("Memory allocation error");
			return (0);
		}
		i++;
	}
	return (1);
}

int	end_program(t_data *data)
{
	free_map(data);
	if (data->image.mlx_image)
		mlx_destroy_image(data->mlx_ptr, data->image.mlx_image);
	if (data->window_ptr)
		mlx_destroy_window(data->mlx_ptr, data->window_ptr);
	if (data->mlx_ptr)
	{
		mlx_destroy_display(data->mlx_ptr);
		free(data->mlx_ptr);
	}
	exit(0);
	return (0);
}
