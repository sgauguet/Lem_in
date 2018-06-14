/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgauguet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/22 10:35:35 by sgauguet          #+#    #+#             */
/*   Updated: 2018/01/11 14:34:14 by sgauguet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	ft_define_param(va_list ap, const char *format, int i, t_env *param)
{
	int	result;
	int	j;

	result = 0;
	j = i;
	while (!ft_check_conversion_specifications(format[j])
			&& ft_check_flags(format[j]) != 6 && format[j] != '\0')
		j++;
	ft_search_flags(format, i, param);
	ft_search_width(format, i, param);
	ft_search_precision(format, i, param);
	ft_search_length(format, j, param);
	j = i;
	ft_search_wildcard(ap, format, j, param);
	ft_undefined_flags(format, i, param);
	j = i;
	while (ft_check_flags(format[j]) && format[j] != '\0')
	{
		result++;
		j++;
	}
	return (result);
}

int	ft_init_param(t_env *param, int all)
{
	if (all == 1)
	{
		param->arg = 0;
		param->nb_arg = 0;
	}
	param->base = 10;
	param->flag_hashtag = 0;
	param->flag_zero = 0;
	param->flag_more = 0;
	param->flag_less = 0;
	param->flag_space = 0;
	param->count_wildcard = 0;
	param->sep = 0;
	param->width = -1;
	param->precision = -1;
	param->length_mod = "0";
	return (1);
}

int	ft_print_arg(va_list ap, const char *format, t_env *param, int result)
{
	int i;

	i = 0;
	while (i < (int)ft_strlen(format))
	{
		while (format[i] != '%' && format[i] != '\0')
		{
			ft_putchar(format[i]);
			i++;
		}
		if (format[i] == '%' && param->nb_arg < param->arg)
		{
			i++;
			result = result - ft_define_param(ap, format, i, param);
			while (ft_check_flags(format[i]) && format[i] != '\0')
				i++;
			result = result + ft_define_type(ap, format[i], param);
			ft_init_param(param, 0);
			if (format[i] != '%')
				param->nb_arg = param->nb_arg + 1;
			i++;
		}
	}
	return (i + result - 2 * param->nb_arg);
}

int	ft_printf(const char *format, ...)
{
	int		return_value;
	va_list	ap;
	t_env	param;

	return_value = 0;
	ft_init_param(&param, 1);
	param.arg = ft_count_arg(format);
	va_start(ap, format);
	return_value = ft_print_arg(ap, format, &param, 0);
	va_end(ap);
	return (return_value);
}
