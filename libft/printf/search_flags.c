/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgauguet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 10:11:58 by sgauguet          #+#    #+#             */
/*   Updated: 2018/01/15 10:17:13 by sgauguet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

char	*ft_select(const char *format, int c)
{
	int		i;
	int		j;
	int		k;
	char	*result;

	i = 0;
	j = c;
	k = c;
	while (format[k] >= '0' && format[k] <= '9')
		k++;
	if (!(result = ft_memalloc(k - i)))
		return (NULL);
	while (j < k)
	{
		result[i] = format[j];
		i++;
		j++;
	}
	return (result);
}

int		ft_search_flags(const char *format, int i, t_env *param)
{
	int j;
	int k;

	j = i;
	k = 0;
	while (!ft_check_conversion_specifications(format[j]) &&
			ft_check_flags(format[j]) <= 3 && format[j] != '\0')
	{
		if (ft_check_flags(format[j]) == 1)
			k++;
		if (format[j] == '#')
			param->flag_hashtag = 1;
		if (format[j] == '0')
			param->flag_zero = 1;
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

int		ft_search_width(const char *format, int i, t_env *param)
{
	int		j;
	int		count;
	char	*tmp;

	j = i;
	while (!ft_check_conversion_specifications(format[j]) && format[j] != '\0')
	{
		while (ft_check_flags(format[j]) <= 3 && ft_check_flags(format[j]) != 0)
			j++;
		if (format[j] == '.')
			return (0);
		else if (format[j] >= '0' && format[j] <= '9')
		{
			tmp = ft_select(format, j);
			param->width = ft_atoi(tmp);
			count = ft_strlen(tmp);
			free(tmp);
			return (count);
		}
		j++;
	}
	return (0);
}

int		ft_search_precision(const char *format, int i, t_env *param)
{
	int		j;
	int		count;
	char	*tmp;

	j = i;
	while (!ft_check_conversion_specifications(format[j]) && format[j] != '\0')
	{
		while (ft_check_flags(format[j]) != 5 && ft_check_flags(format[j]) != 0)
			j++;
		if (format[j] == '.')
		{
			tmp = ft_select(format, j + 1);
			param->precision = ft_atoi(tmp);
			count = ft_strlen(tmp);
			free(tmp);
			return (count + 1);
		}
		else
			return (0);
		j++;
	}
	return (0);
}

int		ft_search_length(const char *format, int j, t_env *param)
{
	while (!ft_check_conversion_specifications(format[j]) &&
			ft_check_flags(format[j]) == 6 && format[j] != '\0')
	{
		if (format[j] == 'j' && !ft_strcmp(param->length_mod, "0"))
			param->length_mod = "j";
		if (format[j] == 'z' && !ft_strcmp(param->length_mod, "0"))
			param->length_mod = "z";
		if (format[j] == 'h' && format[j + 1] == 'h' &&
				!ft_strcmp(param->length_mod, "0"))
			param->length_mod = "hh";
		if (format[j] == 'h' && format[j + 1] != 'h' &&
				!ft_strcmp(param->length_mod, "0"))
			param->length_mod = "h";
		if (format[j] == 'l' && format[j + 1] == 'l')
			param->length_mod = "ll";
		if (format[j] == 'l' && format[j + 1] != 'l')
			param->length_mod = "l";
		j++;
	}
	return (1);
}
