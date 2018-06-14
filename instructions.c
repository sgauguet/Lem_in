/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgauguet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/20 17:13:53 by sgauguet          #+#    #+#             */
/*   Updated: 2018/06/12 10:46:29 by sgauguet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int	ft_print_instructions(t_lem *env)
{
	t_print	*tmp;

	tmp = env->instructions;
	while (tmp)
	{
		if (tmp->error == NONE || tmp->error == ROOM_EXIST ||
				env->debug_option || (tmp->str && tmp->str[0] == '#'))
			ft_printf("%s\n", tmp->str);
		tmp = tmp->next;
	}
	ft_printf("\n");
	return (1);
}

int	ft_check_instructions(t_lem *env, t_print *line)
{
	int		ret;

	if (!line->str)
		line->error = EMPTY_LINE;
	if (env->nb_ants == INT_MIN || (env->nb_ants < 0 &&
				!ft_strstr(line->str, "-") && !ft_strstr(line->str, " ")))
		ret = ft_nb_ants(env, line);
	else
		ret = ft_build_anthill(env, line);
	if (env->debug_option)
		return (1);
	return (ret);
}

int	ft_add_instructions(t_lem *env, char *line)
{
	t_print	*a;
	t_print	*tmp;

	if (!(a = (t_print *)malloc(sizeof(t_print))))
		return (-1);
	a->str = ft_strdup(line);
	a->error = NONE;
	a->next = NULL;
	if (env->instructions == NULL)
		env->instructions = a;
	else
	{
		tmp = env->instructions;
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = a;
	}
	return (ft_check_instructions(env, a));
}

int	ft_read_instructions(t_lem *env)
{
	int		i;
	int		ret;
	char	*line;

	line = NULL;
	i = 1;
	while (get_next_line(0, &line) > 0 && i < MAX_INSTRUCTIONS)
	{
		ret = ft_add_instructions(env, line);
		ft_strdel(&line);
		if (ret <= 0)
		{
			ft_read_comments(env, NULL);
			ft_strdel(&line);
			return (i);
		}
		i++;
	}
	ft_read_comments(env, NULL);
	if (i == MAX_INSTRUCTIONS)
		return (i);
	return (0);
}
