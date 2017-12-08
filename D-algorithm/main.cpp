//
//  main.c
//  算法分析
//
//  Created by ZhangChao on 2017/3/14.
//  Copyright © 2017年 YunShiPei. All rights reserved.
//

#include <stdio.h>
#include "6. ZigZag Conversion.h"


int main(int argc, const char * argv[]) {

    std::string s = "PAYPALISHIRING";
    
    std::string s1 = zigzagString::zigzagString().convert(s,4);
    
    std::cout<<s1<<std::endl;
    
}









