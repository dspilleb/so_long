/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dspilleb <dspilleb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 19:53:46 by dan               #+#    #+#             */
/*   Updated: 2022/10/24 12:27:47 by dspilleb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int			i;
	int			adress;
	const char	f = c;

	i = -1;
	adress = -1;
	while (s[++i])
		if (s[i] == f)
			adress = i;
	if (s[i] == f)
			adress = i;
	if (adress != -1)
		return ((char *)&s[adress]);
	else
		return (NULL);
}
