/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgauguet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/20 17:12:46 by sgauguet          #+#    #+#             */
/*   Updated: 2018/06/13 12:25:39 by sgauguet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H

# define LEM_IN_H
# define MAX_INSTRUCTIONS 10100
# include "./libft/libft.h"

typedef enum	e_error
{
	EMPTY_LINE, EMPTY_ROOM, EMPTY_LINK, MISSING_ANT, NB_ANTS, ROOM_EXIST,
	ROOM_SPACES, NB_ROOMS, ROOM_COORD, ROOM_NAME, LINK_MINUS, NB_LINKS,
	MISSING_ROOM, SAME_ROOM, UNDEFINED, START_ROOM, END_ROOM, PART, NONE
}				t_error;

typedef	enum	e_color
{
	WHITE, GREY, BLACK
}				t_color;

typedef struct	s_ant
{
	int				nb;
	int				print;
	struct s_room	*prev;
	struct s_ant	*next;
}				t_ant;

typedef struct	s_lem
{
	int				nb_ants;
	int				part;
	int				debug_option;
	int				count_option;
	int				print_option;
	int				path_option;
	struct s_room	*first;
	struct s_room	*last;
	struct s_room	*start_room;
	struct s_room	*end_room;
	struct s_print	*instructions;
}				t_lem;

typedef struct	s_room
{
	char			*name;
	int				x;
	int				y;
	t_ant			*ant;
	int				distance;
	int				move;
	enum e_color	color;
	struct s_link	*link;
	struct s_room	*next;
}				t_room;

typedef	struct	s_link
{
	struct s_room	*link;
	struct s_link	*next;
}				t_link;

typedef	struct	s_print
{
	char			*str;
	enum e_error	error;
	struct s_print	*next;
}				t_print;

/*
** sort.c
*/

int				end(t_lem *env);
int				init(t_lem *env);
t_room			*ft_is_sorted(t_lem *env);
int				sort(t_lem *env);

/*
** ant.c
*/

int				print_ants2(t_room *tmp, t_ant *ant, int space);
int				print_ants(t_lem *env);
t_ant			*ft_create_ant(int nb);
t_ant			*ft_init_ants(int nb_ants);

/*
** solve_2.c
*/

void			make_move(t_room *current, t_room *next);
int				forbidden_room(t_lem *env, t_room *next, t_room *prev);
int				min_number_laps_remaining(t_lem *env);
int				better_wait(t_lem *env, t_room *current, t_room *result,
				int min_distance);
t_room			*search_better_path(t_lem *env, t_room *current,
				t_room *smallest_path, int min_distance);

/*
** solve.c
*/

int				start_move(t_lem *env, t_room *result, int min_distance);
int				move_ants(t_lem *env, t_room *current, t_room *result,
				int min_distance);
void			solve(t_lem *env);

/*
** search_path.c
*/

void			ft_print_path(t_lem *env);
t_link			*enqueue(t_link *queue, t_room *new);
t_link			*dequeue(t_link *queue);
t_room			*init_end_room(t_lem *env);
void			breadth_first_search(t_lem *env);

/*
** free_mem.c
*/

t_ant			*free_ants(t_lem *env);
void			free_string(char **str);
void			free_instructions(t_print *instructions);
void			free_links(t_room *ptr);
void			free_env(t_lem *env);

/*
** error.c
*/

void			ft_print_env_errors(t_lem *env);
void			ft_print_syntax_errors2(t_print *line, int nb);
void			ft_print_syntax_errors(t_print *line, int nb);
int				debug(t_lem *env);
int				ft_check_error(t_lem *env);

/*
** comments.c
*/

t_room			*ft_search_room(t_lem *env, t_print *line);
int				ft_check_comments(t_lem *env, t_print *line, t_room *ptr);
int				ft_read_comments(t_lem *env, t_print *line);
int				ft_check_ants(t_lem *env, t_print *line);
int				ft_nb_ants(t_lem *env, t_print *line);

/*
** links.c
*/

int				ft_check_minus(t_print *line);
char			**ft_check_size_link(t_print *line);
char			**ft_check_link(t_lem *env, t_print *line);
int				ft_add_link(t_lem *env, t_room *room1, t_room *room2);
int				ft_create_links(t_lem *env, t_print *line);

/*
** check_rooms.c
*/

int				ft_check_spaces(t_print *line);
int				ft_check_coordinates(char **result, t_print *line);
char			**ft_check_size(t_print *line);
char			**ft_check_new_room(t_lem *env, t_print *line);

/*
** rooms.c
*/

t_room			*ft_init_room(char **result);
int				ft_create_room(t_lem *env, t_print *line);
int				ft_build_anthill(t_lem *env, t_print *line);

/*
** instructions.c
*/

int				ft_print_instructions(t_lem *env);
int				ft_check_instructions(t_lem	*env, t_print *line);
int				ft_add_instructions(t_lem *env, char *line);
int				ft_read_instructions(t_lem *env);

/*
** lem_in.c
*/

void			ft_print_anthill(t_lem *env);
int				bonus_options(t_lem *env);
int				ft_search_options(char **argv, t_lem *env);
int				ft_init_env(t_lem *env);
int				main(int argc, char **argv);

#endif
