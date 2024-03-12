#include "cube.h"

static void	get_to_map(int fd)
{
	char	*ln;

	while (1)
	{
		ln = get_next_line(fd, 1000);
		if (ln[0] != 'N' && ln[0] != 'S' && \
			ln[0] != 'W' && ln[0] != 'E' && \
			ln[0] != 'F' && ln[0] != 'C' && \
			ln[0] != '\n')
		{
			free(ln);
			break ;
		}
		free(ln);
	}
}

int	get_map_rows(char *file)
{
	auto char *ln;
	auto int fd = open(file, O_RDONLY);
	get_to_map(fd);
	auto int i = 0;
	while(1)
	{
		ln = get_next_line(fd, 1000);
		if (!ln)
			break ;
		i++;
		free(ln);
	}
	close(fd);
	return (i);
}

char	**get_map(char *file, int rows)
{
	char	**mp;
	char	*ln;

	mp = (char **) malloc((rows + 1) * (sizeof(char *)));
	mp[rows] = 0;
	auto int fd = open(file, O_RDONLY);
	get_to_map(fd);
	auto int i = -1;
	while (++i < rows)
	{
		ln = get_next_line(fd, 1000);
		if (!ln)
			break ;
		mp[i] = ln;
		mp[i][ft_strlen(ln) - 1] = 0;
	}
	close(fd);
	return (mp);
}

static int	map_helper(char **map, int rows, int x, int y)
{
	if (map[x][y] == 0)
		return (map_checker(map, rows, x, y));
	else if (map[x][y] == '1' || map[x][y] == '2')
		return (1);
	else
		return (0);
}

int	map_checker(char **map, int rows, int x, int y)
{
	int	cnt;
	
	cnt = 1;
	map[x][y] = '2';
	if (x - 1 >= 0)
		cnt = map_helper(map, rows, x - 1, y);
	if (cnt && y - 1 >= 0)
		cnt = map_helper(map, rows, x, y - 1);
	if (cnt && x + 1 < rows)
		cnt = map_helper(map, rows, x + 1, y);
	if (cnt && map[x][y + 1])
		cnt = map_helper(map, rows, x, y + 1);
	return (cnt);
}

static int	pos_checker(char **map, char start, int i, int j)
{
	if (map[i][j] == 'N' || map[i][j] == 'S' || \
		map[i][j] == 'W' || map[i][j] == 'E')
	{
		if (!start)
			return (2);
		else
			return (1);
	}
	else if (map[i][j] != ' ' && \
		map[i][j] != '0' && map[i][j] != '1')
		return (1);
	return (0);
}

int	validate_map(char **map, int rows)
{
	auto char start = 0;
	auto int i = -1, j, x = 0, y = 0, err = 0;
	while (!err && map[++i])
	{
		j = -1;
		while (!err && map[i][++j])
		{
			err = pos_checker(map, start, i, j);
			if (err == 2)
			{
				start = map[i][j];
				map[i][j] = '0';
				x = i;
				y = j;
				err = 0;
			}
		}
	}
	if (err)
		return (0);
	err = map_checker(map, rows, x, y);
	map[x][y] = start;
	return (err);
}
