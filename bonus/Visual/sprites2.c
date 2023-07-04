/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dspilleb <dspilleb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 13:19:13 by dspilleb          #+#    #+#             */
/*   Updated: 2023/07/04 16:19:49 by dspilleb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	free_env_sprites(t_game *data)
{
	if (data->s.env.collectible)
		free(data->s.env.collectible);
	if (data->s.env.wall)
		free(data->s.env.wall);
	if (data->s.env.wooden_floor)
		free(data->s.env.wooden_floor);
	if (data->s.env.exit_opened)
		free(data->s.env.exit_opened);
	if (data->s.env.exit_closed)
		free(data->s.env.exit_closed);
	if (data->s.env.wall2)
		free(data->s.env.wall2);
	if (data->s.env.wall3)
		free(data->s.env.wall3);
	if (data->s.env.ground2)
		free(data->s.env.ground2);
}

void	free_mob_sprites(t_game *data)
{
	int	i;

	i = -1;
	while (++i < 4 && data->s.ennemy.idle)
		free(data->s.ennemy.idle[i]);
	i = -1;
	while (++i < 4 && data->s.ennemy.death)
		free(data->s.ennemy.death[i]);
}

void	free_player_sprites(t_game *data)
{
	int	i;
	int	j;

	i = -1;
	while (++i <= 3)
	{
		j = -1;
		while (++j <= 3 && data->s.player.attack)
			free(data->s.player.attack[i][j]);
		j = -1;
		while (++j <= 3 && data->s.player.idle)
			free(data->s.player.idle[i][j]);
		j = -1;
		while (++j <= 5 && data->s.player.movement)
			free(data->s.player.movement[i][j]);
	}
	if (data->s.player.d0)
		free(data->s.player.d0);
	if (data->s.player.d1)
		free(data->s.player.d1);
}

void	open_exit(t_game *data)
{
	int	*pos;
	int	x;
	int	y;

	pos = find_letter(&data->carte, 'E');
	if (!pos)
		end_t_game(data);
	x = pos[1] * CUBE_SIZE;
	y = pos[0] * CUBE_SIZE;
	mlx_put_image_to_window(data->mlx_ptr, data->mlx_win, \
	data->s.env.exit_opened, x, y);
	free (pos);
}
