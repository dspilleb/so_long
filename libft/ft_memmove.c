/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dspilleb <dspilleb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 19:19:54 by dan               #+#    #+#             */
/*   Updated: 2022/10/16 15:17:44 by dspilleb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t		i;
	char		*dest2;
	char const	*src2;

	dest2 = dest;
	src2 = src;
	i = 0;
	if (!dest && !src)
		return (NULL);
	if (dest > src)
		while (n--)
			dest2[n] = src2[n];
	else
	{
		while (i < n)
		{
			dest2[i] = src2[i];
			i++;
		}
	}
	return (dest);
}
