
/*
**      TODO

**              - write sort for 5 (what about 4???)
**              - write checker prog
**              - when we check if_sorted? What we do if sorted on input? (now we work with sorted array !!!!!)
*/


// 100 num
// FINAL op_ct = |2963| ver with sa ra
// FINAL op_ct = |1982| ver with rolling
// FINAL op_ct = |1570| ver with rolling + find_direction_head
// FINAL op_ct = |1456| ver with rolling + find_direction_head & find_direction_tail
// FINAL op_ct = |611|  ver with choosing > elem
//               |739| 100 num -500|500
// FINAL op_ct = |611|  ver with handling pb



// 20 num
// FINAL op_ct = |180|  ver with sa ra
// FINAL op_ct = |174|
// FINAL op_ct = |104| ver with rolling
// FINAL op_ct = |81| ver with rolling + find_direction_head
// FINAL op_ct = |95| ver with rolling + find_direction_head & find_direction_tail
// FINAL op_ct = |61|  ver with choosing > elem

// 500 num (0 | 500)
// FINAL op_ct = |7456|
// FINAL op_ct = |4712|  ver with handling pb


// 100 num (0 | 1000)   >=100, 620      >=50 522
// 500 num (0 | 1000)   >=100, 4511     >=50 4551


//                     PRINT IN LOWCOSTER LOOP
// **********************************************************************
        
// printf("elem =         |%d|  index |%d|  pop_ cost |%d|   ins_cost |%d|  ra |%d|  rb |%d|  rra |%d|  rrb |%d|  total |%d|\n", head->val, index, pop_cost, ins_cost, stor->ra, stor->rb, stor->rra, stor->rrb, total);
// printf("cur_min_cost = |%d|\n", stor->min_cost);
// printf("pop_val = |%d|\n", stor->pop_val);

// **********************************************************************



//              VERSION Previous

// void        pb_max_min(t_frame *stor)
// {
//     int     i;
//     int     j;
//     t_node  *head;
//     t_node  *tmp_head;

//     head = stor->a->head;
//     i = (j = stor->a->size) - j;
//     find_max_min(stor);
//     while (i < j)
//     {
//         if (head->val != stor->max && head->val != stor->min)
//             do_operation("pb", stor);
//         else
//             do_operation("ra", stor);
//         i++;
//         tmp_head = stor->a->head;
//         head = tmp_head ? tmp_head : NULL;        
//     }
//     if (stor->a->head->val > stor->a->head->next->val)
//         do_operation("sa", stor);
// }



/*
**  vereion discribtion: find min cost to run sa \ ra mod *******************************************************
*/

// size_t      find_insert_cost(t_frame *stor, int index, int val)
// {
//     size_t      ct;
//     size_t      cost;
//     t_node      *head;

//     head = stor->a->head;
//     ct = (cost = 1) - 1;                       // (pb)
//     if (val < head->val && val > stor->a->tail->val)
//         return (cost);
//     while (ct < stor->a->size)
//     {
//         if (val < stor->a->tail->val && val < head->val && stor->a->tail->val != stor->max)
//             cost += 2;
//         else if ((val > stor->a->tail->val || stor->a->tail->val == stor->max) && val > head->val)
//         {
//             cost += 1;
//             if (head->next && head->next->val != stor->min && val > head->next->val)
//                 cost += 1;
//         }
//         head = head ? head->next : NULL;
//         ct++;
//     }
//     return (cost);
// }



// void        find_lowcost(t_frame *stor)                            // VERSION 2 (PREVIOUS)
// {
// //  FIND ONLY INSERTION COST???
// //  POP COST IS CHEPER AND CHEAPER BY THE TIME. BUT INSERTIONS COST - REVERSE

//     int     total_cost;
//     int     ins_cost;
//     int     index;
//     // size_t     adj_cost;
//     int     ct;              // put size_t to ct in all func

//     t_node  *head;
//     head = stor->b->head;
//     stor->min_cost = stor->pop_cost = (total_cost = index = ct = 0);     // stor->min_cost = 
//     stor->pop_val = head->val;
//     while (ct < stor->b->size)
//     {
//         printf("BEFORE_min_cost = |%d|\n", stor->min_cost);
//         index = (ct > (stor->b->size / 2) && stor->b->size != 1) ? stor->b->size - ct : ct;   // rrb 
//         stor->rrb = (index == stor->b->size - ct) ? true : false;      // 1 = rr(b) 0 = r(b)

