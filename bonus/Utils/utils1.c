/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dspilleb <dspilleb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 15:24:33 by dspilleb          #+#    #+#             */
/*   Updated: 2023/06/30 13:20:15 by dspilleb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

char	*ft_join(char *s1, char *s2)
{
	size_t		i;
	size_t		end_s1;
	size_t		end_s2;
	char		*str;

	i = -1;
	if (!s1)
	{
		s1 = (char *)malloc(1 * sizeof(char));
		s1[0] = 0;
	}
	end_s1 = ft_strlen(s1);
	if (!s2 || !s1)
		return (NULL);
	end_s2 = ft_strlen(s2);
	str = malloc(sizeof(char) * (end_s1 + end_s2 + 1));
	if (!str)
		return (NULL);
	ft_strlcpy(str, s1, end_s1 + 1);
	while (++i < end_s2)
		str[end_s1 + i] = s2[i];
	str[end_s1 + i] = '\0';
	free(s1);
	return (str);
}

int	*find_player(t_map_data *map)
{
	int	*position;
	int	i;
	int	j;

	position = malloc(sizeof(int) * 2);
	if (!position)
		return (NULL);
	i = 0;
	j = 0;
	while (map->map_matrix[i])
	{
		j = 0;
		while (map->map_matrix[i][j] && map->map_matrix[i][j] != 'P')
			j++;
		if (map->map_matrix[i][j])
			break ;
		i++;
	}
	position[0] = i;
	position[1] = j;
	return (position);
}

void	init_player(t_game *data, t_p_data *player)
{
	int	*pos;

	pos = find_player(&data->carte);
	player->collected = 0;
	player->steps = 0;
	player->status = 0;
	player->facing = 2;
	player->over = 0;
	player->pos.x = pos[1] * 96;
	player->pos.y = pos[0] * 96;
	player->pos.to_x = pos[1] * 96;
	player->pos.to_y = pos[0] * 96;
	free (pos);
}

int	end_t_game(t_game *data)
{
	mlx_destroy_window(data->mlx_ptr, data->mlx_win);
	free_env_sprites(data);
	free_mob_sprites(data);
	free_player_sprites(data);
	return (0);
}

char	*create_path(char *path, char *name, int j, int i)
{
	char	*tmp_path;
	char	*num;

	tmp_path = NULL;
	num = ft_itoa(j);
	tmp_path = ft_join(tmp_path, path);
	tmp_path = ft_join(tmp_path, num);
	tmp_path = ft_join(tmp_path, "/");
	free(num);
	num = ft_itoa(i);
	tmp_path = ft_join(tmp_path, name);
	tmp_path = ft_join(tmp_path, num);
	tmp_path = ft_join(tmp_path, ".xpm");
	free(num);
	return (tmp_path);
}
