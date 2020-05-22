/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_tools.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbdoogls <jbdoogls@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/22 19:27:17 by jbdoogls          #+#    #+#             */
/*   Updated: 2020/05/22 19:34:54 by jbdoogls         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_push_swap.h"

/*
**  Find the min & max values in 'a' before push elem to 'b' and start sorting
**      min & max will be holding in 'a'
*/

void        find_max_min(t_frame *stor)
{
    int     min;
    int     max;
    int     ct;
    t_node  *head;

    max = min = (head = stor->a->head)->val;
    ct = 0;
    while (ct < stor->a->size)
    {
        if (head->val > max)
            max = head->val;
        else if (head->val < min)
            min = head->val;
        head = head ? head->next : NULL;
        ct++;
    }
    if (max > min)
    {
        stor->max = max;
        stor->min = min;
    }
}

/*
**  Tools for handling min_cost elem to insert from 'b' to 'a'
**      find_insert_cost - find the cost of insertion the elem
**      find_direction (head & tail) - find the best way to rolling 'a': ra / rra
*/

int         find_direction_tail(t_frame *stor, int val)
{
    int         cost_front;
    int         cost_back;
    t_node      *tail;

    tail = stor->a->tail;
    cost_back = cost_front = 0;
    while (val < tail->val && tail->val != stor->max)
    {
        cost_back += 1;
        tail = tail ? tail->prev : NULL;
    }
    cost_front = stor->a->size - cost_back;
    if (cost_back <= cost_front)
        stor->rra = cost_back;
    else
        stor->ra = cost_front;
    return(ft_nbrmin(cost_back, cost_front));
}

int         find_direction_head(t_frame *stor, int val)
{
    int         cost_front;
    int         cost_back;
    t_node      *head;

    head = stor->a->head;
    cost_back = (cost_front = 0) + 1;
    while (val > head->val)
    {
        cost_front += 1;
        head = head ? head->next : NULL;
    }
    cost_back = stor->a->size - cost_front;
    if (cost_back >= cost_front)
        stor->ra = cost_front;
    else
        stor->rra = cost_back;
    return(ft_nbrmin(cost_back, cost_front));
}

int         find_insert_cost(t_frame *stor, int val)
{
    size_t      ct;
    int         cost;
    t_node      *head;

    stor->rra = stor->ra = 0;
    head = stor->a->head;
    ct = cost = 0;
    if (val < head->val && val > stor->a->tail->val)
        return (cost);
    while (ct < stor->a->size)
    {
        if (val < stor->a->tail->val && val < head->val && stor->a->tail->val != stor->max)
            cost = find_direction_tail(stor, val);
        else if ((val > stor->a->tail->val || stor->a->tail->val == stor->max) && val > head->val)
            cost = find_direction_head(stor, val);
        head = head ? head->next : NULL;
        ct++;
    }
    return (cost);
}