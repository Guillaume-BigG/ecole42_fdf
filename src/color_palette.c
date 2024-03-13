/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_palette.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbeaudoi <gbeaudoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 15:41:48 by gbeaudoi          #+#    #+#             */
/*   Updated: 2024/01/27 15:42:26 by gbeaudoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ocean_blue_palette(t_data *data)
{
	data->color_background = 0xFF008080;
	data->color_line = 0xFF00CED1;
	data->color_words = 0xFFFFE0FF;
	data->pos_color = 0xFFFFA500;
	data->neg_color = 0xFF98FB98;
	data->flat_color = 0xFF00CED1;
}

void	summer_sunset_palette(t_data *data)
{
	data->color_background = 0xFF991439;
	data->color_line = 0xFFFFA500;
	data->color_words = 0xFFAC143C;
	data->pos_color = 0xFFEE22FF;
	data->neg_color = 0xFF87CEEB;
	data->flat_color = 0xFFFFD700;
}

void	lavender_palette(t_data *data)
{
	data->color_background = 0xFF9B59B6;
	data->color_line = 0xFF3498db;
	data->color_words = 0xFFE9FF51;
	data->pos_color = 0xFFF39C12;
	data->neg_color = 0xFF22FF22;
	data->flat_color = 0xFFD2B48C;
}

void	white_palette(t_data *data)
{
	data->color_background = 0xFFCCCCCC;
	data->color_line = 0xFFAAAAAA;
	data->color_words = 0xFF333333;
	data->pos_color = 0xFFFF00FF;
	data->neg_color = 0xFF00AAFF;
	data->flat_color = 0xFF8B4513;
}

void	black_palette(t_data *data)
{
	data->color_background = 0xFF000000;
	data->color_line = 0xFF333333;
	data->color_words = 0xFFC0C0C0;
	data->pos_color = 0xFFFF0000;
	data->neg_color = 0xFF0000FF;
	data->flat_color = 0xFF00FF00;
}
