/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzimmerm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/01 15:11:28 by lzimmerm          #+#    #+#             */
/*   Updated: 2019/04/01 15:22:38 by lzimmerm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim_space(char const *s)
{
	char	*trim;
	size_t	i;
	size_t	len;

	i = 0;
	if (!s)
		return (NULL);
	while (*s == ' ')
		s++;
	len = ft_strlen((char *)s);
	if (!len)
		return (ft_strnew(1));
	while (s[len - 1] == ' ')
		len--;
	if (!(trim = ft_strnew(len)))
		return (NULL);
	while (i < len)
		trim[i++] = *s++;
	return (trim);
}
