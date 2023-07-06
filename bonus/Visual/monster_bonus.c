/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monster_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dspilleb <dspilleb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 09:31:53 by dspilleb          #+#    #+#             */
/*   Updated: 2023/07/06 18:33:13 by dspilleb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

void	monster_idle(t_game *data)
{
	static int	frame;
	int			**pos;
	int			i;

	i = -1;
	if (data->player.over)
		return ;
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

	y = pos[0] * CUBE_SIZE;
	x = pos[1] * CUBE_SIZE;
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

	if (data->carte.monsters <= 0 || data->player.over)
		return (NULL);
	position = malloc(sizeof(int *) * (data->carte.monsters));
	if (!position)
		end_t_game(data);
	i = -1;
	while (data->carte.map_matrix[++i])
	{
		j = -1;
		while (data->carte.map_matrix[i][++j])
		{
			if (data->carte.map_matrix[i][j] == 'M')
			{
				position[count] = find_monsters2(i, j);
				if (!position[count++])
					free_int_matrix(data, position, count);
			}
		}
	}
	return (position);
}

int	*find_monsters2(int i, int j)
{
	int	*tmp;

	tmp = malloc(sizeof(int) * 2);
	if (!tmp)
		return (NULL);
	tmp[0] = i;
	tmp[1] = j;
	return (tmp);
}

void	free_int_matrix(t_game *data, int **tab, int size)
{
	int	i;

	i = -1;
	while (++i < size)
		free(tab[i]);
	free(tab);
	end_t_game(data);
}
