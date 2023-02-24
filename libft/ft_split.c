/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dspilleb <dspilleb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 10:20:46 by dan               #+#    #+#             */
/*   Updated: 2022/10/16 15:42:19 by dspilleb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	number_elements(char const *s, char c)
{
	int	i;
	int	elements;

	i = 0;
	elements = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i] && s[i] != c)
		{
			elements++;
			while (s[i] && s[i] != c)
				i++;
		}
	}
	return (elements);
}

static int	start_of_element(int start, char const *s, char c)
{
	int	i;

	i = start;
	if (s[i] == c)
		while (s[i] && s[i] == c)
			i++;
	else
	{
		while (s[i] && s[i] != c)
			i++;
		while (s[i] && s[i] == c)
			i++;
	}
	return (i);
}

static void	free_all(char **str)
{
	int	i;

	i = -1;
	while (str[++i])
		free (str[i]);
	free(str);
}

static char	*copy_string(char const *s, char c)
{
	char	*str;
	int		i;
	int		len;

	len = 0;
	i = -1;
	while (s[++i] != c && s[i])
		len++;
	i = -1;
	str = (char *)malloc(len + 1);
	if (!str)
		return (NULL);
	while (++i < len && s[i])
		str[i] = s[i];
	str[i] = '\0';
	return (str);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		start;
	char	**arr;

	if (!s)
		return (NULL);
	i = -1;
	start = 0;
	arr = (char **)ft_calloc((number_elements(s, c) + 1), sizeof(char *));
	if (!arr)
		return (NULL);
	while (++i < number_elements(s, c))
	{
		if (!(start == 0 && s[0] != c && i == 0))
			start = start_of_element(start, s, c);
		arr[i] = copy_string(s + start, c);
		if (!arr[i])
		{
			free_all(arr);
			return (NULL);
		}
	}
	arr[i] = NULL;
	return (arr);
}
