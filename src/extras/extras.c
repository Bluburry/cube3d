/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extras.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpinto-e <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 16:34:52 by tpinto-e          #+#    #+#             */
/*   Updated: 2024/04/08 16:34:53 by tpinto-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

char	*cpy_line(const char *src)
{
	if (!src || !src[2] || !src[3])
		return (NULL);
	auto int i = 2;
	while (src[i] && src[i] == ' ')
		i++;
	auto size_t s = ft_strlen(src + i);
	auto char *dst = (char *) malloc ((s) * sizeof(char));
	if (!dst)
	{
		print_errors("Memory allocation error.\n");
		return (NULL);
	}
	ft_memcpy(dst, src + i, s - 1);
	s -= 2;
	while (dst[s] && dst[s] == ' ')
		s--;
	dst[s + 1] = 0;
	return (dst);
}

int	get_map_columns(t_data *data)
{
	auto int cl = 0, i = -1, j;
	while (data->new_map.map[++i])
	{
		j = 0;
		while (data->new_map.map[i][j])
			j++;
		while (j > 0 && data->new_map.map[i][j] != '1')
			j--;
		if (j > cl)
			cl = j;
	}
	return (cl + 1);
}
