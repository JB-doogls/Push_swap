/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lowcoster.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbdoogls <jbdoogls@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/14 14:06:55 by jbdoogls          #+#    #+#             */
/*   Updated: 2020/06/01 14:22:02 by jbdoogls         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

/*
**	Find the cost to pop elem by the best way of rolling (rb \ rrb)
*/

int			find_pop(t_frame *st, int index)
{
	int		cost_front;
	int		cost_back;

	cost_front = 0;
	cost_back = 0;
	reset_roll_flags(st, DO_NOT_A, DO_B);
	if (index > st->b->size / 2 && st->b->size != 1)
	{
		cost_back = st->b->size - index;
		st->rrb = cost_back;
	}
	else
	{
		cost_front = index;
		st->rb = cost_front;
	}
	return (ft_nbrmax(cost_back, cost_front));
}

/*
**	Find total cost by handling possible count of simultaneously ops (rr \ rrr)
*/

int			find_total(t_frame *st, int pop_cost, int ins_cost)
{
	int		cost;

	cost = pop_cost + ins_cost;
	if (st->rra && st->rrb)
		cost -= st->rra >= st->rrb ? st->rrb : st->rra;
	else if (st->ra && st->rb)
		cost -= st->ra >= st->rb ? st->rb : st->ra;
	return (cost);
}

/*
**	Store count of operations to handle the best elem
*/

void		reset_lowest(t_frame *st)
{
	t_node	*head;
	int		index;

	index = 0;
	reset_roll_flags(st, DO_A, DO_B);
	head = st->b->head;
	while (head->val != st->pop_val)
	{
		head = head ? head->next : NULL;
		index++;
	}
	find_pop(st, index);
	if (st->pop_val < st->a->tail->val &&
		st->pop_val < st->a->head->val && st->a->tail->val != st->max)
		find_direction_tail(st, st->pop_val);
	else if ((st->pop_val > st->a->tail->val ||
		st->a->tail->val == st->max) && st->pop_val > st->a->head->val)
		find_direction_head(st, st->pop_val);
}

/*
**	Choose the best elem (in case of equal costs choosing greater value)
*/

void		set_lowcoster(t_frame *st)
{
	t_node		*head;

	head = st->b->head;
	while (head)
	{
		if (head->cost == st->min_cost)
			st->pop_val = head->val > st->pop_val ? head->val : st->pop_val;
		head = head ? head->next : NULL;
	}
	if (st->b->head->cost == st->min_cost &&
		st->b->tail->cost == st->min_cost &&
		(st->b->head->val > st->pop_val ||
		st->b->tail->val > st->pop_val))
		st->pop_val = st->b->head->val > st->b->tail->val ?
		st->b->head->val : st->b->tail->val;
	reset_lowest(st);
}

/*
**	Find elem with minimal total cost
**		total_cost = (pop_cost) + (insertion cost) - (rr \ rrr);
**		elem total_cost stored in head->cost;
**
**		set_lowcoster - get the best elem:
**			1. Choose the best elem
**				(in case of an equal costs choosing greater value)
**			2. Store count of operations to handle the best elem
**				st->ra, st->rra - operation to pop the elem;
**				st->rb, st->rrb - operation to insert the elem;
*/

void		find_lowcoster(t_frame *st)
{
	int		total;
	int		ind;
	t_node	*head;

	total = 0;
	ind = 0;
	head = st->b->head;
	st->min_cost = 0;
	st->pop_val = head->val;
	while (ind < st->b->size)
	{
		total = find_total(st, find_pop(st, ind), find_ins(st, head->val));
		head->cost = total;
		st->min_cost = (st->min_cost > total || st->min_cost == 0) ?
		total : st->min_cost;
		head = head ? head->next : NULL;
		ind++;
	}
	set_lowcoster(st);
}
