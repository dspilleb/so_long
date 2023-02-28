/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dspilleb <dspilleb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 15:43:10 by dspilleb          #+#    #+#             */
/*   Updated: 2023/02/28 18:44:32 by dspilleb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	update_player_data(t_game *data, int facing, int status)
{
	data->player.facing = facing;
	data->player.steps++;
	data->player.status = status;
}

void	**init_mob_sprites(t_game *data, void **arr, \
char *path, char *name)
{
	int		img_width;
	int		img_height;
	int		i;
	char	*num;
	char	*tmp_path;

	i = -1;
	arr = malloc(sizeof(void *) * (5));
	while (++i <= 3)
	{
		tmp_path = NULL;
		tmp_path = ft_join(tmp_path, path);
		num = ft_itoa(i);
		tmp_path = ft_join(tmp_path, name);
		tmp_path = ft_join(tmp_path, num);
		tmp_path = ft_join(tmp_path, ".xpm");
		free(num);
		arr[i] = mlx_xpm_file_to_image(data->mlx_ptr, \
		tmp_path, &img_width, &img_height);
		free(tmp_path);
	}
	return (arr);
}

void	free_monster(t_game data, int **tab)
{
	int	i;

	i = 0;
	while (i < data.carte.monsters)
	{
		free (tab[i]);
		i++;
	}
	free(tab);
}

void	fill_screen(t_game data)
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
			if (data.carte.map_matrix[i][j] != 'P')
				mlx_put_image_to_window(data.mlx_ptr, data.mlx_win, \
				sprite(data, data.carte.map_matrix[i][j]), x, y);
			x += 96;
			j++;
		}
		y += 96;
		i++;
	}
}

void	steps_count(t_game *data)
{
	char	*tmp;
	char	*num;

	tmp = NULL;
	num = ft_itoa(data->player.steps);	
	tmp = ft_join(tmp, "Steps :");
	tmp = ft_join(tmp, num);
	mlx_string_put(data->mlx_ptr, data->mlx_win, 50, 50, 0x00FF0000, tmp);
	free(num);
}
