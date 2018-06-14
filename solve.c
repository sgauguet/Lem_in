/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgauguet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/30 10:47:57 by sgauguet          #+#    #+#             */
/*   Updated: 2018/06/12 11:38:27 by sgauguet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		start_move(t_lem *env, t_room *result, int min_distance)
{
	t_link	*room;

	room = env->start_room->link;
	while (room)
	{
		if (room->link && room->link->distance < min_distance)
			min_distance = room->link->distance;
		if (!forbidden_room(env, room->link, env->start_room) &&
				(result == NULL || room->link->distance < result->distance))
			result = room->link;
		if (room->link == env->end_room)
			result = room->link;
		room = room->next;
	}
	if (result == NULL || env->start_room->ant == NULL ||
			better_wait(env, env->start_room, result, min_distance))
		return (0);
	if (result != env->end_room)
		result = search_better_path(env, env->start_room, result, min_distance);
	make_move(env->start_room, result);
	result->move = 1;
	return (1);
}

int		move_ants(t_lem *env, t_room *current, t_room *result, int min_distance)
{
	t_link	*room;

	room = current->link;
	while (room)
	{
		if (room->link && room->link->distance < min_distance)
			min_distance = room->link->distance;
		if (!forbidden_room(env, room->link, current) &&
				current->ant->prev != room->link &&
				(result == NULL || room->link->distance < result->distance))
			result = room->link;
		if (room->link == env->end_room)
			result = room->link;
		room = room->next;
	}
	if (result == NULL)
	{
		current->ant->print = 0;
		return (0);
	}
	if (result != env->end_room)
		result = search_better_path(env, current, result, min_distance);
	make_move(current, result);
	result->move = 1;
	return (1);
}

void	solve(t_lem *env)
{
	t_room	*room;
	t_ant	*ant;

	ant = ft_init_ants(env->nb_ants);
	env->start_room->ant = ant;
	sort(env);
	while (!end(env))
	{
		room = env->first;
		init(env);
		while (room)
		{
			if (room == env->start_room)
				while (start_move(env, NULL, INT_MAX))
					;
			else if (room != env->end_room && room->ant && !room->move)
				move_ants(env, room, NULL, INT_MAX);
			room = room->next;
		}
		sort(env);
		print_ants(env);
		if (env->end_room->ant)
			env->end_room->ant = free_ants(env);
	}
}
