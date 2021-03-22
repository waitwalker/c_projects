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
    
    
    printf("\ndata9:%d\n",data9);
    
    return 0;
}
