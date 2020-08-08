/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/07 13:50:35 by jbdoogls          #+#    #+#             */
/*   Updated: 2020/08/08 20:03:20 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PUSH_SWAP_H
# define FT_PUSH_SWAP_H

# include "libft.h"

# define DO_A 1
# define DO_NOT_A 0
# define DO_B 1
# define DO_NOT_B 0

typedef struct		s_node
{
	int				val;
	int				cost;
	struct s_node	*prev;
	struct s_node	*next;
}					t_node;

typedef struct		s_stack
{
	int				size;
	t_node			*head;
	t_node			*tail;
}					t_stack;

typedef struct		s_frame
{
	t_stack			*a;
	t_stack			*b;
	int				op_ct;
	int				max;
	int				min;
	int				grt;
	int				min_cost;
	int				pop_val;
	int				rra;
	int				ra;
	int				rrb;
	int				rb;
	int				flag_v;
	int				flag_c;
}					t_frame;

/*
**	stack funcs
*/

t_frame				*create_stack(int ac, char **av);
void				handle_arg(char *arg, t_frame *st);
int					free_frame(t_frame **st);
void				free_stack(t_stack *stack);
t_stack				*create_stack_list(void);
void				init_stor_values(t_frame *st);

/*
**	push & pop funcs
*/

t_node				*push_back_val(t_stack **stack, int val);
void				push_back(t_stack **stack, t_node *node);
void				push_front(t_stack **stack, t_node *node);
t_node				*pop_front(t_stack **stack);
t_node				*pop_back(t_stack **stack);
t_node				*create_new_node(int val);

/*
**	funcs to handle operations sa/sb/ss, pa/pb, ra/rb/rr, rra/rrb/rrr
*/

int					parse_operations(char *op, t_frame *st);
int					handle_s(t_stack **stack);
int					handle_p(t_stack **from, t_stack **to);
int					handle_r(t_stack **stack);
int					handle_rr(t_stack **stack);
int					do_operation(char *op, t_frame *st);

/*
**	validation & tools
*/

int					validation(char *arg, t_frame *st);
int					is_valid_int(int val, char *val_av);
int					is_duplicate(int val, t_stack *stack);
void				ft_put_err(t_frame **st);
void				print_op(char *op, t_frame *st);
void				check_operation(char *op, t_frame *st);
void				reset_roll_flags(t_frame *st, int a_fl, int b_f);

/*
**	sort tools
*/

void				sort_three(t_frame *st);
void				sort_five(t_frame *st);
int					is_sorted(t_stack **st_a, t_stack **st_b);
void				insertion_sort(t_frame *st);
void				find_lowcoster(t_frame *st);
void				set_lowcoster(t_frame *st);
void				reset_lowest(t_frame *st);
int					find_pop(t_frame *st, int index);
int					find_total(t_frame *st, int pop_cost, int ins_cost);
int					find_ins(t_frame *st, int val);
int					find_direction_head(t_frame *st, int val);
int					find_direction_tail(t_frame *st, int val);

void				handle_a(t_frame *st);
void				find_max_min(t_frame *st);
int					find_mid(t_frame *st);
int					greater_count(t_frame *st, int val);
int					less_count(t_frame *st, int val);
void				pb_up_to_mid(t_frame *st, int mid);

void				roll_stacks(t_frame *st);
void				roll_a(t_frame *st);
void				roll_b(t_frame *st);

/*
**	visualisation
**		flag -v : print stacks 'a'&'b' after each operation;
**		flag -c : colorize operaion and stacks (if -v);
**		usage: -c -v "integers"
*/

void				is_visual_flags(char *arg, t_frame *st, int *i);
void				print_stacks(t_frame *st);
void				print_color_stacks(t_frame *st);

#endif
