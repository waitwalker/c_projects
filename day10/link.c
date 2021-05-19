//
//  link.c
//  day10
//
//  Created by waitwalker on 2021/5/19.
//

#include "link.h"
#include <stdlib.h>

/// 做的是头部之前插入 要把这个节点插在head之前
STU *insertLink(STU *head, STU tmp) {
    /// 第一次的时候链表应该是空的
    ///1. 从堆区空间申请一个待插入的节点空间
    STU *pi = (STU *)calloc(1, sizeof(STU));
    if (pi == NULL) {
        perror("error");
        return head;
    }
    
    ///2. 将tmp值赋值给 *pi
    *pi = tmp;
    pi->next = NULL;
    
    //3. 插入链表
    if (head == NULL) {
        /// 链表不存在
        head = pi;
    } else {
        /// 链表存在(链表头部插入)
        /// 第一步将pi插入到head之前,指向旧的头部
        pi->next = head;
        /// 第二步将head移到最前面, head指向最新的头节点
        head = pi;
    }
    return head;
}

void printLink(STU *head) {
    if (head == NULL) {
        printf("链表不存在\n");
        return;
    }
    STU *pb = head;/// 不要随意操作头节点
    while (pb != NULL) {
        printf("节点当前信息: %d %s %.1f\n",pb->num, pb->name, pb->score);
        pb = pb->next;
    }
    return;
}
