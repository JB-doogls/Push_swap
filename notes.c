// valgrind --leak-check=full


/*
**      TODO

**              
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
