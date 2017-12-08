//
//  ZigZag Conversion.c
//  D-algorithm
//
//  Created by ZhangChao on 2017/11/29.
//  Copyright © 2017年 YunShiPei. All rights reserved.
//

#include "6. ZigZag Conversion.h"
/*
    The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like
    this: (you may want to display this pattern in a fixed font for better legibility)

    P   A   H   N
    A P L S I I G
    Y   I   R
    And then read line by line: "PAHNAPLSIIGYIR"
    Write the code that will take a string and make this conversion given a number of rows:

    string convert(string text, int nRows);
    convert("PAYPALISHIRING", 3) should return "PAHNAPLSIIGYIR".
*/

using std::string;

string zigzagString::convert(string s,int numRows)
{
    if (numRows <= 1)
    {
        return s;
    }
    
    string *strings = new string[numRows];
    
    // 当前需要往第几行放改元素
    int j = 0;
    
    int flag = 1;
    
    for (int i = 0; i < s.length(); i++)
    {
        strings[j].push_back(s[i]);
        
        if (j == 0)
        {
            flag = 1;
        }
        else if (j == numRows - 1)
        {
            flag = -1;
        }
        
        j += flag;
    }
    
    s.clear();
    
    for (int k = 0; k < numRows; k++)
    {
        s.append(strings[k]);
    }
    
    delete[] strings;
    
    return s;
}
