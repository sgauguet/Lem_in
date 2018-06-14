/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgauguet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/12 17:36:50 by sgauguet          #+#    #+#             */
/*   Updated: 2018/01/11 11:44:27 by sgauguet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

char	*ft_print_sign(char *str, t_env *param, char c)
{
	char *result;

	if (!param)
		return (0);
	if (!(result = (char *)malloc(sizeof(char) * (ft_strlen(str) + 1))))
		return (NULL);
	result[0] = c;
	ft_strcpy(&result[1], str);
	ft_strdel(&str);
	return (result);
}

char	*ft_precision_int_neg(char *str, t_env *param, int neg)
{
	char	*result;
	int		i;

	i = 0;
	if (param->precision > 0 && param->precision >= (int)ft_strlen(str))
	{
		if (!(result = ft_strnew(param->precision + 1)))
			return (NULL);
		while (i <= (param->precision - (int)ft_strlen(str)))
		{
			result[i] = '0';
			i++;
		}
		ft_strcpy(&result[i], &str[1]);
		if (neg < 0)
			result = ft_print_sign(result, param, '-');
		ft_strdel(&str);
		return (result);
	}
	return (str);
}

char	*ft_precision_int(char *str, t_env *param, int neg)
{
	char	*result;
	int		i;

	i = 0;
	if (param->precision == 0 && neg == 0)
		return (ft_strnew(0));
	if (param->precision > 0 && param->precision > (int)ft_strlen(str))
	{
		if (!(result = (char *)malloc(sizeof(char) * (param->precision))))
			return (NULL);
		while (i < (param->precision - (int)ft_strlen(str)))
		{
			result[i] = '0';
			i++;
		}
		ft_strcpy(&result[i], str);
		ft_strdel(&str);
		return (result);
	}
	return (str);
}

char	*ft_precision_string(char *str, t_env *param)
{
	char	*result;
	int		i;

	i = -1;
	if (param->precision == 0)
		return (NULL);
	if (param->precision != -1 && param->precision < (int)ft_strlen(str))
	{
		if ((str[param->precision] & 0x80) == 0x80)
		{
			if ((str[param->precision - 1] & 0xc0) == 0xc0)
				param->precision = param->precision - 1;
			else if ((str[param->precision - 2] & 0xe0) == 0xe0)
				param->precision = param->precision - 2;
			else if ((str[param->precision - 3] & 0xf0) == 0xf0)
				param->precision = param->precision - 3;
		}
		if (!(result = ft_strnew(param->precision)))
			return (NULL);
		while (++i < param->precision)
			result[i] = str[i];
		ft_strdel(&str);
		return (result);
	}
	return (str);
}

char	*ft_print_hashtag(char *str, t_env *param, char c)
{
	char *result;

	result = NULL;
	if ((c == 'o' || c == 'O') && str[0] != '0')
	{
		if (!(result = (char *)malloc(sizeof(char) * (ft_strlen(str) + 1))))
			return (str);
		result[0] = '0';
		ft_strcpy(&result[1], str);
	}
	if ((c == 'x' || c == 'X') && param)
	{
		if (!(result = (char *)malloc(sizeof(char) * (ft_strlen(str) + 2))))
			return (str);
		result[0] = '0';
		result[1] = c;
		ft_strcpy(&result[2], str);
	}
	if (!result)
		return (str);
	ft_strdel(&str);
	return (result);
}
