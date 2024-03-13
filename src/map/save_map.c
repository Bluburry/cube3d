#include "cube.h"

int		save_texture_path(char *path, t_data *data)
{
	if (!ft_strncmp(path, "NO", 2) && !data->new_map.no.path)
		data->new_map.no.path = ft_substr(path, 3, ft_strlen(path) - 4);
	else if (!ft_strncmp(path, "SO", 2) && !data->new_map.so.path)
		data->new_map.so.path = ft_substr(path, 3, ft_strlen(path) - 4);
	else if (!ft_strncmp(path, "WE", 2) && !data->new_map.we.path)
		data->new_map.we.path = ft_substr(path, 3, ft_strlen(path) - 4);
	else if (!ft_strncmp(path, "EA", 2) && !data->new_map.ea.path)
		data->new_map.ea.path = ft_substr(path, 3, ft_strlen(path) - 4);
	else
		return (1);
	return (0);
}

int	save_map(char *line, t_data *data)
{
	int	i;
	int	rows;

	if (!data->new_map.no.path || !data->new_map.so.path || \
		!data->new_map.we.path || !data->new_map.ea.path || \
		!data->new_map.floor || !data->new_map.sky)
	{
		printf("Error - Save Map - Map at first\n");
		exit(0);
	}
	i = 0;
	rows = data->new_map.rows;
	data->new_map.map[rows] = malloc(sizeof(char) * ft_strlen(line) + 1);
	while (line[i] && line[i] != '\n')
	{
		data->new_map.map[rows][i] = line[i];
		if (data->new_map.columns <= i)
			data->new_map.columns = i + 1; // Need to check
		i++;
	}
	data->new_map.map[rows][i] = '\0';
	data->new_map.rows++;
	return 1;
}
