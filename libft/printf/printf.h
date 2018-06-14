/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgauguet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/22 10:31:15 by sgauguet          #+#    #+#             */
/*   Updated: 2018/01/30 13:07:44 by sgauguet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H

# define FT_PRINTF_H

# include <limits.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <wchar.h>
# include "../libft.h"

typedef struct	s_env
{
	int		arg;
	int		nb_arg;
	int		base;
	int		flag_hashtag;
	int		flag_zero;
	int		flag_more;
	int		flag_less;
	int		flag_space;
	int		count_wildcard;
	int		sep;
	int		width;
	int		precision;
	char	*length_mod;
}				t_env;

/*
**wchar.c**
*/

char			*four_bytes(wchar_t i);
char			*three_bytes(wchar_t i);
char			*two_bytes(wchar_t i);
char			*one_byte(wchar_t i);
char			*ft_wchar_t(wchar_t i);

/*
**conversion_1.c**
*/

int				ft_print_backslash_zero(t_env *param);
int				ft_print_int(va_list ap, char c, t_env *param);
int				ft_print_char(va_list ap, char c, t_env *param, int base);
int				ft_print_percent(va_list ap, char c, t_env *param);
int				ft_print_string(va_list ap, char c, t_env *param);

/*
**conversion_2.c**
*/

int				ft_print_oct(va_list ap, char c, t_env *param);
int				ft_print_hexa(va_list ap, char c, t_env *param);
int				ft_print_bin(va_list ap, char c, t_env *param);
int				ft_print_unsigned_int(va_list ap, char c, t_env *param);
int				ft_print_str(char *str, t_env *param);

/*
**conversion_3.c**
*/

int				ft_print_short_int(va_list ap, char c, t_env *param, int base);
int				ft_print_long_int(va_list ap, char c, t_env *param, int base);
int				ft_print_long_long(va_list ap, char c, t_env *param, int base);
int				ft_print_intmax_t(va_list ap, char c, t_env *param, int base);
int				ft_print_size_t(va_list ap, char c, t_env *param, int base);

/*
**conversion_4.c**
*/

int				ft_print_invalid_specifier(char c, t_env *param);
int				ft_print_p(va_list ap, char c, t_env *param);
int				ft_print_wint_t(va_list ap, char c, t_env *param);
char			*ft_join_wchar_t(wchar_t *result);
int				ft_print_tab_wchar_t(va_list ap, char c, t_env *param);

/*
**bonus_conversions.c**
*/

int				ft_undefined_flags(const char *format, int i, t_env *param);
void			ft_wildcard(va_list ap, t_env *param, int c, int flag);
int				ft_search_wildcard(va_list ap, const char *format,
				int i, t_env *param);
int				ft_print_double(va_list ap, char c, t_env *param);

/*
**check.c**
*/

int				ft_check_flags(char c);
int				ft_check_conversion_specifications(char c);
int				ft_check(const char *format);
int				ft_count_arg(const char *format);

/*
**print_flags.c**
*/

char			*ft_print_sign(char *str, t_env *param, char c);
char			*ft_precision_string(char *str, t_env *param);
char			*ft_precision_int(char *str, t_env *param, int neg);
char			*ft_precision_int_neg(char *str, t_env *param, int neg);
char			*ft_print_hashtag(char *str, t_env *param, char c);

/*
**field_width.c**
*/

void			ft_reverse(char *result, char *str, t_env *param, int s);
char			*ft_field_width_right(char *str, t_env *param, int s, int j);
char			*ft_field_width_left(char *str, t_env *param);

/*
**search_flags.c**
*/

char			*ft_select(const char *format, int c);
int				ft_search_flags(const char *format, int i, t_env *param);
int				ft_search_width(const char *format, int i, t_env *param);
int				ft_search_precision(const char *format, int i, t_env *param);
int				ft_search_length(const char *format, int k, t_env *param);

/*
**types.c**
*/

int				ft_length_modifier(va_list ap, char c, t_env *param);
int				ft_bonus_conversion(va_list ap, char c, t_env *param);
int				ft_mandatory_conversion(va_list ap, char c, t_env *param);
int				ft_define_type(va_list ap, char c, t_env *param);

/*
**printf.c**
*/

int				ft_define_param(va_list ap, const char *format, int i,
				t_env *param);
int				ft_init_param(t_env	*param, int all);
int				ft_print_arg(va_list ap, const char *format, t_env *param,
				int result);
int				ft_nb_arg(const char *format);
int				ft_printf(const char *format, ...);

#endif
