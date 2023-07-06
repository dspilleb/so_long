/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dspilleb <dspilleb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 13:09:23 by dspilleb          #+#    #+#             */
/*   Updated: 2023/07/06 12:39:47 by dspilleb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	actions(int keycode, t_game *data)
{
	int		movement;

	movement = data->player.steps;
	if (data->player.status == 0 && !data->player.over)
	{
		if (keycode == Z)
			up_movement(data, 'Z');
		else if (keycode == Q)
			left_movement(data, 'Q');
		else if (keycode == S)
			down_movement(data, 'S');
		else if (keycode == D)
			right_movement(data, 'D');
		else if (keycode == F)
			data->player.status = 2;
	}
	if (keycode == ESC || data->player.over == 1)
		end_t_game(data);
	if (movement != data->player.steps)
		steps_count(data);
	return (0);
}

int	count(t_game *data)
{
	static int	count;

	if (data->player.over)
		return (0);
	if (count % 700 == 0 && data->player.status != 2)
		monster_idle(data);
	if ((count % 1000 == 0 && data->player.status == 2) || \
	(count % 2000 && data->player.status == 1) || \
	(count % 700 == 0 && data->player.status == 3) \
	|| (count % 2000 == 0 && data->player.status == 0))
	{
		count = 0;
		put_background(data);
		if (data->player.status == 2)
			player_attack(data);
		else if (data->player.status == 1)
			player_death(data);
		else if (data->player.status == 3)
			player_movement(data);
		else if (data->player.status == 0)
			player_idle(data);
	}
	count++;
	return (0);
}

void	init_game(t_game *data)
{
	data->res_x = data->carte.columns * CUBE_SIZE;
	data->res_y = data->carte.lines * CUBE_SIZE;
	data->mlx_ptr = mlx_init();
	data->mlx_win = mlx_new_window(data->mlx_ptr, data->res_x, \
	data->res_y, "./so_long");
	mlx_do_key_autorepeatoff(data->mlx_ptr);
	if (data->mlx_win == NULL || data->mlx_ptr == NULL)
		mlx_destroy_window(data->mlx_ptr, data->mlx_win);
}

int	main(int ac, char **av)
{
	t_game	data;

	if (ac != 2)
		return (0);
	if (!set_map(&data, av[1]))
		return (0);
	init_game(&data);
	init_player(&data, &data.player);
	init_t_sprites(&data);
	all_background(data);
	fill_screen(data);
	mlx_hook(data.mlx_win, 2, 1L << 0, actions, &data);
	mlx_hook(data.mlx_win, 17, 1L << 2, end_t_game, &data);
	mlx_loop_hook(data.mlx_ptr, count, &data);
	mlx_loop(data.mlx_ptr);
	return (0);
}
