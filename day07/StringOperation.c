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


int strcmpOperation(const char *s1, const char *s2) {
    printf("比较前4位:%d\n",strncmp(s1, s2, 4));
    return strcmp(s1, s2);
}

void strchrOperation(const char *s, char ch) {
    char *ret = NULL;
//    ret = strchr(s, ch);
//    printf("查找后的字符串:%s\n",ret);
    
    while (1) {
        ret = strchr(s, '2');
        if (ret == NULL) {
            break;
        }
        *ret = '#';
    }
    printf("查找&替换后的字符串:%s\n",s);
}

void strstrOperation(const char *s1, const char *s2) {
    char *ret = NULL;
    while (1) {
        ret = strstr(s1, s2);
        if (ret == NULL) {
            break;
        }
        memset(ret, '*', strlen(s2));
    }
    printf("查找后&替换后的一些敏感词:%s\n",s1);
    
    /// *(a+i) 展开相当于 a[i]
    
    /// int *p = NULL;
    
    /// 对于指向同一数组的指针变量 不能进行+操作
}
