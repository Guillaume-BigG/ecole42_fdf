/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbeaudoi <gbeaudoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 18:04:54 by gbeaudoi          #+#    #+#             */
/*   Updated: 2024/01/29 15:28:55 by gbeaudoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;
	int		i;

	if (!(x > 0 && x < WINDOW_WIDTH && y > 0 && y < WINDOW_HEIGHT))
		return ;
	dst = data->image.img_address + (y * data->image.img_line_length + x
			* (data->image.img_bpp / 8));
	i = data->image.img_bpp - 8;
	while (i >= 0)
	{
		if (data->image.img_endian != 0)
			*dst++ = (color >> i) & 0xFF;
		else
			*dst++ = (color >> (data->image.img_bpp - 8 - i)) & 0xFF;
		i -= 8;
	}
}

void	draw(t_data *data)
{
	int	x;
	int	y;

	y = 0;
	while (y < data->map.height)
	{
		x = 0;
		while (x < data->map.width)
		{
			if (data->flag_isometric)
				isometric_projection(data, &data->map.array[y][x]);
			else
				cavalier_projection(data, &data->map.array[y][x]);
			if (x > 0)
				line_bresenham(data, &data->map.array[y][x - 1],
					&data->map.array[y][x]);
			if (y > 0)
				line_bresenham(data, &data->map.array[y - 1][x],
					&data->map.array[y][x]);
			x++;
		}
		y++;
	}
}

int	render(t_data *data)
{
	if (data->window_ptr == NULL)
		return (1);
	reset_background(data, data->color_background);
	draw_upper_line(data, data->color_line);
	draw_lower_line(data, data->color_line);
	if (data->map.height == 1 && data->map.width == 1)
		my_mlx_pixel_put(data, 800, 550, 0xFF000000);
	else
		draw(data);
	mlx_put_image_to_window(data->mlx_ptr, data->window_ptr,
		data->image.mlx_image, 0, 0);
	draw_menu(data);
	return (0);
}
