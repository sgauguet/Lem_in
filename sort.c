/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgauguet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/02 11:28:17 by sgauguet          #+#    #+#             */
/*   Updated: 2018/05/17 10:25:24 by sgauguet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		end(t_lem *env)
{
	t_room	*tmp;

	tmp = env->first;
	while (tmp)
	{
		if (tmp->ant != NULL)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

int		init(t_lem *env)
{
	t_room *tmp;

	tmp = env->first;
	while (tmp)
	{
		if (tmp->ant)
			tmp->ant->print = 1;
		tmp->move = 0;
		tmp = tmp->next;
	}
	return (1);
}

t_room	*ft_is_sorted(t_lem *env)
{
	t_room	*current;
	t_room	*next;

	if (env->first == NULL)
		return (NULL);
	current = env->first;
	while (current)
	{
		next = current->next;
		while (next && next->ant == NULL)
			next = next->next;
		if (next && current->ant && next->ant &&
				(current->ant->nb > next->ant->nb))
			return (current);
		current = current->next;
	}
	return (NULL);
}

int		sort(t_lem *env)
{
	t_room	*room;
	t_room	*tmp;

	while ((room = ft_is_sorted(env)) != NULL)
	{
		tmp = env->first;
		if (tmp == room)
		{
			env->first = room->next;
			room->next = NULL;
			env->last->next = room;
			env->last = room;
		}
		else
		{
			while (tmp->next != room)
				tmp = tmp->next;
			tmp->next = room->next;
			room->next = NULL;
			env->last->next = room;
			env->last = room;
		}
	}
	return (1);
}
