/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dspilleb <dspilleb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 16:57:52 by dan               #+#    #+#             */
/*   Updated: 2022/10/24 15:20:38 by dspilleb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t	i;
	char	*s;

	i = 0;
	s = (char *)malloc(nmemb * size);
	if (!s)
		return (NULL);
	while (i < nmemb * size)
	{
		s[i] = 0;
		i++;
	}
	return (s);
}
