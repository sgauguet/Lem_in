/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversions_1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgauguet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 14:38:05 by sgauguet          #+#    #+#             */
/*   Updated: 2018/01/11 12:15:28 by sgauguet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	ft_print_backslash_zero(t_env *param)
{
	int		len;
	char	*str;

	str = ft_strnew(0);
	param->precision = -1;
	if (param->width > 0 && param->flag_less == 0 &&
			param->width > (int)ft_strlen(str))
	{
		str = ft_field_width_right(str, param, 1, 0);
		ft_putstr(&str[1]);
		ft_putchar('\0');
		len = (int)ft_strlen(str);
		ft_strdel(&str);
		return (len);
	}
	ft_putchar('\0');
	if (param->width > 0 && param->flag_less == 1)
	{
		str = ft_field_width_left(str, param);
		ft_putstr(&str[1]);
		len = (int)ft_strlen(str);
		ft_strdel(&str);
		return (len);
	}
	return (1);
}

int	ft_print_char(va_list ap, char c, t_env *param, int base)
{
	intmax_t	result;
	char		*str;

	result = va_arg(ap, intmax_t);
	if (result == 0x00 && c == 'c')
		return (ft_print_backslash_zero(param));
	if (c == 'c')
	{
		str = ft_strnew(1);
		str[0] = (char)result;
	}
	else if (c == 'u' || c == 'U' || c == 'o' || c == 'O'
			|| c == 'x' || c == 'X')
		str = ft_itoa_base_2((unsigned char)result, base, c);
	else
		str = ft_itoa_base((char)result, base, c);
	if (c != 'c' && str[0] == '-' && param->precision >= (int)ft_strlen(str))
		str = ft_precision_int_neg(str, param, result);
	if (c != 'c' && result >= 0 && param->precision >= 0)
		str = ft_precision_int(str, param, result);
	if (c == 'c')
		param->precision = -1;
	return (ft_print_str(str, param));
}

int	ft_print_int(va_list ap, char c, t_env *param)
{
	int		result;
	int		len;
	char	*str;

	result = va_arg(ap, int);
	if (!(str = ft_itoa(result)) || !c)
		return (-1);
	if (result < 0 && param->precision >= (int)ft_strlen(str))
		str = ft_precision_int_neg(str, param, result);
	if (result >= 0 && param->precision >= 0)
		str = ft_precision_int(str, param, result);
	if (param->flag_more == 1 && result >= 0)
		str = ft_print_sign(str, param, '+');
	if (result >= 0 && param->flag_space == 1 && param->flag_more == 0)
		str = ft_print_sign(str, param, 32);
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

int	ft_print_percent(va_list ap, char c, t_env *param)
{
	char	*str;
	int		len;

	if (c == '%' && ap)
	{
		str = ft_strnew(1);
		str[0] = '%';
		param->precision = -1;
		if (param->width != -1 && param->flag_less == 0 &&
				param->width > (int)ft_strlen(str))
			str = ft_field_width_right(str, param, 1, 0);
		if (param->width != -1 && param->flag_less == 1)
			str = ft_field_width_left(str, param);
		ft_putstr(str);
		len = ft_strlen(str) - 2;
		ft_strdel(&str);
		return (len);
	}
	return (0);
}

int	ft_print_string(va_list ap, char c, t_env *param)
{
	char	*str;
	int		len;

	str = ft_strdup(va_arg(ap, char *));
	if (str == NULL)
		str = ft_strdup("(null)");
	if (param->precision != -1)
		str = ft_precision_string(str, param);
	if (c == 's')
		param->precision = -1;
	if (param->width != -1 && param->flag_less == 0 &&
			param->width > (int)ft_strlen(str))
		str = ft_field_width_right(str, param, 1, 0);
	if (param->width != -1 && param->flag_less == 1)
		str = ft_field_width_left(str, param);
	ft_putstr(str);
	len = ft_strlen(str);
	ft_strdel(&str);
	if (!c)
		return (0);
	return (len);
}
