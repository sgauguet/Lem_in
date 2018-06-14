/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgauguet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/12 10:25:58 by sgauguet          #+#    #+#             */
/*   Updated: 2018/06/12 11:36:01 by sgauguet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	make_move(t_room *current, t_room *next)
{
	t_ant	*ant;
	t_ant	*tmp;

	ant = current->ant;
	current->ant = (current->ant->next == NULL) ? NULL : ant->next;
	ant->prev = current;
	ant->next = NULL;
	tmp = next->ant;
	if (tmp == NULL)
		next->ant = ant;
	else
	{
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = ant;
	}
}

int		forbidden_room(t_lem *env, t_room *next, t_room *prev)
{
	t_link	*room;
	int		distance;

	if (next == env->start_room || next->ant || next->distance == INT_MAX)
		return (1);
	room = next->link;
	distance = INT_MAX;
	while (room)
	{
		if (room->link && room->link != prev && room->link->distance < distance)
			distance = room->link->distance;
		room = room->next;
	}
	if (next != env->end_room && distance > next->distance)
		return (1);
	return (0);
}

int		min_number_laps_remaining(t_lem *env)
{
	int		result;
	t_room	*room;

	result = 0;
	room = env->first;
	while (room)
	{
		if (room->ant && room->distance > result)
			result = room->distance;
		room = room->next;
	}
	return (result);
}

int		better_wait(t_lem *env, t_room *current, t_room *result,
		int min_distance)
{
	int		nb_ants;
	int		nb_laps;
	int		smaller_path;
	t_link	*room;

	nb_ants = (env->start_room->ant) ? (env->start_room->ant->nb)
		: env->nb_ants;
	nb_laps = min_number_laps_remaining(env);
	smaller_path = 0;
	room = current->link;
	while (room)
	{
		if (room->link->distance < result->distance)
			smaller_path++;
		room = room->next;
	}
	if (!smaller_path || result == env->end_room ||
			result->distance == min_distance)
		return (0);
	if (current == env->start_room && result->distance >
			(current->distance + (env->nb_ants - nb_ants - smaller_path)))
		return (1);
	if (result->distance >= (nb_laps + (env->nb_ants - nb_ants)))
		return (1);
	return (0);
}

t_room	*search_better_path(t_lem *env, t_room *current, t_room *smallest_path,
		int min_distance)
{
	t_link	*room;
	t_room	*result;

	room = current->link;
	result = smallest_path;
	while (room)
	{
		if (!forbidden_room(env, room->link, current) && current->ant->prev !=
				room->link && current->distance >= room->link->distance &&
				!better_wait(env, current, room->link, min_distance) &&
				room->link->distance >= result->distance)
			result = room->link;
		room = room->next;
	}
	if (better_wait(env, current, result, min_distance) && (current->ant &&
			!current->ant->prev->ant &&
			!better_wait(env, current, current->ant->prev, min_distance)))
		result = current->ant->prev;
	return (result);
}
