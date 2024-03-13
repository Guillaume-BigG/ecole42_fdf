/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbeaudoi <gbeaudoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 17:09:13 by gbeaudoi          #+#    #+#             */
/*   Updated: 2024/02/20 14:29:15 by gbeaudoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int argc, char *argv[])
{
	t_data	data;

	data.map.height = 0;
	data.map.width = 0;
	if (!number_arg(argc) || check_folder(argv[1]) == 0
		|| check_file_name(argv[1]) == 0 || check_file(argv[1]) == 0)
		return (0);
	if (read_map(argv[1], &data) == 0)
		return (0);
	if (initialize_display(&data) == 0)
	{
		free_map(&data);
		return (0);
	}
	return (1);
}
