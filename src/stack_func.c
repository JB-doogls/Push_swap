/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_func.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbdoogls <jbdoogls@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/10 20:55:02 by jbdoogls          #+#    #+#             */
/*   Updated: 2020/05/26 17:13:49 by jbdoogls         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_push_swap.h"

t_stack         *create_stack_list(t_stack *stack)
{
    t_stack     *new;

    if (!(new = (t_stack*)malloc(sizeof(t_stack))))
        return (NULL);
    new->size = 0;
    new->head = new->tail = NULL;
    stack = new;
    return (new);
}

void            free_stack(t_stack *stack)
{
    t_node     *next;
    t_node     *tmp;

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

int             free_frame(t_frame **stor)
{
    if (*stor && (*stor)->a)
        free_stack((*stor)->a);
    if (*stor && (*stor)->b)
        free_stack((*stor)->b);
    if (*stor)
        free(*stor);
    return (0);
}

void     handle_arg(char *arg, t_frame *stor)
{
    int         i;
    int         val;
    int         num_ct;
    char        **split;

    split = NULL;
    i = (num_ct = ft_word_count(arg, ' ')) - num_ct;
    if (num_ct == 1)
    {
        if (!push_back_val(&stor->a, val = validation(arg, stor)))
            ft_put_err(&stor);
    }
    else
    {
        split = ft_strsplit(arg, ' ');
        while (i < num_ct)
        {
            if (!push_back_val(&stor->a, val = validation(split[i], stor)))
                ft_put_err(&stor);
            free(split[i++]);
        }
    }
    free(split);
}

t_frame         *create_stack(int ac, char **av)
{
    t_frame     *stor;
    int         i;
    int         j;

    i = 1;
    if (!(stor = (t_frame*)malloc(sizeof(t_frame))))
        ft_put_err(&stor);
    stor->a = create_stack_list(stor->a);
    stor->b = create_stack_list(stor->b);
    init_stor_values(stor);
    while (ac > i)
        handle_arg(av[i++], stor);
    return (stor);
}