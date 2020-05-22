/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_a.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbdoogls <jbdoogls@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/22 02:42:17 by jbdoogls          #+#    #+#             */
/*   Updated: 2020/05/22 20:07:46 by jbdoogls         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_push_swap.h"

/*
**  Find counts of elems that current elem less than
*/

int             less_count(t_frame *stor, int val)
{
    t_node  *head;
    int     ct;
    int     less;

    head = stor->a->head;
    ct = less =  0;
    while (ct < stor->a->size)
    {
        if (val < head->val && head->val != stor->max)
            less++;
        head = head? head->next : NULL;
        ct++;
    }
    return (less);
}

/*
**  Find counts of elems that current elem greater than
*/

int             greater_count(t_frame *stor, int val)
{
    t_node  *head;
    int     ct;
    int     grt;

    head = stor->a->head;
    ct = grt =  0;
    while (ct < stor->a->size)
    {
        if (val > head->val && head->val != stor->min)
            grt++;
        head = head? head->next : NULL;
        ct++;
    }
    return (grt);
}

/*
**  Find the middle elem (half_of_a > 'middle elem' > half_of_a)
*/

int            find_mid(t_frame *stor)
{
    int     mid;
    int     grt;
    int     less;
    t_node  *head;

    head = stor->a->head;
    stor->grt = grt = less = 0;
    mid = head->val;
    while (head)
    {
        grt = greater_count(stor, head->val);
        less = less_count(stor, head->val);
        if (grt >= ((stor->a->size / 2) - 2) && less >= ((stor->a->size / 2) - 2))
        {
            mid = head->val != stor->max && head->val != stor->min ? head->val : mid;
            stor->grt = head->val != stor->max && head->val != stor->min ? grt : stor->grt;
        }
        head = head ? head->next : NULL;
    }
    return (mid);
}

/*
**  Push in 'b' (pb) all elems of 'a' up to middle elem (exclude the middle elem)
*/

void            pb_up_to_mid(t_frame *stor, int mid)
{
    while (stor->grt - 2 != 0)
    {
        if (stor->a->head->val < mid && stor->a->head->val != stor->max && stor->a->head->val != stor->min)
        {
            do_operation("pb", stor);
            stor->grt--;
        }
        else
            do_operation("ra", stor);
    }
}

/*
**  Handle stack 'a' in the begining of the sort
**      1. find min & max elems (holding in 'a');
**      2. Handle the part of stack 'a' to get stack 'b' pre-sorted:
**          - find the 'middle elem' (half_of_a > 'middle elem' > half_of_a);
**          - Push in 'b' (pb) all elems in stack a less than middle elem;
**          - do same before size of stack a not equal 100 or 50 (for >=500 and >= 100 elem)
**      3. Push in 'b' (pb) all other stack a elems exclude min & max elems;
**      4. Get stack a in position head = min, tail = max;
*/

void            handle_a(t_frame *stor)
{
    int     size;
    
    size = stor->a->size;
    find_max_min(stor);
    while (stor->a->size >= (size >= 100 && size < 500 ? 50 : 100))
        pb_up_to_mid(stor, find_mid(stor));   
    while (stor->a->size != 2)
    {
        if (stor->a->head->val != stor->max && stor->a->head->val != stor->min)
            do_operation("pb", stor);
        else
            do_operation("ra", stor);
    }
    if (stor->a->head->val > stor->a->head->next->val)
        do_operation("sa", stor);
}