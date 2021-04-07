//
//  main.c
//  day04
//
//  Created by waitwalker on 2021/3/26.
//

#include <stdio.h>
#include "Tools.h"

#define M_DATA 100
#define M_ADD(a,b) a+b
#define M_MUL(a,b) a*b

/// 静态全局变量
static int data8 = 188888;


/// 函数的声明
/// 返回值类型 函数名（形参类型 形参）；

void test(void);
//void test1(int array[5], int len);
//int getMaxElement(int array[5], int len);
//int getMinElement(int array[5], int len);

int data1 = 100;

/// 不同区域的内存 决定了不同变量的特性
/// 静态局部变量 存储在全局区
void staticTest() {
    /// 静态局部变量的作用域函数内,生命周期存在于整个进程
    static int a = 100;
    a++;
    printf("静态局部变量:%d\n",a);
}

/// 静态函数(局部函数)只能在当前源文件中使用,不能在其他源文件中使用
int main(int argc, const char * argv[]) {
    
    char data5 = -10;
    
    printf("data5: %x\n",data5);
    
    char data6 = 10;
    
    printf("data6: %x\n",data6);
    
    /// 正数的源码 就是数据的二进制(最高位为符号位)
    /// 正数的反码 就是源码本身
    /// 正数的补码 就是源码本身
    
    /// 负数的源码 就是数据的二进制(最高位为符号位)
    /// 负数的反码 就是负数的源码符号位不变 其他位取反
    /// 负数的补码 就是负数的反码加1
    
    /// 负数(任何数据)在计算机中存储的都是补码
    
    for (int j = 0; j < M_DATA; j++) {
        printf("当前值:%d\n", j);
    }
    
    printf("带参数的宏:%d\n",M_ADD(10, 20));
    
    printf("宏只是在预编译的时候单纯的替换:%d\n",M_MUL(10 + 10, 20 + 20));
    
    printf("静态全局变量:%d\n",data8);
    
    staticTest();
    staticTest();
    // insert code here...
    printf("Hello, World!\n");
    /// 形参在调用的时候才会开辟空间,形参在函数结束的时候才被释放
    /// 函数名代表的是函数的入口地址
    /// 如果函数返回值<=4Byte,存放在寄存器.如果>   4Byte存放在栈区.
    test();
    printf("函数的入口地址:%p\n",test);
    int arr[5] = {0};
    int n = sizeof(arr) / sizeof(arr[0]);
    test1(arr, n);
    
    printf("数组元素最大值:%d\n",getMaxElement(arr, n));
    printf("数组元素最小值:%d\n",getMinElement(arr, n));
    
    /// 局部变量不初始化 内容随机
    int data = 0;
    printf("局部变量不初始化,内容随机:%d\n",data);
    
    /// 全局变量不初始化,内容为0
    /// 普通全局变量 定义在函数外部的普通变量
    printf("普通全局变量:%d\n",data1);
    
    
    printf("extern修饰的变量声明:%d\n",newData);
    
    return 0;
}



/// 函数的实现
void test() {
    printf("This is test.\n");  
}

//void test1(int array[5], int len) {
//    int i = 0;
//    printf("请输入%d个int数据",len);
//    for (i = 0; i < len; i++) {
//        scanf("%d",&array[i]);
//    }
//}
//
//int getMaxElement(int array[5], int len) {
//    int max = array[0];
//    for (int i = 0; i < len; i++) {
//        if (max < array[i]) {
//            max = array[i];
//        }
//    }
//    return max;
//}
//
//
//int getMinElement(int array[5], int len) {
//    int min = array[0];
//    for (int i = 0; i < len; i++) {
//        if (min > array[i]) {
//            min = array[i];
//        }
//    }
//    return min;
//}

