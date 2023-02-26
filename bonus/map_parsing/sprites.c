/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dspilleb <dspilleb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 12:50:18 by dspilleb          #+#    #+#             */
/*   Updated: 2023/02/26 14:53:21 by dspilleb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

char	*ft_join(char *s1, char *s2)
{
	size_t		i;
	size_t		end_s1;
	size_t		end_s2;
	char		*str;

	i = -1;
	if (!s1)
	{
		s1 = (char *)malloc(1 * sizeof(char));
		s1[0] = 0;
	}
	end_s1 = ft_strlen(s1);
	if (!s2 || !s1)
		return (NULL);
	end_s2 = ft_strlen(s2);
	str = malloc(sizeof(char) * (end_s1 + end_s2 + 1));
	if (!str)
		return (NULL);
	ft_strlcpy(str, s1, end_s1 + 1);
	while (++i < end_s2)
		str[end_s1 + i] = s2[i];
	str[end_s1 + i] = '\0';
	free(s1);
	return (str);
}

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
		return(data.s.env.wooden_floor);
	return (NULL);
}

void	init_t_sprites(t_game *data)
{
	int		img_width;
	int		img_height;

	init_env_sprites(data);
	data->s.player.idle = init_player_sprites(data, data->s.player.idle, 3, "./Sprites/PS/Idle/", "I");
	data->s.player.movement = init_player_sprites(data, data->s.player.movement, 5, "./Sprites/PS/Movement/", "M");
	data->s.player.attack = init_player_sprites(data, data->s.player.attack, 3, "./Sprites/PS/Attack/", "A");
	printf("%p\n", data->s.player.attack[0][0]);
}

void ***init_player_sprites(t_game *data, void ***arr, int size, char *path, char *name)
{
	int		img_width;
	int		img_height;

	int i;
	int j;
	char *num;
	char *tmp_path;

	j = 0;
	arr = malloc(sizeof(void **) * 5);
	while (j <= 3)
	{
		i = 0;
		tmp_path = NULL;
		arr[j] = malloc(sizeof(void *) * (size + 1));
		while (i <= size)
		{
			num = ft_itoa(j);
			tmp_path = ft_join(tmp_path, path);
			tmp_path = ft_join(tmp_path, num);
			tmp_path = ft_join(tmp_path, "/");
			free(num);
			num = ft_itoa(i);
			tmp_path = ft_join(tmp_path, name);
			tmp_path = ft_join(tmp_path, num);
			tmp_path = ft_join(tmp_path, ".xpm");
			arr[j][i] = mlx_xpm_file_to_image(data->mlx_ptr, tmp_path, &img_width, &img_height);
			free(num);
			free(tmp_path);
			tmp_path = NULL;
			i++;
		}
		j++;
	}
	return (arr);
}

void init_env_sprites(t_game *data)
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

void	all_background(t_game data)
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
			mlx_put_image_to_window(data.mlx_ptr, data.mlx_win, \
				data.s.env.wooden_floor, x, y);
			x += 96;
			j++;
		}
		y += 96;
		i++;
	}
}