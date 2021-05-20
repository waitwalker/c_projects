//
//  link.c
//  day10
//
//  Created by waitwalker on 2021/5/19.
//

#include "link.h"
#include <stdlib.h>
#include <string.h>

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

STU *insertLinkEnd(STU *head, STU tmp) {
    ///1. 为待插入的节点申请空间 必须要做的
    STU *pi = (STU *)calloc(1, sizeof(STU));
    if (pi == NULL) {
        perror("pi error");
        return head;
    }
    ///2. 将tmp数据赋值到*pi里面
    *pi = tmp;
    pi->next = NULL;
    if (head == NULL) {
        head = pi;
    } else {
        /// 不要随意操作head节点
        STU *pd = head;
        ///2.1 先找到尾部节点
        while (pd->next != NULL) {
            pd = pd->next;
        }
        ///2.2 找到尾部的next 为 NULL时将插入节点赋值给尾节点的next
        if (pd->next == NULL) {
            pd->next = pi;
        }
    }
    return head;
}

STU *insertLinkOrder(STU *head, STU tmp) {
    ///1. 给待插入的节点 申请堆区空间
    STU *pi = (STU *)calloc(1, sizeof(STU));
    if (pi == NULL) {
        perror("error");
        return head;
    }
    ///2. 给申请的空间赋值 将tmp赋值给*pi
    *pi = tmp;
    pi->next = NULL;
    ///3. 将节点插入链表
    ///3.1 链表不存在
    if (head == NULL) {
        head = pi;
    } else {
        ///3.2 链表存在
        ///a 寻找插入点
        STU *pb = head;
        /// 借助一个变量 这个变量保存pb前一个变量
        STU *pf = head;
        /// 如果pb的num比插入的节点的num小同时还没有越界,也就是pb->next != NULL
        /// 第一个判断语句不成立,说明pi >= Pb 插入要在中间或者前部
        /// 第二个判断语句不成立,说明遍历到链表尾部还没有找到比pi大的,说明pi最大,插入在尾部
        while (pb->num < pi->num && pb->next != NULL) {
            /// 先保存pf的位置
            pf = pb;
            pb = pb->next;
        }
        
        // 头部或中部插入
        if (pb->num >= pi->num) {
            /// 头部插入
            if (pb == head) {
                /// 指向旧的头
                pi->next = head;
                /// 更新新的头
                head = pi;
                return head;
            } else {
                /// 中部插入
                pf->next = pi;
                pi->next = pb;
                return head;
            }
            
        } else {
            /// 找到末尾了
            pb->next = pi;
            return head;
        }
    }
    return head;
}

STU *searchLink(STU *head, char *name) {
    ///1. 先判断链表是否存在
    if (head == NULL) {
        perror("link is NULL");
        return NULL;
    }
    
    /// 查询链表
    STU *pb = head;
    /// 判断pb是否是末尾并且比较字符串
    while (pb->next != NULL && strcmp(name, pb->name) != 0) {
        pb = pb->next;
    }
    if (strcmp(name, pb->name) == 0) {
        return pb;
    } else {
        return NULL;
    }
}

STU *deleteLink(STU *head, char *name) {
    /// 判断链表是否存在
    if (head == NULL) {
        perror("link is NULL");
        return head;
    }
    /// 实例化一个操作节点
    STU *pb = head;
    STU *pf = head;
    ///1. 寻找删除点的位置
    /// 不相等往下走 同时 不能越界
    while (strcmp(pb->name, name) != 0 && pb->next != NULL) {
        pf = pb;
        pb = pb->next;
    }
    ///2. 找到删除点的位置
    if (strcmp(pb->name, name) == 0) {
        ///3.判断删除节点的位置
        ///3.1 删除的节点是头节点
        if (pb == head) {
            head = pb->next;
            free(pb);
            printf("删除姓名:%s节点成功\n",name);
            return head;
        } else {
            ///3.2 删除点节点是中部节点
            pf->next = pb->next;
            free(pb);
            printf("删除姓名:%s节点成功\n",name);
            return head;
        }
    } else {
        printf("链表中没有查找到待删除数据节点:%s\n",name);
        return head;
    }
    return head;
}

STU *freeLink(STU *head) {
    /// 判断链表是否为空
    if (head == NULL) {
        perror("link is NULL");
        return head;
    } else {
        /// 创建一个操作节点
        STU *pd = head;
        /// 逐个节点释放
        while (pd != NULL) {
            /// head 先保存下一个节点的位置
            head = pd->next;
            /// 释放pd指向的节点
            free(pd);
            /// pd指向head位置
            pd = head;
        }
        printf("链表释放完成:\n");
        return head;
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


