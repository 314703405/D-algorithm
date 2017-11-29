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

using std::string;

string longestString::longestPalindrome(string s)
{
    int n = (int)s.length();
    
    int maxLen = 1;
    
    int logestBegin = 0;
    
    bool table[1000][1000] = {false};
    
    for (int i = 0; i < n; i++)
    {
        table[i][i] = true;
    }
    
    for (int i = 0; i < n-1; i++)
    {
        if (s[i] == s[i + 1])
        {
            table[i][i + 1] = true;
            
            logestBegin = i;
            
            maxLen = 2;
        }
    }
    
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

