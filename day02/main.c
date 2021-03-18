//
//  main.c
//  day02
//
//  Created by waitwalker on 2021/3/15.
//

#include <stdio.h>
typedef int myInt;

int main(int argc, const char * argv[]) {
    //字符是构成字符串的基本 'a'单引号表示取a的ASCII值
    //字符在计算机中存储的是ASCII值
    char ch = 'a';
    printf("%c\n",ch);
    printf("%d\n",ch);
    
    printf("%c\n",ch + 1);
    printf("%d\n",ch + 1);
    char ch1, ch2;
    ch1 = getchar();
    getchar();
    ch2 = getchar();
    printf("%c, %c", ch1, ch2);
    
    printf("A:%d",'0');
    printf("B:%d",'\0');
    printf("C:%d",0);
    printf("D:%d","0");
    
    // insert code here...
    printf("Hello, World!\n");
    //一位二进制只能,存放0或者1,或者计算机只能存高电频或 低电频 一位用b表示(小写)
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
    //auto 自动类型
    //register寄存器变量
    //sizeof 计算类型的大小
    //typedef 为已有的类型取个别名
    //volatile 防止编译器优化
    //register 寄存器变量
    //register 寄存器变量不能取地址
    //volatile防止编译器优化,强制访问内存操作
    //高频繁使用某个变量的时候,系统会把这个变量从内存中优化到寄存器中,通过volatile可以防止编译器优化,强制进行内存操作
    //数据类型包括
    //基本类型
    //构造类型
    //指针类型
    //常量:值是不能修改的
    //变量名代表的就是空间的内容
    //操作变量就是对内容空间的操作
    
    register int num = 30;
    myInt ae = 123;
    
    //不同进制仅仅是数据的表现形式,不会修改数据本身
    //可以在输出前面添加一个#,用于区分不同的进制
    printf("八进制ae:%#o\n", ae);
    printf("十进制ae:%d\n", ae);
    printf("十六进制ae:%#x\n", ae);
    
    printf("ae存储地址:%#x\n", &ae);
    //&ae 代表ae对应空间的起始地址
    //有符号的用%d,无符号输出用%u
    //short 输出可以用%hd或者%d
    short l = 3;
    printf("%d",l);
    
    scanf("%d",&l);
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
    
    /// 字符常量&变量 一般是单引号的
    // 字符常量还包括一些转义字符
    // 输出字符常量用%c
    //字符变量本地存储的是 'a'的ASCII值
    char q = '24';
    return 0;
}
