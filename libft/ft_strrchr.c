/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strrchr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgauguet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/02 21:45:44 by sgauguet          #+#    #+#             */
/*   Updated: 2017/01/19 17:48:48 by sgauguet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	int				i;
	unsigned char	a;
	char			*tmp;

	a = (unsigned char)c;
	tmp = (char *)str;
	i = ft_strlen(tmp);
	while (i >= 0)
	{
		if (tmp[i] == a)
			return (tmp + i);
		i--;
	}
	return (NULL);
}
