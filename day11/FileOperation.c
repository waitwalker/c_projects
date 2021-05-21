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
void fileOperation(void) {
    
    //得到文件的绝对路径，path是相对路径，通过下面的操作就得到了绝对路径abspath
    char *filePath = "/Users/waitwalker/Desktop/工作/github_projects/c_projects/day11/a.txt";
    
    FILE *fp1 = NULL;
    ///1. 打开一个文件 获得文件指针
    fp1 = fopen(filePath, "r");
    if (fp1 == NULL) {
        perror("fopen");
        return;
    }
    
    ///2. 对文件的操作
    
    
    ///3. 关闭文件
    fclose(fp1);
    
}
