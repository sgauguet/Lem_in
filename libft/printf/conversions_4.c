/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversions_4.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgauguet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/05 15:49:37 by sgauguet          #+#    #+#             */
/*   Updated: 2018/01/15 11:19:24 by sgauguet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int		ft_print_invalid_specifier(char c, t_env *param)
{
	char	*str;
	int		i;

	str = ft_strnew(1);
	str[0] = c;
	param->precision = -1;
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

int		ft_print_p(va_list ap, char c, t_env *param)
{
	void	*result;
	int		i;
	char	*str;

	result = va_arg(ap, void *);
	i = 0;
	if (!(str = ft_itoa_base_2((uintmax_t)result, 16, 'x')) || !c)
		return (-1);
	if (param->precision != -1)
		str = ft_precision_int(str, param, (int)result);
	param->flag_hashtag = 1;
	str = ft_print_hashtag(str, param, 'x');
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

int		ft_print_wint_t(va_list ap, char c, t_env *param)
{
	wint_t	result;
	char	*str;
	int		len;

	result = va_arg(ap, intmax_t);
	str = ft_wchar_t(result);
	if (result < 0 || str == NULL)
		return (-1);
	if (result == 0x00)
		return (ft_print_backslash_zero(param));
	if (param->precision != -1)
		str = ft_precision_string(str, param);
	if (param->width != -1 && param->flag_less == 0
			&& param->width > (int)ft_strlen(str))
		str = ft_field_width_right(str, param, 1, 0);
	if (param->width != -1 && param->flag_less == 1)
		str = ft_field_width_left(str, param);
	ft_putstr(str);
	len = ft_strlen(str);
	ft_strdel(&str);
	if (!c)
		return (0);
	if (result == 0)
		return (1);
	return (len);
}

char	*ft_join_wchar_t(wchar_t *result)
{
	char	*str;
	char	*tmp;
	int		i;

	if (result)
	{
		i = 0;
		if (!(str = ft_wchar_t(result[i])))
			return (NULL);
		i++;
		while (result[i])
		{
			if ((tmp = ft_wchar_t(result[i])) == NULL)
				return (NULL);
			str = ft_strjoin(str, tmp);
			ft_strdel(&tmp);
			i++;
		}
	}
	else
		str = ft_strdup("(null)");
	return (str);
}

int		ft_print_tab_wchar_t(va_list ap, char c, t_env *param)
{
	wchar_t	*result;
	char	*str;
	int		i;

	result = va_arg(ap, wchar_t *);
	if (result && result[0] == '\0' && c)
		str = ft_strnew(0);
	else if ((str = ft_join_wchar_t(result)) == NULL)
		return (-1);
	if (param->precision != -1)
		str = ft_precision_string(str, param);
	param->precision = -1;
	if (param->width != -1 && param->flag_less == 0
			&& param->width > (int)ft_strlen(str))
		str = ft_field_width_right(str, param, 1, 0);
	if (param->width != -1 && param->flag_less == 1)
		str = ft_field_width_left(str, param);
	ft_putstr(str);
	i = (int)ft_strlen(str);
	ft_strdel(&str);
	return (i);
}
