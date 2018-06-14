/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   links.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgauguet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/20 17:14:21 by sgauguet          #+#    #+#             */
/*   Updated: 2018/04/30 12:59:05 by sgauguet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		ft_check_minus(t_print *line)
{
	int		i;
	int		minus;
	char	*s;

	s = line->str;
	minus = 0;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == '-')
			minus++;
		i++;
	}
	if (minus != 1)
	{
		line->error = (i == 0) ? EMPTY_LINE : LINK_MINUS;
		return (0);
	}
	return (1);
}

char	**ft_check_size_link(t_print *line)
{
	int		i;
	char	**result;

	if (!(result = ft_strsplit(line->str, '-')))
	{
		line->error = EMPTY_LINK;
		return (NULL);
	}
	i = 0;
	while (result[i])
		i++;
	if (i != 2)
		line->error = NB_LINKS;
	else if (ft_strcmp(result[0], result[1]) == 0)
		line->error = SAME_ROOM;
	if (line->error != NONE)
	{
		free_string(result);
		return (NULL);
	}
	return (result);
}

char	**ft_check_link(t_lem *env, t_print *line)
{
	char	**result;
	t_room	*tmp;
	int		room[2];

	room[0] = 0;
	room[1] = 0;
	if (!ft_check_minus(line) || !(result = ft_check_size_link(line)))
		return (NULL);
	tmp = env->first;
	while (tmp)
	{
		if (ft_strcmp(result[0], tmp->name) == 0)
			room[0] = 1;
		else if (ft_strcmp(result[1], tmp->name) == 0)
			room[1] = 1;
		tmp = tmp->next;
	}
	if (room[0] == 0 || room[1] == 0)
	{
		line->error = MISSING_ROOM;
		free_string(result);
		return (NULL);
	}
	return (result);
}

int		ft_add_link(t_lem *env, t_room *room1, t_room *room2)
{
	t_link	*tmp;
	t_link	*new;

	tmp = room1->link;
	if (!tmp)
	{
		if (!(new = (t_link *)malloc(sizeof(t_link))) || !env)
			return (0);
		new->link = room2;
		new->next = NULL;
		room1->link = new;
	}
	else
	{
		while (tmp->next && tmp->link != room2)
			tmp = tmp->next;
		if (tmp->link == room2 || !(new = (t_link *)malloc(sizeof(t_link))))
			return (0);
		new->link = room2;
		new->next = NULL;
		tmp->next = new;
	}
	return (1);
}

int		ft_create_links(t_lem *env, t_print *line)
{
	int		i;
	char	**result;
	t_room	*tmp;
	t_room	*room1;
	t_room	*room2;

	i = 0;
	if ((result = ft_check_link(env, line)) == NULL)
		return (0);
	tmp = env->first;
	while (tmp)
	{
		if (ft_strcmp(result[0], tmp->name) == 0)
			room1 = tmp;
		if (ft_strcmp(result[1], tmp->name) == 0)
			room2 = tmp;
		tmp = tmp->next;
	}
	ft_add_link(env, room1, room2);
	ft_add_link(env, room2, room1);
	env->part = 1;
	free_string(result);
	return (1);
}
