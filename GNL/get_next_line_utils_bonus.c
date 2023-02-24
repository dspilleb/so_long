/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dspilleb <dspilleb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 12:03:52 by dspilleb          #+#    #+#             */
/*   Updated: 2023/02/07 20:22:01 by dspilleb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlcpy(char *dest, char const *src, size_t size)
{
	size_t	i;
	size_t	a;

	a = 0;
	while (src[a])
		a++;
	if (size <= 0)
		return (a);
	i = 0;
	while (src[i] && size - 1 > i)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (a);
}

size_t	ft_strlen(char const *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t		end_s1;
	size_t		end_s2;
	char		*str;

	if (!s1 || !s2)
		return (NULL);
	end_s1 = ft_strlen(s1);
	end_s2 = ft_strlen(s2);
	str = malloc(sizeof(char) * (end_s1 + end_s2 + 1));
	if (!str)
		return (NULL);
	ft_strlcpy(str, s1, end_s1 + 1);
	ft_strlcpy(&str[end_s1], s2, end_s2 + 1);
	return (str);
}

char	*extract(char *stock)
{
	char		*line;
	size_t		len;

	len = 0;
	if (!stock)
		return (NULL);
	while (stock[len] && stock[len] != '\n')
		len++;
	if (stock[len] == '\n')
		len++;
	line = malloc(sizeof(char) * len + 1);
	if (!line)
	{
		free(stock);
		return (NULL);
	}
	ft_strlcpy(line, stock, len + 1);
	return (line);
}

char	*ft_cleaner(char *stock, char *line)
{
	size_t		start;
	size_t		end;
	char		*new_stock;

	if (!line)
		return (NULL);
	start = ft_strlen(line);
	end = ft_strlen(stock);
	if (end - start == 0)
	{
		free (stock);
		return (NULL);
	}
	new_stock = malloc(sizeof(char) * (end - start) + 1);
	if (!new_stock)
	{
		free (stock);
		free(line);
		line = NULL;
		return (NULL);
	}
	ft_strlcpy(new_stock, &stock[start], 1 + (end - start));
	free(stock);
	return (new_stock);
}
