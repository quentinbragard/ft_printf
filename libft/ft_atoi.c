/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbragard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 19:45:47 by qbragard          #+#    #+#             */
/*   Updated: 2019/04/03 08:56:15 by qbragard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int					u;
	unsigned long long	result;

	u = 1;
	result = 0;
	while (*str == ' ' || *str == '\f' || *str == '\n' || *str
			== '\r' || *str == '\t' || *str == '\v')
		str++;
	if ((*str == '+') || (*str == '-'))
	{
		if (*str == '-')
			u = -1;
		str++;
	}
	while (*str > 47 && *str < 58)
	{
		result = result * 10 + (*str - 48);
		str++;
	}
	if (result > 9223372036854775807)
		return (u == 1 ? -1 : 0);
	return (u * result);
}
