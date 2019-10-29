/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_integer_base.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbragard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/14 13:18:08 by qbragard          #+#    #+#             */
/*   Updated: 2019/05/14 13:27:47 by qbragard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_printf_o(t_parser parser, long long nb)
{
	char	*res;

	res = ft_itoa_base_pf(nb, 8, 0);
	if (nb && ft_pos('#', parser.flag)
			&& parser.prec <= (long long)ft_strlen(res))
		res = ft_prec_width_int(parser, ft_strjoin_rfree("0", res));
	else if (nb && ft_pos('#', parser.flag)
			&& parser.prec > (long long)ft_strlen(res))
	{
		res = ft_prec_width_int(parser, res);
		if (parser.width <= parser.prec
				&& parser.prec < (long long)ft_strlen(res))
			res = ft_strjoin_rfree("0", res);
	}
	else
		res = ft_prec_width_int(parser, res);
	return (res);
}

char	*ft_printf_b(t_parser parser, long long nb)
{
	char	*res;

	res = ft_itoa_base_pf(nb, 2, 0);
	if (nb && ft_pos('#', parser.flag)
			&& parser.prec <= (long long)ft_strlen(res))
		res = ft_prec_width_int(parser, ft_strjoin_rfree("0", res));
	else if (nb && ft_pos('#', parser.flag)
			&& parser.prec > (long long)ft_strlen(res))
	{
		res = ft_prec_width_int(parser, res);
		if (parser.width <= parser.prec
				&& parser.prec < (long long)ft_strlen(res))
			res = ft_strjoin_rfree("0", res);
	}
	else
		res = ft_prec_width_int(parser, res);
	return (res);
}

char	*ft_printf_x(t_parser parser, long long nb)
{
	char	*res;

	res = ft_itoa_base_pf(nb, 16, 0);
	if (nb && ft_pos('#', parser.flag)
			&& parser.prec <= (long long)ft_strlen(res))
		res = ft_prec_width_int(parser, ft_strjoin_rfree("0x", res));
	else if (nb && ft_pos('#', parser.flag)
			&& parser.prec > (long long)ft_strlen(res))
	{
		res = ft_prec_width_int(parser, res);
		if (parser.width <= parser.prec)
			res = ft_strjoin_rfree("0x", res);
		else
			res = ft_hash_flag_edge(res, 0);
	}
	else
		res = ft_prec_width_int(parser, res);
	return (res);
}

char	*ft_printf_x_cap(t_parser parser, long long nb)
{
	char	*res;

	res = ft_itoa_base_pf(nb, 16, 1);
	if (nb && ft_pos('#', parser.flag)
			&& parser.prec <= (long long)ft_strlen(res))
		res = ft_prec_width_int(parser, ft_strjoin_rfree("0X", res));
	else if (nb && ft_pos('#', parser.flag)
			&& parser.prec > (long long)ft_strlen(res))
	{
		res = ft_prec_width_int(parser, res);
		if (parser.width <= parser.prec)
			res = ft_strjoin_rfree("0X", res);
		else
			res = ft_hash_flag_edge(res, 1);
	}
	else
		res = ft_prec_width_int(parser, res);
	return (res);
}

int		ft_printf_addr(t_parser parser, long long nb)
{
	char	*res;

	res = ft_itoa_base_pf(nb, 16, 0);
	if (parser.prec <= (long long)ft_strlen(res))
		res = ft_prec_width_int(parser, ft_strjoin_rfree("0x", res));
	else
	{
		res = ft_prec_width_int(parser, res);
		if (parser.width <= parser.prec)
			res = ft_strjoin_rfree("0x", res);
		else
			res = ft_hash_flag_edge(res, 0);
	}
	if (ft_pos('-', parser.flag))
		res = ft_minus_flag(res);
	return (ft_freelen(res));
}
