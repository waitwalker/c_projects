//
//  main.c
//  day06
//
//  Created by waitwalker on 2021/4/29.
//

#include <stdio.h>
#include <stdlib.h>

int main(int argc, const char * argv[]) {
    
    
    int *addr = NULL;
    addr = (int *)malloc(sizeof(int));
    if (addr == NULL) {
        printf("malloc err");
        return 0;
    }
    //memset(addr, 0, sizeof(int));
    *addr = 1000;
    printf("*addr: %d\n",*addr);
    free(addr);
    
    printf("Hello, World!\n");
    return 0;
}
