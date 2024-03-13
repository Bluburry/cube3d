#include "cube.h"

static int	checker_helper(t_data *data, char *checker, char *ptr)
{
	if (!ft_strncmp(ptr, "EA", 2) && !data->new_map.ea.path)
	{
		data->new_map.ea.path = cpy_line(ptr);
		if (!data->new_map.ea.path)
			return (0);
		checker[3]++;
		return (1);
	}
	else if (!ft_strncmp(ptr, "F", 1) && ptr[1] && ptr[2])
	{
		if (creatergb(&data->new_map.floor, ptr + 2) == 0)
			return (3);
		checker[4]++;
		return (1);
	}
	else if (!ft_strncmp(ptr, "C", 1) && ptr[1] && ptr[2])
	{
		if (creatergb(&data->new_map.sky, ptr + 2) == 0)
			return (3);
		checker[5]++;
		return (1);
	}
	else if (ptr[0] == '\n')
		return (1);
	return (0);
}

static int	line_checker(t_data *data, char *checker, char *ptr)
{
	if (!ft_strncmp(ptr, "NO", 2) && !data->new_map.no.path)
	{
		data->new_map.no.path = cpy_line(ptr);
		if (!data->new_map.no.path)
			return (0);
		checker[0]++;
		return (1);
	}
	else if (!ft_strncmp(ptr, "SO", 2) && !data->new_map.so.path)
	{
		data->new_map.so.path = cpy_line(ptr);
		if (!data->new_map.so.path)
			return (0);
		checker[1]++;
		return (1);
	}
	else if (!ft_strncmp(ptr, "WE", 2) && !data->new_map.we.path)
	{
		data->new_map.we.path = cpy_line(ptr);
		if (!data->new_map.we.path)
			return (0);
		checker[2]++;
		return (1);
	}
	return (checker_helper(data, checker, ptr));
}

/*
	ret for debugging purposes
	ret = 1 -> error from previous function (duplicate texture/colour error)
	ret = 2 -> duplicate colour/missing texture
	ret = 3 -> invalid character found in map section
*/
static int	final_checker(int op, int fd, char *checker, char *ptr)
{
	auto int ret = 0, i = -1, j;
	if (op == 3)
		ret = 1;
	while (!ret && ++i < 6)
		if (checker[i] != 1)
			ret = 2;
	while (!ret)
	{
		ptr = get_next_line(fd, 1000);
		if (!ptr)
			break ;
		j = -1;
		while(!ret && ptr[++j])
		{
			if (ptr[j] != ' ' && ptr[j] != '0' && ptr[j] != '1' && \
				ptr[j] != 'N' && ptr[j] != 'S' && ptr[j] != 'W' && \
				ptr[j] != 'E' && ptr[j] != '\n')
				ret = 3;
		}
		free(ptr);
	}
	close(fd);
	return (ret);
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
	op = 3 -> error
*/
int	read_file(char *file, t_data *data)
{
	auto char *ptr, checker[6] = {0, 0, 0, 0, 0, 0};
	auto int fd = open(file, O_RDONLY), op = 1;
	if (fd < 0)
		return (perror("File does not exist"), 1);
	while (op != 0 && op != 3)
	{
		ptr = get_next_line(fd, 1000);
		if (!ptr)
			break ;
		op = line_checker(data, checker, ptr);
		free(ptr);
	}
	return (final_checker(op, fd, checker, ptr));
}
