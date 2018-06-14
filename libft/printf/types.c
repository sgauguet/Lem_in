/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgauguet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/12 16:08:46 by sgauguet          #+#    #+#             */
/*   Updated: 2018/01/15 11:19:49 by sgauguet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	ft_length_modifier(va_list ap, char c, t_env *param)
{
	if (ft_check_conversion_specifications(c) == 2)
	{
		if (ft_strcmp(param->length_mod, "ll") == 0)
			return (ft_print_long_long(ap, c, param, param->base));
		if (ft_strcmp(param->length_mod, "l") == 0)
			return (ft_print_long_int(ap, c, param, param->base));
		if (ft_strcmp(param->length_mod, "hh") == 0)
			return (ft_print_char(ap, c, param, param->base));
		if (ft_strcmp(param->length_mod, "h") == 0)
			return (ft_print_short_int(ap, c, param, param->base));
		if (ft_strcmp(param->length_mod, "j") == 0)
			return (ft_print_intmax_t(ap, c, param, param->base));
		if (ft_strcmp(param->length_mod, "z") == 0)
			return (ft_print_size_t(ap, c, param, param->base));
	}
	if (ft_check_conversion_specifications(c) != 2)
	{
		if (ft_strcmp(param->length_mod, "l") == 0 && c == 'c')
			return (ft_print_wint_t(ap, c, param));
		if (ft_strcmp(param->length_mod, "l") == 0 && c == 's')
			return (ft_print_tab_wchar_t(ap, c, param));
	}
	return (ft_mandatory_conversion(ap, c, param));
}

int	ft_bonus_conversion(va_list ap, char c, t_env *param)
{
	if (c == 'b')
		return (ft_print_bin(ap, c, param));
	if (c == 'e' || c == 'E')
		return (ft_print_double(ap, c, param));
	if (c == 'f' || c == 'F')
		return (ft_print_double(ap, c, param));
	if (c == 'g' || c == 'G')
		return (ft_print_double(ap, c, param));
	if (c == 'a' || c == 'A')
		return (ft_print_double(ap, c, param));
	return (0);
}

int	ft_mandatory_conversion(va_list ap, char c, t_env *param)
{
	if (c == '%')
		return (ft_print_percent(ap, c, param));
	if (c == 'd' || c == 'i')
		return (ft_print_int(ap, c, param));
	if (c == 's')
		return (ft_print_string(ap, c, param));
	if (c == 'S')
		return (ft_print_tab_wchar_t(ap, c, param));
	if (c == 'c')
		return (ft_print_char(ap, c, param, param->base));
	if (c == 'C')
		return (ft_print_wint_t(ap, c, param));
	if (c == 'x' || c == 'X')
		return (ft_print_hexa(ap, c, param));
	if (c == 'o')
		return (ft_print_oct(ap, c, param));
	if (c == 'O' || c == 'U' || c == 'D')
		return (ft_print_long_int(ap, c, param, param->base));
	if (c == 'u')
		return (ft_print_unsigned_int(ap, c, param));
	if (c == 'p')
		return (ft_print_p(ap, c, param));
	else
		return (ft_print_invalid_specifier(c, param));
	return (0);
}

int	ft_define_type(va_list ap, char c, t_env *param)
{
	if (c == '\0')
		return (0);
	if (c == 'x' || c == 'X')
		param->base = 16;
	else if (c == 'o' || c == 'O')
		param->base = 8;
	if (ft_strcmp(param->length_mod, "0") != 0)
		return (ft_length_modifier(ap, c, param));
	if (c == 'b' || c == 'e' || c == 'E' || c == 'f' || c == 'F'
			|| c == 'g' || c == 'G' || c == 'a' || c == 'A')
		return (ft_bonus_conversion(ap, c, param));
	else
		return (ft_mandatory_conversion(ap, c, param));
	return (0);
}
