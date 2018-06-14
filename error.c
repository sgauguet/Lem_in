/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgauguet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/20 13:46:08 by sgauguet          #+#    #+#             */
/*   Updated: 2018/06/13 12:27:29 by sgauguet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	ft_print_env_errors(t_lem *env)
{
	int	ret;

	ret = 0;
	ft_printf("\033[1m----------------ENV------------------\n\033[00m");
	ft_printf("\033[31m");
	if (env->nb_ants < 1 && (ret = 1))
		ft_printf("no ants.\n");
	if (env->first == NULL && (ret = 1))
		ft_printf("no rooms created.\n");
	if (env->start_room == NULL && (ret = 1))
		ft_printf("start-room not defined.\n");
	if (env->end_room == NULL && (ret = 1))
		ft_printf("end-room not defined.\n");
	if (env->start_room && env->start_room == env->end_room && (ret = 1))
		ft_printf("start_room is identical with end_room.\n");
	if (env->start_room && env->start_room->distance == INT_MAX && (ret = 1))
		ft_printf("No solutions.\n");
	ft_printf("\033[00m");
	if (!ret)
		ft_printf("\033[32mOK !\n\033[00m"
				"\033[1m-------------------------------------\n\033[00m");
}

void	ft_print_syntax_errors2(t_print *line, int nb)
{
	ft_printf("\033[31m");
	if (line->error == LINK_MINUS)
		ft_printf("Line %d : bad number of arguments or bad "
				"number of minus.\n", nb);
	if (line->error == NB_LINKS)
		ft_printf("Line %d : bad number of arguments -> link format : "
				"room_name1-room_name2.\n", nb);
	if (line->error == MISSING_ROOM)
		ft_printf("Line %d : one room doesn't exists.\n", nb);
	if (line->error == SAME_ROOM)
		ft_printf("Line %d : room_name_1 must be different from "
				"room_name_2.\n", nb);
	if (line->error == PART)
		ft_printf("Line %d : You cannot create a new room after having "
				"created links.\n", nb);
	if (line->error == START_ROOM)
		ft_printf("Line %d : start room not found after the command.\n", nb);
	if (line->error == END_ROOM)
		ft_printf("Line %d : end room not found after the command.\n", nb);
	if (line->error == UNDEFINED)
		ft_printf("Line %d : Undefined instruction : don't use minus in rooms "
				"definition or spaces in links definition.\n", nb);
	ft_printf("\033[00m");
}

void	ft_print_syntax_errors(t_print *line, int nb)
{
	ft_printf("\033[31m");
	if (line->error == EMPTY_LINE)
		ft_printf("Line %d : empty line.\n", nb);
	if (line->error == EMPTY_ROOM || line->error == EMPTY_LINK)
		ft_printf("Line %d : malloc error.\n", nb);
	if (line->error == NB_ANTS)
		ft_printf("Line %d : bad number of ants.\n", nb);
	if (line->error == MISSING_ANT)
		ft_printf("Line %d : number of ants is missing or not valid.\n", nb);
	if (line->error == ROOM_EXIST)
		ft_printf("Line %d : the room already exists.\n", nb);
	if (line->error == ROOM_SPACES || line->error == NB_ROOMS)
		ft_printf("Line %d : bad number of arguments or bad number of spaces "
				"-> room format = name coord_x coord_y.\n", nb);
	if (line->error == ROOM_COORD)
		ft_printf("Line %d : bad character detected in definition of room "
				"coordinates (x, y).\n", nb);
	if (line->error == ROOM_NAME)
		ft_printf("Line %d : room name can't be \"L\".\n");
	ft_print_syntax_errors2(line, nb);
	ft_printf("\033[00m");
}

int		debug(t_lem *env)
{
	int		i;
	int		line;
	t_print *tmp;

	i = 0;
	line = 1;
	tmp = env->instructions;
	ft_printf("\033[1m----------------DEBUG----------------\n\033[00m");
	while (tmp)
	{
		if (tmp->error != NONE)
		{
			ft_print_syntax_errors(tmp, line);
			i++;
		}
		line++;
		tmp = tmp->next;
	}
	if (i)
		ft_printf("\033[31mTotal number of syntax errors : %d\n\033[00m", i);
	else
		ft_printf("\033[32mOK !\n\033[00m");
	ft_print_env_errors(env);
	ft_print_instructions(env);
	return (i);
}

int		ft_check_error(t_lem *env)
{
	t_print *tmp;

	if (env->first == NULL || env->start_room == NULL || env->end_room == NULL
			|| env->start_room->distance == INT_MAX ||
			env->start_room == env->end_room)
		return (0);
	tmp = env->instructions;
	while (tmp)
	{
		if (tmp->error == NB_ANTS)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}
