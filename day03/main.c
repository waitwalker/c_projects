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

    ///强制类型转换
    int data5 = 18;
    double data6 = 123.456;
    int data7 = (int)data6;
    printf("data7:%d\n",data7);

    // 二进制转十进制
    // 1010 = 1 * 2^3 + 0 * 2^2 + 1 * 2^1 + 0 * 2^0
    // 十进制转换为二进制
    // 十进制转二进制 不停的除2
    // %d是有符号输出 需要补码运算
    // %u %x是原样输出 也就是内存原样输出
    // 十六进制转换为10进制
    int data9 = 0xabd12;
    // 2 * 16^0 + 1 * 16^1 + d * 16^2 + b * 16^3 + a * 16^4
    // 2        +      16  + 13 * 16 ^2 + 11 * 16^3 + 10 * 16^4
    // 10 11 13 1 2
    // while 循环
    // 程序必须在循环体中写好退出语句 否则一直循环
    // 步进条件
    printf("\ndata9:%d\n",data9);

    /// 具有相同类型的变量 用连续的空间存储 这样的数据结构称为数组
    /// arr[] arr和[]结合是数组 把元素的个数放入中括号中
    /// 用元素的类型定义一个普通变量, 从上往下整体替换

    /// 一维数组定义&初始化
    /// 如果是全部初始化,数组的元素个数可以省略 实际的个数有初始化个数决定,不建议用,少用
    /// 数组未被初始化部分自动补0
    int num[10] = {1,3,6,8,9,18};
    for (int i = 0; i < 10; i++) {
        printf("i:%d\n",num[i]);
    }

    printf("数组的总大小:%lu\n",sizeof(num));
    printf("数组元素的大小:%lu\n",sizeof(num[0]));
    printf("数组元素的个数:%lu\n",sizeof(num) / sizeof(num[0]));

    /// 二维数组:数组的数组
    /// 分段初始化
    /// 连续初始化
    /// 二维数组的遍历
    int arr[3][4] = {{1,2,3,4},{2,5,5,6},{3,5,2,4}};
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 4; j++) {
            printf("当前的元素:%d\n",arr[i][j]);
        }
    }

    /// 字符数组
    /// 每个元素存储的都是ASCII值
    char ch1[5] = {'h','e','l','l','o'};
    for (int i = 0; i < 5; i++) {
        printf("字符数组中的元素：%c\n",ch1[i]);
        printf("字符数组中的元素ascii值：%d\n",ch1[i]);
    }

    /// 数组名的地址就是数组子一个元素的地址
    printf("数组第一个元素地址：%p\n",&ch1[0]);
    printf("数组名的地址：%p\n",ch1);

    char ch2[] = {'h','e','h','e'};
    char ch3[] = "hehe";
    printf("ch2的空间大小：%lu\n",sizeof(ch2));
    printf("ch3的空间大小：%lu\n",sizeof(ch3));

    char buf[10] = "";
//    gets(buf);
//    printf("获取buf输入的内容：%s",buf);

    /// @parameter
    /// 存放的字符串地址
    /// 能够提取字符串的最大长度
    /// 表示标准输入设备
    /// @return 获取到的字符串首地址
    fgets(buf, sizeof(buf), stdin);
    printf("buf的内容：%s",buf);

    char str[3][16] = {"sxddsf","234safd","s2345ysgdsf"};
    printf("字符串第0个元素：%s\n",str[0]);
    printf("字符串第1个元素：%s\n",str[1]);
    printf("字符串第2个元素：%s\n",str[2]);
    
    char str1[4][16] = {};
    for (int i = 0; i < 4; i++) {
        /// 因为str1代表的就是首元素地址，数组名代表的就是地址
        printf("输入字符串：");
        scanf("%s\n",str1[i]);
    }
    
    for (int i = 0; i < 4; i++) {
        printf("输入的数组str[%d]:%s\n",i,str1[i]);
    }
    /// fgets获取键盘输出字符串
    
    return 0;
}
