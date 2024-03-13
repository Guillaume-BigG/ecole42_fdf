/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbeaudoi <gbeaudoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 11:15:57 by guillaumebe       #+#    #+#             */
/*   Updated: 2023/11/13 13:35:57 by gbeaudoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*join;
	size_t	len_join;

	if (!s1)
		return (NULL);
	len_join = ft_strlen(s1) + ft_strlen(s2) + 1;
	join = malloc(sizeof(char) * len_join);
	if (!join)
		return (NULL);
	ft_strlcpy(join, s1, len_join);
	ft_strlcat(join, s2, len_join);
	return (join);
}
