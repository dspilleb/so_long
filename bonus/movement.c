/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dspilleb <dspilleb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 13:14:27 by dspilleb          #+#    #+#             */
/*   Updated: 2023/02/27 19:59:31 by dspilleb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	right_movement(t_game *data, char direction)
{
	int	y;
	int	x;
	int	*pos;

	pos = find_player(&data->carte);
	x = pos[1];
	y = pos[0];
	if (direction == 'D' && x < data->carte.columns - 1)
	{
		if (can_move(data, data->carte.map_matrix[y][x + 1]))
		{
			update_player_data(data, 1, 3);
			data->carte.map_matrix[y][x + 1] = 'P';
			data->carte.map_matrix[y][x] = '0';
			data->player.pos.to_x = (x + 1) * 96;
			data->player.pos.to_y = y * 96;
			data->player.pos.x = pos[1] * 96;
			data->player.pos.y = pos[0] * 96;
		}
	}
	free (pos);
}

void	left_movement(t_game *data, char direction)
{
	int	y;
	int	x;
	int	*pos;

	pos = find_player(&data->carte);
	x = pos[1];
	y = pos[0];
	if (direction == 'Q' && x > 0)
	{
		if (can_move(data, data->carte.map_matrix[y][x - 1]))
		{
			update_player_data(data, 3, 3);
			data->carte.map_matrix[y][x - 1] = 'P';
			data->carte.map_matrix[y][x] = '0';
			data->player.pos.to_x = (x - 1) * 96;
			data->player.pos.to_y = y * 96;
			data->player.pos.x = pos[1] * 96;
			data->player.pos.y = pos[0] * 96;
		}
	}
	free (pos);
}

void	up_movement(t_game *data, char direction)
{
	int	y;
	int	x;
	int	*pos;

	pos = find_player(&data->carte);
	x = pos[1];
	y = pos[0];
	if (direction == 'Z' && y > 0)
	{
		if (can_move(data, data->carte.map_matrix[y - 1][x]))
		{
			update_player_data(data, 0, 3);
			data->carte.map_matrix[y - 1][x] = 'P';
			data->carte.map_matrix[y][x] = '0';
			data->player.pos.to_x = x * 96;
			data->player.pos.to_y = (y - 1) * 96;
			data->player.pos.x = pos[1] * 96;
			data->player.pos.y = pos[0] * 96;
		}
	}
	free (pos);
}

void	down_movement(t_game *data, char direction)
{
	int	y;
	int	x;
	int	*pos;

	pos = find_player(&data->carte);
	x = pos[1];
	y = pos[0];
	if (direction == 'S' && y < data->carte.lines - 1)
	{
		if (can_move(data, data->carte.map_matrix[y + 1][x]))
		{
			update_player_data(data, 2, 3);
			data->carte.map_matrix[y + 1][x] = 'P';
			data->carte.map_matrix[y][x] = '0';
			data->player.pos.to_x = x * 96;
			data->player.pos.to_y = (y + 1) * 96;
			data->player.pos.x = pos[1] * 96;
			data->player.pos.y = pos[0] * 96;
		}
	}
	free (pos);
}

int	can_move(t_game *data, char letter)
{
	if (letter == '1')
		return (0);
	else if (letter == 'C')
		data->player.collected++;
	else if (letter == 'E' && data->player.collected \
	!= data->carte.collectibles)
	{
		printf("Vous n'avez pas récolté tout les collectibles !\n");
		return (0);
	}
	else if (letter == 'E' && data->player.collected \
	== data->carte.collectibles)
	{
		data->player.over = 1;
		fill_screen(*data);
	}
	else if (letter == 'M')
	{
		data->player.status = 1;
		return (0);
	}
	return (1);
}
