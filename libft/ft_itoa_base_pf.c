/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzimmerm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/03 16:58:39 by lzimmerm          #+#    #+#             */
/*   Updated: 2019/05/14 15:12:07 by qbragard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa_base_pf(long long value, int base, int capitalizer)
{
	char					*str;
	int						size;
	char					*tab;
	unsigned long long		tmp;

	size = 0;
	if (capitalizer)
		tab = "0123456789ABCDEF";
	else
		tab = "0123456789abcdef";
	tmp = (unsigned long long)value;
	while (tmp /= base)
		size++;
	tmp = (unsigned long long)value;
	size = size + 1;
	if (!(str = (char *)malloc(sizeof(char) * size + 1)))
		return (NULL);
	str[size] = '\0';
	while (size > 0)
	{
		str[size - 1] = tab[tmp % base];
		size--;
		tmp /= base;
	}
	return (str);
}
