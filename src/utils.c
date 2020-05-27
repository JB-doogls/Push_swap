/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbdoogls <jbdoogls@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/10 21:02:38 by jbdoogls          #+#    #+#             */
/*   Updated: 2020/05/27 16:01:26 by jbdoogls         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_push_swap.h"

t_node		*create_new_node(int val)
{
	t_node		*new;

	if (!(new = (t_node*)malloc(sizeof(t_node))))
		return (NULL);
	new->val = val;
	new->cost = 0;
	new->next = NULL;
	new->prev = NULL;
	return (new);
}

int			do_operation(char *op, t_frame *st)
{
	int		ret;

	ret = 0;
	if (ret = parse_operations(op, st))
		return (ret);
	st->op_ct++;
	print_op(op, st);
	if (st->v && !st->c)
		print_stacks(st);
	else if (st->v && st->c)
		print_color_stacks(st);
	return (ret);
}

void		ft_put_err(t_frame **st)
{
	if ((*st)->c)
		ft_putstr_color("Error\n", "red");
	else
		ft_putstr("Error\n");
	free_frame(st);
	exit(EXIT_FAILURE);
}

void		init_stor_values(t_frame *st)
{
	st->op_ct = 0;
	st->grt = 0;
	st->max = 0;
	st->min = 0;
	st->min_cost = 0;
	st->pop_val = 0;
	st->ra = 0;
	st->rra = 0;
	st->rb = 0;
	st->rrb = 0;
	st->v = 0;
	st->c = 0;
}

void		print_op(char *op, t_frame *st)
{
	if (st->c)
		ft_putstr_color(op, "bold blue");
	else
		ft_putstr(op);
	ft_putchar('\n');
}
