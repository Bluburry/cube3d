#include "cube.h"

int	check_matrix(t_data *data, int i, int j)
{
	auto int row_index, col_index, n = 0;
	auto int index[4][2] = {{-1, 0}, \
		{0, -1}, {0, 1}, {1, 0}, };
	while (n < 4)
	{
		row_index = i + index[n][0];
		col_index = j + index[n][1];
		if (row_index >= 0 && col_index >= 0)
		{
			if (data->new_map.map[row_index][col_index] != '1' && \
				data->new_map.map[row_index][col_index] != ' ' && \
				data->new_map.map[row_index][col_index] != '\0')
				return (1);
		}
		n++;
	}
	return (0);
}

int	get_row_len(char *row, int i)
{
	char	*cut;

	(void) i;
	if (!row)
		return (0);
	cut = ft_strrchr(row, '1');
	if (!cut)
		return (0);
	return (ft_strlen(row) - (ft_strlen(cut) - 1));
}

int	check_closed(t_data *data, int i, int j)
{
	if (get_row_len(data->new_map.map[i], i) > \
		get_row_len(data->new_map.map[i - 1], i - 1) && \
		get_row_len(data->new_map.map[i - 1], i - 1) - 1 < j)
	{
		if (data->new_map.map[i][j] != '1' && j < \
		get_row_len(data->new_map.map[i], i))
			return (1);
	}
	if (get_row_len(data->new_map.map[i], i) > \
		get_row_len(data->new_map.map[i + 1], i+1) \
		&& get_row_len(data->new_map.map[i + 1], i+1) - 1 < j)
	{
		if (data->new_map.map[i][j] != '1' && j < \
		get_row_len(data->new_map.map[i], i) \
			&& data->new_map.map[i][j] != ' ')
			return (1);
	}
	if (data->new_map.map[i][j] == ' ' && j < \
		get_row_len(data->new_map.map[i], i))
	{
		if (check_matrix(data, i, j))
			return (1);
	}
	return (0);
}

int	check_surrounded(char *map, int rows, int i, int j)
{
	char *cut_map;

	cut_map = ft_strtrim(map, " \n");
	if (i == 0 || i == rows)
	{
		if (map[j] != '1' && map[j] != ' ' && map[j] != '\n')
		{
			print_errors("1st or Last rows differ from 1 or Space. \n");
			return (free(cut_map), 1);
		}
	}
	else
	{
		if (cut_map[0] != '1' || cut_map[ft_strlen(cut_map) - 1] != '1')
		{
			print_errors("Side walls differ from 1. \n");
			return (free(cut_map), 1);
		}
	}
	return (free(cut_map), 0);
}

int	validate_map(t_data *data)
{
	auto int i = -1, j;
	while (data->new_map.map[++i])
	{
		j = -1;
		while (data->new_map.map[i][++j] && data->new_map.map[i][j] != '\n')
		{
			if (!ft_strchr("NSWE10 ", data->new_map.map[i][j]))
				return (1);
			if (check_surrounded(data->new_map.map[i], data->new_map.rows - 1, i, j))
				return (1);
			if (i > 0 && i < data->new_map.rows - 1)
				if (check_closed(data, i, j))
					return (1);
		}
	}
	return (0);
}
