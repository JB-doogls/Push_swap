/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_a.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbdoogls <jbdoogls@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/22 02:42:17 by jbdoogls          #+#    #+#             */
/*   Updated: 2020/05/26 23:47:17 by jbdoogls         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_push_swap.h"

/*
**  Find counts of elems that current elem less than
*/

int				less_count(t_frame *st, int val)
{
	t_node	*head;
	int		ct;
	int		less;

	head = st->a->head;
	ct = 0;
	less = 0;
	while (ct < st->a->size)
	{
		if (val < head->val && head->val != st->max)
			less++;
		head = head ? head->next : NULL;
		ct++;
	}
	return (less);
}

/*
**	Find counts of elems that current elem greater than
*/

int				greater_count(t_frame *st, int val)
{
	t_node	*head;
	int		ct;
	int		grt;

	head = st->a->head;
	ct = 0;
	grt = 0;
	while (ct < st->a->size)
	{
		if (val > head->val && head->val != st->min)
			grt++;
		head = head ? head->next : NULL;
		ct++;
	}
	return (grt);
}

/*
**	Find the middle elem (half_of_a > 'middle elem' > half_of_a)
*/

int				find_mid(t_frame *st)
{
	int		mid;
	int		grt;
	int		less;
	t_node	*head;

	head = st->a->head;
	st->grt = 0;
	grt = 0;
	less = 0;
	mid = head->val;
	while (head)
	{
		grt = greater_count(st, head->val);
		less = less_count(st, head->val);
		if (grt >= ((st->a->size / 2) - 2) && less >= ((st->a->size / 2) - 2))
		{
			mid = head->val != st->max && head->val != st->min ?
			head->val : mid;
			st->grt = head->val != st->max && head->val != st->min ?
			grt : st->grt;
		}
		head = head ? head->next : NULL;
	}
	return (mid);
}

/*
**	Push in 'b' (pb) all elems of 'a'
**	up to middle elem (exclude the middle elem)
*/

void			pb_up_to_mid(t_frame *st, int mid)
{
	while (st->grt - 2 != 0)
	{
		if (st->a->head->val < mid && st->a->head->val != st->max &&
			st->a->head->val != st->min)
		{
			do_operation("pb", st);
			st->grt--;
		}
		else
			do_operation("ra", st);
	}
}

/*
**	Handle stack 'a' in the begining of the sort
**		1. find min & max elems (holding in 'a');
**		2. Handle the part of stack 'a' to get stack 'b' pre-sorted:
**			- find the 'middle elem' (half_of_a > 'middle elem' > half_of_a);
**			- Push in 'b' (pb) all elems in stack a less than middle elem;
**			- do same before size of stack a not equal 100 or 50
**		3. Push in 'b' (pb) all other stack a elems exclude min & max elems;
**		4. Get stack a in position head = min, tail = max;
*/

void			handle_a(t_frame *st)
{
	int		size;

	size = st->a->size;
	find_max_min(st);
	while (st->a->size >= (size >= 100 && size < 500 ? 50 : 100))
		pb_up_to_mid(st, find_mid(st));
	while (st->a->size != 2)
	{
		if (st->a->head->val != st->max && st->a->head->val != st->min)
			do_operation("pb", st);
		else
			do_operation("ra", st);
	}
	if (st->a->head->val > st->a->head->next->val)
		do_operation("sa", st);
}
