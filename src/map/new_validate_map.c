#include "cube.h"

static char	*get_to_map(int fd)
{
	char	*ln;

	while (1)
	{
		ln = get_next_line(fd, 1000);
		if (!ln)
			break;
		if (ln[0] != 'N' && ln[0] != 'S' && \
			ln[0] != 'W' && ln[0] != 'E' && \
			ln[0] != 'F' && ln[0] != 'C' && \
			ln[0] != '\n')
		{
			if (ft_strchr(ln, '1'))
				return (ln);
		}
		free(ln);
	}
	return (NULL);
}

int	get_map_rows(char *file)
{
	auto char *ln;
	auto int fd = open(file, O_RDONLY), i = 1, j, cnt;
	ln = get_to_map(fd);
	if (!ln)
		return(i);
	free(ln);
	while(1)
	{
		ln = get_next_line(fd, 1000);
		if (!ln)
			break ;
		j = -1;
		cnt = 0;
		while (!cnt && ln[++j])
			if (ft_strchr("NSWE10", ln[j]))
				cnt = 1;
		if (cnt)
			i++;
		free(ln);
	}
	close(fd);
	return (i);
}

char	**get_map(char *file, int rows)
{
	auto int fd = open(file, O_RDONLY), i = -1, j, cnt;
	auto char **mp = (char **) malloc((rows + 1) * \
		(sizeof(char *))), *ln = get_to_map(fd);
	if (!mp || !ln)
	{
		clear_matrix(mp, rows + 1);
		return (NULL);
	}
	while (1)
	{
		j = -1;
		cnt = 0;
		while (!cnt && ln[++j])
			if (ft_strchr("NSWE10", ln[j]))
				cnt = 1;
		if (cnt)
		{
			mp[++i] = ln;
			mp[i][ft_strlen(ln) - 1] = 0;
		}
		else
			free(ln);
		ln = get_next_line(fd, 1000);
		if (!ln)
			break ;
	}
	mp[rows] = 0;
	close(fd);
	return (mp);
}

/* static void	cpy_map(int fd, char **mp, char *ln)
{
	auto int i = -1, j, cpy = -1;
	while (1)
	{
		j = -1;
		while (ln[++j])
		{
			if (cpy == 1 && !ft_strchr("NSWE10", ln[++j]))
				cpy = 0;
			else if (cpy == -1 && ft_strchr("NSWE10", ln[++j]))
				cpy = 1;
		}
		if (cpy)
		{
			mp[++i] = ln;
			mp[i][ft_strlen(ln) - 1] = 0;
		}
		else
			free(ln);
		ln = get_next_line(fd, 1000);
		if (!ln)
			break ;
	}
}

char	**get_map(char *file, int rows)
{
	auto int fd = open(file, O_RDONLY);
	auto char **mp = (char **) malloc((rows + 1) * \
		(sizeof(char *))), *ln = get_to_map(fd);
	if (!mp || !ln)
	{
		clear_matrix(mp, rows + 1);
		return (NULL);
	}
	cpy_map(fd, mp, ln);
	mp[rows] = 0;
	close(fd);
	return (mp);
} */

/* static int	map_helper(char **map, int rows, int x, int y)
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
} */
