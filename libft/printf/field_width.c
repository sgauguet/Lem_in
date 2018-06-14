/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_field_width.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgauguet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/15 14:09:32 by sgauguet          #+#    #+#             */
/*   Updated: 2018/01/08 12:23:04 by sgauguet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	ft_reverse(char *result, char *str, t_env *param, int s)
{
	int		i;
	int		j;

	i = param->width - (int)ft_strlen(str);
	j = 0;
	while (i < param->width)
	{
		if ((str[j] == '-' || str[j] == '+' || str[j] == ' ')
				&& result[0] == '0' && s == 0)
		{
			result[i] = result[0];
			result[0] = str[j];
		}
		if ((str[j] == 'x' || str[j] == 'X') && str[j - 1] == '0'
				&& result[0] == '0' && param->flag_hashtag == 1)
		{
			result[i] = result[1];
			result[1] = str[j];
		}
		i++;
		j++;
	}
}

char	*ft_field_width_left(char *str, t_env *param)
{
	char	*result;
	int		i;

	i = 0;
	if (param->width != -1 && param->width > (int)ft_strlen(str))
	{
		if (!(result = (char *)malloc(sizeof(char) * param->width)))
			return (NULL);
		while (i < (int)ft_strlen(str))
		{
			result[i] = str[i];
			i++;
		}
		while (i < param->width)
		{
			result[i] = ' ';
			i++;
		}
		result[i] = '\0';
		ft_strdel(&str);
		return (result);
	}
	return (str);
}

char	*ft_field_width_right(char *str, t_env *param, int s, int j)
{
	char	*result;
	int		i;

	i = -1;
	if (!(result = ft_strnew(param->width)))
		return (NULL);
	while (++i < (param->width - (int)ft_strlen(str)))
	{
		result[i] = ' ';
		if (param->flag_zero == 1 && param->precision == -1)
			result[i] = '0';
	}
	while (i < param->width)
	{
		result[i] = str[j];
		i++;
		j++;
	}
	ft_reverse(result, str, param, s);
	ft_strdel(&str);
	return (result);
}
