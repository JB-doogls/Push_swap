/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertion_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbdoogls <jbdoogls@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/26 23:51:40 by jbdoogls          #+#    #+#             */
/*   Updated: 2020/05/26 23:53:55 by jbdoogls         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_push_swap.h"

void		roll_a(t_frame *st)
{
	while (st->ra || st->rra)
	{
		if (st->ra)
		{
			do_operation("ra", st);
			st->ra--;
		}
		else
		{
			do_operation("rra", st);
			st->rra--;
		}
	}
}

void		roll_b(t_frame *st)
{
	while (st->rb || st->rrb)
	{
		if (st->rb)
		{
			do_operation("rb", st);
			st->rb--;
		}
		else
		{
			do_operation("rrb", st);
			st->rrb--;
		}
	}
}

/*
**	Roll both stacks by rr \ rrr if possible, than roll needed stack
*/

void		roll_stacks(t_frame *st)
{
	while (st->ra && st->rb)
	{
		do_operation("rr", st);
		st->ra--;
		st->rb--;
	}
	while (st->rra && st->rrb)
	{
		do_operation("rrr", st);
		st->rra--;
		st->rrb--;
	}
	roll_a(st);
	roll_b(st);
}

/*
**	Get sorted stack by using the insertion sort
**		1. Handle stack 'a' to push in stack 'b' pre-sorted elems;
**		2. Find the best elem to push (find_lowcoster);
**		3. Roll stacks to position for pushing. Than push to 'a' (pa);
**		4. Roll stack 'a' back to get correct position;
*/

void		insertion_sort(t_frame *st)
{
	int		ct;
	size_t	size;

	ct = 0;
	size = st->b->size;
	while (ct < size)
	{
		find_lowcoster(st);
		roll_stacks(st);
		do_operation("pa", st);
		ct++;
	}
	while (st->a->head->val != st->min && st->a->tail->val != st->max)
		do_operation("rra", st);
}
