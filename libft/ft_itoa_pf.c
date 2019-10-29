/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbragard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 16:20:28 by qbragard          #+#    #+#             */
/*   Updated: 2019/05/14 13:36:13 by qbragard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_itoa_pf(long long n)
{
	long long	i;
	long long	nb;
	char		*ret;

	if (!n)
		return ((ret = ft_strdup("0")));
	i = ft_intlen(n) - 1;
	nb = n;
	if (!(ret = malloc(sizeof(char) * (ft_intlen(nb) + 1))))
		return (NULL);
	if (nb < 0)
	{
		ret[0] = '-';
		nb = -nb;
	}
	while (nb > 0)
	{
		ret[i--] = (nb % 10) + '0';
		nb = nb / 10;
	}
	ret[ft_intlen(n)] = '\0';
	return (ret);
}
