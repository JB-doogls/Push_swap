/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_pop.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbdoogls <jbdoogls@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/13 15:37:46 by jbdoogls          #+#    #+#             */
/*   Updated: 2020/05/27 00:39:20 by jbdoogls         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_push_swap.h"

t_node		*pop_back(t_stack **stack)
{
	t_node		*tmp;

	if ((*stack)->tail == NULL)
		return (NULL);
	tmp = (*stack)->tail;
	(*stack)->tail = (*stack)->tail->prev;
	if ((*stack)->tail)
		(*stack)->tail->next = NULL;
	if (tmp == (*stack)->head)
		(*stack)->head = NULL;
	(*stack)->size--;
	return (tmp);
}

t_node		*pop_front(t_stack **stack)
{
	t_node		*tmp;

	if ((*stack)->head == NULL)
		return (NULL);
	tmp = (*stack)->head;
	(*stack)->head = (*stack)->head->next;
	if ((*stack)->head)
		(*stack)->head->prev = NULL;
	if (tmp == (*stack)->tail)
		(*stack)->tail = NULL;
	(*stack)->size--;
	return (tmp);
}

void		push_front(t_stack **stack, t_node *node)
{
	if (node == NULL)
		;
	node->next = (*stack)->head;
	node->prev = NULL;
	if ((*stack)->head)
		(*stack)->head->prev = node;
	(*stack)->head = node;
	if ((*stack)->tail == NULL)
		(*stack)->tail = node;
	(*stack)->size++;
}

void		*push_back(t_stack **stack, t_node *node)
{
	node->next = NULL;
	node->prev = (*stack)->tail;
	if ((*stack)->tail)
		(*stack)->tail->next = node;
	(*stack)->tail = node;
	if ((*stack)->head == NULL)
		(*stack)->head = node;
	(*stack)->size++;
}

t_node		*push_back_val(t_stack **stack, int val)
{
	t_node		*new;

	if (!(new = create_new_node(val)))
		return (NULL);
	push_back(stack, new);
	return (new);
}
