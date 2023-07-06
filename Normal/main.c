/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dspilleb <dspilleb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 13:09:23 by dspilleb          #+#    #+#             */
/*   Updated: 2023/07/06 18:28:21 by dspilleb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	*find_player(t_map_data *map)
{
	int	*position;
	int	i;
	int	j;

	position = malloc(sizeof(int) * 2);
	if (!position)
		return (NULL);
	i = 0;
	j = 0;
	while (map->map_matrix[i])
	{
		j = 0;
		while (map->map_matrix[i][j] && map->map_matrix[i][j] != 'P')
			j++;
		if (map->map_matrix[i][j])
			break ;
		i++;
	}
	position[0] = i;
	position[1] = j;
	return (position);
}

int	end_game(t_game *data)
{
	mlx_destroy_window(data->mlx_ptr, data->mlx_win);
	if (data->carte.map_matrix)
		free_matrix(data->carte.map_matrix);
	free_sprites(data);
	exit(EXIT_SUCCESS);
	return (0);
}

int	actions(int keycode, t_game *data)
{
	int		movement;

	movement = data->player.steps;
	if (keycode == Z)
		vertical_movement(data, 'Z');
	else if (keycode == Q)
		side_movement(data, 'Q');
	else if (keycode == S)
		vertical_movement(data, 'S');
	else if (keycode == D)
		side_movement(data, 'D');
	else if (keycode == ESC)
		end_game(data);
	movement -= data->player.steps;
	if (movement)
	{
		fill_screen (*data, keycode);
		ft_printf("Steps : %d\n", data->player.steps);
	}
	if (data->player.status)
		end_game(data);
	return (0);
}

void	init_player(t_p_data *player)
{
	player->collected = 0;
	player->steps = 0;
	player->status = 0;
}

int	main(int ac, char **av)
{
	t_game	data;

	if (ac != 2)
	{
		ft_printf("Error\nMauvais nombre d'arguments\n");
		return (0);
	}
	else if (!set_map(&data, av[1]))
		return (0);
	init_player(&data.player);
	data.mlx_ptr = mlx_init();
	data.mlx_win = mlx_new_window(data.mlx_ptr, data.carte.columns * 96, \
	data.carte.lines * 96, "./so_long");
	if (data.mlx_win == NULL || data.mlx_ptr == NULL)
		return (EXIT_FAILURE);
	init_t_sprites(&data);
	fill_screen (data, S);
	mlx_hook(data.mlx_win, 2, 1L << 0, actions, &data);
	mlx_hook(data.mlx_win, 17, 1L << 2, end_game, &data);
	mlx_loop(data.mlx_ptr);
	return (EXIT_SUCCESS);
}
