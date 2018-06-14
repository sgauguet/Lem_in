/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_path.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgauguet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/30 10:47:13 by sgauguet          #+#    #+#             */
/*   Updated: 2018/06/13 09:41:47 by sgauguet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	ft_print_path(t_lem *env)
{
	t_room *tmp;
	t_link *next;

	tmp = env->start_room;
	if (!env->start_room || !env->end_room || (env->start_room ==
				env->end_room) || env->start_room->distance == INT_MAX)
		return ;
	ft_printf("\n\033[1m----- BEST PATH -----\n\033[00m");
	while (tmp != env->end_room)
	{
		ft_printf("%s -> ", tmp->name);
		next = tmp->link;
		tmp = next->link;
		while (next)
		{
			if (next->link->distance < tmp->distance)
				tmp = next->link;
			next = next->next;
		}
	}
	ft_printf("%s\n", env->end_room->name);
}

t_link	*enqueue(t_link *queue, t_room *new)
{
	t_link	*elem;
	t_link	*tmp;

	if (!new || !(elem = (t_link *)malloc(sizeof(t_link))))
		return (NULL);
	elem->link = new;
	elem->next = NULL;
	if (!queue)
		queue = elem;
	else
	{
		tmp = queue;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = elem;
	}
	return (queue);
}

t_link	*dequeue(t_link *queue)
{
	t_link *next;

	if (!queue)
		return (NULL);
	next = queue->next;
	free(queue);
	queue = next;
	return (queue);
}

t_room	*init_end_room(t_lem *env)
{
	t_room	*current;

	if (!(current = env->end_room))
		return (NULL);
	current->color = GREY;
	current->distance = 0;
	return (current);
}

void	breadth_first_search(t_lem *env)
{
	t_link	*queue;
	t_room	*current;
	t_link	*tmp;

	if (!env->start_room || !(current = init_end_room(env)))
		return ;
	queue = NULL;
	queue = enqueue(queue, current);
	while (queue != NULL)
	{
		current = queue->link;
		tmp = current->link;
		queue = dequeue(queue);
		while (tmp)
		{
			if (tmp->link->color == WHITE && current != env->start_room)
			{
				tmp->link->color = GREY;
				tmp->link->distance = current->distance + 1;
				queue = enqueue(queue, tmp->link);
			}
			tmp = tmp->next;
		}
		current->color = BLACK;
	}
}
