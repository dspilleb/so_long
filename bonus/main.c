/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dspilleb <dspilleb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 13:09:23 by dspilleb          #+#    #+#             */
/*   Updated: 2023/03/01 09:29:19 by dspilleb         ###   ########.fr       */
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
		else if (keycode == ESC)
			end_t_game(data);
	}
	if (data->player.over == 1)
		end_t_game(data);
	movement -= data->player.steps;
	if (movement)
		printf("Steps : %d\n", data->player.steps);
	return (0);
}

int	count(t_game *data)
{
	static int	count;

	if (!data->player.over)
	{
		if (count % 700 == 0 && data->player.status != 2)
			monster_idle(data);
		if (count % 1000 == 0 && data->player.status == 2)
		{
			count = 0;
			put_background(data);
			player_attack(data);
		}
		else if (count % 2000 && data->player.status == 1)
		{
			count = 0;
			put_background(data);
			player_death(data);
		}
		else if (count % 700 == 0 && data->player.status == 3)
		{
			count = 0;
			put_background(data);
			player_movement(data);
		}
		else if (count % 2000 == 0 && data->player.status == 0)
		{
			count = 0;
			put_background(data);
			player_idle(data);
		}
		count++;
	}
}

void	init_game(t_game *data, t_data *img)
{
	data->res_x = data->carte.columns * 96;
	data->res_y = data->carte.lines * 96;
	data->mlx_ptr = mlx_init();
	data->mlx_win = mlx_new_window(data->mlx_ptr, data->res_x, \
	data->res_y, "./so_long");
	mlx_do_key_autorepeatoff(data->mlx_ptr);
	img->img = mlx_new_image (data->mlx_ptr, data->res_x, data->res_y);
	if (data->mlx_win == NULL || data->mlx_ptr == NULL)
		end_t_game(data);
}

int	main(void)
{
	t_game	data;
	t_data	img;

	data.carte = check_map_validity("./maps/map.ber");
	if (data.carte.validity)
		data.carte.map_matrix = ft_map_matrix("./maps/map.ber", data.carte);
	else
	{
		printf("la carte n'est pas valide.\n");
		exit (1);
	}
	init_game(&data, &img);
	init_player(&data, &data.player);
	init_t_sprites(&data);
	all_background(data);
	fill_screen(data);
	mlx_hook(data.mlx_win, 2, 1L << 0, actions, &data);
	mlx_hook(data.mlx_win, 17, 1L << 2, end_t_game, &data);
	mlx_loop_hook(data.mlx_ptr, count, &data);
	mlx_loop(data.mlx_ptr);
	return (EXIT_SUCCESS);
}
