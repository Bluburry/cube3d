#include "cube.h"

int	check_matrix(t_data *data, int i, int j)
{
	auto int	m = 0, y, x, n;

	y = j;
	while (m < 3)
	{	
		n = 0;
		x = i;
		while (n < 3)
		{
			if (x > 0 && y > 0)
			{
				if (data->new_map.map[x - 1][y - 1] != '1' && \
					data->new_map.map[x - 1][y - 1] != ' ' && \
					data->new_map.map[x - 1][y - 1] != '\0')
				{
					// printf("Line: |%s|\n", data->new_map.map[i]);
					// printf("Value: |%c| - X:%d - Y:%d\n", data->new_map.map[x - 1][y - 1], x, y);
					return 1;
				}
			}
			x++;
			n++;
		}
		y++;
		m++;
	}
	return 0;
}

int	get_row_len(char *row, int i)
{
	char *cut;

	(void) i;
	if (!row)
		return 0;
	cut = ft_strrchr(row, '1');
	if (!cut)
		return (0);
	// printf("\nLine: %d -> |%s|\n", i, row);
	// printf("\nCUt: %s\n", cut);
	// printf("Row_l: %li | Cut_l: %li | ", ft_strlen(row), ft_strlen(cut));
	// printf("Final: %li\n", ft_strlen(row) - (ft_strlen(cut) - 1));
	return ft_strlen(row) - (ft_strlen(cut) - 1);
}

int	check_closed(t_data *data, int i, int j)
{
	if (get_row_len(data->new_map.map[i], i) > get_row_len(data->new_map.map[i - 1], i-1) \
		&& get_row_len(data->new_map.map[i - 1], i-1) - 1 < j)
	{
		// printf("Line  x-1: |%d|             |%s|\n", i - 1, data->new_map.map[i - 1]);
		// printf("Line  x:   |%d| - j: |%d(%c)|%s|\n", i, j, data->new_map.map[i][j], data->new_map.map[i]);
		// printf("Get_row_len  x-1: |%d|\n", get_row_len(data->new_map.map[i - 1], i - 1));
		// printf("Get_row_len  x:   |%d|\n", get_row_len(data->new_map.map[i], i));
		if (data->new_map.map[i][j] != '1' && j < get_row_len(data->new_map.map[i], i))
		{
			printf("--1--\n");
			return 1;
		}
	}
	if (get_row_len(data->new_map.map[i], i) > get_row_len(data->new_map.map[i + 1], i+1) \
		&& get_row_len(data->new_map.map[i + 1], i+1) - 1 < j)
	{
		if (data->new_map.map[i][j] != '1' && j < get_row_len(data->new_map.map[i], i) \
			&& data->new_map.map[i][j] != ' ')
		{
			printf("\n--2--\n");
			printf("Line  x: |%d| - j: |%d| %s\n", i, j, data->new_map.map[i]);
			printf("Value  : |%c|\n", data->new_map.map[i][j]);
			return 1;
		}
	}
	if (data->new_map.map[i][j] == ' ' && j < get_row_len(data->new_map.map[i], i))
	{
		// printf("J: %d - Len: %d\n", j, get_row_len(data->new_map.map[i], i));
		if (check_matrix(data, i, j))
			return 1;
	}
	return 0;
}

/*int	check_closed(t_data *data, int i, int j)
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
}*/

int	check_surrounded(char *map, int rows, int i, int j)
{
	char *cut_map;

	cut_map = ft_strtrim(map, " ");
	if (i == 0 || i == rows)
	{
		if (map[j] != '1' && map[j] != ' ' && map[j] != '\n')
		{
			printf("1st or Last rows differ from 1 or Space. \n");
			free(cut_map);
			return 1;
		}
	}
	else
	{
		if (cut_map[0] != '1' || cut_map[ft_strlen(cut_map) - 1] != '1')
		{
			printf("Side walls differ from 1. \n");
			free(cut_map);
			return 1;
		}
	}
	free(cut_map);
	return 0;
}

int	validate_map(t_data *data)
{
	auto int	i = -1, j;

	while (data->new_map.map[++i])
	{
		j = -1;
		while (data->new_map.map[i][++j])
		{
			if (!ft_strchr("NSWE10 ", data->new_map.map[i][j]))
			{
				printf("OK1 - |%c|\n", data->new_map.map[i][j]);
				return 1;
			}
			if (check_surrounded(data->new_map.map[i], data->new_map.rows - 1, i, j))
			{
				printf("OK2\n");
				return 1;
			}
			if (i > 0 && i < data->new_map.rows - 1)
				if (check_closed(data, i, j))
				{
					printf("OK3\n");
					return 1;
				}
		}
	}

	for (int i = 0; data->new_map.map[i]; i++)
	{
		printf("%s\n", data->new_map.map[i]);
	}
	return 0;
}
