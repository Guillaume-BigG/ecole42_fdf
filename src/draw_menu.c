/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_menu.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbeaudoi <gbeaudoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 15:11:20 by gbeaudoi          #+#    #+#             */
/*   Updated: 2024/01/27 16:55:17 by gbeaudoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	write_cavaliere_instruction(t_data *data)
{
	mlx_string_put(data->mlx_ptr, data->window_ptr, 1440, 980,
		data->color_words, "Look at cavaliere projection:");
	mlx_string_put(data->mlx_ptr, data->window_ptr, 1340, 1010,
		data->color_words, "Back to Isometric proj: press Z");
	mlx_string_put(data->mlx_ptr, data->window_ptr, 1340, 1030,
		data->color_words, "From the top: press X");
	mlx_string_put(data->mlx_ptr, data->window_ptr, 1540, 1010,
		data->color_words, "From the wide: press C");
	mlx_string_put(data->mlx_ptr, data->window_ptr, 1540, 1030,
		data->color_words, "From the lenght: press V");
}

void	write_paralelle_instruction(t_data *data)
{
	mlx_string_put(data->mlx_ptr, data->window_ptr, 1440, 20, data->color_words,
		"Look at parallele projection:");
	mlx_string_put(data->mlx_ptr, data->window_ptr, 1340, 50, data->color_words,
		"Back to Isometric proj: press Q");
	mlx_string_put(data->mlx_ptr, data->window_ptr, 1340, 70, data->color_words,
		"From the top: press W");
	mlx_string_put(data->mlx_ptr, data->window_ptr, 1540, 50, data->color_words,
		"From the length: press E");
	mlx_string_put(data->mlx_ptr, data->window_ptr, 1540, 70, data->color_words,
		"From the wide: press R");
}

void	write_rotation_instruction(t_data *data)
{
	mlx_string_put(data->mlx_ptr, data->window_ptr, 840, 20, data->color_words,
		"To rotate around the Z-Axis:");
	mlx_string_put(data->mlx_ptr, data->window_ptr, 840, 50, data->color_words,
		"left: press the left arrow");
	mlx_string_put(data->mlx_ptr, data->window_ptr, 840, 70, data->color_words,
		"right: press the right arrow:");
	mlx_string_put(data->mlx_ptr, data->window_ptr, 1040, 20, data->color_words,
		"To rotate around the X-Axis:");
	mlx_string_put(data->mlx_ptr, data->window_ptr, 1040, 50, data->color_words,
		"up: press the up arrow");
	mlx_string_put(data->mlx_ptr, data->window_ptr, 1040, 70, data->color_words,
		"down: press the down arrow:");
}

void	write_color_palette_instc(t_data *data)
{
	mlx_string_put(data->mlx_ptr, data->window_ptr, 425, 20, data->color_words,
		"To use the color palette below:");
	mlx_string_put(data->mlx_ptr, data->window_ptr, 320, 50, data->color_words,
		"White palette (default): press A");
	mlx_string_put(data->mlx_ptr, data->window_ptr, 320, 70, data->color_words,
		"Black palette: press S");
	mlx_string_put(data->mlx_ptr, data->window_ptr, 530, 50, data->color_words,
		"Ocean Blue palette: press D");
	mlx_string_put(data->mlx_ptr, data->window_ptr, 530, 70, data->color_words,
		"Summer sunset palette: press F");
	mlx_string_put(data->mlx_ptr, data->window_ptr, 530, 90, data->color_words,
		"Lavender palette: press G");
}

void	draw_menu(t_data *data)
{
	mlx_string_put(data->mlx_ptr, data->window_ptr, 20, 20, data->color_words,
		"To change the focus");
	mlx_string_put(data->mlx_ptr, data->window_ptr, 20, 50, data->color_words,
		"To zoom: press +");
	mlx_string_put(data->mlx_ptr, data->window_ptr, 20, 70, data->color_words,
		"To de-zoom: press -");
	write_color_palette_instc(data);
	write_rotation_instruction(data);
	write_paralelle_instruction(data);
	mlx_string_put(data->mlx_ptr, data->window_ptr, 320, 980, data->color_words,
		"To change the depth of view: use the mouse wheel");
	mlx_string_put(data->mlx_ptr, data->window_ptr, 320, 1010,
		data->color_words, "Slide up to increase the altitude");
	mlx_string_put(data->mlx_ptr, data->window_ptr, 320, 1030,
		data->color_words, "Slide down to increase the depth");
	mlx_string_put(data->mlx_ptr, data->window_ptr, 900, 980, data->color_words,
		"To translate the model where you wish");
	mlx_string_put(data->mlx_ptr, data->window_ptr, 900, 1010,
		data->color_words, "Drag your mouse on the window");
	write_cavaliere_instruction(data);
}
