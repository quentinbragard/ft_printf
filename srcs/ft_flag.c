/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbragard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/14 13:17:36 by qbragard          #+#    #+#             */
/*   Updated: 2019/05/14 13:17:39 by qbragard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*ft_zero_flag(t_parser parser, char *str, long long nb)
{
	int	i;
	int	j;

	i = -1;
	while (str[++i])
		if (str[i] == ' ')
			str[i] = '0';
	if ((j = ft_pos('-', str)))
	{
		str[j - 1] = '0';
		*str = '-';
	}
	if (ft_pos('#', parser.flag) && ft_pos(parser.type, "oxX") && nb)
	{
		if (ft_pos('x', str) && (str[ft_pos('x', str) - 1] = '0'))
			ft_pos(parser.type, "x") ? str[ft_pos('0', str)] = 'x' : 0;
		else if (ft_pos('X', str) && (str[ft_pos('X', str) - 1] = '0'))
			ft_pos(parser.type, "X") ? str[ft_pos('0', str)] = 'X' : 0;
	}
	if (ft_pos('+', parser.flag) && nb >= 0)
	{
		if ((str[ft_pos('+', str) - 1] = '0'))
			str[ft_pos('0', str) - 1] = '+';
	}
	return (str);
}

char		*ft_minus_flag(char *str)
{
	long long		i;
	long long		j;
	char			*tmp;
	char			*tmp2;

	i = 0;
	j = 0;
	while (str[i] == ' ')
		i++;
	tmp = str;
	str = ft_strtrim_space(str);
	tmp2 = str;
	while (*str)
		tmp[j++] = *str++;
	while (i-- > 0)
		tmp[j++] = ' ';
	ft_strdel(&tmp2);
	return (tmp);
}

char		*ft_hash_flag_edge(char *str, int flag)
{
	long long i;

	i = (long long)ft_strlen(str) - 1;
	while (ft_isdigit(str[i]) || (str[i] >= 'A' && str[i] <= 'F')
			|| (str[i] >= 'a' && str[i] <= 'f'))
		i--;
	if (flag == 1)
		str[i--] = 'X';
	else
		str[i--] = 'x';
	str[i] = '0';
	return (str);
}
