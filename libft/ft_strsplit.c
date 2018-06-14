/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgauguet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/29 12:15:11 by sgauguet          #+#    #+#             */
/*   Updated: 2017/01/29 16:39:30 by sgauguet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_nb_words(char const *s, char c)
{
	int i;
	int result;

	i = 0;
	result = 0;
	while (s[i] != '\0')
	{
		while (s[i] == c)
			i++;
		if (s[i] != c && s[i] != '\0')
			result++;
		while (s[i] != c && s[i] != '\0')
			i++;
	}
	return (result);
}

static int	ft_size(char const *s, char c)
{
	int i;

	i = 0;
	while (s[i] != c && s[i] != '\0')
		i++;
	return (i);
}

char		**ft_strsplit(char const *s, char c)
{
	char	**ptr;
	int		i;
	int		nb;
	size_t	size;

	if (s == NULL)
		return (NULL);
	i = 0;
	nb = ft_nb_words(s, c);
	if ((ptr = (char**)malloc(sizeof(*ptr) * (nb + 1))) == NULL)
		return (NULL);
	while (nb--)
	{
		while (*s != '\0' && *s == c)
			s++;
		size = ft_size(s, c);
		ptr[i] = ft_strsub(s, 0, size);
		if (ptr[i] == '\0')
			return (NULL);
		s = s + ft_size(s, c);
		i++;
	}
	ptr[i] = NULL;
	return (ptr);
}
