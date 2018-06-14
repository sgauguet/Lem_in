/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strncat.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgauguet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/02 21:45:09 by sgauguet          #+#    #+#             */
/*   Updated: 2017/01/28 16:56:21 by sgauguet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *dest, const char *src, size_t n)
{
	size_t	i;
	size_t	j;
	char	*result;

	i = 0;
	j = 0;
	result = dest;
	while (result[i] != '\0')
	{
		i++;
	}
	while (src[j] != '\0' && n > 0)
	{
		result[i] = src[j];
		i++;
		j++;
		n--;
	}
	result[i] = '\0';
	return (result);
}
