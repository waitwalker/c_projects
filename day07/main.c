//
//  main.c
//  day07
//
//  Created by waitwalker on 2021/5/7.
//

#include <stdio.h>
#include "StringOperation.h"

int main(int argc, const char * argv[]) {
    
    char string[] = "123456789";
    
    int length = lengthOfStr(string);
    printf("字符串长度:%d\n",length);
    printf("字符串的存储长度:%lu\n",sizeof(string));//这里末尾会有一个\0
    
    strcpyOperation(string);
    
    strcatOperation(string);
    
    char s1[] = "123456";
    char s2[] = "123455";
    
    printf("字符串比较结果:%d\n",strcmpOperation(s1, s2));
    
    strchrOperation(string, '3');
    
    char re[] = "www.sex.hh.sex.com";
    char re2[] = "sex";
    strstrOperation(re, re2);
    
    printf("Hello, World!\n");
    return 0;
}
