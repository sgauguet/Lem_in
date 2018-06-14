/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversions_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgauguet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/01 15:58:31 by sgauguet          #+#    #+#             */
/*   Updated: 2018/01/10 17:02:07 by sgauguet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	ft_print_str(char *str, t_env *param)
{
	int	len;

	if (param->width != -1 && param->flag_less == 0 &&
			param->width > (int)ft_strlen(str))
		str = ft_field_width_right(str, param, 0, 0);
	if (param->width != -1 && param->flag_less == 1)
		str = ft_field_width_left(str, param);
	ft_putstr(str);
	len = ft_strlen(str);
	ft_strdel(&str);
	return (len);
}

int	ft_print_oct(va_list ap, char c, t_env *param)
{
	unsigned int	result;
	int				i;
	char			*str;

	result = va_arg(ap, unsigned int);
	i = 0;
	if (!(str = ft_itoa_base_2(result, 8, c)))
		return (-1);
	if (param->precision >= 0)
		str = ft_precision_int(str, param, result);
	if (param->flag_hashtag == 1)
		str = ft_print_hashtag(str, param, c);
	if (param->width != -1 && param->flag_less == 0 &&
			param->width > (int)ft_strlen(str))
		str = ft_field_width_right(str, param, 0, 0);
	if (param->width != -1 && param->flag_less == 1)
		str = ft_field_width_left(str, param);
	ft_putstr(str);
	i = ft_strlen(str);
	ft_strdel(&str);
	return (i);
}

int	ft_print_hexa(va_list ap, char c, t_env *param)
{
	unsigned int	result;
	int				i;
	char			*str;

	result = va_arg(ap, unsigned int);
	i = 0;
	if (!(str = ft_itoa_base_2(result, 16, c)))
		return (-1);
	if (param->precision != -1)
		str = ft_precision_int(str, param, result);
	if (param->flag_hashtag == 1 && result != 0)
		str = ft_print_hashtag(str, param, c);
	if (param->width != -1 && param->flag_less == 0 &&
			param->width > (int)ft_strlen(str))
		str = ft_field_width_right(str, param, 0, 0);
	if (param->width != -1 && param->flag_less == 1)
		str = ft_field_width_left(str, param);
	ft_putstr(str);
	i = ft_strlen(str);
	ft_strdel(&str);
	return (i);
}

int	ft_print_bin(va_list ap, char c, t_env *param)
{
	intmax_t	result;
	int			i;
	char		*str;

	result = va_arg(ap, intmax_t);
	str = ft_itoa_base(result, 2, 0);
	if (param->precision != -1)
		str = ft_precision_int(str, param, result);
	if (param->flag_hashtag == 1 && result != 0)
		str = ft_print_hashtag(str, param, c);
	if (param->width != -1 && param->flag_less == 0 &&
			param->width > (int)ft_strlen(str))
		str = ft_field_width_right(str, param, 0, 0);
	if (param->width != -1 && param->flag_less == 1)
		str = ft_field_width_left(str, param);
	ft_putstr(str);
	i = ft_strlen(str);
	ft_strdel(&str);
	return (i);
}

int	ft_print_unsigned_int(va_list ap, char c, t_env *param)
{
	unsigned int	result;
	int				i;
	char			*str;

	result = va_arg(ap, unsigned int);
	i = 0;
	if (!(str = ft_itoa_base((intmax_t)result, 10, c)))
		return (-1);
	if (param->precision != -1)
		str = ft_precision_int(str, param, result);
	if (param->width != -1 && param->flag_less == 0 &&
			param->width > (int)ft_strlen(str))
		str = ft_field_width_right(str, param, 0, 0);
	if (param->width != -1 && param->flag_less == 1)
		str = ft_field_width_left(str, param);
	ft_putstr(str);
	i = ft_strlen(str);
	ft_strdel(&str);
	return (i);
}
