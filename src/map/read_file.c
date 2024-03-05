#include "cube.h"

unsigned long createRGB(char *sub_str)
{
    char    **values;
    int     RGB[3];
    auto int     i = 0;

    values = ft_split(sub_str, ',');
    while (values[i] != 0)
        i++;
    if (i != 3)
    {
        printf("RGB wrong amount of values!\n");
        exit(0);
    }
    i = -1;
    while (values[++i])
    {
        RGB[i] = ft_atoi(values[i]);
        if (RGB[i] > 255)
        {
            printf("RGB wrong value!\n");
            exit(0);
        }
    }
    free(values);
    return ((RGB[0] & 0xff) << 16) + ((RGB[1] & 0xff) << 8) + (RGB[2] & 0xff);
}

int		check_commas(char *str)
{
	auto int	i = 0, j = 0;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
		{
			if (str[i] != ',')
			{
				printf("RGB - Not a comma [%C]!\n", str[i]);
				return 1;
			}
			j++;
		}
		i++;
	}
	if (j != 2)
	{
		printf("RGB - Wrong amount of commas!\n");
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
		data->new_map.floor = createRGB(sub_str);
	else if (t == 'C')
		data->new_map.sky = createRGB(sub_str);
	free(sub_str);
}

int	read_file(char *file, t_data *data)
{
	char		*ptrs;
	auto	int	map_flag = 0, fd;

	fd = open(file, O_RDONLY);
	data->new_map.map = malloc(sizeof(char *) * 23); // Strlen do mapa
	while (fd > 0)
	{
		ptrs = get_next_line(fd, 1000);
		if (!ptrs)
			break ;
		if ((!ft_strncmp(ptrs, "NO", 2) || !ft_strncmp(ptrs, "SO", 2) \
				|| !ft_strncmp(ptrs, "WE", 2) || !ft_strncmp(ptrs, "EA", 2)) && (map_flag == 0))
			save_texture_path(ptrs, data);
		else if ((!ft_strncmp(ptrs, "F", 1) || !ft_strncmp(ptrs, "C", 1)) && (map_flag == 0) )
			save_colours(ptrs, data);
		else if (ft_strchr(ptrs, '1'))
		{
			if (!data->new_map.no_path || !data->new_map.so_path || \
				!data->new_map.we_path || !data->new_map.ea_path || \
				!data->new_map.floor || !data->new_map.sky)
			{
				free(ptrs);
				printf("Missing texture or RGB\n");
				return 1;
			}
			map_flag = 1;
			save_map(ptrs, data);
		}
		else
			if (map_flag == 1)
			{
				printf("ERROR\n");
				free(ptrs);
				return 1;
			}
		free(ptrs);
	}
	data->new_map.map[data->new_map.rows] = 0; // Is it ok!?
	close(fd);
	return 0;
}