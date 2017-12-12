//
//  7.cpp
//  D-algorithm
//
//  Created by ZhangChao on 2017/12/9.
//  Copyright © 2017年 YunShiPei. All rights reserved.
//

#include "7. Reverse Integer.hpp"
/*
    Given a 32-bit signed integer, reverse digits of an integer.

    Example 1:

    Input: 123
    Output:  321
    Example 2:

    Input: -123
    Output: -321
    Example 3:

    Input: 120
    Output: 21
    Note:
    Assume we are dealing with an environment which could only hold integers within the 32-bit signed integer range. For the purpose of this problem, assume that your function returns 0 when the reversed integer overflows.
*/

#include <limits.h>

int reverseInteger::reverse(int x)
{
    int result = 0;
    
    while (x != 0) {
        
        int temp = 0;
        
        temp = result * 10 + x % 10;
        
        if (temp / 10 != result)
        {
            return 0;
        }
        
        result = temp;
        
        x /= 10;
    }
    
    return result;
}
