#include "So_long.h"

typedef struct    data_s
{
    void          *mlx_ptr;
    void          *mlx_win;
}                 data_t;

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int	actions(int keycode, data_t *data)
{
	int		img_width;
	int		img_height;
	void *herbe;
	herbe = mlx_xpm_file_to_image(data->mlx_ptr, "./source/personnage2.xpm", &img_width, &img_height);
	if (keycode == Z)
		mlx_put_image_to_window(data->mlx_ptr, data->mlx_win, herbe, 0, 0);
	else if (keycode == Q)
		printf("q\n");
	else if (keycode == S)
		printf("s\n");
	else if (keycode == D)
		printf("d\n");
	else if (keycode == esc)
	{
		mlx_destroy_window(data->mlx_ptr, data->mlx_win);
		printf("ESC DESTROYED\n");
		exit(1);
	}
	return 0;
}

void	*sprite(data_t data, char letter)
{
	int		img_width;
	int		img_height;
	void	*sol_bois;
	void	*collectible;
	void	*mur;
	void	*personnage;
	void	*sortie;

	sol_bois = mlx_xpm_file_to_image(data.mlx_ptr, "./source/wooden_floor.xpm", &img_width, &img_height);
	collectible = mlx_xpm_file_to_image(data.mlx_ptr, "./source/collectible.xpm", &img_width, &img_height);
	mur = mlx_xpm_file_to_image(data.mlx_ptr, "./source/mur.xpm", &img_width, &img_height);
	personnage = mlx_xpm_file_to_image(data.mlx_ptr, "./source/personnage.xpm", &img_width, &img_height);
	sortie = mlx_xpm_file_to_image(data.mlx_ptr, "./source/sortie.xpm", &img_width, &img_height);
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
		printf("\n");
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

int main(void)
{
	int res_x;
	int res_y;

    data_t        data;
	t_data		img;

	map_data carte;

	carte = check_map_validity("map.ber");
	if (carte.validity)
		carte.map_matrix = ft_map_matrix("map.ber", carte);
	else
	{
		printf("la carte n'est pas valide.\n");
		exit (1);
	}
	res_x = carte.columns * 96;
	res_y = carte.lines * 96;
	//setup fenêtre
    if ((data.mlx_ptr = mlx_init()) == NULL)
        return (EXIT_FAILURE);
    if ((data.mlx_win = mlx_new_window(data.mlx_ptr, res_x, res_y, "I'm too good at making games")) == NULL)
        return (EXIT_FAILURE);
	img.img = mlx_new_image(data.mlx_ptr, res_x, res_y);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
								&img.endian);
	// Fin setup fenêtre

	mlx_hook(data.mlx_win, 2, 1L<<0 , actions, &data);
	fill_screen(data, res_x, res_y, carte);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
								&img.endian);
	mlx_mouse_show(data.mlx_ptr, data.mlx_win);
	
    mlx_loop(data.mlx_ptr);
    return (EXIT_SUCCESS);
}