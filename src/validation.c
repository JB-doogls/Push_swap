/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbdoogls <jbdoogls@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/10 22:06:44 by jbdoogls          #+#    #+#             */
/*   Updated: 2020/05/27 01:07:22 by jbdoogls         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_push_swap.h"

int			is_sorted(t_stack **st_a, t_stack **st_b)
{
	t_node		*h;
	t_node		*t;
	size_t		ct;

	if ((*st_a) == NULL || (*st_b)->head != NULL)
		return (1);
	h = (*st_a)->head;
	t = (*st_a)->tail;
	ct = 0;
	while (ct < (*st_a)->size / 2)
	{
		if (h->val > t->val)
			return (1);
		if (h->val < h->next->val && t->val > t->prev->val)
			ct++;
		else
			return (1);
		h = h ? h->next : NULL;
		t = t ? t->prev : NULL;
	}
	return (0);
}

int			is_valid_int(int val, char *arg)
{
	char		*char_int;
	int			ret;
	int			ct;

	ret = 0;
	ct = 0;
	char_int = ft_itoa(val);
	if (val < -2147483648 || val > 2147483647)
		return (ret = 1);
	if (ft_strcmp(char_int, arg))
	{
		free(char_int);
		return (ret = 1);
	}
	while (char_int[ct])
	{
		if (char_int[ct] == '-')
			ct++;
		ret = !ft_isdigit(char_int[ct]) ? 1 : 0;
		ct++;
	}
	free(char_int);
	return (ret);
}

int			is_duplicate(int val, t_stack *stack)
{
	t_node		*head;

	head = stack->head;
	while (head)
	{
		if (head->val == val)
			return (1);
		head = head->next;
	}
	return (0);
}

int			validation(char *arg, t_frame *st)
{
	int			val;

	val = ft_atoi(arg);
	if (is_valid_int(val, arg) || is_duplicate(val, st->a))
		ft_put_err(&st);
	return (val);
}
