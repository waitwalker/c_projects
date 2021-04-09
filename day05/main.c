//
//  main.c
//  day05
//
//  Created by waitwalker on 2021/4/7.
//

#include <stdio.h>

int main(int argc, const char * argv[]) {
    
    /// 指针的取值长度由指针所指向的类型的长度决定
    int num1 = 0x01020304;
    int *p1;
    p1 = &num1;
    short *p2;
    p2 = &num1;
    
    char *p3;
    p3 = &num1;
    
    printf("p2:%x\n",*p2);
    
    printf("p3:%x\n",*p3);
    
    /// 指针的跨度
    int num2 = 100;
    
    
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
    
    printf("num的首地址:%p\n",&num);
    printf("p的首地址:%p\n",p);
    /// *p 星号p表示取p所保存的地址编号所对应的空间内容
    printf("*p的值:%d\n",*p);
    
    *p = 100;
    printf("重新赋值后的*p的值:%d\n",*p);
    
    // insert code here...
    printf("Hello, World!\n");
    return 0;
}
