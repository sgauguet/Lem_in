/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgauguet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/08 11:02:00 by sgauguet          #+#    #+#             */
/*   Updated: 2017/12/18 12:28:46 by sgauguet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_len_n(uintmax_t n, int base)
{
	size_t	i;

	i = 1;
	while (n /= base)
		i++;
	return (i);
}

char		*ft_itoa_base_2(uintmax_t value, int base, char convert)
{
	char			*result;
	uintmax_t		nb;
	int				len;

	nb = value;
	len = ft_len_n(nb, base);
	if ((result = (char*)malloc(sizeof(char) * (len + 1))) == NULL)
		return (NULL);
	result[len] = '\0';
	while (len-- > 0)
	{
		result[len] = nb % base + '0';
		if (result[len] > '9' && convert == 'X')
			result[len] = result[len] + 7;
		if (result[len] > '9' && convert == 'x')
			result[len] = result[len] + 39;
		nb = nb / base;
	}
	return (result);
}
