#include "cube.h"

int	check_matrix(t_data *data, int i, int j)
{
	int	y;
	int	x;
	int	n;
	int	m;

	y = j;
	m = 0;
	while (m < 3)
	{	
		n = 0;
		x = i;
		while (n < 3)
		{
			if (data->new_map.map[x - 1][y - 1] != '1' && \
				data->new_map.map[x - 1][y - 1] != ' ' && \
				data->new_map.map[x - 1][y - 1] != '\0')
			{
				printf("V: %c\n", data->new_map.map[x - 1][y - 1]);
				return 1;
			}
			x++;
			n++;
		}
		y++;
		m++;
	}
	return 0;
}

int	check_closed(t_data *data, int i, int j)
{
	if (ft_strlen(data->new_map.map[i]) > ft_strlen(data->new_map.map[i - 1]) \
		&& (int)ft_strlen(data->new_map.map[i - 1]) - 1 < j)
	{
		if (data->new_map.map[i][j] != '1')
			return 1;
	}
	if (ft_strlen(data->new_map.map[i]) > ft_strlen(data->new_map.map[i + 1]) \
		&& (int)ft_strlen(data->new_map.map[i + 1]) - 1 < j)
	{
		if (data->new_map.map[i][j] != '1')
			return 1;
	}
	if (data->new_map.map[i][j] == ' ')
		if (check_matrix(data, i, j))
			return 1;
	return 0;
}

int	check_surrounded(char *map, int rows, int i, int j)
{
	char *cut_map;

	cut_map = ft_strtrim(map, " ");
	if (i == 0 || i == rows)
	{
		if (map[j] != '1' && map[j] != ' ' && map[j] != '\n')
		{
			printf("1st or Last rows differ from 1 or Space. \n");
			return 1;
		}
	}
	else
	{
		if (cut_map[0] != '1' || cut_map[ft_strlen(cut_map) - 1] != '1')
		{
			printf("Side walls differ from 1. \n");
			return 1;
		}
	}
	return 0;
}

int	validate_map(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (data->new_map.map[i])
	{
		j = 0;
		while (data->new_map.map[i][j])
		{
			if (check_surrounded(data->new_map.map[i], data->new_map.rows - 1, i, j))
				return 1;
			if (i > 0 && i < data->new_map.rows - 1)
				if (check_closed(data, i, j))
					return 1;
			j++;
		}
		i++;
	}

	for (int i = 0; data->new_map.map[i]; i++)
	{
		printf("%s\n", data->new_map.map[i]);
	}
	return 0;
}
