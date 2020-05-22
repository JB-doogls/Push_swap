/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbdoogls <jbdoogls@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/10 21:02:38 by jbdoogls          #+#    #+#             */
/*   Updated: 2020/05/22 20:13:45 by jbdoogls         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_push_swap.h"

void        ft_put_err(t_frame **stor)
{
    ft_putstr("Error\n");
    free_frame(stor);
    exit(EXIT_FAILURE);
}

void        init_stor_values(t_frame *stor)
{
    stor->op_ct = 0;
    stor->grt = stor->max = stor->min = 0;
    stor->min_cost = 0;
    stor->pop_val = 0;
    stor->ra = stor->rra = 0;
    stor->rb = stor->rrb = 0;
}

void        print_op(char *op)
{
    ft_putstr(op);
    ft_putchar('\n');
}