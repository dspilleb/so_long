/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dspilleb <dspilleb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 14:03:08 by dspilleb          #+#    #+#             */
/*   Updated: 2023/02/24 14:43:57 by dspilleb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	player_idle(t_game *data)
{
	static int frame;
	int *pos;
	int x;
	int y;
	int dir;

	dir = data->player.facing;
	pos = find_player(&data->carte);
	y = pos[0] * 96;
	x = pos[1] * 96;
	if (frame > 3)
		frame = 0;
	fill_screen(*data);
	mlx_put_image_to_window(data->mlx_ptr, data->mlx_win, data->s.player.idle[dir][frame], x, y);
	frame++;
}

void	player_movement(t_game *data, int x, int y, int final_x, int final_y)
{
	int frame = 0;
	int distance_x;
	int distance_y;
	int dir;

	dir = data->player.facing;
	distance_x = ((x - final_x) * (-1)) / 6;
	distance_y = ((y - final_y) * (-1)) / 6;
	if ( (x - final_x) % 6 == 0 && (y - final_y) % 6 == 0)
	{
		while (x != final_x || y != final_y)
		{
			fill_screen(*data);
			x += distance_x;
			y += distance_y;
			mlx_put_image_to_window(data->mlx_ptr, data->mlx_win, data->s.player.movement[dir][frame], x, y);
			frame++;
		}
	}
}
