/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_integer.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbragard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/14 13:18:03 by qbragard          #+#    #+#             */
/*   Updated: 2019/05/14 13:30:03 by qbragard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char		*ft_printf_di(t_parser parser, long long nb)
{
	char	*res;
	char	sign;
	int		i;

	if ((sign = '+') && nb < 0)
		sign = '-';
	nb < -9223372036854775807 ? (res = ft_strdup("9223372036854775808"))
	: (res = ft_itoa_pf(ft_abs(nb)));
	res = ft_prec_width_int(parser, res);
	if (*res != ' ' && ft_pos(' ', parser.flag) && !ft_pos('+', parser.flag))
		res = ft_strjoin_rfree(" ", res);
	if (*res != ' ' && ft_pos('+', parser.flag) && nb >= 0)
		res = ft_strjoin_rfree("+", res);
	else if ((ft_pos('+', parser.flag) || sign == '-') && !(i = 0))
	{
		if (res[i] != ' ' && sign == '-' && (res = ft_strjoin_rfree("-", res)))
			return (res);
		while (res[i] == ' ')
			i++;
		res[i - 1] = sign;
	}
	return (res);
}

static char		*ft_printf_u(t_parser parser, long long nb)
{
	char	*tmp;
	char	*res;

	tmp = ft_itoa_base_pf(nb, 10, 0);
	res = ft_prec_width_int(parser, tmp);
	return (res);
}

int				ft_printf_int(t_parser parser, long long nb)
{
	char		*(*f[7])(t_parser, long long);
	long long	conv;
	char		*res;

	f[0] = ft_printf_di;
	f[1] = ft_printf_di;
	f[2] = ft_printf_o;
	f[3] = ft_printf_u;
	f[4] = ft_printf_x;
	f[5] = ft_printf_x_cap;
	f[6] = ft_printf_b;
	conv = ft_int_conv(parser, nb);
	res = f[ft_pos(parser.type, "diouxXb") - 1](parser, conv);
	if (ft_pos('-', parser.flag))
		res = ft_minus_flag(res);
	if (ft_pos('0', parser.flag) && !ft_pos('-', parser.flag)
			&& parser.prec == 0)
		res = ft_zero_flag(parser, res, conv);
	if (ft_pos(' ', parser.flag) && ft_pos('0', parser.flag)
			&& ft_pos(parser.type, "di") && conv >= 0)
		*res = ' ';
	if (!conv && parser.prec == -1
		&& (!ft_pos('#', parser.flag) || ft_pos(parser.type, "xX")))
		res[ft_strlen(res) - 1] = (!parser.width ? '\0' : ' ');
	return (ft_freelen(res));
}

int				ft_printf_longlong(t_parser parser, long long nb)
{
	int i;

	i = 0;
	if (parser.type == 'p')
		i = ft_printf_addr(parser, nb);
	else
		i = ft_printf_int(parser, nb);
	return (i);
}
