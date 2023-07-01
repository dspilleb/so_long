/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dspilleb <dspilleb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 19:44:48 by dspilleb          #+#    #+#             */
/*   Updated: 2023/07/01 11:59:43 by dspilleb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	player_death(t_game *data)
{
	static int	frame;
	int			x;
	int			y;
	int			*pos;

	if (data->player.over)
		return ;
	pos = find_letter(&data->carte, 'P');
	if (!pos)
		return ;
	y = pos[0] * CUBE_SIZE;
	x = pos[1] * CUBE_SIZE;
	if (frame == 0)
		mlx_put_image_to_window(data->mlx_ptr, \
		data->mlx_win, data->s.player.d0, x, y);
	else if (frame == 1)
		mlx_put_image_to_window(data->mlx_ptr, \
		data->mlx_win, data->s.player.d1, x, y);
	frame++;
	free(pos);
	if (frame >= 2)
		data->player.over = 1;
}
