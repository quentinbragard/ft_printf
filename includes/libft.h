/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbragard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 20:05:04 by qbragard          #+#    #+#             */
/*   Updated: 2019/05/14 15:14:44 by qbragard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

void				ft_putchar(char c);
int					ft_atoi(const char *str);
void				ft_putstr(char const *s);
size_t				ft_strlen(const char *s);
char				*ft_strdup(const char *s1);
long				ft_pow(int nb, int p);
char				*ft_itoa_pf(long long n);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
long long			ft_intlen(long long n);
int					ft_isdigit(int c);
int					ft_tolower(int c);
char				*ft_strnew(size_t size);
void				*ft_memset(void *b, int c, size_t len);
void				ft_strdel(char **as);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
char				*ft_strjoin_rfree(char const *s1, char *s2);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strtrim_space(char const *s);
long				ft_pow(int nb, int p);
long long			ft_max(long long a, long long b);
char				*ft_itoa_base_pf(long long value, int base,
		int capitalizer);
long long			ft_abs(long long nb);
void				ft_strclr(char *s);
char				*ft_strcpy(char *dst, const char *src);

#endif
