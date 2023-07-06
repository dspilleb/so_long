/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites2_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dspilleb <dspilleb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 13:19:13 by dspilleb          #+#    #+#             */
/*   Updated: 2023/07/06 14:24:05 by dspilleb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	free_env_sprites(t_game *data)
{
	if (data->s.env.collectible)
		mlx_destroy_image(data->mlx_ptr, data->s.env.collectible);
	if (data->s.env.wall)
		mlx_destroy_image(data->mlx_ptr, data->s.env.wall);
	if (data->s.env.wooden_floor)
		mlx_destroy_image(data->mlx_ptr, data->s.env.wooden_floor);
	if (data->s.env.exit_opened)
		mlx_destroy_image(data->mlx_ptr, data->s.env.exit_opened);
	if (data->s.env.exit_closed)
		mlx_destroy_image(data->mlx_ptr, data->s.env.exit_closed);
	if (data->s.env.wall2)
		mlx_destroy_image(data->mlx_ptr, data->s.env.wall2);
	if (data->s.env.wall3)
		mlx_destroy_image(data->mlx_ptr, data->s.env.wall3);
	if (data->s.env.ground2)
		mlx_destroy_image(data->mlx_ptr, data->s.env.ground2);
	if (data->s.player.d0)
		mlx_destroy_image(data->mlx_ptr, data->s.player.d0);
	if (data->s.player.d1)
		mlx_destroy_image(data->mlx_ptr, data->s.player.d1);
}

void	free_mob_sprites(t_game *data)
{
	int	i;

	i = -1;
	while (++i < 4 && data->s.ennemy.idle)
	{
		mlx_destroy_image(data->mlx_ptr, data->s.ennemy.idle[i]);
	}
	i = -1;
	while (++i < 4 && data->s.ennemy.death)
	{
		mlx_destroy_image(data->mlx_ptr, data->s.ennemy.death[i]);
	}
	free(data->s.ennemy.death);
	free(data->s.ennemy.idle);
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
			mlx_destroy_image(data->mlx_ptr, data->s.player.attack[i][j]);
		j = -1;
		while (++j <= 3 && data->s.player.idle)
			mlx_destroy_image(data->mlx_ptr, data->s.player.idle[i][j]);
		j = -1;
		while (++j <= 5 && data->s.player.movement)
			mlx_destroy_image(data->mlx_ptr, data->s.player.movement[i][j]);
	}
	if (data->s.player.attack)
		free_void_matrix(data->s.player.attack, 4);
	if (data->s.player.idle)
		free_void_matrix(data->s.player.idle, 4);
	if (data->s.player.movement)
		free_void_matrix(data->s.player.movement, 4);
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
