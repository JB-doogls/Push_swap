/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lowcoster.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbdoogls <jbdoogls@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/14 14:06:55 by jbdoogls          #+#    #+#             */
/*   Updated: 2020/05/22 20:07:45 by jbdoogls         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_push_swap.h"

/*
**  Find the cost to pop elem by the best way of rolling (rb \ rrb)
*/

int         find_pop_cost(t_frame *stor, int index)
{
    int         cost_front;
    int         cost_back;

    cost_front = cost_back = 0;
    stor->rb = stor->rrb = 0;
    if (index > stor->b->size / 2 && stor->b->size != 1)
        stor->rrb = (cost_back = stor->b->size - index);
    else
        stor->rb = (cost_front = index);
    return (ft_nbrmax(cost_back, cost_front));
}

/*
**  Find total cost by handling possible count of simultaneously ops (rr \ rrr)
*/

int         find_total_cost(t_frame *stor, int pop_cost, int ins_cost)
{
    int     cost;

    cost = pop_cost + ins_cost;
    if (stor->rra && stor->rrb)
        cost -= stor->rra >= stor->rrb ? stor->rrb : stor->rra;
    else if (stor->ra && stor->rb)
        cost -= stor->ra >= stor->rb ? stor->rb : stor->ra;
    return (cost);
}

/*
**  Store count of operations to handle the best elem
*/

void        reset_lowest(t_frame *stor)
{
    t_node      *head;
    int         index;

    index = 0;
    stor->ra = stor->rra = stor->rb = stor->rrb = 0;
    head = stor->b->head;
    while (head->val != stor->pop_val)
    {
        head = head ? head->next : NULL;
        index++;
    }
    find_pop_cost(stor, index);
    if (stor->pop_val < stor->a->tail->val && stor->pop_val < stor->a->head->val &&
        stor->a->tail->val != stor->max)
        find_direction_tail(stor, stor->pop_val);
    else if ((stor->pop_val > stor->a->tail->val || stor->a->tail->val == stor->max) &&
        stor->pop_val > stor->a->head->val)
        find_direction_head(stor, stor->pop_val);
}

/*
**  Choose the best elem (in case of equal costs choosing greater value)
*/

void        set_lowcoster(t_frame *stor)
{
    t_node      *head;

    head = stor->b->head;
    while (head)
    {
        if (head->cost == stor->min_cost)
            stor->pop_val = head->val > stor->pop_val ? head->val : stor->pop_val;
        head = head ? head->next : NULL;
    }
    if (stor->b->head->cost == stor->min_cost && stor->b->tail->cost == stor->min_cost &&
        (stor->b->head->val > stor->pop_val || stor->b->tail->val > stor->pop_val))
        stor->pop_val = stor->b->head->val > stor->b->tail->val ? stor->b->head->val : stor->b->tail->val;
    reset_lowest(stor);
}

/*
**  Find elem with minimal total cost
**      total_cost = (pop_cost) + (insertion cost) - (csimultaneously ops (rr \ rrr));
**      elem total_cost stored in head->cost;
**
**      set_lowcoster - get the best elem:
**          1. Choose the best elem (in case of an equal costs choosing greater value)
**          2. Store count of operations to handle the best elem (reset_lowcoster)
**              stor->ra, stor->rra - operation to pop the elem;
**              stor->rb, stor->rrb - operation to insert the elem;
*/

void        find_lowcoster(t_frame *stor)
{
    int         total;
    int         index;
    t_node      *head;

    total = index = 0;
    head = stor->b->head;
    stor->min_cost = 0;
    stor->pop_val = head->val;
    while (index < stor->b->size)
    {
        total = find_total_cost(stor, find_pop_cost(stor, index), find_insert_cost(stor, head->val));
        head->cost = total;
        stor->min_cost = (stor->min_cost > total || stor->min_cost == 0) ? total : stor->min_cost;
        head = head ? head->next : NULL;
        index++;
    }
    set_lowcoster(stor);
}