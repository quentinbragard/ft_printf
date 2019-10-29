/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_float_numbers.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbragard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/14 13:17:57 by qbragard          #+#    #+#             */
/*   Updated: 2019/05/14 13:29:29 by qbragard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char			*ft_round_float(char *res)
{
	int		i;
	int		round;

	i = ft_strlen(res) - 1;
	if (res[i] < '5' && !(res[i] = 0))
		return (res);
	if (res[--i] < '9' && !(res[i] = 0))
	{
		res[i] == '9' ? (res[i] = '0') : (res[i] += 1);
		return (res);
	}
	round = 1;
	while (round)
	{
		res[i--] = '0';
		if (res[i] == '.')
			i--;
		if (res[i] != '9' && !(round = 0))
			res[i]++;
	}
	res[ft_strlen(res) - 1] = 0;
	return (res);
}

static char		*ft_ftoa_prec(char *res, long double f1, int i, t_parser parser)
{
	int j;

	j = 0;
	while (i-- > 0 || parser.prec--)
	{
		f1 *= 10.L;
		res[j++] = (int)f1 + '0';
		f1 = f1 - (int)f1;
		if (!i && parser.prec)
			res[j++] = '.';
	}
	res[j] = '\0';
	return (ft_round_float(res));
}

static char		*ft_printf_float_pos(t_parser parser, long double f)
{
	int				i;
	char			*res;
	long double		f1;

	f1 = f;
	if (!(i = 0) && parser.prec == 0)
		parser.prec = 6;
	parser.prec++;
	while (f > 1.L && (f /= 10.L))
		i++;
	res = ft_strnew(i + parser.prec + 2);
	if (!i && (*res++ = '0'))
		*res++ = '.';
	res = ft_ftoa_prec(res, f, i, parser);
	return ((!(int)f1) ? res - 2 : res);
}

static char		*ft_printf_float_neg(t_parser parser, long double f)
{
	int				i;
	char			*res;
	long double		f1;

	f1 = -f;
	if (!(i = 0) && parser.prec == 0)
		parser.prec = 6;
	parser.prec++;
	while (f1 > 1.L && (f1 /= 10.L))
		i++;
	res = ft_strnew(i + parser.prec + 3);
	*res++ = '-';
	if (!i && (*res++ = '0'))
		*res++ = '.';
	res = ft_ftoa_prec(res, f1, i, parser);
	return ((!(int)f) ? res - 3 : res - 1);
}

int				ft_printf_float(t_parser parser, long double f)
{
	char	*res;

	if (parser.prec == -1 && (parser.type = 'd'))
		return (ft_printf_int(parser, (long long)f));
	f < 0.L ? (res = ft_printf_float_neg(parser, f))
		: (res = ft_printf_float_pos(parser, f));
	return (ft_freelen(res));
}
