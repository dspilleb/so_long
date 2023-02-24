/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dspilleb <dspilleb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 13:34:06 by dan               #+#    #+#             */
/*   Updated: 2022/10/16 20:03:03 by dspilleb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	strmatch(const char *haystack, const char *needle \
, size_t len, size_t i)
{
	int		a;
	size_t	c;

	a = 0;
	c = i;
	while (haystack[c] == needle[a] && \
	c < len && needle[a] && haystack[c])
	{
		a++;
		c++;
	}
	return (a);
}

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t		i;
	size_t		location;
	size_t		a;

	i = 0;
	a = 0;
	if (ft_strlen(needle) == 0)
		return ((char *)haystack);
	if (len == 0 && needle)
		return (NULL);
	while (haystack[i] && i < len)
	{
		if (haystack[i] == needle[0])
		{
			location = i;
			a = strmatch(haystack, needle, len, i);
			if (a == ft_strlen(needle))
				return ((char *)&haystack[location]);
			else
				a = 0;
		}
		i++;
	}
	return (NULL);
}
