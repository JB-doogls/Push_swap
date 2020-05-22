/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbdoogls <jbdoogls@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/07 13:50:35 by jbdoogls          #+#    #+#             */
/*   Updated: 2020/05/22 19:54:30 by jbdoogls         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PUSH_SWAP
# define FT_PUSH_SWAP

# include "../libft/libft.h"
# include <stdbool.h>
# include <stdlib.h>        // DEL? - duplicate include in libft
# include <stdio.h>         //  DEL - FOR CHECKING

typedef struct      s_node
{
    int             val;
    int             cost;
    struct s_node  *prev;
    struct s_node  *next;
}                   t_node;

typedef struct      s_stack
{
    size_t          size;
    t_node          *head;
    t_node          *tail;
}                   t_stack;

typedef struct      s_frame
{
    t_stack         *a;
    t_stack         *b;
    size_t          op_ct;
    int             max;
    int             min;
    int             grt;
    int             min_cost;
    int             pop_val;
    int             rra;
    int             ra;
    int             rrb;
    int             rb;

       
}                   t_frame;

/*
**  stack funcs
*/

t_frame             *create_stack(int ac, char **av);
void                handle_arg(char *arg, t_frame *stor);
int                 free_frame(t_frame **stor);
void                free_stack(t_stack *stack);
t_stack             *create_stack_list(t_stack *stack);
void                init_stor_values(t_frame *stor);

/*
**  push & pop funcs
*/

t_node             *push_back_val(t_stack **stack, int val);
void                *push_back(t_stack **stack, t_node *node);
void                push_front(t_stack **stack, t_node *node);
t_node              *pop_front(t_stack **stack);
t_node              *pop_back(t_stack **stack);
t_node              *create_new_node(int val);

/*
**  funcs to handle operations sa/sb/ss, pa/pb, ra/rb/rr, rra/rrb/rrr
*/

int                 parse_operations(char *op, t_frame *stor);
int                 handle_s(t_stack **stack);
int                 handle_p(t_stack **from, t_stack **to);
int                 handle_r(t_stack **stack);
int                 handle_rr(t_stack **stack);

int                 do_operation(char *op, t_frame *stor);
/*
**  validation & tools
*/

int                 validation(char *arg, t_frame *stor);
int                 is_valid_int(int val, char *val_av);
int                 is_duplicate(int val, t_stack *stack);          // rewrite to list from head and tail
void                ft_put_err(t_frame **stor);

void                print_op(char *op);

/*
**  sort tools
*/

void                sort_three(t_frame *stor);

int                 is_sorted(t_stack **stack);
void                insertion_sort(t_frame *stor);

void                find_lowcoster(t_frame *stor);
int                 find_insert_cost(t_frame *stor, int val);
int                 find_direction_head(t_frame *stor, int val);
int                 find_direction_tail(t_frame *stor, int val);
int                 find_pop_cost(t_frame *stor, int index);
int                 find_total_cost(t_frame *stor, int pop_cost, int ins_cost);

void                set_lowcoster(t_frame *stor);
void                reset_lowest(t_frame *stor);


// void                pb_max_min(t_frame *stor);
void                handle_a(t_frame *stor);
void                find_max_min(t_frame *stor);
int                 find_mid(t_frame *stor);
int                 greater_count(t_frame *stor, int val);
int                 less_count(t_frame *stor, int val);
void                pb_up_to_mid(t_frame *stor, int mid);


void                roll_stacks(t_frame *stor);
void                roll_a(t_frame *stor);
void                roll_b(t_frame *stor);


#endif