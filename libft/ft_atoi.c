/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgauguet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/29 13:04:18 by sgauguet          #+#    #+#             */
/*   Updated: 2017/12/08 14:01:15 by sgauguet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *nptr)
{
	int			i;
	long long	result;
	int			neg;

	i = 0;
	result = 0;
	neg = 1;
	while (nptr[i] == '\n' || nptr[i] == '\t' || nptr[i] == '\v' || nptr[i]
			== 13 || nptr[i] == '\f' || nptr[i] == '\f' || nptr[i] == 32)
		i++;
	if (nptr[i] == '-')
		neg = -1;
	if ((nptr[i] == '+') || (nptr[i] == '-'))
		i++;
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		result = result * 10 + (nptr[i] - '0');
		i++;
	}
	return (neg * result);
}