//         ins_cost = find_insert_cost(stor, head->val);
//         // adj_cost = check_adjacent(stor, head);
//         total_cost = ins_cost + index;
//         total_cost = stor->rrb && stor->rra_ct ? total_cost - stor->rra_ct : total_cost; // rrb + rra = rrr
//         total_cost = !stor->rrb && stor->ra_ct ? total_cost - stor->ra_ct : total_cost;  // rb + ra = rr
        
//         total_cost = stor->rrb && stor->rra_ct ? total_cost - stor->rra_ct : total_cost - stor->ra_ct; //  ins_cost + index;

//         // stor->pop_cost = stor->min_cost > total_cost ? index : stor->pop_cost;
//         // stor->min_cost = stor->min_cost == 0 ? total_cost : stor->min_cost;
//         stor->min_cost = (stor->min_cost > total_cost || stor->min_cost == 0)  ? total_cost : stor->min_cost;
//         stor->pop_val = stor->min_cost > total_cost ? head->val : stor->pop_val;        // stor->min_cost > total_cost
        
//         // put here check fot pop elem < than equal cost elem ((elem 18, cost 2 | elem 12, cost 2 = pop_cost for elem 12))
        
        
//         printf("elem =         |%d|  index |%d|  rrb |%s|  ins_cost |%d|  rra_ct |%d|  ra_ct|%d|  total_cost |%d|\n", head->val, index, stor->rrb ? "true" : "false", ins_cost, stor->rra_ct, stor->ra_ct, total_cost);
//         printf("cur_min_cost = |%d|\n", stor->min_cost);
//         // printf("cur_pop_cost = |%ld|\n", stor->pop_cost);
//         printf("pop_val = |%d|\n", stor->pop_val);

//         head = head ? head->next : NULL;
//         ct++;
//     }
//     printf("\n FIND DIRECTION POP_VAL\n");
//     stor->rra_ct = stor->ra_ct = 0;
//     if (stor->pop_val < stor->a->tail->val && stor->pop_val < stor->a->head->val && stor->a->tail->val != stor->max)
//         find_direction_tail(stor, stor->pop_val);
//     else if ((stor->pop_val > stor->a->tail->val || stor->a->tail->val == stor->max) && stor->pop_val > stor->a->head->val)    
//         find_direction_head(stor, stor->pop_val);

//     printf("FINAL_min_cost = |%d|\n", stor->min_cost);
//     // printf("FINAL_pop_cost = |%ld|\n", stor->pop_cost);
//     printf("FINAL_pop_val = |%d|\n", stor->pop_val);
// }



// void        find_lowcost(t_frame *stor)                      // VERSION 1 (OLD)
// {

// //  FIND ONLY INSERTION COST???
// //  POP COST IS CHEPER AND CHEAPER BY THE TIME. BUT INSERTIONS COST - REVERSE

//     int     total_cost;
//     int     ins_cost;
//     int     index;
//     // size_t     adj_cost;
//     int     ct;              // put size_t to ct in all func

//     t_node  *head;
//     head = stor->b->head;
//     stor->min_cost = stor->pop_cost = (total_cost = index = ct = 0);     // stor->min_cost = 
//     stor->pop_val = head->val;
//     while (ct < stor->b->size)
//     {
//         printf("BEFORE_min_cost = |%d|\n", stor->min_cost);
//         index = (ct > (stor->b->size / 2) && stor->b->size != 1) ? stor->b->size - ct : ct;   // rra 
//         stor->rrb = (index == stor->b->size - ct) ? true : false;      // 1 = rr(b) 0 = r(b)

//         ins_cost = find_insert_cost(stor, head->val);
//         // adj_cost = check_adjacent(stor, head);
//         total_cost = ins_cost + index;
//         total_cost = stor->rrb && stor->rra_ct ? total_cost - stor->rra_ct : total_cost; // rrb + rra = rrr
//         total_cost = !stor->rrb && stor->ra_ct ? total_cost - stor->ra_ct : total_cost;  // rb + ra = rr
        
//         total_cost = stor->rrb && stor->rra_ct ? total_cost - stor->rra_ct : total_cost - stor->ra_ct; //  ins_cost + index;

//         // stor->pop_cost = stor->min_cost > total_cost ? index : stor->pop_cost;
//         // stor->min_cost = stor->min_cost == 0 ? total_cost : stor->min_cost;
//         stor->min_cost = (stor->min_cost > total_cost || stor->min_cost == 0)  ? total_cost : stor->min_cost;
//         stor->pop_val = stor->min_cost > total_cost ? head->val : stor->pop_val;        // stor->min_cost > total_cost
        
