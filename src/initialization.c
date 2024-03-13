/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbeaudoi <gbeaudoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 14:59:00 by gbeaudoi          #+#    #+#             */
/*   Updated: 2024/02/23 20:31:35 by gbeaudoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	initiatize_display_next(t_data *data)
{
	data->image.mlx_image = mlx_new_image(data->mlx_ptr, WINDOW_WIDTH,
			WINDOW_HEIGHT);
	if (data->image.mlx_image == NULL)
	{
		free(data->window_ptr);
		free(data->mlx_ptr);
		free(data->image.mlx_image);
		return (0);
	}
	data->image.img_address = mlx_get_data_addr(data->image.mlx_image,
			&data->image.img_bpp, &data->image.img_line_length,
			&data->image.img_endian);
	if (data->image.mlx_image == NULL)
	{
		free(data->window_ptr);
		free(data->mlx_ptr);
		free(data->image.mlx_image);
		free(data->image.img_address);
		return (0);
	}
	initialize_map_pixel_loc(data);
	initialize_hook(data);
	return (1);
}

int	initialize_display(t_data *data)
{
	data->mlx_ptr = mlx_init();
	if (data->mlx_ptr == NULL)
	{
		free(data->mlx_ptr);
		return (0);
	}
	data->window_ptr = mlx_new_window(data->mlx_ptr, WINDOW_WIDTH,
			WINDOW_HEIGHT, "My favorite window");
	if (data->window_ptr == NULL)
	{
		free(data->window_ptr);
		free(data->mlx_ptr);
		return (0);
	}
	if (!initiatize_display_next(data))
		return (0);
	return (1);
}
