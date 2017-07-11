//
//  3. Longest Substring.c
//  D-algorithm
//
//  Created by ZhangChao on 2017/7/6.
//  Copyright © 2017年 YunShiPei. All rights reserved.
//

#include "3. Longest Substring.h"
#include <stdlib.h>
#include <string.h>


/*
 Given a string, find the length of the longest substring without repeating characters.
 
 Examples:
 
 Given "abcabcbb", the answer is "abc", which the length is 3.
 
 Given "bbbbb", the answer is "b", with the length of 1.
 
 Given "pwwkew", the answer is "wke", with the length of 3. Note that the answer must be a substring, "pwke" is a subsequence and not a substring.
 */

/**
 * 时间复杂度:O(n)
 * 空间复杂度:O(1)
 
 * 思路:只需要遍历一次字符串,start变量用于存储与上一个子串中出现相同元素的初始位置 i-start 则表示当前子串的长度.
 * 用maxLen存储遍历时得到的最大字符串长度.
 * arr数组各个元素对应ASCII码中编码值,每次遍历用传入的字符串对应位置的ASCII值获取该字符上次出现的位置,如果出现位
 置大于start值,则将该位置记录在对应元素中.
 */
#define max(a,b) a>b?a:b

int lengthOfLongestSubstring(char* s)
{
    int maxLen = 0, start = -1;
   
    int arr[256];
    
    memset(arr, -1, 256 * sizeof(int));
    
    for (int i = 0 ; i < strlen(s); i++)
    {
        int c = s[i];
        
        if (arr[c] > start)
        {
            start = arr[c];
        }
        
        arr[c] = i;
        
        maxLen = max(maxLen, i - start);
    }
    
    return maxLen;
}
