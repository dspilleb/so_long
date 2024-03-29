/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dspilleb <dspilleb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 17:48:05 by dspilleb          #+#    #+#             */
/*   Updated: 2023/07/06 18:33:13 by dspilleb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

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
	{
		if (data->carte.map_matrix)
			free_matrix(data->carte.map_matrix);
		return (0);
	}
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

void	free_void_matrix(void ***tab, int size)
{
	int	i;

	i = -1;
	while (++i < size)
		free(tab[i]);
	free(tab);
}
