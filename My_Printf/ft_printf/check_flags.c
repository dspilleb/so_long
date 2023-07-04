/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dan <dan@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 11:41:56 by dan               #+#    #+#             */
/*   Updated: 2022/10/02 18:28:24 by dan              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	check_flags(va_list ap, char c, int count)
{
	if (c == 'i' || c == 'd')
		count = check_flag1(ap, c, count);
	else if (c == 'p' || c == 'x')
		count = check_flag2(ap, c, count);
	else if (c == 'X' || c == '%' || c == 'c')
		count = check_flag3(ap, c, count);
	else if (c == 's')
		count = check_flag4(ap, c, count);
	else if (c == 'u')
		count = check_flag0(ap, c, count);
	return (count);
}
