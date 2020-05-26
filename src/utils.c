/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbdoogls <jbdoogls@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/10 21:02:38 by jbdoogls          #+#    #+#             */
/*   Updated: 2020/05/26 20:02:47 by jbdoogls         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_push_swap.h"

void    check_operation(char *op, t_frame *stor)
{
    if (ft_strcmp(op, "sa") && ft_strcmp(op, "sb") && ft_strcmp(op, "ss") &&
        ft_strcmp(op, "pa") && ft_strcmp(op, "pb") && ft_strcmp(op, "ra") &&
        ft_strcmp(op, "rb") && ft_strcmp(op, "rr") && ft_strcmp(op, "rra") &&
        ft_strcmp(op, "rrb") && ft_strcmp(op, "rrr"))
        {
            free(op);
            ft_put_err(&stor);
        }
}

int     do_operation(char *op, t_frame *stor)
{
    int     ret;
    ret = 0;
    if (ret = parse_operations(op, stor))
        return(ret);
    stor->op_ct++;
    print_op(op);
    return (ret);
}

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