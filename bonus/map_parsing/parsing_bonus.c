/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dspilleb <dspilleb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 11:52:40 by dspilleb          #+#    #+#             */
/*   Updated: 2023/07/06 18:33:13 by dspilleb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

void	free_matrix(char **str)
{
	int	i;

	i = -1;
	if (!str)
		return ;
	while (str[++i])
		free (str[i]);
	free(str);
}

char	*line_extractor(char *line, int len)
{
	int		i;
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

char	**ft_map_matrix(char *map, t_map_data data)
{
	int		fd;
	int		i;
	char	**map_matrix;
	char	*line;

	i = -1;
	fd = open(map, O_RDONLY);
	if (!data.validity)
		return (NULL);
	map_matrix = (char **)ft_calloc(sizeof(char *), data.lines + 1);
	if (!map_matrix)
		return (NULL);
	while (++i < data.lines)
	{
		line = get_next_line(fd);
		map_matrix[i] = line_extractor(line, data.columns);
		if (line)
			free (line);
		if (!map_matrix[i])
		{
			free_matrix(map_matrix);
			return (NULL);
		}
	}
	return (map_matrix);
}
