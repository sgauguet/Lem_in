/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgauguet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/29 13:05:34 by sgauguet          #+#    #+#             */
/*   Updated: 2017/01/29 13:05:35 by sgauguet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_len_n(int n)
{
	size_t	i;

	i = 1;
	while (n /= 10)
		i++;
	return (i);
}

static int	nb_negatif(int n)
{
	int neg;

	neg = 1;
	if (n < 0)
		neg = -1;
	return (neg);
}

char		*ft_itoa(int n)
{
	char			*result;
	unsigned int	nb;
	int				len;
	int				neg;

	nb = (n < 0) ? -n : n;
	len = ft_len_n(nb);
	if ((neg = nb_negatif(n)) == -1)
		len++;
	if ((result = (char*)malloc(sizeof(char) * (len + 1))) == NULL)
		return (NULL);
	result[len] = '\0';
	while (len-- > 0)
	{
		result[len] = nb % 10 + '0';
		nb = nb / 10;
	}
	if (neg == -1)
		result[0] = '-';
	return (result);
}
