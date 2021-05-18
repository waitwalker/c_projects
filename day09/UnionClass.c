//
//  UnionClass.c
//  day09
//
//  Created by waitwalker on 2021/5/18.
//

#include "UnionClass.h"

union Data {
    char a;
    short b;
    int c;
};


void unionOPeration(void) {
    union Data data;
    printf("%lu\n",sizeof(union Data));
    data.a = 10;
    data.b = 20;
    data.c = 30;
    printf("%d\n",data.a+data.b+data.c);
}
