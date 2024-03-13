/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbeaudoi <gbeaudoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 14:19:40 by gbeaudoi          #+#    #+#             */
/*   Updated: 2024/02/20 19:28:44 by gbeaudoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

char	*ft_strjoinfree(char *s1, char *s2)
{
	char	*str;
	size_t	i;
	size_t	j;

	if (!s1 || !s2)
		return (NULL);
	str = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!str)
		return (NULL);
	i = -1;
	while (s1[++i])
		str[i] = s1[i];
	j = 0;
	while (s2[j])
		str[i++] = s2[j++];
	str[i] = '\0';
	free(s1);
	return (str);
}

char	*ft_gnltomap(int fd)
{
	int		readbytes;
	char	*bigline;
	char	*buffer;

	readbytes = 1;
	bigline = ft_calloc(1, sizeof(char));
	if (!bigline)
		return (NULL);
	buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!buffer)
		return (NULL);
	while (readbytes > 0)
	{
		readbytes = read(fd, buffer, BUFFER_SIZE);
		if (readbytes == -1)
			return (free(bigline), free(buffer), NULL);
		if (readbytes == 0)
			return (free(buffer), close(fd), bigline);
		buffer[readbytes] = '\0';
		bigline = ft_strjoinfree(bigline, buffer);
	}
	close(fd);
	return (free(buffer), bigline);
}

void	check_split_space_alloc(char **tab, t_one_line_map *pre_map)
{
	if (tab == NULL)
	{
		free(tab);
		free(pre_map->map_in_one);
		free_map_tab(pre_map->lines);
		exit(0);
	}
}

void	check_split_coma_alloc(char **tab, char **tab2, t_one_line_map *pre_map)
{
	if (tab == NULL)
	{
		free(tab);
		free_map_tab(tab2);
		free(pre_map->map_in_one);
		free_map_tab(pre_map->lines);
		exit(0);
	}
}

void	free_map_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}
