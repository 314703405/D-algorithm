//
//  8  String to Integer (atoi).cpp
//  D-algorithm
//
//  Created by ZhangChao on 2017/12/14.
//  Copyright © 2017年 YunShiPei. All rights reserved.
//

#include "8  String to Integer (atoi).hpp"
/*
 Implement atoi to convert a string to an integer.
 
 Hint: Carefully consider all possible input cases. If you want a challenge, please do not see below and ask yourself what are the possible input cases.
 
 Notes: It is intended for this problem to be specified vaguely (ie, no given input specs). You are responsible to gather all the input requirements up front.
 
 Update (2015-02-10):
 The signature of the C++ function had been updated. If you still see your function signature accepts a const char * argument, please click the reload button  to reset your code definition.
 */

#include <sstream>
using std::string;

int stringToInt::atoi(string str)
{
    // 系统接口
    std::stringstream stream(str);

    int i = 0;

    stream >> i;

    return i;
}

int stringToInt::atoi2(string str)
{
    long result = 0;
    
    int indicator = 1;
    
    for(int i = 0; i < str.size();)
    {
        // 找到第一个不是空格的元素
        i = (int)str.find_first_not_of(' ');
        
        // 看看是不是带有正负号
        if (str[i] == '-' || str[i] == '+')
        {
            indicator = (str[i++] == '-') ? -1 : 1;
        }
        
        while ('0'<= str[i] && str[i] <= '9')
        {
            // char - '0' 就是当前位数的int值
            result = result * 10 + (str[i++] - '0');
            
            if (result * indicator >= INT_MAX) return INT_MAX;
            
            if (result * indicator <= INT_MIN) return INT_MIN;
        }
        
        break;
    }
    
    return (int)result * indicator;
}
