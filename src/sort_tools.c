/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_tools.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbdoogls <jbdoogls@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/22 19:27:17 by jbdoogls          #+#    #+#             */
/*   Updated: 2020/06/01 14:22:59 by jbdoogls         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void		reset_roll_flags(t_frame *st, int a_fl, int b_fl)
{
	if (a_fl == DO_A)
	{
		st->ra = 0;
		st->rra = 0;
	}
	if (b_fl == DO_B)
	{
		st->rb = 0;
		st->rrb = 0;
	}
}

/*
**	Find the min & max values in 'a' before push elem to 'b' and start sorting
**		min & max will be holding in 'a'
*/

void		find_max_min(t_frame *st)
{
	int		min;
	int		max;
	int		ct;
	t_node	*head;

	head = st->a->head;
	max = head->val;
	min = head->val;
	ct = 0;
	while (ct < st->a->size)
	{
		if (head->val > max)
			max = head->val;
		else if (head->val < min)
			min = head->val;
		head = head ? head->next : NULL;
		ct++;
	}
	if (max > min)
	{
		st->max = max;
		st->min = min;
	}
}

/*
**	Tools for handling min_cost elem to insert from 'b' to 'a'
**		find_ins_cost - find the cost of insertion the elem
**		find_direction (head & tail) - find the best way to rolling 'a'
*/

int			find_direction_tail(t_frame *st, int val)
{
	int		cost_front;
	int		cost_back;
	t_node	*tail;

	tail = st->a->tail;
	cost_back = 0;
	cost_front = 0;
	while (val < tail->val && tail->val != st->max)
	{
		cost_back += 1;
		tail = tail ? tail->prev : NULL;
	}
	cost_front = st->a->size - cost_back;
	if (cost_back <= cost_front)
		st->rra = cost_back;
	else
		st->ra = cost_front;
	return (ft_nbrmin(cost_back, cost_front));
}

int			find_direction_head(t_frame *st, int val)
{
	int		cost_front;
	int		cost_back;
	t_node	*head;

	head = st->a->head;
	cost_back = 1;
	cost_front = 0;
	while (val > head->val)
	{
		cost_front += 1;
		head = head ? head->next : NULL;
	}
	cost_back = st->a->size - cost_front;
	if (cost_back >= cost_front)
		st->ra = cost_front;
	else
		st->rra = cost_back;
	return (ft_nbrmin(cost_back, cost_front));
}

int			find_ins(t_frame *st, int val)
{
	int		ct;
	int		cost;
	t_node	*head;

	reset_roll_flags(st, DO_A, DO_NOT_B);
	head = st->a->head;
	ct = 0;
	cost = 0;
	if (val < head->val && val > st->a->tail->val)
		return (cost);
	while (ct < st->a->size)
	{
		if (val < st->a->tail->val && val < head->val &&
			st->a->tail->val != st->max)
			cost = find_direction_tail(st, val);
		else if ((val > st->a->tail->val || st->a->tail->val == st->max) &&
			val > head->val)
			cost = find_direction_head(st, val);
		head = head ? head->next : NULL;
		ct++;
	}
	return (cost);
}
