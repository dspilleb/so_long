/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   attack.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dspilleb <dspilleb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 20:15:25 by dspilleb          #+#    #+#             */
/*   Updated: 2023/02/28 17:37:14 by dspilleb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	update_target(t_game *data, int x, int y)
{
	if (data->player.facing == 0)
	{
		data->player.pos.target_y = y - 1;
		data->player.pos.target_x = x;
	}
	else if (data->player.facing == 1)
	{
		data->player.pos.target_y = y;
		data->player.pos.target_x = x + 1;
	}
	else if (data->player.facing == 2)
	{
		data->player.pos.target_y = y + 1;
		data->player.pos.target_x = x;
	}
	else
	{
		data->player.pos.target_y = y;
		data->player.pos.target_x = x - 1;
	}
}

void	face_ennemy(t_game *data, int x1, int y1)
{
	int	x;
	int	y;

	x = x1 / 96;
	y = y1 / 96;
	if (data->carte.map_matrix[y - 1][x] == 'M')
		data->player.facing = 0;
	else if (data->carte.map_matrix[y][x + 1] == 'M')
		data->player.facing = 1;
	else if (data->carte.map_matrix[y + 1][x] == 'M')
		data->player.facing = 2;
	else if (data->carte.map_matrix[y][x - 1] == 'M')
		data->player.facing = 3;
	else
		return ;
}


void	ennemy_death(t_game *data)
{
	static int	frame;
	int	x;
	int	y;

	x = data->player.pos.target_x;
	y = data->player.pos.target_y;
	if (data->carte.map_matrix[y][x] != 'M')
		return ;
	if (frame >= 3)
	{
		frame = 0;
		data->carte.map_matrix[y][x] = '0';
		data->carte.monsters--;
		mlx_put_image_to_window(data->mlx_ptr, data->mlx_win, \
		data->s.env.wooden_floor, x * 96, y * 96);
		return ;
	}
	mlx_put_image_to_window(data->mlx_ptr, data->mlx_win, \
	data->s.env.wooden_floor, x * 96, y * 96);
	mlx_put_image_to_window(data->mlx_ptr, data->mlx_win, \
	data->s.ennemy.death[frame], x * 96, y * 96);
	printf("coucou%d\n", frame);
	frame++;
}
