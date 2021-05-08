//
//  StringOperation.c
//  day07
//
//  Created by waitwalker on 2021/5/7.
//

#include "StringOperation.h"

int lengthOfStr(const char *s) {
    return strlen(s);
}

void strcpyOperation(const char *s) {
    char new[128] = "";
    strcpy(new, s);
    printf("strcpy拷贝后的字符串:%s\n",new);
    
    char ss[124] = "";
    strncpy(ss, s, 3);
    
    printf("strncpy拷贝:%s\n",ss);
}

void strcatOperation(const char *s) {
    char a[12345] = "0";
    strcat(a, s);
    printf("拼接后的字符串:%s\n",a);
    
    char b[125] = "a";
    strncat(b, s, 3);
    printf("字符限制拼接后:%s\n",b);
}
