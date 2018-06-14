/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgauguet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/26 19:20:16 by sgauguet          #+#    #+#             */
/*   Updated: 2017/02/05 12:42:54 by sgauguet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_size(char *s)
{
	size_t	size;
	size_t	i;
	size_t	j;

	if (!s)
		return (0);
	size = ft_strlen((char*)s);
	i = 0;
	while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
		i++;
	j = i;
	if (s[i] != '\0')
	{
		i = size - 1;
		while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
		{
			j++;
			i--;
		}
	}
	return (size - j);
}

static char		*ft_except(void)
{
	char	*result;

	result = malloc(sizeof(char));
	result[0] = '\0';
	return (result);
}

char			*ft_strtrim(char const *s)
{
	char	*result;
	size_t	i;
	size_t	j;
	size_t	size;

	i = 0;
	j = 0;
	size = ft_size((char*)s);
	if (size == 0)
		return (ft_except());
	if ((result = (char*)malloc(sizeof(char) * (size + 1))) == NULL)
		return (NULL);
	while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
		i++;
	while (j < size)
		result[j++] = s[i++];
	result[j] = '\0';
	return (result);
}
