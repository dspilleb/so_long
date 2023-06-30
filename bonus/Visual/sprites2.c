/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dspilleb <dspilleb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 13:19:13 by dspilleb          #+#    #+#             */
/*   Updated: 2023/06/30 13:22:04 by dspilleb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	free_env_sprites(t_game *data)
{
	free(data->s.env.collectible);
	free(data->s.env.wall);
	free(data->s.env.wooden_floor);
	free(data->s.env.exit_opened);
	free(data->s.env.exit_closed);
	free(data->s.env.wall2);
	free(data->s.env.wall3);
	free(data->s.env.ground2);
}

void	free_mob_sprites(t_game *data)
{
	int	i;

	i = -1;
	while (++i < 4)
		free(data->s.ennemy.idle[i]);
	i = -1;
	while (++i < 4)
		free(data->s.ennemy.death[i]);
}

void	free_player_sprites(t_game *data)
{
	int	i;
	int	j;

	i = -1;
	j = -1;
	while (++i <= 3)
	{
		j = -1;
		while (++j <= 3)
		{
			free(data->s.player.attack[i][j]);
			free(data->s.player.idle[i][j]);
			free(data->s.player.movement[i][j]);
		}
	}
	free(data->s.player.d0);
	free(data->s.player.d1);
}
