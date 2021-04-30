//
//  main.c
//  day06
//
//  Created by waitwalker on 2021/4/29.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, const char * argv[]) {
    
    int *p = NULL;
    p = (int *)calloc(1, sizeof(int));
    if (p == NULL) {
        return 0;
    }
    
    *p = 110;
    printf("%d\n",*p);
    
    free(p);
    
    
    int *addr = NULL;
    addr = (int *)malloc(sizeof(int));
    if (addr == NULL) {
        printf("malloc err");
        return 0;
    }
    memset(addr, 0, sizeof(int));
    *addr = 1000;
    printf("*addr: %d\n",*addr);
    free(addr);
    
    /// 为数组申请内存
    int n = 5;
    int *arr = NULL;
    arr = (int *)malloc(n * sizeof(int));
    
    if (arr == NULL) {
        return 0;
    }
    
    memset(arr, 0, n * sizeof(int));
    
    for(int i = 0; i < n; i++) {
        *(arr+i) = i + 100;
    }
    
    for(int i = 0; i < n; i++) {
        printf("arr[%d]:%d\n",i,arr[i]);
    }
    
    int *add = NULL;
    
    arr = (int *)realloc(arr, (10 * sizeof(int)));
    for(int i = 5; i < 10; i++) {
        *(arr+i) = i + 100;
    }
    for(int i = 5; i < 10; i++) {
        printf("arr_add[%d]:%d\n",i,arr[i]);
    }
    
    free(arr);
    
    printf("Hello, World!\n");
    return 0;
}