//         // put here check fot pop elem < than equal cost elem ((elem 18, cost 2 | elem 12, cost 2 = pop_cost for elem 12))
        
        
//         printf("elem =         |%d|  index |%d|  rrb |%s|  ins_cost |%d|  rra_ct |%d|  ra_ct|%d|  total_cost |%d|\n", head->val, index, stor->rrb ? "true" : "false", ins_cost, stor->rra_ct, stor->ra_ct, total_cost);
//         printf("cur_min_cost = |%d|\n", stor->min_cost);
//         // printf("cur_pop_cost = |%ld|\n", stor->pop_cost);
//         printf("pop_val = |%d|\n", stor->pop_val);

//         head = head ? head->next : NULL;
//         ct++;
//     }
//     printf("\n FIND DIRECTION POP_VAL\n");
//     stor->rra_ct = stor->ra_ct = 0;
//     if (stor->pop_val < stor->a->tail->val && stor->pop_val < stor->a->head->val && stor->a->tail->val != stor->max)
//         find_direction_tail(stor, stor->pop_val);
//     else if ((stor->pop_val > stor->a->tail->val || stor->a->tail->val == stor->max) && stor->pop_val > stor->a->head->val)    
//         find_direction_head(stor, stor->pop_val);

//     printf("FINAL_min_cost = |%d|\n", stor->min_cost);
//     // printf("FINAL_pop_cost = |%ld|\n", stor->pop_cost);
//     printf("FINAL_pop_val = |%d|\n", stor->pop_val);
// }





// void        roll_both(t_frame *stor)
// {
//     int     i;
//     int     j;

//     i = j = 0;

//     // while (stor->rra_ct || stor->ra_ct)

//     // while (stor->pop_val != stor->b->head->val)
//     while ((i < stor->ra_ct || j < stor->rra_ct) || stor->pop_val != stor->b->head->val)
//     {           
//         printf ("{ roll BOTH }\n");
//         if (stor->pop_val > stor->a->head->val && !stor->rrb)     // ra
//         {
//             if (stor->rrb)
//             {
//                 do_operation("ra", stor);
//                 do_operation("rrb", stor);
//             }
//             else
//                 do_operation("rr", stor);
//             i++;
//         }
//         else if (stor->pop_val < stor->a->tail->val && stor->a->tail->val != stor->max)     // rra
//         {
//             if (stor->rrb)
//                 do_operation("rrr", stor);
//             else
//             {
//                 do_operation("rra", stor);
//                 do_operation("rb", stor);
//             }
//             j++;
//         }
//     }
// }




// void        roll_stacks(t_frame *stor)
// {
//     printf("{ 1 }\n");
//     int ct;

//     ct = 0;

            // VERSION 3 (rolling B)

    // while (stor->pop_val > stor->a->head->val && (stor->ra_ct || stor->rra_ct))
    // {
    //     printf ("{ roll A }\n");
    //     if (stor->pop_val > stor->a->head->val && stor->ra_ct)             // PUT DIRECTION HERE
    //     {
    //         printf ("{ do ra (>head)}\n");
    //         do_operation("ra", stor);
    //         stor->ra_ct--;
    //     }
    //     else if (stor->pop_val > stor->a->head->val && stor->rra_ct)
    //     {
    //             printf ("{ do rra (>head)}\n");
    //             do_operation("rra", stor);
    //             stor->rra_ct--;
    //     }
    // }
    // while ((stor->pop_val < stor->a->tail->val && stor->a->tail->val != stor->max) && (stor->ra_ct || stor->rra_ct))
    // // while (stor->pop_val < stor->a->tail->val && (stor->ra_ct || stor->rra_ct))
    // { 
    //         //&& stor->a->tail->val != stor->max)
    //        if (stor->pop_val < stor->a->tail->val && stor->rra_ct)
    //        {
    //            printf ("{ do rra (<tail)}\n");
    //            do_operation("rra", stor);
    //            stor->rra_ct--;   
    //        }
    //        else if (stor->pop_val < stor->a->tail->val && stor->ra_ct)
    //        {
    //            printf ("{ do ra (<tail)}\n");
    //            do_operation("ra", stor);
    //            stor->ra_ct--;
    //        }
    //         // PUT HERE FIND_INSERT_DIRECTION_TAIL CONDITIONS !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
    // }

        
            // VERSION 2

    // while (ct < stor->pop_cost || (stor->pop_val < stor->a->tail->val ||
    //     stor->pop_val > stor->a->head->val))
    // {
    //     if (stor->pop_val < stor->a->tail->val && stor->a->tail->val != stor->max)
    //     {
    //         if (stor->rrb)
    //             do_operation("rrr", stor);
    //         else
    //         {
    //             do_operation("rra", stor);
    //             do_operation("rb", stor);
    //         }
    //     }
    //     else if (stor->pop_val > stor->a->head->val && stor->a->head->val != stor->max)
    //     {
    //         if (stor->rrb)
    //         {
    //             do_operation("ra", stor);
    //             do_operation("rrb", stor); 
    //         }
    //         else
    //             do_operation("rr", stor);
    //     }
    //     else if (stor->pop_val > stor->a->tail->val && stor->pop_val < stor->a->head->val)        // tail < val < head
    //     {
    //         if (stor->rrb)
    //             do_operation("rrb", stor);
    //         else
    //             do_operation("rb", stor);
    //     }



            // VERSION 1

