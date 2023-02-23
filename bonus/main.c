/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dspilleb <dspilleb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 13:09:23 by dspilleb          #+#    #+#             */
/*   Updated: 2023/02/23 13:23:01 by dspilleb         ###   ########.fr       */
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

int	end_t_game(t_game *data)
{
	mlx_destroy_window(data->mlx_ptr, data->mlx_win);
	printf("ESC DESTROYED\n");
	exit(1);
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
		end_t_game(data);
	movement -= data->player.steps;
	if (movement)
	{
		fill_screen (*data, data->carte.columns * 96, \
		data->carte.lines * 96, keycode);
		printf("Steps : %d\n", data->player.steps);
		printf("facing : %C\n", data->player.facing);
	}
	if (data->player.status)
		end_t_game(data);
	return (0);
}

void	render_player(t_game *data)
{
	static int count;
	int *pos;
	int x;
	int y;
	pos = find_player(&data->carte);
	y = pos[0] * 96;
	x = pos[1] * 96;
	if (count > 4)
		count = 0;
	mlx_put_image_to_window(data->mlx_ptr, data->mlx_win, data->s.player.idle[count], x, y);
	count++;
}

int	count(t_game *data)
{
	static int count;
	if (count % 1500 == 0)
		render_player(data);
	count++;
}
void	init_player(t_p_data *player)
{
	player->collected = 0;
	player->steps = 0;
	player->status = 0;
	player->facing = 'S';
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
	init_player(&data.player);
	data.mlx_ptr = mlx_init();
	data.mlx_win = mlx_new_window(data.mlx_ptr, data.carte.columns * 96, \
	data.carte.lines * 96, "./so_long");
	mlx_do_key_autorepeatoff(data.mlx_ptr);
	if (data.mlx_win == NULL || data.mlx_ptr == NULL)
		return (EXIT_FAILURE);
	img.img = mlx_new_image (data.mlx_ptr, data.carte.columns * 96, \
	data.carte.lines * 96);
	init_t_sprites(&data);
	fill_screen (data, data.carte.columns * 96, data.carte.lines * 96, S);
	mlx_hook(data.mlx_win, 2, 1L << 0, actions, &data);
	mlx_hook(data.mlx_win, 17, 1L << 2, end_t_game, &data);
	mlx_loop_hook(data.mlx_ptr, count, &data);
	mlx_loop(data.mlx_ptr);
	return (EXIT_SUCCESS);
}
