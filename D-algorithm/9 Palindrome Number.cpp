//
//  9 Palindrome Number.cpp
//  D-algorithm
//
//  Created by ZhangChao on 2018/9/20.
//  Copyright © 2018年 YunShiPei. All rights reserved.
//

/*
 Determine whether an integer is a palindrome. An integer is a palindrome when it reads the same backward as forward.
 
 Example 1:
 
 Input: 121
 Output: true
 Example 2:
 
 Input: -121
 Output: false
 Explanation: From left to right, it reads -121. From right to left, it becomes 121-. Therefore it is not a palindrome.
 Example 3:
 
 Input: 10
 Output: false
 Explanation: Reads 01 from right to left. Therefore it is not a palindrome.
 Follow up:
 
 Coud you solve it without converting the integer to a string?
 */

// 参照 reverse integer 的思路
// 1.按照问题描述中负数是永远都不可能成为回文的
// 2.因为输入为int型，如果是回文，反转后还是相等的，不存在int类型越界问题。

#include "9 Palindrome Number.hpp"

bool isPalindrome(int x)
{
    if (x < 0)
    {
        return false;
    }
    
    int result = 0;
    
    int temp = x;
    
    while (x != 0)
    {
        result = result * 10 + x % 10;
        
        x = x / 10;
    }
    
    if (result == temp)
    {
        return true;
    }
    
    return false;
}
