#include "so_long.h"

void	side_movement(game *data, char direction)
{

	int	*pos;
	pos = find_player(&data->carte);
	if (!pos)
		return;
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
	free (pos);
}

void	vertical_movement(game *data, char direction)
{
	int	*pos;

	pos = find_player(&data->carte);
	if (!pos)
		return;
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
	free (pos);
}

int	can_move(game *data, char letter)
{
	if (letter == '1')
		return (0);
	else if (letter == 'C')
	{
		data->player.collected++;
		return (1);
	}
	else if (letter == 'E' && data->player.collected != data->carte.collectibles)
		return (0);
	if (letter == 'E' && data->player.collected == data->carte.collectibles)
		data->player.status = 1;
	return (1);
}
