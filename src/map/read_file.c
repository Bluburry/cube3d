#include "cube.h"

static int	helper_helper(t_data *data, bool *checker, char *ptr)
{
	if (!ft_strncmp(ptr, "F", 1) && ptr[1] && ptr[2])
	{
		if (checker[4])
		{
			checker[4] = false;
			return (0);
		}
		if (creatergb(&data->new_map.floor, ptr + 2) == 0)
			return (0);
		checker[4] = true;
		return (1);
	}
	else if (!ft_strncmp(ptr, "C", 1) && ptr[1] && ptr[2])
	{
		if (checker[5])
		{
			checker[5] = false;
			return (0);
		}
		if (creatergb(&data->new_map.sky, ptr + 2) == 0)
			return (0);
		checker[5] = true;
		return (1);
	}
	return (0);
}

static int	checker_helper(t_data *data, bool *checker, char *ptr)
{
	if (!ft_strncmp(ptr, "WE", 2) && ptr[2] && ptr[3])
	{
		if (checker[2])
		{
			checker[2] = false;
			return (0);
		}
		data->new_map.we.path = ptr;
		data->new_map.we.path[ft_strlen(ptr) - 1] = 0;
		checker[2] = true;
		return (2);
	}
	else if (!ft_strncmp(ptr, "EA", 2) && ptr[2] && ptr[3])
	{
		if (checker[3])
		{
			checker[3] = false;
			return (0);
		}
		data->new_map.ea.path = ptr;
		data->new_map.ea.path[ft_strlen(ptr) - 1] = 0;
		checker[3] = true;
		return (2);
	}
	return (helper_helper(data, checker, ptr));
}

static int	line_checker(t_data *data, bool *checker, char *ptr)
{
	if (!ft_strncmp(ptr, "NO", 2) && ptr[2] && ptr[3])
	{
		if (checker[0])
		{
			checker[0] = false;
			return (0);
		}
		data->new_map.no.path = ptr;
		data->new_map.no.path[ft_strlen(ptr) - 1] = 0;
		checker[0] = true;
		return (2);
	}
	else if (!ft_strncmp(ptr, "SO", 2) && ptr[2] && ptr[3])
	{
		if (checker[1])
		{
			checker[1] = false;
			return (0);
		}
		data->new_map.so.path = ptr;
		data->new_map.so.path[ft_strlen(ptr) - 1] = 0;
		checker[1] = true;
		return (2);
	}
	return (checker_helper(data, checker, ptr));
}

/* static int	final_checker(bool checker)
{
	int	i;

	i = -1;
	while (++i < 6)
	{
		if (!checker[i])
			return (1);
	}
	return (0);
} */

/*
	bool[6] checker
	0 -> NO path
	1 -> SO path
	2 -> WE path
	3 -> EA path
	4 -> Floor colour
	5 -> Ceiling colour
*/
int	read_file(char *file, t_data *data)
{
	char		*ptr;

	auto int fd = open(file, O_RDONLY), op;
	auto bool checker[6] = {false, false, \
		false, false, false, false};
	if (fd < 0)
		return (perror("File does not exist"), 1);
	while (1)
	{
		ptr = get_next_line(fd, 1000);
		if (!ptr)
			break ;
		op = line_checker(data, checker, ptr);
		if (!op || op == 1)
			free(ptr);
		if (!op && ptr[0] == '\n')
			break ;
	}
	close(fd);
	auto int i = -1;
	while (++i < 6)
		if (!checker[i])
			return (1);
	return (0);
}

//data->new_map.map = malloc(sizeof(char *) * 24); // Strlen do mapa
	// data->new_map.map[data->new_map.rows] = 0;
		/* if (ptr[0] == '\n')
			continue;
		if (validate_textures(data))
		{
			if (ptr[0] == ' ' || ptr[0] == '1')
			{
				free(ptr);
				break ;
			}
			save_settings(data, ptrs);
		}
		else if (!validate_textures(data))
			save_map(ptr, data); */


/* int		check_commas(char *str)
{
	auto int	i = 0, j = 0;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
		{
			if (str[i] != ',')
			{
				printf("rgb - Not a comma [%C]!\n", str[i]);
				return 1;
			}
			j++;
		}
		i++;
	}
	if (j != 2)
	{
		printf("rgb - Wrong amount of commas!\n");
		return 1;
	}
	return 0;
}

void	save_colours(char *str, t_data *data)
{
	char		t;
	auto char	*sub_str = NULL;

	sub_str = ft_substr(str, 2, ft_strlen(str) - 3);
	if (check_commas(sub_str))
		exit(0);	
	t = str[0];	
	if (t == 'F')
		data->new_map.floor = creatergb(sub_str);
	else if (t == 'C')
		data->new_map.sky = creatergb(sub_str);
	free(sub_str);
}

int	save_settings(t_data *data, char *ptrs)
{
	if ((!ft_strncmp(ptrs, "NO", 2) || !ft_strncmp(ptrs, "SO", 2) \
		|| !ft_strncmp(ptrs, "WE", 2) || !ft_strncmp(ptrs, "EA", 2)))
	{
		save_texture_path(ptrs, data);
		return 0;
	}
	else if ((!ft_strncmp(ptrs, "F", 1) || !ft_strncmp(ptrs, "C", 1)))
	{
		save_colours(ptrs, data);
		return 0;
	}
	return 1;
} */