//
//  main.c
//  day05
//
//  Created by waitwalker on 2021/4/7.
//

#include <stdio.h>

int main(int argc, const char * argv[]) {
    /// 内存是以字节为单位存储的
    
    /// 32位系统中,任何指针(内存地址)都占4Byte
    /// 64位系统中,任何指针(内存地址)都占8字节
    
    int a = 10;
    printf("int 类型指针占用空间:%lu\n",sizeof(&a));
    printf("char 类型指针占用空间:%lu\n",sizeof(char *));
    printf("long 类型指针占用空间:%lu\n",sizeof(long *));
    printf("double 类型指针占用空间:%lu\n",sizeof(double *));
    printf("float 类型指针占用空间:%lu\n",sizeof(float *));
    
    /// 定义num时,系统会为num分配一个合法的空间
    int num = 10;
    int *p;
    p = &num;
    
    printf("%p\n",p);
    
    // insert code here...
    printf("Hello, World!\n");
    return 0;
}
