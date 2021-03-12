//
//  main.c
//  day01
//
//  Created by waitwalker on 2021/3/12.
//

#include <stdio.h>
#include "person.h"

double getCircle(double a) {
    return a * a * 3.14;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    printf("Hello, World!\n");
    double c = 0.0;
    printf("请输入半径b:");
    // 输入函数
    scanf("%lf:", &c);
    double a;
    a = getCircle(c);
    printf("%.2f",a);
    return 0;
}


