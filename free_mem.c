/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_mem.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgauguet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/20 17:13:38 by sgauguet          #+#    #+#             */
/*   Updated: 2018/05/07 14:33:02 by sgauguet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_ant	*free_ants(t_lem *env)
{
	t_ant *tmp;
	t_ant *current;

	if ((tmp = env->end_room->ant))
	{
		while (tmp)
		{
			current = tmp;
			tmp = tmp->next;
			free(current);
		}
	}
	return (NULL);
}

void	free_string(char **str)
{
	int i;

	i = 0;
	if (str == NULL)
		return ;
	while (str[i])
	{
		ft_strdel(&str[i]);
		i++;
	}
	free(str);
}

void	free_instructions(t_print *instructions)
{
	t_print *tmp;
	t_print *current;

	tmp = instructions;
	while (tmp)
	{
		current = tmp;
		tmp = tmp->next;
		if (current->str)
			ft_strdel(&current->str);
		free(current);
	}
}

void	free_links(t_room *ptr)
{
	t_link *tmp;
	t_link *current;

	tmp = ptr->link;
	while (tmp)
	{
		current = tmp;
		tmp = tmp->next;
		free(current);
	}
}

void	free_env(t_lem *env)
{
	t_room	*tmp;
	t_room	*ptr;

	tmp = env->first;
	while (tmp)
	{
		ptr = tmp;
		tmp = tmp->next;
		if (ptr->name)
			ft_strdel(&ptr->name);
		free_links(ptr);
		free(ptr);
	}
	free_instructions(env->instructions);
}
