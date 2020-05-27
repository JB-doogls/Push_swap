/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbdoogls <jbdoogls@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/10 20:45:13 by jbdoogls          #+#    #+#             */
/*   Updated: 2020/05/27 19:20:20 by jbdoogls         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_push_swap.h"

void		sort_five(t_frame *st)
{
	find_max_min(st);
	while (st->a->size != 3)
	{
		if (st->a->head->val != st->max &&
			st->a->head->val != st->min &&
			(st->a->head->next->val == st->min ||
			st->a->head->next->val == st->max))
			do_operation("sa", st);
		if (st->a->head->val == st->max || st->a->head->val == st->min)
			do_operation("pb", st);
		else if (st->a->tail->val == st->max ||
			st->a->tail->val == st->min)
			do_operation("rra", st);
		else
			do_operation("ra", st);
	}
	sort_three(st);
	if (st->b->head->val != st->min)
		do_operation("sb", st);
	do_operation("pa", st);
	do_operation("pa", st);
	do_operation("ra", st);
}

void		sort_three(t_frame *st)
{
	if (st->a->head->val > st->a->head->next->val &&
		st->a->head->val < st->a->tail->val)
		do_operation("sa", st);
	else if (st->a->head->val > st->a->tail->val &&
		st->a->head->val > st->a->head->next->val)
		do_operation("ra", st);
	else if (st->a->head->val < st->a->head->next->val)
		do_operation("rra", st);
	if (st->a->head->val > st->a->head->next->val)
		do_operation("sa", st);
}

int			main(int ac, char **av)
{
	t_frame		*st;

	if (!(st = create_stack(ac, av)))
		return (free_frame(&st));
	if (st->a->head == NULL || !is_sorted(&st->a, &st->b))
		return (0);
	if (st->a->size <= 3)
		sort_three(st);
	else if (st->a->size == 5)
		sort_five(st);
	else
	{
		handle_a(st);
		insertion_sort(st);
	}
	free_frame(&st);
	return (0);
}
