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
# define ESC 65307

typedef struct sprites
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
}	t_sprites;
typedef struct img
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct map
{
	char	**map_matrix;
	int		collectibles;
	int		exit;
	int		character;
	int		validity;
	int		lines;
	int		columns;
}	t_map_data;

typedef struct player
{
	int	collected;
	int	steps;
	int	status;
}	t_p_data;

typedef struct game
{
	void		*mlx_ptr;
	void		*mlx_win;
	t_map_data	carte;
	t_p_data	player;
	t_sprites	s;
}	t_game;

void		end_t_game(t_game *data);
void		*sprite(t_game data, char letter, int keycode);
int			*find_player(t_map_data *map);
void		check_walls(char *line, int count, t_map_data *data);
void		add_t_map_data(t_map_data *data, char *line, int count);
void		init_struct(t_map_data *data);
void		map_len(t_map_data *data, char *map);
t_map_data	check_map_validity(char *map);
void		free_matrix(char **str);
char		*line_extractor(char *line, int len);
char		**ft_map_matrix(char *map, t_map_data data);
int			can_move(t_game *data, char letter);
void		side_movement(t_game *data, char direction);
void		vertical_movement(t_game *data, char direction);
void		fill_screen(t_game data, int res_x, int res_y, int keycode);
void		init_t_sprites(t_game *data);

#endif
