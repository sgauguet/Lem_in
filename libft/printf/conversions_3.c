/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversions_3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgauguet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/01 17:23:17 by sgauguet          #+#    #+#             */
/*   Updated: 2018/01/15 11:18:07 by sgauguet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	ft_print_short_int(va_list ap, char c, t_env *param, int base)
{
	intmax_t	result;
	char		*str;

	result = va_arg(ap, intmax_t);
	if (c == 'x' || c == 'X' || c == 'o' || c == 'O' || c == 'u' || c == 'U')
		str = ft_itoa_base_2((unsigned short)result, base, c);
	else
		str = ft_itoa_base((short int)result, base, c);
	if (!str)
		return (-1);
	if ((result < 0 || str[0] == '-') &&
			param->precision >= (int)ft_strlen(str))
		str = ft_precision_int_neg(str, param, result);
	if (result >= 0 && param->precision >= 0)
		str = ft_precision_int(str, param, result);
	if (param->flag_more == 0 && param->flag_space == 1 && param->width == -1)
		str = ft_print_sign(str, param, 32);
	if (param->flag_hashtag == 1 && (param->flag_zero == 0 ||
				param->precision > 0))
		str = ft_print_hashtag(str, param, c);
	if (param->flag_more == 1)
		str = ft_print_sign(str, param, '+');
	return (ft_print_str(str, param));
}

int	ft_print_long_int(va_list ap, char c, t_env *param, int base)
{
	intmax_t	result;
	char		*str;

	result = va_arg(ap, intmax_t);
	if (c == 'o' || c == 'O' || c == 'u' || c == 'U' || c == 'x' || c == 'X')
		str = ft_itoa_base_2((unsigned long)result, base, c);
	else
		str = ft_itoa_base((long)result, base, c);
	if (!str)
		return (-1);
	if (result < 0 && param->precision >= (int)ft_strlen(str))
		str = ft_precision_int_neg(str, param, result);
	if (result >= 0 && param->precision >= 0)
		str = ft_precision_int(str, param, result);
	if (param->flag_space == 1 && param->flag_more == 0)
		str = ft_print_sign(str, param, 32);
	if (param->flag_hashtag == 1 && (param->flag_zero == 0 ||
				param->precision > 0) && (base == 16 || base == 8))
		str = ft_print_hashtag(str, param, c);
	if (param->flag_more == 1 && c != 'x' && c != 'X' && c != 'o' && c != 'O')
		str = ft_print_sign(str, param, '+');
	return (ft_print_str(str, param));
}

int	ft_print_long_long(va_list ap, char c, t_env *param, int base)
{
	intmax_t	result;
	char		*str;

	result = va_arg(ap, intmax_t);
	if (c == 'x' || c == 'X' || c == 'o' || c == 'O' || c == 'u' || c == 'U')
		str = ft_itoa_base_2((unsigned long long)result, base, c);
	else
		str = ft_itoa_base((long long)result, base, c);
	if (!str)
		return (-1);
	if (result < 0 && param->precision >= (int)ft_strlen(str))
		str = ft_precision_int_neg(str, param, result);
	if (result >= 0 && param->precision >= 0)
		str = ft_precision_int(str, param, result);
	if (param->flag_more == 0 && param->flag_space == 1 && param->width == -1)
		str = ft_print_sign(str, param, 32);
	if (param->flag_hashtag == 1 && (param->flag_zero == 0 ||
				param->precision > 0) && base == 16)
		str = ft_print_hashtag(str, param, c);
	if (param->flag_more == 1)
		str = ft_print_sign(str, param, '+');
	return (ft_print_str(str, param));
}

int	ft_print_intmax_t(va_list ap, char c, t_env *param, int base)
{
	intmax_t	result;
	char		*str;

	result = va_arg(ap, intmax_t);
	if (c == 'o' || c == 'O' || c == 'u' || c == 'U' || c == 'x' || c == 'X')
		str = ft_itoa_base_2((uintmax_t)result, base, c);
	else
		str = ft_itoa_base(result, base, c);
	if (!str)
		return (-1);
	if (result < 0 && param->precision >= (int)ft_strlen(str))
		str = ft_precision_int_neg(str, param, result);
	if (result >= 0 && param->precision >= 0)
		str = ft_precision_int(str, param, result);
	if (param->flag_more == 0 && param->flag_space == 1 && param->width == -1)
		str = ft_print_sign(str, param, 32);
	if (param->flag_hashtag == 1 && (param->flag_zero == 0 ||
				param->precision > 0) && base == 16)
		str = ft_print_hashtag(str, param, c);
	if (param->flag_more == 1)
		str = ft_print_sign(str, param, '+');
	return (ft_print_str(str, param));
}

int	ft_print_size_t(va_list ap, char c, t_env *param, int base)
{
	intmax_t	result;
	char		*str;

	result = va_arg(ap, intmax_t);
	if (c == 'o' || c == 'O' || c == 'u' || c == 'U' || c == 'x' || c == 'X')
		str = ft_itoa_base_2((ssize_t)result, base, c);
	else
		str = ft_itoa_base((size_t)result, base, c);
	if (!str)
		return (-1);
	if (result < 0 && param->precision >= (int)ft_strlen(str))
		str = ft_precision_int_neg(str, param, result);
	if (result >= 0 && param->precision >= 0)
		str = ft_precision_int(str, param, result);
	if (param->flag_more == 0 && param->flag_space == 1 && param->width == -1)
		str = ft_print_sign(str, param, 32);
	if (param->flag_hashtag == 1 && (param->flag_zero == 0 ||
				param->precision > 0) && base == 16)
		str = ft_print_hashtag(str, param, c);
	if (param->flag_more == 1)
		str = ft_print_sign(str, param, '+');
	return (ft_print_str(str, param));
}
