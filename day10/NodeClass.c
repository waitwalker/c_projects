//
//  NodeClass.c
//  day10
//
//  Created by waitwalker on 2021/5/18.
//

#include "NodeClass.h"

typedef struct stu {
    /// 数据域
    int num;
    char name[32];
    float score;
    
    /// 指针域
    struct stu *next; /// 保存下一个节点的地址
    
} Stu;
