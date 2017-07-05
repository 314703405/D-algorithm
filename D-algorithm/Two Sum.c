//
//  Two Sum.c
//  算法分析
//
//  Created by ZhangChao on 2017/6/29.
//  Copyright © 2017年 YunShiPei. All rights reserved.
//

#include "Two Sum.h"
#include <stdlib.h>
/*
    Given an array of integers, return indices of the two numbers 
    such that they add up to a specific target.

    You may assume that each input would have exactly one solution, 
    and you may not use the same element twice.

    Example:
    Given nums = [2, 7, 11, 15], target = 9,

    Because nums[0] + nums[1] = 2 + 7 = 9,
    return [0, 1].
*/


/**
 * 时间复杂度:O(n^2)
 */
int* twoSum(int* array, int length, int target)
{
    int* a = (int *)malloc(2 * sizeof(int));
    
    for (int i = 0; i < length; i++)
    {
        for (int j = i + 1; j < length; j++)
        {
            if(array[i] + array[j] == target)
            {
                a[0] = i;
                a[1] = j;
                return a;
            }
        }
    }
    return NULL;
}


