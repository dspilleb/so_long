/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dspilleb <dspilleb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 13:14:27 by dspilleb          #+#    #+#             */
/*   Updated: 2023/02/23 12:02:37 by dspilleb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	side_movement(t_game *data, char direction)
{
	int	*pos;

	pos = find_player(&data->carte);
	if (!pos)
		return ;
	if (direction == 'D' && pos[1] < data->carte.columns - 1)
	{
		if (can_move(data, data->carte.map_matrix[pos[0]][pos[1] + 1]))
		{
			data->carte.map_matrix[pos[0]][pos[1] + 1] = 'P';
			data->carte.map_matrix[pos[0]][pos[1]] = '0';
			data->player.steps++;
		}
	}
	else if (direction == 'Q' && pos[1] > 0)
	{
		if (can_move(data, data->carte.map_matrix[pos[0]][pos[1] - 1]))
		{
			data->carte.map_matrix[pos[0]][pos[1] - 1] = 'P';
			data->carte.map_matrix[pos[0]][pos[1]] = '0';
			data->player.steps++;
		}
	}
	data->player.facing = direction;
	free (pos);
}

void	vertical_movement(t_game *data, char direction)
{
	int	*pos;

	pos = find_player(&data->carte);
	if (!pos)
		return ;
	if (direction == 'Z' && pos[0] > 0)
	{
		if (can_move(data, data->carte.map_matrix[pos[0] - 1][pos[1]]))
		{
			data->carte.map_matrix[pos[0] - 1][pos[1]] = 'P';
			data->carte.map_matrix[pos[0]][pos[1]] = '0';
			data->player.steps++;
		}
	}
	else if (direction == 'S' && pos[0] < data->carte.lines - 1)
	{
		if (can_move(data, data->carte.map_matrix[pos[0] + 1][pos[1]]))
		{
			data->carte.map_matrix[pos[0] + 1][pos[1]] = 'P';
			data->carte.map_matrix[pos[0]][pos[1]] = '0';
			data->player.steps++;
		}
	}
	data->player.facing = direction;
	free (pos);
}

int	can_move(t_game *data, char letter)
{
	if (letter == '1')
		return (0);
	else if (letter == 'C')
	{
		data->player.collected++;
		return (1);
	}
	else if (letter == 'E' && data->player.collected \
	!= data->carte.collectibles)
	{
		printf("Vous n'avez pas récolté tout les collectibles !\n");
		return (0);
	}
	if (letter == 'E' && data->player.collected == data->carte.collectibles)
		data->player.status = 1;
	return (1);
}
