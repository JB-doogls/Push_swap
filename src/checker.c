/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbdoogls <jbdoogls@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/26 16:01:07 by jbdoogls          #+#    #+#             */
/*   Updated: 2020/05/26 20:06:31 by jbdoogls         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_push_swap.h"

int     main(int ac, char **av)
{
    t_frame     *stor;
    char        *op;

    op = NULL;
    if (ac == 1)
        return (1);
    if (!(stor = create_stack(ac, av)))
        ft_put_err(&stor);
    while (get_next_line(0, &op))
    {
        check_operation(op, stor);
        parse_operations(op, stor);
        if (op)
            free(op);
    }
    free(op);
    if (is_sorted(&stor->a))
        ft_putstr("KO\n");
    else
        ft_putstr("OK\n");
    free_frame(&stor);
    return (0);
}