/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_check.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbeaudoi <gbeaudoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 17:03:29 by gbeaudoi          #+#    #+#             */
/*   Updated: 2024/02/20 15:12:22 by gbeaudoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	number_arg(int argc)
{
	if (argc == 2)
	{
		return (1);
	}
	else
	{
		ft_printf("the program has too many/too little arguments \n");
		return (0);
	}
}

int	check_folder(char *file_name)
{
	int	fd;

	fd = open(file_name, __O_DIRECT);
	if (fd < 0)
	{
		ft_printf("please provide a correct map file path \n");
		return (0);
	}
	else
	{
		close(fd);
		return (1);
	}
}

int	check_file(char *file_name)
{
	int		fd;
	char	*line;

	fd = open(file_name, O_RDONLY);
	line = get_next_line_bonus(fd);
	if (!line)
	{
		free(line);
		close(fd);
		return (0);
	}
	else
	{
		free(line);
		close(fd);
		return (1);
	}
}

int	check_file_name(char *file_name)
{
	int	fd;
	int	i;

	i = ft_strlen(file_name);
	if (!(file_name[i - 1] == 'f' && file_name[i - 2] == 'd' && file_name[i
				- 3] == 'f'))
	{
		ft_printf("please provide a correct format file \n");
		return (0);
	}
	fd = open(file_name, O_RDONLY);
	if (fd < 0)
	{
		ft_printf("please provide a correct map file path \n");
		return (0);
	}
	close(fd);
	return (1);
}

int	check_map(t_data *data, int width_check)
{
	if (data->map.height == 0 || width_check == 0)
	{
		ft_printf("Please provide a map with correct structure \n");
		return (0);
	}
	else
		return (1);
}
