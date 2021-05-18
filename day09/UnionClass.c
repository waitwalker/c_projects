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


enum Type{
    TypeA = 0,
    TypeB = 1,
    TypeC = 2,
};

void enumOperation(void) {
    enum Type a = TypeA;
    printf("%d\n",a);
}

void unionOPeration(void) {
    union Data data;
    printf("%lu\n",sizeof(union Data));
    data.a = 10;
    data.b = 20;
    data.c = 30;
    printf("%d\n",data.a+data.b+data.c);
    
    enumOperation();
}

