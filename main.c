#include "So_long.h"

typedef struct    data_s
{
    void          *mlx_ptr;
    void          *mlx_win;
	map_data	carte;
}                 data_t;

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

int	*find_player(map_data *map)
{
	int	*position;
	int i;
	int j;

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
			break;
		i++;
	}
	position[0] = i;
	position[1] = j;
	return (position);
}

void	side_movement(map_data *map, char direction)
{

	int	*pos;
	pos = find_player(map);
	if (!pos)
		return;
	if (direction == 'D' && pos[1] < map->columns - 1)
	{
			if (map->map_matrix[pos[0]][pos[1] + 1] != '1' && map->map_matrix[pos[0]][pos[1] + 1] != 'E')
			{
				map->map_matrix[pos[0]][pos[1] + 1] = 'P';
				map->map_matrix[pos[0]][pos[1]] = '0';
			}
	}
	else if (direction == 'Q' && pos[1] > 0)
	{
			if (map->map_matrix[pos[0]][pos[1] - 1] != '1' && map->map_matrix[pos[0]][pos[1] - 1] != 'E')
			{
				map->map_matrix[pos[0]][pos[1] - 1] = 'P';
				map->map_matrix[pos[0]][pos[1]] = '0';
			}
	}
	free (pos);
}

void	vertical_movement(map_data *map, char direction)
{
	int	*pos;

	pos = find_player(map);
	if (!pos)
		return;
	if (direction == 'Z' && pos[0] > 0)
	{
			if (map->map_matrix[pos[0] - 1][pos[1]] != '1' && map->map_matrix[pos[0] - 1][pos[1]] != 'E')
			{
				map->map_matrix[pos[0] - 1][pos[1]] = 'P';
				map->map_matrix[pos[0]][pos[1]] = '0';
			}
	}
	else if (direction == 'S' && pos[0] < map->lines - 1)
	{
			if (map->map_matrix[pos[0] + 1][pos[1]] != '1' && map->map_matrix[pos[0] + 1][pos[1]] != 'E')
			{
				map->map_matrix[pos[0] + 1][pos[1]] = 'P';
				map->map_matrix[pos[0]][pos[1]] = '0';
			}
	}
	free (pos);
}
void	init_sprite()
{

}
void	*sprite(data_t data, char letter)
{
	int		img_width;
	int		img_height;
	static void	*sol_bois;
	static void	*collectible;
	static void	*mur;
	static void	*personnage;
	static void	*sortie;

	if (!sol_bois)
	{
		sol_bois = mlx_xpm_file_to_image(data.mlx_ptr, "./source/wooden_floor.xpm", &img_width, &img_height);
		collectible = mlx_xpm_file_to_image(data.mlx_ptr, "./source/collectible.xpm", &img_width, &img_height);
		mur = mlx_xpm_file_to_image(data.mlx_ptr, "./source/mur.xpm", &img_width, &img_height);
		personnage = mlx_xpm_file_to_image(data.mlx_ptr, "./source/personnage2.xpm", &img_width, &img_height);
		sortie = mlx_xpm_file_to_image(data.mlx_ptr, "./source/sortie.xpm", &img_width, &img_height);
	}
	if (letter == '0')
		return (sol_bois);
	if (letter == 'E')
		return (sortie);
	if (letter == '1')
		return (mur);
	if (letter == 'C')
		return (collectible);
	if (letter == 'P')
		return (personnage);
	else
		return (NULL);
}

void	fill_screen(data_t data, int res_x, int res_y, map_data carte)
{

	int x = 0;
	int y = 0;
	int i = 0;
	int j = 0;
	while (carte.map_matrix[i])
	{
		x = 0;
		j = 0;
		while (carte.map_matrix[i][j])
		{
			mlx_put_image_to_window(data.mlx_ptr, data.mlx_win, sprite(data, carte.map_matrix[i][j]), x, y);
			x += 96;
			j++;
		}
		y += 96;
		i++;
	}
}

int	actions(int keycode, data_t *data)
{
	int		img_width;
	int		img_height;

	if (keycode == Z)
		vertical_movement(&data->carte, 'Z');
	else if (keycode == Q)
		side_movement(&data->carte, 'Q');
	else if (keycode == S)
		vertical_movement(&data->carte, 'S');
	else if (keycode == D)
		side_movement(&data->carte, 'D');
	else if (keycode == esc)
	{
		mlx_destroy_window(data->mlx_ptr, data->mlx_win);
		printf("ESC DESTROYED\n");
		exit(1);
	}
	fill_screen(*data, data->carte.columns * 96, data->carte.lines * 96, data->carte);
}

int main(void)
{
	int res_x;
	int res_y;

    data_t        data;
	t_data		img;

	data.carte = check_map_validity("map.ber");
	if (data.carte.validity)
		data.carte.map_matrix = ft_map_matrix("map.ber", data.carte);
	else
	{
		printf("la carte n'est pas valide.\n");
		exit (1);
	}
	res_x = data.carte.columns * 96;
	res_y = data.carte.lines * 96;
	//setup fenêtre
    if ((data.mlx_ptr = mlx_init()) == NULL)
        return (EXIT_FAILURE);
    if ((data.mlx_win = mlx_new_window(data.mlx_ptr, res_x, res_y, "I'm too good at making games")) == NULL)
        return (EXIT_FAILURE);
	img.img = mlx_new_image(data.mlx_ptr, res_x, res_y);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
								&img.endian);
	// Fin setup fenêtre
	fill_screen(data, data.carte.columns * 96, data.carte.lines * 96, data.carte);
	mlx_hook(data.mlx_win, 2, 1L<<0 , actions, &data);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
								&img.endian);
	mlx_mouse_show(data.mlx_ptr, data.mlx_win);
	
    mlx_loop(data.mlx_ptr);
    return (EXIT_SUCCESS);
}