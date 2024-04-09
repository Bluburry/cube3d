/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpinto-e <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 16:34:44 by tpinto-e          #+#    #+#             */
/*   Updated: 2024/04/08 16:34:45 by tpinto-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

static int	line_check(char *str)
{
	auto int i = -1, empty_line = 1;
	while (str[++i])
	{
		if (str[i] == ' ' || str[i] == '\n')
			continue ;
		else if (str[i] == '0' || str[i] == '1' || \
			str[i] == 'N' || str[i] == 'S' || \
			str[i] == 'W' || str[i] == 'E')
		{
			empty_line = 0;
			continue ;
		}
		return (3);
	}
	return (empty_line);
}

static int	valid_map_helper(char *str, int *map)
{
	auto int ret = 0;
	ret = line_check(str);
	if (ret == 0)
	{
		if (*map == -1 || *map == 1)
		{
			*map = 1;
			ret = 0;
		}
		else if (*map == 0)
			ret = 4;
	}
	else if (ret == 1)
	{
		ret = 0;
		if (*map == 1)
			*map = 0;
	}
	return (ret);
}

/*
	ret for debugging purposes
	ret = 1 -> error from previous function (duplicate texture/colour error)
	^ now already returned returned from calling function
	ret = 2 -> duplicate colour/missing texture
	ret = 3 -> invalid character found in map section
	ret = 4 -> invalid map configuration (divided map)
*/
int	final_checker(int fd, int ret, char *checker, char *ptr)
{
	auto int i = -1, map = -1;
	if (ret == 1)
		ret = 0;
	while (!ret && ++i < 6)
		if (checker[i] != 1)
		{
			printf("%d\n", checker[i]);
			ret = 2;
		}
	while (1)
	{
		ptr = get_next_line(fd, 1000);
		if (!ptr)
			break ;
		if (!ret)
			ret = valid_map_helper(ptr, &map);
		free(ptr);
	}
	return (ret);
}
