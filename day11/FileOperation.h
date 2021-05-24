//
//  FileOperation.h
//  day11
//
//  Created by waitwalker on 2021/5/20.
//

#ifndef FileOperation_h
#define FileOperation_h

#include <stdio.h>

/// 文件读操作
void fileReadOperation(void);

/// 文件写操作
void fileWriteOperation(void);

/// 文件的读写操作
void fileReadWriteOperation(void);

/// 文件的字符串读
void fileStringReadOperation(void);

/// 文件的字符串写
void fileStringWriteOperation(void);

/// 文件数据块读
void fileBlockReadOperation(void);

/// 文件数据块写
void fileBlockWriteOperation(void);

/// 文件格式化读操作
void fileFScanfOperation(void);

/// 文件格式化写操作
void fileFPrintfOperation(void);

/// 文件的随机读写操作
void fileRandomOperation(void);

/// 文件结束检测操作
void fileFeofOperation(void);

/// 打印帮助信息
void printHelp(void);

/// 获取文件名
void getFileName(char *desFileName, char *srcFileName);

#endif /* FileOperation_h */
