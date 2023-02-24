/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dspilleb <dspilleb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 18:54:22 by dan               #+#    #+#             */
/*   Updated: 2022/10/16 20:03:16 by dspilleb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t		length;
	char		*str;
	size_t		i;

	if (!s)
		return (NULL);
	length = 0;
	i = 0;
	if (start < ft_strlen(s))
		while (length < len && s[start + length] != '\0')
			length++;
	str = malloc(length + 1);
	if (!str)
		return (NULL);
	while (i < length)
	{
		str[i] = s[start + i];
		i++;
	}
	str[i] = '\0';
	return (str);
}
