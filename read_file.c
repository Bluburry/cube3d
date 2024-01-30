#include "./libft/libft.h"
#include "map.h"

void	read_file(char *file, t_data *data)
{
	char	*ptrs;
	int		fd;

	fd = open(file, O_RDONLY);
	data->new_map.map = malloc(sizeof(char *) * 23);
	while (fd > 0)
	{
		ptrs = get_next_line(fd);
		if (!ptrs)
			break ;
		if (!ft_strncmp(ptrs, "NO", 2) || !ft_strncmp(ptrs, "SO", 2) \
				|| !ft_strncmp(ptrs, "WE", 2) || !ft_strncmp(ptrs, "EA", 2))
			save_texture_path(ptrs, data);
		else if (!ft_strncmp(ptrs, "F", 1) || !ft_strncmp(ptrs, "C", 1))
			continue ;
		else if (!ft_strchr(ptrs, '1'))
			continue ;
		else
			save_map(ptrs, data);
		free(ptrs);
	}
	data->new_map.map[data->new_map.rows] = 0; // Is it ok!?
	close(fd);
}