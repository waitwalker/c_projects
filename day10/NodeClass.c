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


void nodeOperation(void) {
    Stu data1 = {100,"zhangsan1",59};
    Stu data2 = {100,"zhangsan2",89};
    Stu data3 = {100,"zhangsan3",19};
    Stu data4 = {100,"zhangsan4",29};
    Stu data5 = {100,"zhangsan5",39};
    
    /// 链表头
    Stu *head = NULL;
    head = &data1;
    data1.next = &data2;
    data2.next = &data3;
    data3.next = &data4;
    data4.next = &data5;
    data5.next = NULL;
    
    /// 遍历链表
    Stu *pb = head;
    while (pb != NULL) {
        printf("%s\n",pb->name);
        pb = pb->next;///pb移动到下一个节点
    }
    
}
