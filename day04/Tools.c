//
//  Tools.c
//  day04
//
//  Created by waitwalker on 2021/3/30.
//

#include "Tools.h"

/// 函数的实现
void test1(int array[5], int len) {
    int i = 0;
    printf("请输入%d个int数据",len);
    for (i = 0; i < len; i++) {
        scanf("%d",&array[i]);
    }
}

int getMaxElement(int array[5], int len) {
    int max = array[0];
    for (int i = 0; i < len; i++) {
        if (max < array[i]) {
            max = array[i];
        }
    }
    return max;
}


int getMinElement(int array[5], int len) {
    int min = array[0];
    for (int i = 0; i < len; i++) {
        if (min > array[i]) {
            min = array[i];
        }
    }
    return min;
}
