#include "cube.h"

static int	checker_helper(t_data *data, char *checker, char *ptr)
{
	if (!ft_strncmp(ptr, "EA", 2) && !data->new_map.ea.path)
	{
		data->new_map.ea.path = ptr;
		data->new_map.ea.path[ft_strlen(ptr) - 1] = 0;
		checker[3]++;
		return (2);
	}
	else if (!ft_strncmp(ptr, "F", 1) && ptr[1] && ptr[2])
	{
		if (creatergb(&data->new_map.floor, ptr + 2) == 0)
			return (0);
		checker[4]++;
		return (3);
	}
	else if (!ft_strncmp(ptr, "C", 1) && ptr[1] && ptr[2])
	{
		if (creatergb(&data->new_map.sky, ptr + 2) == 0)
			return (0);
		checker[5]++;
		return (3);
	}
	return (1);
}

static int	line_checker(t_data *data, char *checker, char *ptr)
{
	if (!ft_strncmp(ptr, "NO", 2) && !data->new_map.no.path)
	{
		data->new_map.no.path = ptr;
		data->new_map.no.path[ft_strlen(ptr) - 1] = 0;
		checker[0]++;
		return (2);
	}
	else if (!ft_strncmp(ptr, "SO", 2) && !data->new_map.so.path)
	{
		data->new_map.so.path = ptr;
		data->new_map.so.path[ft_strlen(ptr) - 1] = 0;
		checker[1]++;
		return (2);
	}
	else if (!ft_strncmp(ptr, "WE", 2) && !data->new_map.we.path)
	{
		data->new_map.we.path = ptr;
		data->new_map.we.path[ft_strlen(ptr) - 1] = 0;
		checker[2]++;
		return (2);
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
	auto int ret = 0, j;
	if (!op)
		ret = 1;
	auto int i = -1;
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

	op = 0 -> error
	op = 1 -> no match / '\n' (check if '\n', stop if not - assumes map start)
	op = 2 -> map path (must not free line ptr - saved as texture location)
	op = 3 -> colour
*/
int	read_file(char *file, t_data *data)
{
	auto char *ptr, checker[6] = {0, 0, 0, 0, 0, 0};
	auto int fd = open(file, O_RDONLY), op;
	if (fd < 0)
		return (perror("File does not exist"), 1);
	while (1)
	{
		ptr = get_next_line(fd, 1000);
		if (!ptr)
			break ;
		op = line_checker(data, checker, ptr);
		if ((op == 1 && ptr[0] != '\n') || !op)
		{
			free(ptr);
			break ;
		}
		if (op != 2)
			free(ptr);
	}
	return (final_checker(op, fd, checker, ptr));
}
