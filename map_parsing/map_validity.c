/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validity.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dspilleb <dspilleb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 11:50:50 by dspilleb          #+#    #+#             */
/*   Updated: 2023/02/16 12:30:20 by dspilleb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	check_walls(char *line, int count, map_data *data)
{
	int	i;

	i = 0;
	if (count == 0 || count == data->lines - 1)
	{
		while (line[i] && line[i] != '\n')
		{
			if (line[i] != '1')
				data->validity = 0;
			i++;
		}
	}
	else
	{
		if (line[i] != '1')
			data->validity = 0;
		while (line[i] && line[i] != '\n')
			i++;
		if (line[i - 1] != '1')
			data->validity = 0;
	}
	return ;
}

void	add_map_data(map_data *data, char *line, int count)
{
	int	i;

	i = 0;
	while (line[i] && line[i] != '\n')
	{
		if (line[i] == 'E')
			data->exit++;
		else if (line[i] == 'C')
			data->collectibles++;
		else if (line[i] == 'P')
			data->character++;
		else if (line[i] != '1' && line[i] != '0')
			data->validity = 0;
		i++;
	}
	if (count == 0)
		data->columns = i;
	else if (i != data->columns)
		data->validity = 0;
	return ;
}

void	init_struct(map_data *data)
{
	data->lines = 0;
	data->columns = -1;
	data->exit = 0;
	data->collectibles = 0;
	data->character = 0;
	data->validity = 0;
}

void	map_len(map_data *data, char *map)
{
	int		fd;
	char	*line;

	fd = open(map, O_RDONLY);
	line = "";
	while (line)
	{
		line = get_next_line(fd);
		if (!line)
			return ;
		free(line);
		data->lines++;
	}
}

map_data	check_map_validity(char *map)
{
	int			count;
	char		*line;
	map_data	data;
	int			fd;

	count = 0;
	init_struct(&data);
	fd = open(map, O_RDONLY);
	data.validity = 1;
	map_len(&data, map);
	while (data.validity)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		check_walls(line, count, &data);
		add_map_data(&data, line, count);
		free (line);
		count++;
	}
	if (data.character != 1 || data.collectibles <= 0 || data.exit != 1)
		data.validity = 0;
	return (data);
}
/*
int	main(void)
{
	int	i;

	i = 0;
	map_data result;
	result = check_map_validity("map.ber");
	if (result.validity)
	{
		printf("YOUPPI\n");
		result.map_matrix = ft_map_matrix("map.ber", result);
		printf("Voici la matrice :\n");
		while (result.map_matrix[i])
		{
			printf("%s\n", result.map_matrix[i]);
			i++;
		}
		free_all(result.map_matrix);

	}
	else
		printf("MAP DE MERDE / PAS OUF");
	return (0);
}*/