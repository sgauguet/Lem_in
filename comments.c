/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   comments.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgauguet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/20 15:16:12 by sgauguet          #+#    #+#             */
/*   Updated: 2018/05/07 16:16:52 by sgauguet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		ft_check_ants(t_lem *env, t_print *line)
{
	int i;

	i = 0;
	while (line->str[i])
	{
		if (i == 0 && line->str[i] == '-')
			i++;
		if (line->str[i] < 48 || line->str[i] > 57)
		{
			line->error = MISSING_ANT;
			env->nb_ants = -1;
			return (0);
		}
		i++;
	}
	return (1);
}

int		ft_nb_ants(t_lem *env, t_print *line)
{
	long long result;

	if (!line || line->str[0] == '\0')
	{
		if (line)
			line->error = EMPTY_LINE;
		return (0);
	}
	if (line->str[0] == '#')
	{
		ft_read_comments(env, line);
		return (1);
	}
	if (!ft_check_ants(env, line))
		return (0);
	result = ft_atoll(line->str);
	env->nb_ants = result;
	if (result <= 0 || result > INT_MAX)
	{
		env->nb_ants = -1;
		line->error = NB_ANTS;
		return (0);
	}
	return (1);
}

t_room	*ft_search_room(t_lem *env, t_print *line)
{
	char	**name;
	t_print *tmp;
	t_room	*result;

	if (!line->next)
		return (NULL);
	tmp = line;
	while (tmp->str && tmp->str[0] == '#')
		tmp = tmp->next;
	if (!tmp->str || !ft_strstr(tmp->str, " ") ||
			!(name = ft_strsplit(tmp->str, ' ')))
		return (NULL);
	result = env->first;
	while (result)
	{
		if (ft_strcmp(result->name, name[0]) == 0)
		{
			free_string(name);
			return (result);
		}
		result = result->next;
	}
	free_string(name);
	return (NULL);
}

int		ft_check_comments(t_lem *env, t_print *line, t_room *ptr)
{
	if (!line->str || line->str[0] != '#')
		return (0);
	if (ft_strcmp(line->str, "##start") == 0)
	{
		if (!(ptr = ft_search_room(env, line)))
		{
			line->error = START_ROOM;
			return (0);
		}
		env->start_room = ptr;
		line->error = NONE;
	}
	else if (ft_strcmp(line->str, "##end") == 0)
	{
		if (!(ptr = ft_search_room(env, line)))
		{
			line->error = END_ROOM;
			return (0);
		}
		env->end_room = ptr;
		line->error = NONE;
	}
	return (1);
}

int		ft_read_comments(t_lem *env, t_print *line)
{
	t_print	*tmp;

	tmp = env->instructions;
	if (line)
		return (ft_check_comments(env, line, NULL));
	while (tmp)
	{
		if (tmp->str && tmp->str[0] == '#')
			ft_check_comments(env, tmp, NULL);
		tmp = tmp->next;
	}
	return (1);
}