//     while (ct < stor->pop_cost && stor->a->tail->val != stor->min)
//     {
//         if (stor->a->tail->val != stor->max)
//         {
//             if (stor->rrb)
//                 do_operation("rrr", stor);
//             else
//             {
//                 do_operation("rra", stor);
//                 do_operation("rb", stor);
//             }
//         }
//         else
//         {
//             if (stor->rrb)
//                 do_operation("rrb", stor);
//             else
//                 do_operation("rb", stor);
//         }
//         // printf("roll loop #%d\n", ct);
//         // printf("ct = |%d|  pop_cost = |%ld|\n", ct, stor->pop_cost);
//         // t_node *p = stor->a->head;
//         // printf("----a----\n");
//         // while (p)
//         // {
//         //     printf("%d\n", p->val);
//         //     p = p ? p->next : NULL;
//         // }
//         // printf("----b----\n");
//         // t_node *p1 = stor->b->head;
//         // while (p1)
//         // {
//         //     printf("%d\n", p1->val);
//         //     p1 = p1 ? p1->next : NULL;
//         // }    
//         // poinerts ??
//         ct++;
//     }
// }        

// void        roll_back(t_frame *stor)
// {
//     while (stor->a->head->val != stor->min && stor->a->tail->val != stor->max)
//         do_operation("rra", stor);
// }

// void        put_elem(t_frame *stor)
// {
//     int     ct;
//     int     val;
//     t_node *p;
//     t_node *p1;
    
//     do_operation("pa", stor);
//         printf("-------put elem PUSH #-------\n");
//         p = stor->a->head;
//         printf("----a----\n");
//         while (p)
//         {
//             printf("%d\n", p->val);
//             p = p ? p->next : NULL;
//         }
//         printf("----b----\n");
//         p1 = stor->b->head;
//         while (p1)
//         {
//             printf("%d\n", p1->val);
//             p1 = p1 ? p1->next : NULL;
//         }


//     // do sa / ra / rra             ||| val > tail && val < head - correct
    
//     while (stor->a->head->val > stor->a->head->next->val ||
//     (stor->a->head->val < stor->a->tail->val && stor->a->tail->val != stor->max)) //&& stor->a->head->val < stor->a->tail->val)
//     {
//         while (stor->a->head->val < stor->a->tail->val && stor->a->tail->val != stor->max)
//         {
//             do_operation("rra", stor);
//             do_operation("sa", stor);
//             printf("-------SORT WITH TAIL------- #\n");
//             p = stor->a->head;
//             printf("----a----\n");
//             while (p)
//             {
//                 printf("%d\n", p->val);
//                 p = p ? p->next : NULL;
//             }
//             printf("----b----\n");
//             p1 = stor->b->head;
//             while (p1)
//             {
//                 printf("%d\n", p1->val);
//                 p1 = p1 ? p1->next : NULL;
//             }
//         }
//         // else if ((val > tail->val || tail->val == stor->max) && val > head->val)

//         // ((stor->a->head->val > stor->a->tail->val || stor->a->tail->val == stor->max) ||
//         //     stor->a->head->next && stor->a->head->val > stor->a->head->next->val)
//         while (stor->a->head->next && stor->a->head->val > stor->a->head->next->val)
//         {
//             do_operation("sa", stor);
//             if (stor->a->head->next->next->val != stor->min && stor->a->head->next->val > stor->a->head->next->next->val)
//                 do_operation("ra", stor);
            
//             printf("-------SORT WITH HEAD------- #\n");
//             p = stor->a->head;
//             printf("----a----\n");
//             while (p)
//             {
//                 printf("%d\n", p->val);
//                 p = p ? p->next : NULL;
//             }
//             printf("----b----\n");
//             p1 = stor->b->head;
//             while (p1)
//             {
//                 printf("%d\n", p1->val);
//                 p1 = p1 ? p1->next : NULL;
//             }
//         }
//     }
// }

/*
**  *************************************************************************************************************
*/