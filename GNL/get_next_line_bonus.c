/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dspilleb <dspilleb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 11:46:53 by dan               #+#    #+#             */
/*   Updated: 2023/02/07 17:42:06 by dspilleb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_strrchr(const char *s, int c)
{
	long long	i;
	long long	address;

	i = -1;
	address = -1;
	while (c - 128 > 0)
		c -= 128;
	while (s[++i])
		if (s[i] == c)
			address = i;
	if (s[i] == c)
			address = i;
	if (address != -1)
		return ((char *)&s[address]);
	else
		return (NULL);
}

char	*free_join(char *stock, char *buffer)
{
	char	*temp;

	if (stock)
	{
		temp = ft_strjoin(stock, buffer);
		free (stock);
		return (temp);
	}
	else
		stock = ft_strjoin("", buffer);
	return (stock);
}

char	*read_new_line(int fd, char *stock, char *buffer)
{
	ssize_t		tmp2;

	while (!stock || !ft_strrchr(stock, '\n'))
	{
		tmp2 = read(fd, buffer, BUFFER_SIZE);
		if (tmp2 == -1)
		{
			free (buffer);
			if (stock)
				free(stock);
			return (NULL);
		}
		if (tmp2 == 0)
			break ;
		buffer[tmp2] = '\0';
		stock = free_join(stock, buffer);
		if (!stock)
		{
			free (buffer);
			return (NULL);
		}
	}
	free (buffer);
	return (stock);
}

char	*get_next_line(int fd)
{
	char		*line;
	char		*buffer;
	static char	*stock[FD_MAX];

	if (BUFFER_SIZE <= 0 || fd < 0 || fd > FD_MAX)
		return (NULL);
	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	stock[fd] = read_new_line(fd, stock[fd], buffer);
	if (!stock[fd])
		return (NULL);
	line = extract(stock[fd]);
	stock[fd] = ft_cleaner(stock[fd], line);
	return (line);
}
