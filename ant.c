/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ant.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgauguet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/04 14:09:10 by sgauguet          #+#    #+#             */
/*   Updated: 2018/05/07 15:33:46 by sgauguet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		print_ants2(t_room *tmp, t_ant *ant, int space)
{
	while (ant)
	{
		if (ant->print == 1)
		{
			if (space == 1)
				ft_printf(" ");
			ft_printf("L%d-%s", ant->nb, tmp->name);
			space = 1;
		}
		ant = ant->next;
	}
	return (space);
}

int		print_ants(t_lem *env)
{
	t_room	*tmp;
	t_ant	*ant;
	int		space;

	tmp = env->first;
	space = 0;
	while (tmp)
	{
		if (tmp != env->start_room && (ant = tmp->ant) != NULL)
			space = print_ants2(tmp, ant, space);
		tmp = tmp->next;
	}
	if (space == 1)
	{
		ft_printf("\n");
		if (env->count_option != -1)
			env->count_option = env->count_option + 1;
	}
	return (1);
}

t_ant	*ft_create_ant(int nb)
{
	t_ant *new;

	if (!(new = (t_ant *)malloc(sizeof(t_ant))))
		return (NULL);
	new->nb = nb;
	new->print = 1;
	new->next = NULL;
	return (new);
}

t_ant	*ft_init_ants(int nb_ants)
{
	t_ant	*result;
	t_ant	*new;
	t_ant	*last;
	int		i;

	if (nb_ants <= 0 || (result = NULL))
		return (NULL);
	i = 1;
	while (i <= nb_ants)
	{
		if (!(new = ft_create_ant(i)))
			return (NULL);
		if (!result)
		{
			result = new;
			last = new;
		}
		else
		{
			last->next = new;
			last = new;
		}
		i++;
	}
	return (result);
}
