/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_conversions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgauguet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/05 15:43:26 by sgauguet          #+#    #+#             */
/*   Updated: 2018/01/15 10:47:07 by sgauguet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	ft_wildcard(va_list ap, t_env *param, int c, int flag)
{
	int	bin;

	if (c == 1)
	{
		if (param->width == -1 || flag == 4)
			param->width = va_arg(ap, intmax_t);
		else
			bin = va_arg(ap, intmax_t);
		if (param->width < 0)
		{
			param->width = -1 * param->width;
			param->flag_less = 1;
		}
	}
	if (c == 2)
	{
		if (param->precision <= 0)
			param->precision = va_arg(ap, intmax_t);
		if (param->precision < 0)
			param->precision = -1;
	}
}

int		ft_search_wildcard(va_list ap, const char *format, int j, t_env *param)
{
	while (!ft_check_conversion_specifications(format[j]) && format[j] != '\0')
	{
		if (format[j] == '*')
		{
			if (format[j - 1] != '.')
			{
				ft_wildcard(ap, param, 1, ft_check_flags(format[j - 1]));
				while (ft_check_flags(format[j++]) == 2)
					param->count_wildcard = param->count_wildcard + 1;
				if (format[j] == '.')
					j++;
			}
			if (format[j - 1] == '.')
			{
				ft_wildcard(ap, param, 2, 0);
				while (ft_check_flags(format[j++]) == 2)
					param->count_wildcard = param->count_wildcard + 1;
			}
			return (param->count_wildcard);
		}
		j++;
	}
	return (0);
}

int		ft_undefined_flags(const char *format, int i, t_env *param)
{
	int j;
	int k;

	j = i;
	k = 0;
	while (!ft_check_conversion_specifications(format[j]) &&
			ft_check_flags(format[j]) <= 3 && format[j] != '\0')
		j++;
	while (!ft_check_conversion_specifications(format[j]) && format[j] != '\0')
	{
		if (format[j] == '#')
			param->flag_hashtag = 1;
		if (format[j] == '-')
			param->flag_less = 1;
		if (format[j] == '+')
			param->flag_more = 1;
		if (format[j] == ' ')
			param->flag_space = 1;
		j++;
	}
	return (k);
}

int		ft_print_double(va_list ap, char c, t_env *param)
{
	double	result;
	char	*str;

	result = va_arg(ap, double);
	str = ft_itoa_base(result, 10, c);
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
