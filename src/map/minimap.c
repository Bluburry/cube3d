#include "cube.h"

void	get_player_position(t_data *data)
{
	int		x;
	int		y;
	char 	pos;

	x = 0;
	while (data->new_map.map[x])
	{
		y = 0;
		while (data->new_map.map[x][y])
		{
			pos = data->new_map.map[x][y];
			if (pos == 'N' || pos == 'E' || pos == 'S' || pos == 'W')
				set_player_position(data, x, y, pos);
			y++;
		}
		x++;
	}

}