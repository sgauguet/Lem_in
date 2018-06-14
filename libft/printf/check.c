/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgauguet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 13:50:16 by sgauguet          #+#    #+#             */
/*   Updated: 2018/01/10 14:59:23 by sgauguet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	ft_check_flags(char c)
{
	int result;

	result = 0;
	if (c == '#' || c == '-' || c == '+' || (c == ' ') || c == '0')
		result = 1;
	else if (c == '*' || c == '$' || c == 'L' || c == 39)
		result = 2;
	else if (c == ',' || c == ';' || c == ':' || c == '_')
		result = 3;
	else if (c >= '1' && c <= '9')
		result = 4;
	else if (c == '.')
		result = 5;
	else if (c == 'h' || c == 'l' || c == 'j' || c == 'z')
		result = 6;
	return (result);
}

int	ft_check_conversion_specifications(char c)
{
	int result;

	result = 0;
	if (c == '%')
		result = 1;
	if (c == 'd' || c == 'i' || c == 'o' || c == 'u'
			|| c == 'x' || c == 'X')
		result = 2;
	if (c == 's' || c == 'S' || c == 'c' || c == 'C')
		result = 3;
	if (c == 'p')
		result = 4;
	if (c == 'D' || c == 'U' || c == 'O')
		result = 5;
	if (c == 'e' || c == 'E' || c == 'f' || c == 'F')
		result = 6;
	if (c == 'g' || c == 'G' || c == 'a' || c == 'A')
		result = 7;
	return (result);
}

int	ft_count_arg(const char *restrict format)
{
	int i;
	int count;

	i = 0;
	count = 0;
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			i++;
			while (ft_check_flags(format[i]) && format[i] != '*')
				i++;
			count++;
		}
		i++;
	}
	return (count);
}
