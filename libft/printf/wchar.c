/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unicode.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgauguet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 14:07:14 by sgauguet          #+#    #+#             */
/*   Updated: 2018/01/15 13:31:20 by sgauguet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

/*
** masks utf-8 :
** 110xxxxx 10xxxxxx : 0x07c0 / 0x003f
** 1110xxxx 10xxxxxx 10xxxxxx : 0xf000 / 0x0fc0 / 0x003f
** 11110xxx 10xxxxxx 10xxxxxx 10xxxxxx : 0x1c0000 / 0x03f000 / 0x0fc0 / 0x003f
** 0xf0 	= 11110000
** 0xe0		= 11100000
** 0xc0		= 11000000
** 0x80		= 10000000
*/

char	*four_bytes(wchar_t i)
{
	char	*str;

	if (!(str = ft_strnew(4)))
		return (NULL);
	str[0] = (((i & 0x1c0000) >> 18) + 0xf0);
	str[1] = (((i & 0x03f000) >> 12) + 0x80);
	str[2] = (((i & 0x0fc0) >> 6) + 0x80);
	str[3] = ((i & 0x003f) + 0x80);
	return (str);
}

char	*three_bytes(wchar_t i)
{
	char	*str;

	if (!(str = ft_strnew(3)))
		return (NULL);
	str[0] = (((i & 0xf000) >> 12) + 0xe0);
	str[1] = (((i & 0x0fc0) >> 6) + 0x80);
	str[2] = ((i & 0x003f) + 0x80);
	return (str);
}

char	*two_bytes(wchar_t i)
{
	char	*str;

	if (!(str = ft_strnew(2)))
		return (NULL);
	str[0] = (((i & 0x07c0) >> 6) + 0xc0);
	str[1] = ((i & 0x003f) + 0x80);
	return (str);
}

char	*one_byte(wchar_t i)
{
	char	*str;

	if (!(str = ft_strnew(1)))
		return (NULL);
	if (i == 0)
		str[0] = '\0';
	if (i != 0)
		str[0] = i;
	return (str);
}

char	*ft_wchar_t(wchar_t i)
{
	if (i >= 0xd800 && i <= 0xdfff)
		return (NULL);
	if (i >= 0x10000 && i <= 0x10ffff && MB_CUR_MAX == 4)
		return (four_bytes(i));
	else if (i >= 0x0800 && i <= 0xffff && MB_CUR_MAX >= 3)
		return (three_bytes(i));
	else if (i >= 0x80 && i <= 0x07ff && MB_CUR_MAX >= 2)
		return (two_bytes(i));
	else if (i >= 0x00 && i <= 0xff)
		return (one_byte(i));
	return (NULL);
}
