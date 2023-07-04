/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dspilleb <dspilleb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 09:34:33 by dspilleb          #+#    #+#             */
/*   Updated: 2023/07/04 18:24:32 by dspilleb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	check_path(char *map, t_map_data *data)
{
	char	**tmp_map;
	int		*pos;

	if (!data->validity || !data->map_matrix)
	{
		data->validity = 0;
		return ;
	}
	pos = find_player(data);
	if (!pos)
	{
		data->validity = 0;
		return ;
	}
	tmp_map = ft_map_matrix(map, *data);
	if (!tmp_map)
	{
		free(pos);
		data->validity = 0;
		return ;
	}
	tmp_map = paint(tmp_map, pos[0], pos[1]);
	data->validity = checkitems(tmp_map);
	free_matrix(tmp_map);
	free(pos);
}

char	**paint(char **map, int i, int j)
{
	map[i][j] = '1';
	if (map[i + 1][j] != '1')
		map = paint(map, i + 1, j);
	if (map[i - 1][j] != '1')
		map = paint(map, i - 1, j);
	if (map[i][j + 1] != '1')
		map = paint(map, i, j + 1);
	if (map[i][j - 1] != '1')
		map = paint(map, i, j - 1);
	return (map);
}

int	checkitems(char **map)
{
	int	i;
	int	j;

	i = -1;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
			if (map[i][j] == 'C' || map[i][j] == 'E')
				return (0);
	}
	return (1);
}
