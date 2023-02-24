/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dspilleb <dspilleb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 18:53:55 by dan               #+#    #+#             */
/*   Updated: 2022/10/16 19:50:50 by dspilleb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*str;

	str = malloc((ft_strlen(s)) + 1);
	if (!str)
		return (NULL);
	ft_memcpy(str, s, ft_strlen(s) + 1);
	return (str);
}
