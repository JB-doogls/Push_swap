/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visualization.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbdoogls <jbdoogls@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/27 14:41:53 by jbdoogls          #+#    #+#             */
/*   Updated: 2020/06/01 14:23:21 by jbdoogls         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void			is_visual_flags(char *arg, t_frame *st, int *i)
{
	if (!ft_strcmp(arg, "-v"))
	{
		st->flag_v = 1;
		*i += 1;
	}
	else if (!ft_strcmp(arg, "-c"))
	{
		st->flag_c = 1;
		*i += 1;
	}
}

void			print_stacks(t_frame *st)
{
	t_node	*a_head;
	t_node	*b_head;

	a_head = st->a->head;
	b_head = st->b->head;
	ft_putstr("stack a\t  stack b\n");
	while (a_head || b_head)
	{
		if (a_head)
			ft_putnbr(a_head->val);
		else
			ft_putchar('-');
		ft_putstr("\t|\t");
		if (b_head)
			ft_putnbr(b_head->val);
		else
			ft_putchar('-');
		ft_putchar('\n');
		a_head = a_head ? a_head->next : NULL;
		b_head = b_head ? b_head->next : NULL;
	}
	ft_putchar('\n');
}

void			print_color_stacks(t_frame *st)
{
	t_node	*a_head;
	t_node	*b_head;

	a_head = st->a->head;
	b_head = st->b->head;
	ft_putstr("stack a\t  stack b\n");
	while (a_head || b_head)
	{
		if (a_head)
			ft_putnbr_color(a_head->val, "green");
		else
			ft_putstr_color("-", "red");
		ft_putstr("\t|\t");
		if (b_head)
			ft_putnbr_color(b_head->val, "green");
		else
			ft_putstr_color("-", "red");
		ft_putchar('\n');
		a_head = a_head ? a_head->next : NULL;
		b_head = b_head ? b_head->next : NULL;
	}
	ft_putchar('\n');
}
