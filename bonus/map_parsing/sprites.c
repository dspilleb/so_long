/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dspilleb <dspilleb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 12:50:18 by dspilleb          #+#    #+#             */
/*   Updated: 2023/02/24 13:21:05 by dspilleb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	*sprite(t_game data, char letter, int keycode)
{
	if (letter == '0')
		return (data.s.env.wooden_floor);
	else if (letter == 'E')
	{
		if (data.player.collected == data.carte.collectibles)
			return (data.s.env.exit_opened);
		else
			return (data.s.env.exit_closed);
	}
	else if (letter == '1')
		return (data.s.env.wall);
	else if (letter == 'C')
		return (data.s.env.collectible);
	else
		return(data.s.env.wooden_floor);
	return (NULL);
}

void	init_t_sprites(t_game *data)
{
	int		img_width;
	int		img_height;

	init_env_sprites(data);
	init_player_sprites(data, &data->s.player.idle, 3, "./Sprites/PS/Idle/2/PIS");
}

void init_player_sprites(t_game *data, void **arr, int size, char *path)
{
	int		img_width;
	int		img_height;

	int i;
	char *num;
	char *tmp_path;
	char *tmp_path2;

	i = 0;
	while (i <= size)
	{
		num = ft_itoa(i);
		tmp_path = ft_strjoin(path, num);
		tmp_path2 = ft_strjoin(tmp_path, ".xpm");
		printf("%s\n", tmp_path2);
		arr[i] = mlx_xpm_file_to_image(data->mlx_ptr, tmp_path2, &img_width, &img_height);
		free(num);
		free(tmp_path);
		free(tmp_path2);
		i++;
	}
}

void init_env_sprites(t_game *data)
{
	int		img_width;
	int		img_height;

	data->s.env.collectible = mlx_xpm_file_to_image(data->mlx_ptr, \
	"./Sprites/collectible.xpm", &img_width, &img_height);
	data->s.env.wall = mlx_xpm_file_to_image(data->mlx_ptr, \
	"./Sprites/wall.xpm", &img_width, &img_height);
	data->s.env.wooden_floor = mlx_xpm_file_to_image(data->mlx_ptr, \
	"./Sprites/wooden_floor.xpm", &img_width, &img_height);
	data->s.env.exit_opened = mlx_xpm_file_to_image(data->mlx_ptr, \
	"./Sprites/opened_door.xpm", &img_width, &img_height);
	data->s.env.exit_closed = mlx_xpm_file_to_image(data->mlx_ptr, \
	"./Sprites/closed_door.xpm", &img_width, &img_height);
	data->s.player.player_east = mlx_xpm_file_to_image(data->mlx_ptr, \
	"./Sprites/player_east.xpm", &img_width, &img_height);
	data->s.player.player_north = mlx_xpm_file_to_image(data->mlx_ptr, \
	"./Sprites/player_north.xpm", &img_width, &img_height);
	data->s.player.player_west = mlx_xpm_file_to_image(data->mlx_ptr, \
	"./Sprites/player_west.xpm", &img_width, &img_height);
}

void	fill_screen(t_game data, int res_x, int res_y, int keycode)
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
			sprite(data, data.carte.map_matrix[i][j], keycode), x, y);
			x += 96;
			j++;
		}
		y += 96;
		i++;
	}
}
