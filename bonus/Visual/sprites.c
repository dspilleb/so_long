/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dspilleb <dspilleb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 12:50:18 by dspilleb          #+#    #+#             */
/*   Updated: 2023/02/28 17:27:53 by dspilleb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	*sprite(t_game data, char letter)
{
	static int	count;

	if (count > 11)
		count = 0;
	count++;
	if (letter == 'E')
			return (data.s.env.exit_closed);
	else if (letter == '1')
	{
		if (count % 5 == 0 && count % 10 != 0)
			return (data.s.env.wall3);
		else if (count % 10 == 0)
			return (data.s.env.wall2);
		return (data.s.env.wall);
	}
	else if (letter == 'C')
		return (data.s.env.collectible);
	if (count % 10 == 0)
		return (data.s.env.ground2);
	return (data.s.env.wooden_floor);
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
	data->s.ennemy.idle = init_mob_sprites \
	(data, data->s.ennemy.idle, "./Sprites/ES/idle/", "I");
	data->s.ennemy.death = init_mob_sprites \
	(data, data->s.ennemy.idle, "./Sprites/ES/Death/", "D");
	data->s.env.ground2 = mlx_xpm_file_to_image(data->mlx_ptr, \
	"./Sprites/ground2.xpm", &img_width, &img_height);
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
	data->s.env.wall2 = mlx_xpm_file_to_image(data->mlx_ptr, \
	"./Sprites/wall2.xpm", &img_width, &img_height);
	data->s.env.wall3 = mlx_xpm_file_to_image(data->mlx_ptr, \
	"./Sprites/wall3.xpm", &img_width, &img_height);
	data->s.player.d0 = mlx_xpm_file_to_image(data->mlx_ptr, \
	"./Sprites/PS/Dead/D0.xpm", &img_width, &img_height);
	data->s.player.d1 = mlx_xpm_file_to_image(data->mlx_ptr, \
	"./Sprites/PS/Dead/D1.xpm", &img_width, &img_height);
}
