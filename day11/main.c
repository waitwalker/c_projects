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
            char sourceFileName[1024] = "";
            char dstFileName[1024] = "";
            /// 1.获取源文件 目的文件名
            
            /// 2.获取源文件内容
            
            /// 3.获取用户输入的密码
            
            /// 4.对源文件内容进行加密
            
            /// 5. 对加密好的 文件内容 保存到目的文件
        } else if(cmd == 2) {
            printf("---- 解密 ---\n");
            
            /// 1.获取源文件 目的文件名
            
            /// 2.获取源文件内容
            
            /// 3.获取用户输入的密码
            
            /// 4.对源文件内容进行解密
            
            /// 5. 对加密好的 文件内容 保存到目的文件
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
