/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbeaudoi <gbeaudoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 20:18:43 by gbeaudoi          #+#    #+#             */
/*   Updated: 2024/02/23 20:21:40 by gbeaudoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	free_map(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->map.height)
	{
		free(data->map.array[i]);
		i++;
	}
	free(data->map.array);
}

void	free_fill_array(char **tab1, char **tab2, int i, int j)
{
	free(tab1[j]);
	free(tab1);
	free(tab2[i]);
}
