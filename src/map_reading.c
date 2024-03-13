/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_reading.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbeaudoi <gbeaudoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 14:21:41 by gbeaudoi          #+#    #+#             */
/*   Updated: 2024/02/20 19:50:45 by gbeaudoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_count_decimal(char *line, char space)
{
	int	i;
	int	decimal;

	if (!line)
		return (0);
	i = 0;
	decimal = 0;
	while (line[i])
	{
		while (line[i] && (line[i] == space || (line[i] == 10)))
			i++;
		if (line[i])
			decimal++;
		while (line[i] && !(line[i] == space || (line[i] == 10)))
			i++;
	}
	return (decimal);
}

int	width_map(char **lines, t_data *data)
{
	int	width_check;
	int	i;

	i = 0;
	width_check = ft_count_decimal(lines[i], ' ');
	while (lines[i])
	{
		data->map.width = ft_count_decimal(lines[i], ' ');
		if (data->map.width != width_check)
		{
			width_check = 0;
		}
		i++;
	}
	return (width_check);
}

void	fill_array(t_coordinate *z_depth, char *line, t_data *data,
		t_one_line_map *pre_map)
{
	char	**arg_split;
	char	**nums_split;
	int		i;
	int		j;

	arg_split = ft_split(line, ' ');
	check_split_space_alloc(arg_split, pre_map);
	i = -1;
	while (arg_split[++i])
	{
		nums_split = ft_split(arg_split[i], ',');
		check_split_coma_alloc(nums_split, arg_split, pre_map);
		j = 0;
		z_depth[i].z = ft_atoi(nums_split[j]);
		if (nums_split[j + 1])
		{
			z_depth[i].color = ft_atoi_base_hex(nums_split[j + 1]);
			data->flag_color_given = 1;
			free(nums_split[j + 1]);
		}
		else
			z_depth[i].color = 0;
		free_fill_array(nums_split, arg_split, i, j);
	}
	free(arg_split);
}

int	read_map(char *file_name, t_data *data)
{
	int				fd;
	int				i;
	t_one_line_map	pre_map;

	fd = open(file_name, O_RDONLY);
	pre_map.map_in_one = ft_gnltomap(fd);
	if (pre_map.map_in_one == NULL)
		return (free(pre_map.map_in_one), 0);
	data->flag_color_given = 0;
	pre_map.lines = ft_split(pre_map.map_in_one, '\n');
	if (pre_map.lines == NULL)
		return (free(pre_map.map_in_one), free(pre_map.lines), 0);
	while (pre_map.lines[data->map.height])
		data->map.height++;
	i = width_map(pre_map.lines, data);
	if (check_map(data, i) == 0 || array_allocation(data) == 0
		|| array_allocation_decimal(data) == 0)
		return (free(pre_map.map_in_one), free_map_tab(pre_map.lines), 0);
	i = -1;
	while (pre_map.lines[++i])
		fill_array(data->map.array[i], pre_map.lines[i], data, &pre_map);
	close(fd);
	return (free(pre_map.map_in_one), free_map_tab(pre_map.lines), 1);
}
