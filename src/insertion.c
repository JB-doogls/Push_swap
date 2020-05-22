/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertion.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbdoogls <jbdoogls@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/18 14:40:21 by jbdoogls          #+#    #+#             */
/*   Updated: 2020/05/22 20:13:28 by jbdoogls         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_push_swap.h"

void        roll_a(t_frame *stor)
{
    while (stor->ra || stor->rra)
    {
        if (stor->ra)
        {
            do_operation("ra", stor);
            stor->ra--;
        }
        else
        {
            do_operation("rra", stor);
            stor->rra--;
        }
    }
}

void        roll_b(t_frame *stor)
{
    while (stor->rb || stor->rrb)
    {
        if (stor->rb)
        {
            do_operation("rb", stor);
            stor->rb--;
        }
        else
        {
            do_operation("rrb", stor);
            stor->rrb--;
        }   
    }
}

/*
**  Roll both stacks by rr \ rrr if possible, than roll needed stack
*/

void        roll_stacks(t_frame *stor)
{
    while (stor->ra && stor->rb)
    {
        do_operation("rr", stor);
        stor->ra--;
        stor->rb--;
    }
    while (stor->rra && stor->rrb)
    {
        do_operation("rrr", stor);
        stor->rra--;
        stor->rrb--;
    }
    roll_a(stor);
    roll_b(stor);
}

/*
**  Get sorted stack by using the insertion sort
**      1. Handle stack 'a' to push in stack 'b' pre-sorted elems;
**      2. Find the best elem to push (find_lowcoster);
**      3. Roll stacks to position for pushing. Than push to 'a' (pa);
**      4. Roll stack 'a' back to get correct posotion;
*/

void         insertion_sort(t_frame *stor)
{
    int     ct;
    size_t  size;

    handle_a(stor);
    ct = 0;
    size = stor->b->size;
    while (ct < size)
    {
        find_lowcoster(stor);
        roll_stacks(stor);
        do_operation("pa", stor);
        ct++;
    }
    while (stor->a->head->val != stor->min && stor->a->tail->val != stor->max)
        do_operation("rra", stor);

    // is_sorted(&stor->a);
}