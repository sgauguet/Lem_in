/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rooms.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgauguet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/20 17:14:58 by sgauguet          #+#    #+#             */
/*   Updated: 2018/05/07 15:46:56 by sgauguet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_room	*ft_init_room(char **result)
{
	t_room *new;

	if (!(new = (t_room *)malloc(sizeof(t_room))) || !result)
		return (NULL);
	new->name = ft_strdup(result[0]);
	new->x = ft_atoi(result[1]);
	new->y = ft_atoi(result[2]);
	new->ant = NULL;
	new->color = WHITE;
	new->distance = INT_MAX;
	new->link = NULL;
	new->next = NULL;
	return (new);
}

int		ft_create_room(t_lem *env, t_print *line)
{
	char	**result;
	t_room	*new;

	result = NULL;
	if ((result = ft_check_new_room(env, line)))
	{
		if (!(new = ft_init_room(result)))
			return (-1);
		if (env->first == NULL)
		{
			env->first = new;
			env->last = new;
		}
		else
		{
			env->last->next = new;
			env->last = new;
		}
		free_string(result);
		return (1);
	}
	if (line->error == ROOM_EXIST)
		return (1);
	return (0);
}

int		ft_build_anthill(t_lem *env, t_print *line)
{
	if (line->str == NULL)
		return (0);
	else if (line->str[0] == '#')
	{
		if (env->debug_option == 0)
			ft_read_comments(env, line);
		return (1);
	}
	if (ft_strstr(line->str, " ") && ft_strstr(line->str, "-"))
	{
		line->error = UNDEFINED;
		return (0);
	}
	if (ft_strstr(line->str, " "))
	{
		if (env->part != 0)
		{
			line->error = PART;
			return (0);
		}
		return (ft_create_room(env, line));
	}
	return (ft_create_links(env, line));
}
