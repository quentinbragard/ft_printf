/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbragard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/01 18:00:22 by qbragard          #+#    #+#             */
/*   Updated: 2019/05/14 13:23:07 by qbragard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char					*flag_parser(char **str, char *flag)
{
	int		i;

	ft_strclr(flag);
	i = 0;
	if (*str)
		(*str)++;
	while (**str == '#' || **str == '0' || **str == ' ' || **str == '+'
			|| **str == '-')
	{
		if (!ft_pos(**str, flag))
			flag[i++] = **str;
		(*str)++;
	}
	return (flag);
}

static int					width_parser(char **str)
{
	int		i;

	i = ft_atoi(*str);
	while (**str >= '0' && **str <= '9')
		(*str)++;
	return (i);
}

static int					prec_parser(char **str)
{
	int j;

	if (**str != '.')
		return (0);
	(*str)++;
	j = width_parser(str);
	return (j == 0 ? -1 : j);
}

static char					*conv_parser(char **str, char *conv)
{
	int		i;

	i = 0;
	ft_strclr(conv);
	while ((**str) == 'h' && (i += 1))
		(*str)++;
	if (i > 0 && i >= 1 && (conv = ft_strcpy(conv, "h")))
		return (i > 1 ? (conv = ft_strcpy(conv, "hh")) : conv);
	while ((**str) == 'l' && (i += 1))
		(*str)++;
	if (i > 0 && i >= 1 && (conv = ft_strcpy(conv, "l")))
		return (i > 1 ? (conv = ft_strcpy(conv, "ll")) : conv);
	while (**str == 'L' && (i += 1))
		(*str)++;
	if (i > 0)
		return ((conv = ft_strcpy(conv, "L")));
	while (**str == 'j' && (i += 1))
		(*str)++;
	if (i > 0)
		return ((conv = ft_strcpy(conv, "j")));
	while (**str == 'z' && (i += 1))
		(*str)++;
	return (i == 0 ? conv : (conv = ft_strcpy(conv, "z")));
}

t_parser					ft_parser(t_parser parser, char **str)
{
	parser.flag = flag_parser(str, parser.flag);
	parser.width = width_parser(str);
	parser.prec = prec_parser(str);
	parser.conv = conv_parser(str, parser.conv);
	parser.type = **str;
	(*str)++;
	if (ft_pos('0', parser.flag) && ft_pos('-', parser.flag))
		parser.flag[ft_pos('0', parser.flag) - 1] = '-';
	if (ft_pos(parser.type, "DOU")
			&& (parser.conv = ft_strcpy(parser.conv, "l")))
		parser.type = ft_tolower(parser.type);
	return (parser);
}
