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
void test1(int array[5], int len);
int test2(int array[5], int len);

int main(int argc, const char * argv[]) {
    // insert code here...
    printf("Hello, World!\n");
    /// 形参在调用的时候才会开辟空间,形参在函数结束的时候才被释放
    /// 函数名代表的是函数的入口地址
    /// 如果函数返回值<=4Byte,存放在寄存器.如果>4Byte存放在栈区.
    test();
    printf("函数的入口地址:%p\n",test);
    int arr[5] = {0};
    int n = sizeof(arr) / sizeof(arr[0]);
    test1(arr, n);
    
    printf("数组元素最大值:%d\n",test2(arr, n));
    return 0;
}

/// 函数的实现
void test() {
    printf("This is test.\n");  
}

void test1(int array[5], int len) {
    int i = 0;
    printf("请输入%d个int数据",len);
    for (i = 0; i < len; i++) {
        scanf("%d",&array[i]);
    }
}

int test2(int array[5], int len) {
    int max = array[0];
    for (int i = 0; i < len; i++) {
        if (max < array[i]) {
            max = array[i];
        }
    }
    return max;
}


