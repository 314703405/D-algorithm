//
//  Add Two Numbers.c
//  算法分析
//
//  Created by ZhangChao on 2017/7/4.
//  Copyright © 2017年 YunShiPei. All rights reserved.
//

#include "Add Two Numbers.h"
#include <stdlib.h>
#include <string.h>
/*
 You are given two non-empty linked lists representing two non-negative integers. 
 The digits are stored in reverse order and each of their nodes contain a single digit.
 Add the two numbers and return it as a linked list.
 
 You may assume the two numbers do not contain any leading zero, except the number 0 itself.
 
 Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
 Output: 7 -> 0 -> 8
 */

struct ListNode{
    int val;
    struct ListNode *next;
};

struct ListNode *createList()
{
    // node1 每次都新建一个节点
    struct ListNode *node1;
    // node2 每次循环next指针指向上一个节点
    struct ListNode *node2;
    // 头指针
    struct ListNode *headNode;
    printf("动态生成链表,输入-1结束\n");
    node1 = node2 = (struct ListNode *)malloc(sizeof(struct ListNode));
    if (node1 == NULL || node2 == NULL)
    {
        printf("内存不足\n");
        exit(0);
    }
    memset(node1, 0, sizeof(struct ListNode));
    printf("请输入首节点数据\n");
    scanf("%d",&node1->val);
    node1->next = NULL;
    headNode = NULL;
    while (node1->val >= 0)
    {
        if (headNode == NULL)
        {
            headNode = node1;
        }
        else
        {
            node2->next = node1;
        }
        node2 = node1;
        node1 = (struct ListNode*)malloc(sizeof(struct ListNode));
        if (node1 == NULL)
        {
            printf("内存不足\n");
            exit(0);
        }
        memset(node1, 0, sizeof(struct ListNode));
        printf("请输入下一个节点数据\n");
        scanf("%d",&node1->val);
        node1->next = NULL;
    }
    printf("列表创建成功\n");
    
    return headNode;
}

void printList(struct ListNode *listNode)
{
    if (listNode == NULL)
    {
        printf("列表为空\n");
    }
    printf("[");
    while (listNode != NULL) {
        printf(" %d ",listNode->val);
        listNode = listNode->next;
    }
    printf("]\n");
}

/**
 * 时间复杂度:O(n);
 */
struct ListNode *addTwoNumbers(struct ListNode *l1, struct ListNode *l2)
{
    // pHead 用来记录新建的列表头 p1 新建节点 p2 上一个节点信息
    struct ListNode *pHead,*p1,*p2;
    p2 = (struct ListNode *)malloc(sizeof(struct ListNode));;
    pHead = NULL;
    
    // sum/10 求得的商,如果该商不为0,就要再进行一次循环,创建一个新节点.
    int discuss = 0;
    
    // l1和l2 可能长度不同,所以需要用||运算,有可能在俩个链表都为空,但是discuss还有值,需要新建节点
    while (l1 != NULL || l2 != NULL || discuss != 0)
    {
        p1 = (struct ListNode *)malloc(sizeof(struct ListNode));
        memset(p1, 0, sizeof(struct ListNode));
        p1->next = NULL;
        
        // sum:和 remainder:余数
        int sum ,remainder;
        sum = (l1 ? l1->val : 0) + (l2 ? l2->val : 0) + discuss;
        remainder = sum % 10;
        
        p1->val = remainder;
        
        discuss = sum / 10;
        
        if (pHead == NULL)
        {
            pHead = p1;
        }
        else
        {
            p2->next = p1;
        }
        p2 = p1;
        
        l1 = l1 ? l1->next : NULL;
        l2 = l2 ? l2->next : NULL;
    }
    
    return pHead;
}

void testTwoNumbers()
{
    struct ListNode *node1 = createList();
    
    printList(node1);
    
    struct ListNode *node2 = createList();
    
    printList(node2);
    
    printList(addTwoNumbers(node1, node2));
}
