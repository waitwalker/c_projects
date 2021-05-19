//
//  link.h
//  day10
//
//  Created by waitwalker on 2021/5/19.
//

/// 下面两行是防止头文件重复包含
#ifndef link_h
#define link_h

#include <stdio.h>

typedef struct stu {
    /// 数据域
    int num;
    char name[32];
    float score;
    
    /// 指针域
    struct stu *next;
    
} STU;


#endif /* link_h */
