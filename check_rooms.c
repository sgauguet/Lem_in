/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_rooms.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgauguet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/30 13:37:02 by sgauguet          #+#    #+#             */
/*   Updated: 2018/04/30 13:38:17 by sgauguet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		ft_check_spaces(t_print *line)
{
	int		i;
	int		spaces;
	char	*s;

	s = line->str;
	spaces = 0;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == ' ')
			spaces++;
		i++;
	}
	if (spaces != 2)
	{
		line->error = ROOM_SPACES;
		return (0);
	}
	return (1);
}

int		ft_check_coordinates(char **result, t_print *line)
{
	int		i;
	int		j;

	i = 0;
	while (result[i])
	{
		j = 0;
		while (i > 0 && result[i][j])
		{
			if ((result[i][j] < 48 || result[i][j] > 57) && result[i][j] != '-')
				line->error = ROOM_COORD;
			j++;
		}
		i++;
	}
	return (i);
}

char	**ft_check_size(t_print *line)
{
	int		i;
	char	**result;

	if (!(result = ft_strsplit(line->str, ' ')))
	{
		line->error = EMPTY_ROOM;
		return (NULL);
	}
	i = ft_check_coordinates(result, line);
	if (line->error != NONE || i != 3)
	{
		if (line->error == NONE)
			line->error = NB_ROOMS;
		free_string(result);
		return (NULL);
	}
	return (result);
}

char	**ft_check_new_room(t_lem *env, t_print *line)
{
	char	**result;
	t_room	*tmp;

	if (!ft_check_spaces(line) || !(result = ft_check_size(line)))
		return (NULL);
	tmp = env->first;
	while (tmp)
	{
		if (ft_strcmp(result[0], tmp->name) == 0)
		{
			line->error = ROOM_EXIST;
			tmp->x = ft_atoi(result[1]);
			tmp->y = ft_atoi(result[2]);
		}
		tmp = tmp->next;
	}
	if (line->error == NONE && ft_strcmp(result[0], "L") == 0)
		line->error = ROOM_NAME;
	if (line->error != NONE)
	{
		free_string(result);
		return (NULL);
	}
	return (result);
}
