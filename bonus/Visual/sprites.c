/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dspilleb <dspilleb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 12:50:18 by dspilleb          #+#    #+#             */
/*   Updated: 2023/07/04 15:23:59 by dspilleb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	*sprite(t_game data, char letter)
{
	static int	count;

	if (count > 11)
		count = 0;
	count++;
	if (letter == 'E' && !(data.player.collected == data.carte.collectibles))
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
	data->s.env.ground2 = put_img(data, "./Sprites/ground2.xpm");
}

void	***init_player_sprites(t_game *data, void ***arr, \
char *path, char *name)
{
	int		nb;
	int		i;
	int		j;
	char	*tmp_path;

	j = -1;
	if (!strcmp(name, "M"))
		nb = 6;
	else
		nb = 4;
	arr = malloc(sizeof(void **) * 4);
	while (++j < 4)
	{
		i = -1;
		arr[j] = malloc(sizeof(void *) * (nb));
		while (++i < nb)
		{
			tmp_path = create_path(path, name, j, i);
			if (!tmp_path)
				end_t_game(data);
			arr[j][i] = put_img(data, tmp_path);
			free(tmp_path);
		}
	}
	return (arr);
}

void	init_env_sprites(t_game *data)
{

	data->s.env.collectible = put_img(data, "./Sprites/collectible.xpm");
	data->s.env.wall = put_img(data, "./Sprites/wall.xpm");
	data->s.env.wooden_floor = put_img(data, "./Sprites/wooden_floor.xpm");
	data->s.env.exit_opened = put_img(data, "./Sprites/opened_door.xpm");
	data->s.env.exit_closed = put_img(data, "./Sprites/closed_door.xpm");
	data->s.env.wall2 = put_img(data, "./Sprites/wall2.xpm");
	data->s.env.wall3 = put_img(data, "./Sprites/wall3.xpm");
	data->s.player.d0 = put_img(data, "./Sprites/PS/Dead/D0.xpm");
	data->s.player.d1 = put_img(data, "./Sprites/PS/Dead/D1.xpm");
}
