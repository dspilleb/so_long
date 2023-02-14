/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dspilleb <dspilleb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 11:52:40 by dspilleb          #+#    #+#             */
/*   Updated: 2023/02/14 09:43:26 by dspilleb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "So_long.h"

void	free_all(char **str)
{
	int	i;

	i = -1;
	while (str[++i])
		free (str[i]);
	free(str);
}

char	*line_extractor(char *line, int len)
{
	int	i;
	char	*end_line;

	i = 0;
	if (!line || len <= 0)
		return (NULL);
	end_line = malloc(sizeof(char) * (len + 1));
	if (!end_line)
		return (NULL);
	while (line[i] && line[i] != '\n')
	{
		end_line[i] = line[i];
		i++;
	}
	end_line[i] = '\0';
	return (end_line);

}

char **ft_map_matrix(char *map, map_data data)
{
	int		fd;
	int		i;
	char	**map_matrix;
	char	*tmp_line;
	char	*line;

	i = 0;
	fd = open(map, O_RDONLY);
	map_matrix = (char **)ft_calloc(sizeof(char *), data.lines + 1);
	if (!map_matrix)
		return (NULL);
	map_matrix[data.lines] = NULL;
	while (i < data.lines)
	{
		line = get_next_line(fd);
		if (!line)
		{
			free_all(map_matrix);
			return (NULL);
		}
		map_matrix[i] = line_extractor(line, data.columns);
		free (line);
		if (!map_matrix[i])
		{
			free_all(map_matrix);
			return NULL;
		}
		i++;
	}
	return(map_matrix);
}

//ALGO VERIFICATION TRAJET POSSIBLE