/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dspilleb <dspilleb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 14:03:08 by dspilleb          #+#    #+#             */
/*   Updated: 2023/07/01 11:53:52 by dspilleb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	player_idle(t_game *data)
{
	static int	frame;
	int			x;
	int			y;
	int			dir;
	int			*pos;

	pos = find_letter(&data->carte, 'P');
	if (!pos)
		return ;
	y = pos[0] * CUBE_SIZE;
	x = pos[1] * CUBE_SIZE;
	if (frame <= 1)
		face_ennemy(data, x, y);
	dir = data->player.facing;
	if (frame > 3)
		frame = 0;
	mlx_put_image_to_window(data->mlx_ptr, data->mlx_win, \
	data->s.player.idle[dir][frame], x, y);
	frame++;
	free(pos);
}

void	player_movement(t_game *data)
{
	static int	frame;
	static int	x;
	static int	y;
	int			dir;

	dir = data->player.facing;
	if (frame == 0)
	{
		x = data->player.pos.x;
		y = data->player.pos.y;
	}
	x += (data->player.pos.to_x - data->player.pos.x) / 6;
	y += (data->player.pos.to_y - data->player.pos.y) / 6;
	if ((x == data->player.pos.to_x && y == data->player.pos.to_y) || frame > 5)
	{
		frame = 0;
		data->player.status = 0;
	}
	mlx_put_image_to_window(data->mlx_ptr, data->mlx_win, \
	data->s.player.movement[dir][frame], x, y);
	frame++;
}

void	player_attack(t_game *data)
{
	static int	frame;
	int			dir;
	int			x;
	int			y;
	int			*pos;

	pos = find_letter(&data->carte, 'P');
	if (!pos)
		return ;
	y = pos[0] * CUBE_SIZE;
	x = pos[1] * CUBE_SIZE;
	dir = data->player.facing;
	if (frame >= 4)
	{
		frame = 0;
		data->player.status = 0;
	}
	mlx_put_image_to_window(data->mlx_ptr, data->mlx_win, \
	data->s.player.attack[dir][frame], x, y);
	update_target(data, x / CUBE_SIZE, y / CUBE_SIZE);
	ennemy_death(data);
	frame++;
	free (pos);
}

void	put_background(t_game *data)
{
	if (!data->player.over)
	{
		mlx_put_image_to_window(data->mlx_ptr, data->mlx_win, \
		data->s.env.wooden_floor, data->player.pos.x, data->player.pos.y);
		mlx_put_image_to_window(data->mlx_ptr, data->mlx_win, \
		data->s.env.wooden_floor, data->player.pos.to_x, data->player.pos.to_y);
	}
}

void	all_background(t_game data)
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
				data.s.env.wooden_floor, x, y);
			x += CUBE_SIZE;
			j++;
		}
		y += CUBE_SIZE;
		i++;
	}
}
