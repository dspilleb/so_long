/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dspilleb <dspilleb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 19:44:48 by dspilleb          #+#    #+#             */
/*   Updated: 2023/03/01 09:30:40 by dspilleb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	player_death(t_game *data)
{
	static int	frame;
	int			x;
	int			y;
	int			*pos;

	pos = find_player(&data->carte);
	y = pos[0] * 96;
	x = pos[1] * 96;
	if (frame >= 2)
	{
		frame = 0;
		data->player.over = 1;
	}
	if (frame == 0)
		mlx_put_image_to_window(data->mlx_ptr, \
		data->mlx_win, data->s.player.d0, x, y);
	else if (frame == 1)
		mlx_put_image_to_window(data->mlx_ptr, \
		data->mlx_win, data->s.player.d1, x, y);
	frame++;
	free(pos);
}
