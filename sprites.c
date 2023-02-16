#include "./so_long.h"

void	*sprite(game data, char letter, int keycode)
{
	if (letter == '0')
		return (data.s.wooden_floor);
	else if (letter == 'E')
	{
		if (data.player.collected == data.carte.collectibles)
			return (data.s.exit_opened);
		else
			return (data.s.exit_closed);
	}
	else if (letter == '1')
		return (data.s.wall);
	else if (letter == 'C')
		return (data.s.collectible);
	else if (letter == 'P')
	{
		if (keycode == Z)
			return (data.s.player_north);
		else if (keycode == D)
			return (data.s.player_east);
		else if (keycode == Q)
			return (data.s.player_west);
		else
			return(data.s.player_south);
	}
	return (NULL);
}

void	init_sprites(game *data)
{
	int		img_width;
	int		img_height;
	data->s.collectible = mlx_xpm_file_to_image(data->mlx_ptr, "./source/collectible.xpm", &img_width, &img_height);
	data->s.wall = mlx_xpm_file_to_image(data->mlx_ptr, "./source/wall.xpm", &img_width, &img_height);
	data->s.wooden_floor = mlx_xpm_file_to_image(data->mlx_ptr, "./source/wooden_floor.xpm", &img_width, &img_height);
	data->s.exit_opened = mlx_xpm_file_to_image(data->mlx_ptr, "./source/opened_door.xpm", &img_width, &img_height);
	data->s.exit_closed = mlx_xpm_file_to_image(data->mlx_ptr, "./source/closed_door.xpm", &img_width, &img_height);
	data->s.player_south = mlx_xpm_file_to_image(data->mlx_ptr, "./source/player_south.xpm", &img_width, &img_height);
	data->s.player_east = mlx_xpm_file_to_image(data->mlx_ptr, "./source/player_east.xpm", &img_width, &img_height);
	data->s.player_north = mlx_xpm_file_to_image(data->mlx_ptr, "./source/player_north.xpm", &img_width, &img_height);
	data->s.player_west = mlx_xpm_file_to_image(data->mlx_ptr, "./source/player_west.xpm", &img_width, &img_height);
}

void	fill_screen(game data, int res_x, int res_y, map_data carte, int keycode)
{

	int x = 0;
	int y = 0;
	int i = 0;
	int j = 0;
	while (carte.map_matrix[i])
	{
		x = 0;
		j = 0;
		while (carte.map_matrix[i][j])
		{
			mlx_put_image_to_window(data.mlx_ptr, data.mlx_win, sprite(data, carte.map_matrix[i][j], keycode), x, y);
			x += 96;
			j++;
		}
		y += 96;
		i++;
	}
}