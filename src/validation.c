/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbdoogls <jbdoogls@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/10 22:06:44 by jbdoogls          #+#    #+#             */
/*   Updated: 2020/05/22 18:56:52 by jbdoogls         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_push_swap.h"

int         is_sorted(t_stack **stack)
{
    t_node     *h;
    t_node     *t;
    size_t      ct;
    int         vh;
    int         vt;

    if ((*stack) == NULL)
        return (1);
    vh = (h = (*stack)->head)->val;
    vt = (t = (*stack)->tail)->val;
    ct = 0;
    while (ct < (*stack)->size / 2)
    {
        if (vh > vt)
            return (1);
        if (h->val < (vh = h->next->val) && t->val > (vt = t->prev->val))
            ct++;
        else
            return (1);
        h = h ? h->next : NULL;
        t = t ? t->prev : NULL;
    }
    return (0);
}

int         is_valid_int(int val, char* arg)
{
    char    *char_int;
    int     ret;
    int     ct;

    ret = ct = 0;
    char_int = ft_itoa(val);
    if (val < -2147483648 || val > 2147483647)
        return (ret = 1);
    if (ft_strcmp(char_int, arg))
    {
        free(char_int);
        return (ret = 1);
    }
    while (char_int[ct])
    {
        if (char_int[ct] == '-')
            ct++;
        ret = !ft_isdigit(char_int[ct]) ? 1 : 0;
        ct++;     
    }
    free(char_int);
    return (ret);
}
int         is_duplicate(int val, t_stack *stack)
{
    t_node     *head;

    head = stack->head;
    while (head)
    {
        if (head->val == val)
            return (1);
        head = head->next;
    }
    return (0);
}

int     validation(char *arg, t_frame *stor)
{   
    int     val;

    val = ft_atoi(arg);
    if (is_valid_int(val, arg) || is_duplicate(val, stor->a))
        ft_put_err(&stor);
    return (val);
}