//
//  5. Longest Palindromic Substring.c
//  D-algorithm
//
//  Created by ZhangChao on 2017/7/22.
//  Copyright © 2017年 YunShiPei. All rights reserved.
//

#include "5. Longest Palindromic Substring.h"

/*
 Given a string s, find the longest palindromic substring in s. You may assume that the maximum length of s is 1000.
 
 Example:
 
 Input: "babad"
 
 Output: "bab"
 
 Note: "aba" is also a valid answer.
 Example:
 
 Input: "cbbd"
 
 Output: "bb"
 */

// 示例: 动态规划法
//     0   1   2   3   4   5   6   7   8   9
//     s   d   d   f   j   f   d   d   f   f
// 0 s 1
// 1 d     1   1                   1
// 2 d         1               1
// 3 f             1       1
// 4 j                 1
// 5 f                     1
// 6 d                         1   1
// 7 d                             1
// 8 f                                 1   1
// 9 f                                     1

using std::string;

string longestString::longestPalindrome(string s)
{
    int n = (int)s.length();
    
    int maxLen = 1;
    
    int logestBegin = 0;
    
    bool table[1000][1000] = {false};
    
    // 将二维数组中间一行都初始化为true
    for (int i = 0; i < n; i++)
    {
        table[i][i] = true;
    }
    
    // 遍历一遍字符串,寻找相邻俩个字符相同的子串,并把对应位置设置为true
    for (int i = 0; i < n-1; i++)
    {
        if (s[i] == s[i + 1])
        {
            table[i][i + 1] = true;
            
            logestBegin = i;
            
            maxLen = 2;
        }
    }
    
    // 该层遍历是从第0-2/1-3...0-3/1-4...0-4/1-5...这种模式发起遍历的,直到找到最长串为止
    for (int len = 3; len <= n; len++)
    {
        for (int i = 0; i < n - len + 1; i++)
        {
            int j = i + len - 1;
            
            if (s[i] == s[j] && table[i+1][j-1])
            {
                table[i][j] = true;
                
                logestBegin = i;
                
                maxLen = len;
            }
        }
    }
    
    return s.substr(logestBegin, maxLen);
}

