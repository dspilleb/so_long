/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dspilleb <dspilleb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 19:20:02 by dan               #+#    #+#             */
/*   Updated: 2022/10/16 19:54:23 by dspilleb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, char const *src, size_t size)
{
	size_t	dest_size;
	size_t	src_size;
	size_t	i;

	i = 0;
	if (size == 0)
		return (ft_strlen(src));
	if ((!*dest && !dest))
		return (0);
	dest_size = ft_strlen(dest);
	src_size = ft_strlen(src);
	if (size == 0 || dest_size > size)
		return (size + src_size);
	else if (!*src)
		return (dest_size);
	while (src[i] && (i + dest_size < size - 1))
	{
		dest[dest_size + i] = src[i];
		i++;
	}
	dest[dest_size + i] = '\0';
	return (src_size + dest_size);
}
