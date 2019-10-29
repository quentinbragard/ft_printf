/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser_complement.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbragard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/14 13:17:47 by qbragard          #+#    #+#             */
/*   Updated: 2019/05/14 13:28:16 by qbragard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char				ft_parser_init(t_parser *parser, int *i)
{
	*i = 0;
	parser->type = 0;
	parser->width = 0;
	parser->prec = 0;
	if (!(parser->flag = ft_strnew(5)))
		return (0);
	if (!(parser->conv = ft_strnew(2)))
		return (0);
	return (1);
}

int					ft_pos(char c, char *str)
{
	int i;

	i = 0;
	if (!str)
		return (0);
	while (*str)
	{
		if (*str == c)
			return (i + 1);
		i++;
		str++;
	}
	return (0);
}

char				*ft_prec_width_int(t_parser parser, char *res)
{
	long long	i;
	long long	j;
	char		*tmp;

	i = -1;
	j = -1;
	if (ft_max(parser.prec, parser.width) < (long long)ft_strlen(res))
		return (res);
	if (parser.prec <= (long long)ft_strlen(res))
		parser.prec = 0;
	(parser.width -= parser.prec) < 0 ? (parser.width = 0) : 0;
	tmp = ft_strnew(parser.width + parser.prec + (long long)ft_strlen(res) + 1);
	while (++i < (parser.prec > (long long)ft_strlen(res) ?
				parser.width : parser.width - (long long)ft_strlen(res)))
		tmp[i] = ' ';
	while (parser.prec && (++j < (parser.prec - (long long)ft_strlen(res))))
		tmp[i++] = '0';
	j = -1;
	while (res[++j])
		tmp[i++] = res[j];
	tmp[i] = '\0';
	free(res);
	return (tmp);
}

long long			ft_int_conv(t_parser parser, long long nb)
{
	long long	n;

	if (ft_strnequ("hh", parser.conv, 2) && (n = (unsigned char)nb))
		ft_pos(parser.type, "di") ? (n = (char)nb) : 0;
	else if (ft_strnequ("h", parser.conv, 1) && (n = (unsigned short)nb))
		ft_pos(parser.type, "di") ? (n = (short)nb) : 0;
	else if (ft_strnequ("ll", parser.conv, 2) && (n = (unsigned long long)nb))
		ft_pos(parser.type, "di") ? (n = (long long)nb) : 0;
	else if (ft_strnequ("l", parser.conv, 1) && (n = (unsigned long)nb))
		ft_pos(parser.type, "di") ? (n = (long)nb) : 0;
	else if (ft_strnequ("j", parser.conv, 1) && (n = (uintmax_t)nb))
		ft_pos(parser.type, "di") ? (n = (intmax_t)nb) : 0;
	else if (ft_strnequ("z", parser.conv, 1) && (n = (size_t)nb))
		ft_pos(parser.type, "di") ? (n = (intmax_t)nb) : 0;
	else if (ft_pos(parser.type, "di"))
		n = (int)nb;
	else
		n = (unsigned int)nb;
	return (n);
}

int					ft_parser_free(t_parser parser)
{
	ft_strdel(&(parser.flag));
	ft_strdel(&(parser.conv));
	return (0);
}
