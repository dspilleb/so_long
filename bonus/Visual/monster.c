/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monster.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dspilleb <dspilleb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 09:31:53 by dspilleb          #+#    #+#             */
/*   Updated: 2023/06/30 11:31:08 by dspilleb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	monster_idle(t_game *data)
{
	static int	frame;
	int			**pos;
	int			i;

	i = -1;
	pos = find_monsters(data, 0);
	if (pos)
	{
		while (++i < data->carte.monsters)
		{
			if (frame > 3)
				frame = rand() % 3;
			monster_idle2(data, pos[i], frame);
			frame++;
		}
		free_monster(*data, pos);
	}
}

void	monster_idle2(t_game *data, int *pos, int frame)
{
	int			x;
	int			y;

	y = pos[0] * 96;
	x = pos[1] * 96;
	mlx_put_image_to_window(data->mlx_ptr, data->mlx_win, \
	data->s.env.wooden_floor, x, y);
	mlx_put_image_to_window(data->mlx_ptr, data->mlx_win, \
	data->s.ennemy.idle[frame], x, y);
	frame++;
}

int	**find_monsters(t_game *data, int count)
{
	int	**position;
	int	i;
	int	j;

	if (data->carte.monsters <= 0)
		return (NULL);
	position = malloc(sizeof(int *) * (data->carte.monsters));
	if (!position)
		return (NULL);
	i = -1;
	while (data->carte.map_matrix[++i])
	{
		j = -1;
		while (data->carte.map_matrix[i][++j])
		{
			if (data->carte.map_matrix[i][j] == 'M')
			{
				position[count] = malloc(sizeof(int) * 2);
				position[count][0] = i;
				position[count][1] = j;
				count++;
			}
		}
	}
	return (position);
}
