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
    while (1) {
        char cmd[32] = "";
        printf("请输入操作指令:");
        scanf("%s",cmd);
        if (strcmp(cmd, "help") == 0) {
            printf("----- help 帮助 -----\n");
            stuHelp();
        } else if (strcmp(cmd, "insert") == 0) {
            printf("----- insert 插入 -----\n");
        } else if (strcmp(cmd, "print") == 0) {
            printf("----- print 遍历 -----\n");
        } else if (strcmp(cmd, "search") == 0) {
            printf("----- search 查询 -----\n");
        } else if (strcmp(cmd, "delete") == 0) {
            printf("----- delete 删除 -----\n");
        } else if (strcmp(cmd, "free") == 0) {
            printf("----- free 释放 -----\n");
        } else if (strcmp(cmd, "quit") == 0) {
            printf("----- quit 退出 -----\n");
            break;
        }
    }
    printf("Hello, World!\n");
    return 0;
}


