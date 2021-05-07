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
    printf("Hello, World!\n");
    return 0;
}
