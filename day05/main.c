//
//  main.c
//  day05
//
//  Created by waitwalker on 2021/4/7.
//

#include <stdio.h>
#define bool int
#define true 1
#define false 0

void swap_data(int data1, int data2) {
    int tmp = data1;
    data1 = data2;
    data2 = tmp;
    printf("data1:%d; data2:%d\n",data1, data2);
}

// 修改两个外部变量的值,需要将外部变量的地址传递进来,也就是指针作为参数
void change_data(int *p1, int *p2) {
    int tmp;
    tmp = *p1;
    *p1 = *p2;
    *p2 = tmp;
}

void my_array(int arr[5], int n) {
    printf("arr长度:%lu\n",sizeof(arr));
}

int main(int argc, const char * argv[]) {
    
    int myArr[5] = {0};
    my_array(myArr, 1);
    
    //swap_data(100, 102);
    int data1 = 100;
    int data2 = 102;
    printf("data1:%d; data2:%d\n",data1, data2);
    change_data(&data1, &data2);
    printf("data1:%d; data2:%d\n",data1, data2);
    
    /// 数组指针
    /// 苹果对内存存储有优化
    int arrNum[5] = {10,20,30,40,50};
    int (*p12)[5];
    
    p12 = &arrNum;
    printf("%lu\n",sizeof(p12));
    
    printf("p12地址:%p\n",p12);
    printf("p12 + 1地址:%p\n",p12 + 1);
    
    
    printf("%d\n",*(*p12 + 3));
    
    /// 字符串指针数组
    char *strArr[3] = {"hehehe","hhddd","heiheihei"};
    printf("%lu\n",sizeof(strArr));
    printf("%s\n",strArr[1]);
    
    /// 数组名代表的就是第0个元素的地址
    int arr[5] = {1,23,45,56,33};
    int *d;
    d = &arr[3];
    printf("*d的值:%d\n",*d);
    
    printf("数组首地址:%p\n",&arr);
    printf("数组首地址+1:%p\n",&arr + 1);
    
    /// 指向同一数组的指针变量相加减
    int *p10 = arr;
    int *p20 = arr + 3;
    printf("p20 - p10:%ld\n",p20 - p10);
    
    bool v = (p20 > p10) ? true : false;
    printf("指向同一数组两指针变量比较大小:%d\n", v);
    
    int array[5] = {10,20,30,56,33};
    int *pm = array;
    
    printf("pm:%d\n",*pm++);// 这个相当于指针的移动
    printf("pm:%d\n",(*pm)++);
    printf("pm:%d\n",*(pm++));
    
    /// 不要操作没有初始化的指针变量
    int *m1 = NULL;
    printf("m1:%p\n",m1);
    /// 下面直接报错
    //printf("m1的值:%d\n",*m1);
    
    /// 取地址符 和 *解锁音符的区别
    int z = 100;
    int *x = &z;
    /// &z类型为 int *;
    /// *x 类型为 int
    
    void *k = NULL;
    int c = 20;
    k = &c;
    printf("k:%p\n",k);
    printf("*k:%d\n",*(int *)k);
    
    
    /// 指针变量的合法初始化
    int m = 100;
    int *p8 = &m;
    printf("p8地址:%p\n",p8);
    
    /// 指针的取值长度由指针所指向的类型的长度决定
    int num1 = 0x01020304;
    int *p1;
    p1 = &num1;
    short *p2;
    p2 = &num1;
    
    char *p3;
    p3 = &num1;
    
    printf("p2:%x\n",*p2);
    
    printf("p3:%x\n",*p3);
    
    /// 指针的跨度
    int num2 = 100;
    int *p4;
    p4 = &num2;
    printf("p4: %p\n",p4);
    /// p4 + 1 相当于 num2所占用的总字节长度 + 1个字节
    printf("p4 + 1: %p\n",p4 + 1);
    
    short *p5;
    p5 = &num2;
    printf("p5: %p\n",p5);
    printf("p5 + 1: %p\n",p5 + 1);
    
    
    /// 内存是以字节为单位存储的
    
    /// 32位系统中,任何指针(内存地址)都占4Byte
    /// 64位系统中,任何指针(内存地址)都占8字节
    
    int a = 10;
    printf("int 类型指针占用空间:%lu\n",sizeof(&a));
    printf("char 类型指针占用空间:%lu\n",sizeof(char *));
    printf("long 类型指针占用空间:%lu\n",sizeof(long *));
    printf("double 类型指针占用空间:%lu\n",sizeof(double *));
    printf("float 类型指针占用空间:%lu\n",sizeof(float *));
    
    /// 定义num时,系统会为num分配一个合法的空间
    int num = 10;
    int *p;
    p = &num;
    
    printf("num的首地址:%p\n",&num);
    printf("p的首地址:%p\n",p);
    /// *p 星号p表示取p所保存的地址编号所对应的空间内容
    printf("*p的值:%d\n",*p);
    
    *p = 100;
    printf("重新赋值后的*p的值:%d\n",*p);
    
    // insert code here...
    printf("Hello, World!\n");
    return 0;
}
