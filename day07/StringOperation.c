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
    strncpy(<#char *__dst#>, <#const char *__src#>, <#size_t __n#>)
}
