#include "cube.h"

static	void	check_player(t_data *data, int flag)
{
	if (!flag)
	{
		print_errors("No player was set.\n");
		on_destroy(data);
	}
}

void	get_player_position(t_data *data)
{
	auto int x = 0, y, flag_pos = 0;
	auto char pos;
	while (data->new_map.map[x])
	{
		y = 0;
		while (data->new_map.map[x][y])
		{
			pos = data->new_map.map[x][y];
			if (pos == 'N' || pos == 'E' || pos == 'S' || pos == 'W')
			{
				if (flag_pos == 1)
				{
					print_errors("More than 1 player\n");
					on_destroy(data);
				}
				set_player_position(data, x, y, pos);
				flag_pos = 1;
			}
			y++;
		}
		x++;
	}
	check_player(data, flag_pos);
}
