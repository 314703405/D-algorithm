//
//  main.c
//  算法分析
//
//  Created by ZhangChao on 2017/3/14.
//  Copyright © 2017年 YunShiPei. All rights reserved.
//

#include <stdio.h>
#include "Add Two Numbers.h"
int main(int argc, const char * argv[]) {
    
    
    return 0;
}

void testTwoNumbers()
{
    struct ListNode *node1 = createList();
    
    printList(node1);
    
    struct ListNode *node2 = createList();
    
    printList(node2);
    
    printList(addTwoNumbers(node1, node2));
}







