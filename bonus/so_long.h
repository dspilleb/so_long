/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dspilleb <dspilleb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 13:18:16 by dspilleb          #+#    #+#             */
/*   Updated: 2023/02/28 00:23:12 by dspilleb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include "../GNL/get_next_line.h"
# include "../libft/libft.h"
# include <fcntl.h>
# include <math.h>
# include <stdio.h>
# include <string.h>
# include <mlx.h>
# include <stdbool.h>

# define Z 122
# define Q 113
# define D 100
# define S 115
# define ESC 65307
# define F 102

typedef struct position
{
	int	target_x;
	int	target_y;
	int	x;
	int	y;
	int	to_x;
	int	to_y;
}t_pos;
typedef struct env_sprites
{
	void	*collectible;
	void	*wall;
	void	*wall2;
	void	*wall3;
	void	*wooden_floor;
	void	*exit_opened;
	void	*exit_closed;
}	t_env;

typedef struct player_sprites
{
	void	***idle;
	void	***movement;
	void	*d0;
	void	*d1;
	void	***attack;
}	t_player_sprites;

typedef struct ennemy_sprites
{
	void	**idle;
	void	**death;
}	t_ennemy_sprites;
typedef struct sprites
{
	t_env				env;
	t_player_sprites	player;
	t_ennemy_sprites	ennemy;
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
	int		monsters;
}	t_map_data;

typedef struct player
{
	int		collected;
	int		steps;
	int		status;
	int		over;
	int		facing;
	t_pos	pos;
}	t_p_data;

typedef struct game
{
	void		*mlx_ptr;
	void		*mlx_win;
	t_map_data	carte;
	int			res_x;
	int			res_y;
	t_p_data	player;
	t_sprites	s;
}	t_game;

void		ennemy_death(t_game *data);
void		update_target(t_game *data, int x, int y);
int			*check_for_ennemy(t_game *data, int x1, int y1);
void		face_ennemy(t_game *data, int x, int y);
void		player_death(t_game *data);
void		free_monster(t_game data, int **tab);
void		**init_mob_sprites(t_game *data, void **arr, \
			char *path, char *name);
int			**find_monsters(t_game *data);
void		monster_idle(t_game *data);
void		monster_idle2(t_game *data, int *pos, int frame);
void		update_player_data(t_game *data, int facing, int status);
void		init_player(t_game *data, t_p_data *player);
char		*ft_join(char *s1, char *s2);
char		*create_path(char *path, char *name, int j, int i);
void		all_background(t_game data);
void		put_background(t_game *data);
void		player_attack(t_game *data);
void		***init_player_sprites(t_game *data, void \
			***arr, char *path, char *name);
void		init_env_sprites(t_game *data);
int			end_t_game(t_game *data);
void		*sprite(t_game data, char letter);
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
void		right_movement(t_game *data, char direction);
void		left_movement(t_game *data, char direction);
void		down_movement(t_game *data, char direction);
void		up_movement(t_game *data, char direction);
void		fill_screen(t_game data);
void		init_t_sprites(t_game *data);
void		player_idle(t_game *data);
void		player_movement(t_game *data);

#endif
