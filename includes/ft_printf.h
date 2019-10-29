/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbragard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/01 17:32:18 by qbragard          #+#    #+#             */
/*   Updated: 2019/05/14 15:13:54 by qbragard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft.h"
# include <stdarg.h>

typedef struct		s_parser
{
	char			*flag;
	long long		width;
	long long		prec;
	char			*conv;
	char			type;
}					t_parser;

t_parser			ft_parser(t_parser parser, char **str);
int					ft_pos(char c, char *str);
int					ft_freelen(char *str);
int					ft_printf_longlong(t_parser parser, long long nb);
int					ft_printf_float(t_parser parser, long double f);
char				*ft_printf_o(t_parser parser, long long nb);
char				*ft_round_float(char *res);
char				*ft_printf_b(t_parser parser, long long nb);
char				*ft_printf_x(t_parser parser, long long nb);
char				*ft_printf_x_cap(t_parser parser, long long nb);
int					ft_printf_addr(t_parser parser, long long nb);
int					ft_printf_int(t_parser parser, long long nb);
char				*ft_prec_width(t_parser parser, char *res);
char				*ft_prec_width_int(t_parser parser, char *res);
long long			ft_int_conv(t_parser parser, long long nb);
char				*ft_zero_flag(t_parser parser, char *str, long long nb);
char				*ft_minus_flag(char *str);
char				*ft_hash_flag_edge(char *str, int flag);
int					ft_printf(char *format, ...);
char				ft_parser_init(t_parser *parser, int *i);
int					ft_parser_free(t_parser parser);

#endif
