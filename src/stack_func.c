/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_func.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/10 20:55:02 by jbdoogls          #+#    #+#             */
/*   Updated: 2020/08/08 20:02:43 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

t_stack			*create_stack_list(void)
{
	t_stack		*new;

	if (!(new = (t_stack*)malloc(sizeof(t_stack))))
		return (NULL);
	new->size = 0;
	new->head = NULL;
	new->tail = NULL;
	return (new);
}

void			free_stack(t_stack *stack)
{
	t_node		*next;
	t_node		*tmp;

	tmp = stack->head;
	next = NULL;
	while (tmp)
	{
		next = tmp->next;
		free(tmp);
		tmp = next;
	}
	free(stack);
	stack = NULL;
}

int				free_frame(t_frame **st)
{
	if (*st && (*st)->a)
		free_stack((*st)->a);
	if (*st && (*st)->b)
		free_stack((*st)->b);
	if (*st)
		free(*st);
	return (0);
}

void			handle_arg(char *arg, t_frame *st)
{
	int			i;
	int			num_ct;
	char		**split;

	split = NULL;
	*arg == '\0' ? ft_put_err(&st) : (num_ct = ft_word_count(arg, ' '));
	i = 0;
	if (num_ct == 1)
	{
		if (!push_back_val(&st->a, validation(arg, st)))
			ft_put_err(&st);
	}
	else
	{
		split = ft_strsplit(arg, ' ');
		while (i < num_ct)
		{
			if (!push_back_val(&st->a, validation(split[i], st)))
				ft_put_err(&st);
			free(split[i++]);
		}
	}
	free(split);
}

t_frame			*create_stack(int ac, char **av)
{
	t_frame		*st;
	int			i;

	i = 1;
	if (!(st = (t_frame*)malloc(sizeof(t_frame))))
		ft_put_err(&st);
	st->a = create_stack_list();
	st->b = create_stack_list();
	init_stor_values(st);
	while (ac > i)
	{
		is_visual_flags(av[i], st, &i);
		is_visual_flags(av[i], st, &i);
		handle_arg(av[i++], st);
	}
	return (st);
}
