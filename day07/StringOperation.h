//
//  StringOperation.h
//  day07
//
//  Created by waitwalker on 2021/5/7.
//

#ifndef StringOperation_h
#define StringOperation_h

#include <stdio.h>
#include <string.h>

/// 封装获取字符串长度
int lengthOfStr(const char *s);

/// 字符串拷贝
void strcpyOperation(const char *s);

/// 字符串的拼接
void strcatOperation(const char *s);

/// 字符串的比较
int strcmpOperation(const char *s1, const char *s2);

/// 在字符串中查找字符出现的位置
void strchrOperation(const char *s, char ch);

#endif /* StringOperation_h */
