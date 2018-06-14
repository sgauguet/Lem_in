/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgauguet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/20 17:14:08 by sgauguet          #+#    #+#             */
/*   Updated: 2018/06/13 12:25:42 by sgauguet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	ft_print_anthill(t_lem *env)
{
	t_room *tmp;
	t_link *tmp2;

	tmp = env->first;
	ft_printf("\n\033[1m----- ANTHILL -----\n\033[00m");
	if (tmp == NULL)
		ft_printf("Empty farm\n");
	while (tmp)
	{
		ft_printf("\033[1m\033[34m%s%s%s\033[00m\033[32m (%d, %d) - distance : "
				"%d\n\033[00m", tmp == env->start_room ? ("START_ROOM ") : "",
				tmp == env->end_room ? ("END_ROOM ") : "",
				tmp->name, tmp->x, tmp->y, tmp->distance);
		tmp2 = tmp->link;
		while (tmp2)
		{
			ft_printf("   link -> %s\n", tmp2->link->name);
			tmp2 = tmp2->next;
		}
		tmp = tmp->next;
	}
}

int		bonus_options(t_lem *env)
{
	if (!env)
		return (0);
	if (env->count_option != -1)
		ft_printf("\n\033[1m----- NUMBER OF LAPS -----\n\033[00m%d\n",
				env->count_option);
	if (env->path_option)
		ft_print_path(env);
	if (env->print_option)
		ft_print_anthill(env);
	return (1);
}

int		ft_search_options(char **argv, t_lem *env)
{
	int i;

	i = 1;
	if (!argv)
		return (0);
	while (argv[i])
	{
		if (!ft_strcmp(argv[i], "-count"))
			env->count_option = 0;
		if (!ft_strcmp(argv[i], "-debug"))
			env->debug_option = 1;
		if (!ft_strcmp(argv[i], "-print"))
			env->print_option = 1;
		if (!ft_strcmp(argv[i], "-path"))
			env->path_option = 1;
		i++;
	}
	return (1);
}

int		ft_init_env(t_lem *env)
{
	if (!env)
		return (0);
	env->nb_ants = INT_MIN;
	env->part = 0;
	env->count_option = -1;
	env->debug_option = 0;
	env->print_option = 0;
	env->path_option = 0;
	env->first = NULL;
	env->start_room = NULL;
	env->end_room = NULL;
	env->instructions = NULL;
	return (1);
}

int		main(int argc, char **argv)
{
	t_lem	env;

	ft_init_env(&env);
	if (argc > 1)
		ft_search_options(argv, &env);
	ft_read_instructions(&env);
	breadth_first_search(&env);
	if (env.debug_option)
	{
		debug(&env);
		bonus_options(&env);
	}
	else
	{
		if (!ft_check_error(&env))
			ft_printf("ERROR\n");
		else
		{
			ft_print_instructions(&env);
			solve(&env);
			bonus_options(&env);
		}
	}
	free_env(&env);
	return (1);
}
