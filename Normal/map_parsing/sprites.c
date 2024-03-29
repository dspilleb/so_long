/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dspilleb <dspilleb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 12:50:18 by dspilleb          #+#    #+#             */
/*   Updated: 2023/07/06 17:11:13 by dspilleb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	*sprite(t_game data, char letter, int keycode)
{
	if (letter == '0')
		return (data.s.wooden_floor);
	if (letter == 'E')
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
	data->s.collectible = put_img(data, "./source/collectible.xpm");
	data->s.wall = put_img(data, "./source/wall.xpm");
	data->s.wooden_floor = put_img(data, "./source/wooden_floor.xpm");
	data->s.exit_opened = put_img(data, "./source/opened_door.xpm");
	data->s.exit_closed = put_img(data, "./source/closed_door.xpm");
	data->s.player_south = put_img(data, "./source/player_south.xpm");
	data->s.player_east = put_img(data, "./source/player_east.xpm");
	data->s.player_north = put_img(data, "./source/player_north.xpm");
	data->s.player_west = put_img(data, "./source/player_west.xpm");
}

void	fill_screen(t_game data, int keycode)
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
			x += CUBE_SIZE;
			j++;
		}
		y += CUBE_SIZE;
		i++;
	}
}

void	free_sprites(t_game *data)
{
	if (data->s.collectible)
		mlx_destroy_image(data->mlx_ptr, data->s.collectible);
	if (data->s.exit_closed)
		mlx_destroy_image(data->mlx_ptr, data->s.exit_closed);
	if (data->s.exit_opened)
		mlx_destroy_image(data->mlx_ptr, data->s.exit_opened);
	if (data->s.player_east)
		mlx_destroy_image(data->mlx_ptr, data->s.player_east);
	if (data->s.player_north)
		mlx_destroy_image(data->mlx_ptr, data->s.player_north);
	if (data->s.player_south)
		mlx_destroy_image(data->mlx_ptr, data->s.player_south);
	if (data->s.player_west)
		mlx_destroy_image(data->mlx_ptr, data->s.player_west);
	if (data->s.wall)
		mlx_destroy_image(data->mlx_ptr, data->s.wall);
	if (data->s.wooden_floor)
		mlx_destroy_image(data->mlx_ptr, data->s.wooden_floor);
}
