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
    
    return 0;
}
