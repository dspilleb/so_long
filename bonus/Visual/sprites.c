/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dspilleb <dspilleb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 12:50:18 by dspilleb          #+#    #+#             */
/*   Updated: 2023/02/26 15:40:31 by dspilleb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	*sprite(t_game data, char letter)
{
	if (letter == 'E')
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
		return (data.s.env.wooden_floor);
	return (NULL);
}

void	init_t_sprites(t_game *data)
{
	int		img_width;
	int		img_height;

	init_env_sprites(data);
	data->s.player.idle = init_player_sprites(data, data->s.player.idle, \
	"./Sprites/PS/Idle/", "I");
	data->s.player.movement = init_player_sprites(data, \
	data->s.player.movement, "./Sprites/PS/Movement/", "M");
	data->s.player.attack = init_player_sprites(data, data->s.player.attack, \
	"./Sprites/PS/Attack/", "A");
}

void	***init_player_sprites(t_game *data, void ***arr, \
char *path, char *name)
{
	int		img_width;
	int		img_height;
	int		i;
	int		j;
	char	*tmp_path;

	j = -1;
	arr = malloc(sizeof(void **) * 5);
	while (++j <= 3)
	{
		i = -1;
		arr[j] = malloc(sizeof(void *) * (6));
		while (++i <= 5)
		{
			tmp_path = create_path(path, name, j, i);
			arr[j][i] = mlx_xpm_file_to_image(data->mlx_ptr, \
			tmp_path, &img_width, &img_height);
			free(tmp_path);
		}
	}
	return (arr);
}

void	init_env_sprites(t_game *data)
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
