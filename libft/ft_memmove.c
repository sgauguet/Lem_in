/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memmove.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgauguet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/02 21:42:33 by sgauguet          #+#    #+#             */
/*   Updated: 2017/01/30 21:49:44 by sgauguet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char	*s1;
	char	*s2;

	if (dest < src)
		return (ft_memcpy(dest, src, n));
	s1 = (char*)dest;
	s2 = (char*)src;
	if (!n || dest == src)
		return (dest);
	while (n > 0)
	{
		n--;
		s1[n] = s2[n];
	}
	return (dest);
}
