#ifndef SO_LONG_H
# define SO_LONG_H
# include "./GNL/get_next_line.h"
# include "./libft/libft.h"
# include <fcntl.h>
# include <stdio.h>
# include <string.h>
# include <mlx.h>
# include <stdbool.h>

# define Z 122
# define Q 113
# define D 100
# define S 115
# define esc 65307

typedef struct
{
	void	*collectible;
	void	*wall;
	void	*wooden_floor;
	void	*exit_opened;
	void	*exit_closed;
	void	*player_south;
	void	*player_east;
	void	*player_north;
	void	*player_west;
} sprites;
typedef struct	img {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct	map
{
	char	**map_matrix;
	int		collectibles;
	int		exit;
	int		character;
	int		validity;
	int		lines;
	int		columns;
} map_data;

typedef struct player
{
	int	collected;
	int	steps;
	int	status;
}	p_data;

typedef struct
{
    void          *mlx_ptr;
    void          *mlx_win;
	map_data	carte;
	p_data		player;
	sprites		s;
}                 game;

void	end_game(game *data);
void	*sprite(game data, char letter, int keycode);
int	*find_player(map_data *map);
void	check_walls(char *line, int count, map_data *data);
void add_map_data(map_data *data, char *line, int count);
void	init_struct(map_data *data);
void	map_len(map_data *data, char *map);
map_data check_map_validity(char *map);
void	free_all(char **str);
char	*line_extractor(char *line, int len);
char	**ft_map_matrix(char *map, map_data data);
int		can_move(game *data, char letter);
void	side_movement(game *data, char direction);
void	vertical_movement(game *data, char direction);
void	fill_screen(game data, int res_x, int res_y, map_data carte, int keycode);
void	init_sprites(game *data);

#endif
