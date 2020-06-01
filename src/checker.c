/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbdoogls <jbdoogls@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/26 16:01:07 by jbdoogls          #+#    #+#             */
/*   Updated: 2020/06/01 18:23:44 by jbdoogls         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	check_operation(char *op, t_frame *st)
{
	if (ft_strcmp(op, "sa") && ft_strcmp(op, "sb") && ft_strcmp(op, "ss") &&
		ft_strcmp(op, "pa") && ft_strcmp(op, "pb") && ft_strcmp(op, "ra") &&
		ft_strcmp(op, "rb") && ft_strcmp(op, "rr") && ft_strcmp(op, "rra") &&
		ft_strcmp(op, "rrb") && ft_strcmp(op, "rrr"))
	{
		free(op);
		ft_put_err(&st);
	}
}

int		main(int ac, char **av)
{
	t_frame		*st;
	char		*op;

	op = NULL;
	if (ac == 1)
		return (1);
	if (!(st = create_stack(ac, av)))
		ft_put_err(&st);
	while (get_next_line(0, &op))
	{
		check_operation(op, st);
		parse_operations(op, st);
		if (op)
			free(op);
	}
	free(op);
	if (is_sorted(&st->a, &st->b))
		ft_putstr("KO\n");
	else
		ft_putstr("OK\n");
	free_frame(&st);
	return (0);
}
