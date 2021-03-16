//
//  main.c
//  day02
//
//  Created by waitwalker on 2021/3/15.
//

#include <stdio.h>

int main(int argc, const char * argv[]) {
    // insert code here...
    printf("Hello, World!\n");
    //一位二进制只能,存放0或者1,或者计算机只能存高电频或低电频 一位用b表示(小写)
    //一个字节=8个位 1B = 8b
    //一个字节范围00000000~11111111
    //计算机开辟一个字节空间,就相当于开辟一个8b二进制位,每一位只能存0或1
    //1KB = 1024B
    //char 字符类型,占1字节空间(8位空间)
    //short 短整型,占2个字节空间(8*2=16位空间)
    //int 整型,占4字节空间(8*4=32位),即当定义int类型变量的时候,会开辟4字节空间来存储变量
    //long 长整型,占8字节空间(8*8=64位);long long, 长长整型看计算机系统,一般占16字节
    //float 单精度浮点型,占4字节空间(8*4=32位)
    //double 双精度浮点型,占8字节空间(8*8=64位)
    //sizeof 测定类型的长度,而不是变量的长度
    //signed有符号,最高位为符号位,其他位为数据位;最高位为1表示负数,最高位为0表示为正数
    //unsigned无符号,自身的二进制位都是数据位,没有符号位
    // singed char 表示的范围 11111111~10000000 ~~ 00000000~01111111
    //signed有符号数默认是省略的
    //struct结构体中的成员拥有独立的空间
    volatile int cdd = 20;
    
    //volatile 防止编译器优化
    struct data {
        char a;
        int bl;
        long ca;
    };
    //union共用体,成员共享同一份空间
    union data2 {
        char a;
        int ba;
        long d;
    };
    unsigned int m = -12;
    printf("%u\n",m);
    int a, b;
    char c[1] = "1";
    printf("c:%s\n",c);
    printf("char 类型占用长度:%lu\n",sizeof(c));
    printf("输入数字a和b\n");
    scanf("%d %d", &a, &b);
    printf("a:%d\nb:%d\n",a, b);
    printf("int类型长度:%lu\n",sizeof(a));
    printf("long类型长度:%lu\n",sizeof(long));
    return 0;
}
