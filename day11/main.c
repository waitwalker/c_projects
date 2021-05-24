//
//  main.c
//  day11
//
//  Created by waitwalker on 2021/5/20.
//

#include <stdio.h>
#include "FileOperation.h"

int main(int argc, const char * argv[]) {
    // insert code here...
    //fileReadOperation();
    //fileWriteOperation();
    //fileReadWriteOperation();
    //fileStringWriteOperation();
    //fileStringReadOperation();
    //fileBlockWriteOperation();
    //fileBlockReadOperation();
    //fileFPrintfOperation();
    //fileFScanfOperation();
    //fileRandomOperation();
    //fileFeofOperation();
    while (1) {
        int cmd = 0;
        printHelp();
        /// 获取键盘输入的指令
        scanf("%d",&cmd);
        if (cmd == 1) {
            /// 加密
            printf("---- 加密 ---\n");
            char sourceFileName[1024] = "/Users/waitwalker/Desktop/工作/github_projects/c_projects/day11/source.txt";
            char dstFileName[1024] = "/Users/waitwalker/Desktop/工作/github_projects/c_projects/day11/dst.txt";
            
            unsigned long fileLength = 0;
            unsigned int password = 0;
            
            /// 1.获取源文件 目的文件名
            getFileName(dstFileName, sourceFileName);
            printf("源文件名称:%s\n",sourceFileName);
            printf("目的文件名称:%s\n",dstFileName);
            /// 2.获取源文件内容
            char *data = readSrcFile(&fileLength,sourceFileName);
            printf("读取到的文件内容:%s\n",data);
            
            /// 3.获取用户输入的密码
            printf("请输入你的密码:\n");
            scanf("%d",&password);
            
            /// 4.对源文件内容进行加密
            data = fileTextEncrypt(data,fileLength,password);
            printf("加密后的内容:%s\n",data);
            
            /// 5. 对加密好的 文件内容 保存到目的文件
            saveFile(data, fileLength, dstFileName);
        } else if(cmd == 2) {
            printf("---- 解密 ---\n");
            char sourceFileName[1024] = "/Users/waitwalker/Desktop/工作/github_projects/c_projects/day11/dst.txt";
            char dstFileName[1024] = "/Users/waitwalker/Desktop/工作/github_projects/c_projects/day11/dec.txt";
            
            unsigned long fileLength = 0;
            unsigned int password = 0;
            
            /// 1.获取源文件 目的文件名
            getFileName(dstFileName, sourceFileName);
            printf("源文件名称:%s\n",sourceFileName);
            printf("目的文件名称:%s\n",dstFileName);
            /// 2.获取源文件内容
            char *data = readSrcFile(&fileLength,sourceFileName);
            printf("读取到的文件内容:%s\n",data);
            
            /// 3.获取用户输入的密码
            printf("请输入你的密码:\n");
            scanf("%d",&password);
            
            /// 4.对源文件内容进行解密
            data = fileTextDecrypt(data, fileLength, password);
            
            /// 5. 对加密好的 文件内容 保存到目的文件
            saveFile(data, fileLength, dstFileName);
        } else if(cmd == 3) {
            printf("---- 退出 ---\n");
            break;
        } else {
            printf("请输入一个正确的选项\n");
        }
    }
    printf("Hello, World!\n");
    return 0;
}
