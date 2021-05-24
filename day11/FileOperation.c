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

typedef struct {
    char name[16];
    int def;
    int att;
} Hero;


void fileBlockReadOperation(void) {
    Hero hero[4];
    FILE *fp = NULL;
    fp = fopen("/Users/waitwalker/Desktop/工作/github_projects/c_projects/day11/d.txt", "r");
    if (fp == NULL) {
        perror("fp open");
        return;
    }
    fread(hero, sizeof(Hero), 4, fp);
    
    for (int i = 0; i < 4; i++) {
        printf("姓名:%s %d %d\n",hero[i].name,hero[i].def, hero[i].att);
    }
    
    fclose(fp);
}


void fileBlockWriteOperation(void) {
    Hero hero[] = {
        {"德玛西亚",80,60},
        {"盲僧",90,80},
        {"小法",40,85},
        {"小炮",50,90}
    };
    
    int n = sizeof(hero)/sizeof(hero[0]);
    
    FILE *fp = NULL;
    
    fp = fopen("/Users/waitwalker/Desktop/工作/github_projects/c_projects/day11/d.txt", "w");
    if (fp == NULL) {
        perror("fp open");
        return;
    }
    fwrite(hero, sizeof(Hero), n, fp);
    fclose(fp);
}

void fileFPrintfOperation(void) {
    Hero hero[] = {
        {"德玛西亚",80,60},
        {"盲僧",90,80},
        {"小法",40,85},
        {"小炮",50,90}
    };
    
    int n = sizeof(hero)/sizeof(hero[0]);
    
    FILE *fp = NULL;
    
    fp = fopen("/Users/waitwalker/Desktop/工作/github_projects/c_projects/day11/e.txt", "w");
    if (fp == NULL) {
        perror("fp open");
        return;
    }
    
    for (int i = 0; i < n; i++) {
        fprintf(fp, "英雄名称:%s 防御:%d 攻击:%d\n",hero[i].name,hero[i].def,hero[i].att);
    }
    
    fclose(fp);
}

void fileFScanfOperation(void) {
    Hero hero[4];
    FILE *fp = NULL;
    fp = fopen("/Users/waitwalker/Desktop/工作/github_projects/c_projects/day11/e.txt", "r");
    if (fp == NULL) {
        perror("fp open");
        return;
    }
    
    for (int i = 0; i < 4 ; i++) {
        fscanf(fp, "英雄名称:%s 防御:%d 攻击:%d\n",hero[i].name,&hero[i].def,&hero[i].att);
    }
    
    for (int i = 0; i < 4 ; i++) {
        printf("英雄名称:%s 防御:%d 攻击:%d\n",hero[i].name,hero[i].def,hero[i].att);
    }
    
    fclose(fp);
}

void fileRandomOperation(void) {
    FILE *fp = NULL;
    
    fp = fopen("/Users/waitwalker/Desktop/工作/github_projects/c_projects/day11/f.txt", "r");
    if (fp == NULL) {
        perror("fp open");
        return;
    }
    
    long currentPosition = ftell(fp);
    
    printf("当前流指针距离首位置的字节数:%ld\n",currentPosition);
    
    /// 重置到首位置
    rewind(fp);
    
    /// 定位到文件尾部
    fseek(fp, 0, SEEK_END);
    
    long totalFileLength = ftell(fp);
    printf("文件的总长度:%ld\n",totalFileLength);
    
    /// 重置到首位置
    rewind(fp);
    
    /// 根据文件的总大小 合理申请内存空间
    char *fileData = (char *)calloc(1, totalFileLength + 1);/// +1 用于末尾存放\0
    if (fileData == NULL) {
        fclose(fp);
        return;
    }
    
    /// 一次性 将文件数据读到 内存空间
    fread(fileData, totalFileLength, 1, fp);
    
    printf("读到的文件内容:%s\n",fileData);
    free(fileData);
    fclose(fp);
}

void fileFeofOperation(void) {
    /// 判断文件是否到达文件末尾
    ///EOF 宏只能用于文本文件检测文件结束 feof既可以用于文本文件也可以用于二进制文件检测文件结束
    FILE *fp = NULL;
    
    fp = fopen("/Users/waitwalker/Desktop/工作/github_projects/c_projects/day11/f.txt", "r");
    if (fp == NULL) {
        perror("fp open");
        return;
    }
    
    /// feof == 0 表示未结束
    while (!feof(fp)) {
        char cha = getc(fp);
        printf("%c\n",cha);
    }
    
    fclose(fp); 
}

void printHelp(void) {
    printf("********** 1:加密文件 *********\n");
    printf("********** 2:解密文件 *********\n");
    printf("********** 3:退出程序 *********\n");
}

void getFileName(char *desFileName, char *srcFileName) {
    printf("请输入你的源文件名称:");
    scanf("%s",srcFileName);
    printf("请输入你的目标文件名称:");
    scanf("%s",desFileName);
}

char *readSrcFile(unsigned long *fileLength, char *srcFileName) {
    FILE *fp = NULL;
    char *data = NULL;
    fp = fopen(srcFileName, "r");
    if (fp == NULL) {
        perror("fopen");
        return NULL;
    }
    
    /// 获取文件总长度
    /// 将文件流指针 定位到文件尾部
    fseek(fp, 0, 2);
    *fileLength = ftell(fp);
    
    /// 复位文件流指针
    rewind(fp);
    
    /// 根据文件的长度申请堆区空间
    data = (char *)calloc(1, *fileLength);
    if (data == NULL) {
        perror("calloc error");
        return NULL;
    }
    
    /// 一次性读物文件内容
    fread(data, *fileLength, 1, fp);
    
    /// 关闭文件
    fclose(fp);
    
    /// 将读物的文件内容首地址 返回
    return data;
}

char *fileTextEncrypt(char *fileText, unsigned long fileLength, unsigned int password) {
    
    int i = 0;
    for (i = 0; i < fileLength; i++) {
        fileText[i] += password;/// 加密过程
    }
    return fileText;
}
