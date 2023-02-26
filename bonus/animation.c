/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dspilleb <dspilleb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 14:03:08 by dspilleb          #+#    #+#             */
/*   Updated: 2023/02/26 14:54:51 by dspilleb         ###   ########.fr       */
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
	put_background(data);
	mlx_put_image_to_window(data->mlx_ptr, data->mlx_win, data->s.player.idle[dir][frame], x, y);
	frame++;
}

void	player_movement(t_game *data)
{
	static int frame;
	static int	x;
	static int	y;
	int dir;

	dir = data->player.facing;
	if (frame == 0)
	{
		x = data->player.pos.x;
		y = data->player.pos.y;
	}
	x += (data->player.pos.to_x - data->player.pos.x) / 4;
	y += (data->player.pos.to_y - data->player.pos.y) / 4;
	if ((x == data->player.pos.to_x && y == data->player.pos.to_y) || frame > 5)
	{
		frame = 0;
		data->player.status = 0;
		put_background(data);
		mlx_put_image_to_window(data->mlx_ptr, data->mlx_win, data->s.player.idle[dir][frame], x, y);
	}
	put_background(data);
	mlx_put_image_to_window(data->mlx_ptr, data->mlx_win, data->s.player.movement[dir][frame], x, y);
	frame++;
}

void	player_attack(t_game *data)
{
	static int frame;
	int	dir;
	int *pos;
	int x;
	int y;

	pos = find_player(&data->carte);
	y = pos[0] * 96;
	x = pos[1] * 96;
	dir = data->player.facing;
	if (frame == 4)
	{
		frame = 0;
		data->player.status = 0;
	}
	put_background(data);
	mlx_put_image_to_window(data->mlx_ptr, data->mlx_win, data->s.player.attack[dir][frame], x, y);
	frame++;
}

void	put_background(t_game *data)
{
	int	close_x;
	int	close_y;

	mlx_put_image_to_window(data->mlx_ptr, data->mlx_win, data->s.env.wooden_floor, data->player.pos.x, data->player.pos.y);
	mlx_put_image_to_window(data->mlx_ptr, data->mlx_win, data->s.env.wooden_floor, data->player.pos.to_x, data->player.pos.to_y);
}

int	find_close_block(int i)
{
	int	nearest_multiple;

	if (i % 96 <= 48) {
        nearest_multiple = i - (i % 96);
    } else {
        nearest_multiple = i + (96 - (i % 96));
    }
	return (nearest_multiple);
}