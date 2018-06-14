/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgauguet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/26 19:19:57 by sgauguet          #+#    #+#             */
/*   Updated: 2017/01/28 16:48:09 by sgauguet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*result;
	size_t	i;
	size_t	j;

	i = 0;
	j = (size_t)start;
	result = ft_memalloc(len + 1);
	if (s == NULL || result == NULL)
		return (NULL);
	while (i < len)
	{
		result[i] = s[i + j];
		i++;
	}
	result[i] = '\0';
	return (result);
}
