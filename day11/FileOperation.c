//
//  FileOperation.c
//  day11
//
//  Created by waitwalker on 2021/5/20.
//

#include "FileOperation.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/// c语言中三个特殊的文件指针无需定义
/// 1. stdin 标准输入 默认当前终端(键盘)
/// 2. stdout 标准输出 默认当前终端(屏幕)
/// 3. stderr 标准出错 默认当前终端(屏幕)
void fileReadOperation(void) {
    
    char buffer[1024] = "";
    int i = 0;
    //得到文件的绝对路径，path是相对路径，通过下面的操作就得到了绝对路径abspath
    char *filePath = "/Users/waitwalker/Desktop/工作/github_projects/c_projects/day11/a.txt";
    
    FILE *fp1 = NULL;
    ///1. 打开一个文件 获得文件指针 进行读操作
    fp1 = fopen(filePath, "r");
    if (fp1 == NULL) {
        perror("fopen");
        return;
    }
    
    ///2. 对文件的操作
    while (1) {
        buffer[i] = fgetc(fp1);
        /// 读到文件末尾
        if (buffer[i] == EOF) {
            break;
        }
        i++;
    }
    
    printf("读取的文件内容:%s\n",buffer);
    
    ///3. 关闭文件
    fclose(fp1);
}


void fileWriteOperation(void) {
    /// 一个字节一个字节写 效率很低 为了调试看
    FILE *fp = NULL;
    char buf[128] = "";
    int i = 0;
    char *filePath = "/Users/waitwalker/Desktop/工作/github_projects/c_projects/day11/b.txt";
    fp = fopen(filePath, "w");
    if (fp == NULL) {
        perror("file open");
        return;
    }
    
    /// 使用fputc进行文件的数据写入
    printf("请输入要写入文件的字符串:");
    /// 获取换行符
    fgets(buf,sizeof(buf),stdin);
    /// 去掉键盘输入的换行符
    buf[strlen(buf)-1] = 0;
    while (buf[i] != '\0') {
        fputc(buf[i], fp);
        i++;
    }
    
    /// 文件关闭
    fclose(fp);
}

void fileReadWriteOperation(void) {
    FILE *fp1 = NULL;
    FILE *fp2 = NULL;
    
    /// 以只读的方式打开a.txt
    fp1 = fopen("/Users/waitwalker/Desktop/工作/github_projects/c_projects/day11/a.txt", "r");
    if (fp1 == NULL) {
        perror("fp1 open ");
        return;
    }
    
    /// 以写的形式打开b.txt,如果没有创建,有清空内容
    fp2 = fopen("/Users/waitwalker/Desktop/工作/github_projects/c_projects/day11/b.txt", "w");
    if (fp2 == NULL) {
        perror("fp2 error");
        return;
    }
    
    /// 从fp1 中 每读取一个字节 写入到fp2中
    while (1) {
        char ch;
        /// 读
        ch = fgetc(fp1);
        /// 已经读到文件末尾
        if (ch == EOF) {
            break;
        }
        
        /// 写
        fputc(ch, fp2);
    }
    
    fclose(fp1);
    fclose(fp2);
}

void fileStringWriteOperation(void) {
    
    char *buf[] = {"北京\n","上海\n","天津\n","重庆"};
    int n = sizeof(buf)/sizeof(buf[0]);
    FILE *fp = NULL;
    fp = fopen("/Users/waitwalker/Desktop/工作/github_projects/c_projects/day11/c.txt", "w");
    if (fp == NULL) {
        perror("fp open");
        return;
    }
    for (int i = 0; i < n; i++) {
        fputs(buf[i], fp);
    }
    
    fclose(fp);
}

void fileStringReadOperation(void) {
    FILE *fp = NULL;
    char buf[128] = "";
    fp = fopen("/Users/waitwalker/Desktop/工作/github_projects/c_projects/day11/c.txt", "r");
    if (fp == NULL) {
        perror("fp open");
        return;
    }
    /// fgets从文件中获取字符串 读到\0符时 自动结束
    while (1) {
        char *ret = NULL;
        ret = fgets(buf, sizeof(buf), fp);
        if (ret == NULL) {
            break;
        }
        printf("读取到的字符串:%s\n",buf);
    }
    fclose(fp);
}
