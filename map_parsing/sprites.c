/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dspilleb <dspilleb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 12:50:18 by dspilleb          #+#    #+#             */
/*   Updated: 2023/02/17 13:16:27 by dspilleb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	*sprite(t_game data, char letter, int keycode)
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
			return (data.s.player_south);
	}
	return (NULL);
}

void	init_t_sprites(t_game *data)
{
	int		img_width;
	int		img_height;

	data->s.collectible = mlx_xpm_file_to_image(data->mlx_ptr, \
	"./source/collectible.xpm", &img_width, &img_height);
	data->s.wall = mlx_xpm_file_to_image(data->mlx_ptr, \
	"./source/wall.xpm", &img_width, &img_height);
	data->s.wooden_floor = mlx_xpm_file_to_image(data->mlx_ptr, \
	"./source/wooden_floor.xpm", &img_width, &img_height);
	data->s.exit_opened = mlx_xpm_file_to_image(data->mlx_ptr, \
	"./source/opened_door.xpm", &img_width, &img_height);
	data->s.exit_closed = mlx_xpm_file_to_image(data->mlx_ptr, \
	"./source/closed_door.xpm", &img_width, &img_height);
	data->s.player_south = mlx_xpm_file_to_image(data->mlx_ptr, \
	"./source/player_south.xpm", &img_width, &img_height);
	data->s.player_east = mlx_xpm_file_to_image(data->mlx_ptr, \
	"./source/player_east.xpm", &img_width, &img_height);
	data->s.player_north = mlx_xpm_file_to_image(data->mlx_ptr, \
	"./source/player_north.xpm", &img_width, &img_height);
	data->s.player_west = mlx_xpm_file_to_image(data->mlx_ptr, \
	"./source/player_west.xpm", &img_width, &img_height);
}

void	fill_screen(t_game data, int res_x, int res_y, int keycode)
{
	int	x;
	int	y;
	int	i;
	int	j;

	y = 0;
	i = 0;
	while (data.carte.map_matrix[i])
	{
		x = 0;
		j = 0;
		while (data.carte.map_matrix[i][j])
		{
			mlx_put_image_to_window(data.mlx_ptr, data.mlx_win, \
			sprite(data, data.carte.map_matrix[i][j], keycode), x, y);
			x += 96;
			j++;
		}
		y += 96;
		i++;
	}
}
