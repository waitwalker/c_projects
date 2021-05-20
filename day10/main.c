//
//  main.c
//  day10
//
//  Created by waitwalker on 2021/5/18.
//

#include <stdio.h>
#include "NodeClass.h"
#include "link.h"
#include <string.h>
/// 打印数据
void stuHelp(void) {
    printf("#############################\n");
    printf("# help: 打印帮助信息          #\n");
    printf("# insert: 插入链表节点        #\n");
    printf("# print: 遍历链表节点         #\n");
    printf("# search: 查询链表节点        #\n");
    printf("# delete: 删除链表节点        #\n");
    printf("# free: 释放链表             #\n");
    printf("# quit: 退出                #\n");
    printf("############################\n");
}

int main(int argc, const char * argv[]) {
    // insert code here...
    //nodeOperation();
    
    /// 定义一个链表头 并且置为空
    STU *head = NULL;
    while (1) {
        char cmd[32] = "";
        printf("请输入操作指令:");
        scanf("%s",cmd);
        if (strcmp(cmd, "help") == 0) {
            printf("----- help 帮助 -----\n");
            stuHelp();
        } else if (strcmp(cmd, "insert") == 0) {
            printf("----- insert 插入 -----\n");
            printf("请输入节点信息\n");
            STU tmp;
            scanf("%d %s %f",&tmp.num, tmp.name, &tmp.score);
            /// 在链表head之前插入节点
            //head = insertLink(head, tmp);
            
            /// 在链表尾部插入节点
            //head = insertLinkEnd(head, tmp);
            
            /// 有序插入
            head = insertLinkOrder(head, tmp);
        } else if (strcmp(cmd, "print") == 0) {
            printf("----- print 遍历 -----\n");
            printLink(head);
        } else if (strcmp(cmd, "search") == 0) {
            printf("----- search 查询 -----\n");
            printf("请输入要查找的用户名\n");
            char name[64] = "";
            scanf("%s",name);
            STU *ret = NULL;
            ret = searchLink(head, name);
            if (ret != NULL) {
                printf("num:%d name:%s score:%.1f",ret->num,ret->name,ret->score);
            } else {
                printf("没有查找到数据\n");
            }
        } else if (strcmp(cmd, "delete") == 0) {
            printf("----- delete 删除 -----\n");
            printf("请输入将要删除的姓名:\n");
            char name[64] = "";
            scanf("%s",name);
            head = deleteLink(head, name);
        } else if (strcmp(cmd, "free") == 0) {
            printf("----- free 释放 -----\n");
            head = freeLink(head);
        } else if (strcmp(cmd, "quit") == 0) {
            printf("----- quit 退出 -----\n");
            break;
        }
    }
    printf("Hello, World!\n");
    return 0;
}


