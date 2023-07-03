/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dspilleb <dspilleb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 17:48:05 by dspilleb          #+#    #+#             */
/*   Updated: 2023/07/03 19:29:42 by dspilleb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	*put_img(t_game *data, char *path)
{
	int	img_width;
	int	img_height;

	return (mlx_xpm_file_to_image(data->mlx_ptr, \
				path, &img_width, &img_height));
}

int	set_map(t_game *data, char *path)
{
	char	*tmp;

	tmp = ft_strjoin("./maps/", path);
	if (!tmp)
		return (0);
	data->carte = check_map_validity(tmp);
	free (tmp);
	if (!data->carte.validity)
	{
		if (data->carte.map_matrix)
			free_matrix(data->carte.map_matrix);
		printf("Error\nLa carte n'est pas valide.\n");
		return (0);
	}
	return (1);
}

void	*malloc_fail(t_game *data, void *test)
{
	if (!test)
		data->player.over = 1;
	return (test);
}