/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbragard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/02 12:32:46 by qbragard          #+#    #+#             */
/*   Updated: 2019/05/14 13:26:55 by qbragard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int				ft_freelen(char *str)
{
	int i;

	i = ft_strlen(str);
	ft_putstr(str);
	ft_strdel(&str);
	return (i);
}

static int		ft_print_text(char **format, int *k)
{
	int i;

	i = 0;
	while ((*format)[i] && (*format)[i] != '%')
		i++;
	if (**format)
		write(1, *format, i);
	if (!(*format)[i])
	{
		*k += i;
		return (0);
	}
	*format += i;
	*k += i;
	return (1);
}

static int		ft_printf_str(t_parser parser, char *str)
{
	char		*width;
	char		*prec;
	long long	i;
	long long	j;

	prec = ft_strdup(str ? str : "(null)");
	if (parser.prec && parser.prec < (long long)ft_strlen(prec))
		prec[parser.prec == -1 ? 0 : parser.prec] = '\0';
	if (parser.width > (long long)ft_strlen(prec) && (i = -1))
	{
		j = -1;
		width = ft_strnew(parser.width);
		while (++i < parser.width - (long long)ft_strlen(prec))
			width[i] = (ft_pos('0', parser.flag) ? '0' : ' ');
		while (prec && prec[++j])
			width[i++] = prec[j];
		ft_strdel(&prec);
		return (ft_freelen(ft_pos('-', parser.flag) \
					? ft_minus_flag(width) : width));
	}
	else
		return (ft_freelen(prec));
}

static int		ft_printf_char(t_parser parser, int c)
{
	char		*width;
	long long	i;

	if (parser.width > 0 && (i = -1))
	{
		width = ft_strnew(parser.width);
		while (++i < parser.width - 1)
			width[i] = (ft_pos('0', parser.flag) ? '0' : ' ');
		if (!c)
		{
			if (ft_pos('-', parser.flag))
				ft_putchar(c);
			i = ft_freelen(width);
			if (!ft_pos('-', parser.flag))
				ft_putchar(c);
			return (i + 1);
		}
		width[i] = c;
		if (ft_pos('-', parser.flag))
			ft_minus_flag(width);
		return (ft_freelen(width));
	}
	else
		ft_putchar(c);
	return (1);
}

int				ft_printf(char *format, ...)
{
	t_parser	parser;
	va_list		ap;
	int			i;

	if (!ft_parser_init(&parser, &i))
		return (-1);
	va_start(ap, format);
	while (ft_print_text(&format, &i))
	{
		parser = ft_parser(parser, &format);
		if (ft_pos(parser.type, "diouxXbp"))
			i += ft_printf_longlong(parser, va_arg(ap, long long));
		else if (parser.type == 's')
			i += ft_printf_str(parser, va_arg(ap, char *));
		else if (parser.type == 'f' || parser.type == 'F')
			i += ft_printf_float(parser, (ft_pos('L', parser.conv)
						? va_arg(ap, long double) : va_arg(ap, double)));
		else
			parser.type == 'c' ? (i += ft_printf_char(parser, va_arg(ap, int)))
				: (i += ft_printf_char(parser, parser.type));
	}
	ft_parser_free(parser);
	va_end(ap);
	return (i);
}
