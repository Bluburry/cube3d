/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpinto-e <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 16:34:57 by tpinto-e          #+#    #+#             */
/*   Updated: 2024/04/11 14:25:43 by tpinto-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

static int	helper_helper(t_data *data, char *checker, char *ptr)
{
	auto int i = 1;
	if (!ft_strncmp(ptr, "F", 1) || !ft_strncmp(ptr, "C", 1))
		while (ptr[i] && ptr[i] == ' ')
			i++;
	if (!ft_strncmp(ptr, "F", 1) && ptr[1] && ptr[2])
	{
		if (creatergb(&data->new_map.floor, ptr + i) == 0)
		{
			print_errors("Invalid RGB\n");
			return (2);
		}
		checker[4]++;
		return (1);
	}
	else if (!ft_strncmp(ptr, "C", 1) && ptr[1] && ptr[2])
	{
		if (creatergb(&data->new_map.sky, ptr + i) == 0)
		{
			print_errors("Invalid RGB\n");
			return (2);
		}
		checker[5]++;
		return (1);
	}
	return (0);
}

static int	checker_helper(t_data *data, char *checker, char *ptr)
{
	if (!ft_strncmp(ptr, "WE", 2))
	{
		if (!data->new_map.we.path)
			data->new_map.we.path = cpy_line(ptr);
		if (!data->new_map.we.path)
			return (2);
		checker[2]++;
		return (1);
	}
	else if (!ft_strncmp(ptr, "EA", 2))
	{
		if (!data->new_map.ea.path)
			data->new_map.ea.path = cpy_line(ptr);
		if (!data->new_map.ea.path)
			return (2);
		checker[3]++;
		return (1);
	}
	return (helper_helper(data, checker, ptr));
}

static int	line_checker(t_data *data, char *checker, char *ptr)
{
	if (ptr[0] == '\n')
		return (1);
	else if (!ft_strncmp(ptr, "NO", 2))
	{
		if (!data->new_map.no.path)
			data->new_map.no.path = cpy_line(ptr);
		if (!data->new_map.no.path)
			return (2);
		checker[0]++;
		return (1);
	}
	else if (!ft_strncmp(ptr, "SO", 2))
	{
		if (!data->new_map.so.path)
			data->new_map.so.path = cpy_line(ptr);
		if (!data->new_map.so.path)
			return (2);
		checker[1]++;
		return (1);
	}
	return (checker_helper(data, checker, ptr));
}

/*
	char[6] checker
	0 -> NO path
	1 -> SO path
	2 -> WE path
	3 -> EA path
	4 -> Floor colour
	5 -> Ceiling colour

	op = 0 -> stop (assumes start of map section)
	op = 1 -> '\n' / colour / texture path
	op = 2 -> error
*/
int	read_file(char *file, t_data *data)
{
	auto char *ptr, checker[6] = {0, 0, 0, 0, 0, 0};
	auto int fd = open(file, O_RDONLY), op = 1;
	if (fd < 0)
		return (print_errors("File does not exist"), 1);
	while (op == 1)
	{
		ptr = get_next_line(fd, 1000);
		if (!ptr)
			break ;
		op = line_checker(data, checker, ptr);
		free(ptr);
	}
	auto int ret = final_checker(fd, op, checker, ptr);
	close(fd);
	return (ret);
}
