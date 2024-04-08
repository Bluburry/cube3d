/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rgb.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpinto-e <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 16:34:54 by tpinto-e          #+#    #+#             */
/*   Updated: 2024/04/08 16:34:55 by tpinto-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

static int	validatergb(char *str)
{
	auto int i = -1, j = 0, k = 0;
	while (str[++i])
	{
		if (str[i] == ',')
			j++;
		else if (ft_isdigit(str[i]))
		{
			if (k <= j)
				k++;
		}
		else if (str[i] != ' ' && str[i] != '\n')
			return (1);
	}
	if (j != 2)
		return (1);
	else if (k != 3)
		return (1);
	return (0);
}

int	creatergb(unsigned int *clr, char *sub_str)
{
	if (!ft_isdigit(sub_str[0]) || validatergb(sub_str))
		return (0);
	auto char **values = ft_split(sub_str, ',');
	auto int rgb[3];
	auto int i = -1;
	while (values[++i])
	{
		if (i >= 3 || values[i][0] == 0 || values[i][0] == '\n')
		{
			printf("Wrong rgb values!\n");
			clear_matrix(values, -1);
			return (0);
		}
		rgb[i] = ft_atoi(values[i]);
		if (rgb[i] > 255 || rgb[i] < 0)
		{
			printf("rgb wrong value!\n");
			clear_matrix(values, -1);
			return (0);
		}
	}
	clear_matrix(values, -1);
	*clr = ((rgb[0] & 0xff) << 16) + ((rgb[1] & 0xff) << 8) + (rgb[2] & 0xff);
	return (1);
}
