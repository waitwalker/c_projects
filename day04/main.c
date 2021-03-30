//
//  main.c
//  day04
//
//  Created by waitwalker on 2021/3/26.
//

#include <stdio.h>
/// 函数的声明
/// 返回值类型 函数名（形参类型 形参）；


void test(void);

int main(int argc, const char * argv[]) {
    // insert code here...
    printf("Hello, World!\n");
    /// 形参在调用的时候才会开辟空间,形参在函数结束的时候才被释放
    /// 函数名代表的是函数的入口地址
    test();
    printf("函数的入口地址:%p\n",test);
    return 0;
}

/// 函数的实现
void test() {
    printf("This is test.\n");  
}

