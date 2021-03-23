//
//  main.c
//  day03
//
//  Created by waitwalker on 2021/3/18.
//

#include <stdio.h>

int main(int argc, const char * argv[]) {
    // insert code here...
    printf("Hello, World!\n");
    /// 有符号和无符号进行运算,会先将有符号的转换成无符号,无符号的补码是很大的数
    int data1 = -20;
    unsigned int data2 = 10;
    if (data1 + data2) {
        printf(">0\n");
    } else {
        printf("<0\n");
    }
    int data3 = 30;
    int data4 = -50;
    printf("%d\n", data3 + data4);
    /// sizeof计算类型的长度
    
    ///强制类型转换
    int data5 = 18;
    double data6 = 123.456;
    int data7 = (int)data6;
    printf("data7:%d\n",data7);
    
    // 二进制转十进制
    // 1010 = 1 * 2^3 + 0 * 2^2 + 1 * 2^1 + 0 * 2^0
    // 十进制转换为二进制
    // 十进制转二进制 不停的除2
    // %d是有符号输出 需要补码运算
    // %u %x是原样输出 也就是内存原样输出
    // 十六进制转换为10进制
    int data9 = 0xabd12;
    // 2 * 16^0 + 1 * 16^1 + d * 16^2 + b * 16^3 + a * 16^4
    // 2        +      16  + 13 * 16 ^2 + 11 * 16^3 + 10 * 16^4
    // 10 11 13 1 2
    // while 循环
    // 程序必须在循环体中写好退出语句 否则一直循环
    // 步进条件
    printf("\ndata9:%d\n",data9);
    
    /// 具有相同类型的变量 用连续的空间存储 这样的数据结构称为数组
    /// arr[] arr和[]结合是数组 把元素的个数放入中括号中
    /// 用元素的类型定义一个普通变量, 从上往下整体替换
    
    /// 一维数组定义&初始化
    /// 如果是全部初始化,数组的元素个数可以省略 实际的个数有初始化个数决定,不建议用,少用
    /// 数组未被初始化部分自动补0
    int num[10] = {1,3,6,8,9,18};
    for (int i = 0; i < 10; i++) {
        printf("i:%d\n",num[i]);
    }
    
    printf("数组的总大小:%lu\n",sizeof(num));
    printf("数组元素的大小:%lu\n",sizeof(num[0]));
    printf("数组元素的个数:%lu\n",sizeof(num) / sizeof(num[0]));
    
    return 0;
}
