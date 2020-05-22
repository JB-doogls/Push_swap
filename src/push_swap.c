/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbdoogls <jbdoogls@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/10 20:45:13 by jbdoogls          #+#    #+#             */
/*   Updated: 2020/05/22 19:07:50 by jbdoogls         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_push_swap.h"

void        sort_three(t_frame *stor)
{
    if (stor->a->head->val > stor->a->head->next->val &&
        stor->a->head->val < stor->a->tail->val)
        do_operation("sa", stor);
    else if (stor->a->head->val > stor->a->tail->val)
        do_operation("ra", stor);
}

int         main(int ac, char **av)
{
    t_frame     *stor;
    
    if (!(stor = create_stack(ac, av)))
        return (free_frame(&stor));
    printf("size = |%ld|\n", stor->a->size);
    if (stor->a->head == NULL || !is_sorted(&stor->a))
        return (0);
    if (stor->a->size <= 3)
        sort_three(stor);
    else
        insertion_sort(stor);
    printf("FINAL OP_CT = |%ld|\n", stor->op_ct);
/*
**  sort check
*/
    if (is_sorted(&stor->a))
        printf("Unsorted\n");
    else
        printf("Sorted\n");


/*
**  stacks check & print
*/

    // printf("op_ct = %ld\n", stor->op_ct);
    // printf("max = %d\n", stor->max);
    // printf("min = %d\n", stor->min);
    // t_node  *p = stor->a->head;
    // printf("----a----\n");
    // while (p)
    // {
    //     printf("%d\n", p->val);
    //     p = p ? p->next : NULL;
    // }

    // printf("----b----\n");
    // t_node  *p1 = stor->b->head;
    // while (p1)
    // {
    //     printf("%d\n", p1->val);
    //     p1 = p1 ? p1->next : NULL;
    // }

    // printf("----------lowcost#1-------------\n");
    // find_lowcost(stor);
    // printf("-----------------------\n");
    // printf("FINAL_min_cost = |%ld|\n", stor->min_cost);
    // printf("FINAL_pop_cost = |%ld|\n", stor->pop_cost);
    
    // do_operation("pa", stor);
    // do_operation("sa", stor);
    // p = stor->a->head;
    // printf("----a----\n");
    // while (p)
    // {
    //     printf("%d\n", p->val);
    //     p = p ? p->next : NULL;
    // }

    // printf("----b----\n");
    // p1 = stor->b->head;
    // while (p1)
    // {
    //     printf("%d\n", p1->val);
    //     p1 = p1 ? p1->next : NULL;
    // }
    
    // printf("----------lowcost#2-------------\n");    
    // find_lowcost(stor);
    // printf("-----------------------\n");
    // printf("FINAL_min_cost = |%ld|\n", stor->min_cost);
    // printf("FINAL_pop_cost = |%ld|\n", stor->pop_cost);

    // do_operation("sb", stor);
    // do_operation("pa", stor);
    // do_operation("sa", stor);
    // p = stor->a->head;
    // printf("----a----\n");
    //     while (p)
    // {
    //     printf("%d\n", p->val);
    //     p = p ? p->next : NULL;
    // }

    // printf("----b----\n");
    // p1 = stor->b->head;
    // while (p1)
    // {
    //     printf("%d\n", p1->val);
    //     p1 = p1 ? p1->next : NULL;
    // }
    // printf("----------lowcost#3-------------\n");    
    // find_lowcost(stor);
    // printf("-----------------------\n");
    // printf("FINAL_min_cost = |%ld|\n", stor->min_cost);
    // printf("FINAL_pop_cost = |%ld|\n", stor->pop_cost);
    // // do_operation("pa", stor);   // 19
    // // do_operation("sa", stor);
    // // do_operation("ra", stor);
    // // do_operation("sa", stor);
    // // do_operation("ra", stor);
    // // do_operation("sa", stor);

    // do_operation("rrb", stor);      // 6
    // do_operation("pa", stor);
    // do_operation("sa", stor);
    // do_operation("ra", stor);
    // do_operation("sa", stor);
    // p = stor->a->head;
    // printf("----a----\n");
    //     while (p)
    // {
    //     printf("%d\n", p->val);
    //     p = p ? p->next : NULL;
    // }

    // printf("----b----\n");
    // p1 = stor->b->head;
    // while (p1)
    // {
    //     printf("%d\n", p1->val);
    //     p1 = p1 ? p1->next : NULL;
    // }
    
    // printf("----------lowcost#4-------------\n");    
    // find_lowcost(stor);
    // printf("-----------------------\n");
    // printf("FINAL_min_cost = |%ld|\n", stor->min_cost);
    // printf("FINAL_pop_cost = |%ld|\n", stor->pop_cost);

    // printf("\n%d\n", 1/2);
    return (0);
}