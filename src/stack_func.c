/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_func.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbdoogls <jbdoogls@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/10 20:55:02 by jbdoogls          #+#    #+#             */
/*   Updated: 2020/05/14 13:41:41 by jbdoogls         ###   ########.fr       */
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

    i = 0;
    split = NULL;
    num_ct = ft_word_count(arg, ' ');
    if (num_ct == 1)
    {
        val = validation(arg, stor);
        if (push_back_val(&stor->a, val) == NULL)
            ft_put_err(&stor);
    }
    else
    {
        split = ft_strsplit(arg, ' ');
        while (i < num_ct)
        {
            val = validation(split[i], stor);
            if (push_back_val(&stor->a, val) == NULL)
                ft_put_err(&stor);
            free(split[i]);
            i++;
        }
    }
}

//     av = (ac == 2 ? ft_strsplit(av[1], ' ') : av);
//     ct = (ac == 2 ? 0 : 1);
//     while ((ac == 2 ? (int)av[ct] : ct < ac))    // check if empty arg: push_swap "" "1 3 4" ..
//     {
//         val = ft_atoi(av[ct]);
//         if (!is_valid_int(val, av[ct]) || !is_duplicate(val, stor->a))
//         {
//             ft_memdel((void*)(ac == 2 ? av : NULL));
//             ft_put_err(&stor);
//         }
//         if (!push_back_val(stor->a, val))
//         {
//             ft_memdel((void*)(ac == 2 ? av : NULL));
//             ft_put_err(&stor);
//         }
//         ct++;
//     }
//     ft_memdel((void*)(ac == 2 ? av : NULL));
// }

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