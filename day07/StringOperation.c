//
//  StringOperation.c
//  day07
//
//  Created by waitwalker on 2021/5/7.
//

#include "StringOperation.h"

int lengthOfStr(const char *s) {
    return strlen(s);
}

void strcpyOperation(const char *s) {
    char new[128] = "";
    strcpy(new, s);
    printf("strcpy拷贝后的字符串:%s\n",new);
    
    char ss[124] = "";
    strncpy(ss, s, 3);
    
    printf("strncpy拷贝:%s\n",ss);
}

void strcatOperation(const char *s) {
    char a[12345] = "0";
    strcat(a, s);
    printf("拼接后的字符串:%s\n",a);
    
    char b[125] = "a";
    strncat(b, s, 3);
    printf("字符限制拼接后:%s\n",b);
}


int strcmpOperation(const char *s1, const char *s2) {
    printf("比较前4位:%d\n",strncmp(s1, s2, 4));
    return strcmp(s1, s2);
}

void strchrOperation(const char *s, char ch) {
    char *ret = NULL;
//    ret = strchr(s, ch);
//    printf("查找后的字符串:%s\n",ret);
    
    while (1) {
        ret = strchr(s, '2');
        if (ret == NULL) {
            break;
        }
        *ret = '#';
    }
    printf("查找&替换后的字符串:%s\n",s);
}

void strstrOperation(const char *s1, const char *s2) {
    char *ret = NULL;
    while (1) {
        ret = strstr(s1, s2);
        if (ret == NULL) {
            break;
        }
        memset(ret, '*', strlen(s2));
    }
    printf("查找后&替换后的一些敏感词:%s\n",s1);
    
    /// *(a+i) 展开相当于 a[i]
    
    /// int *p = NULL;
    
    /// 对于指向同一数组的指针变量 不能进行+操作
    /// 指向同一数组的指针变量相减 结果为跳过相应的元素个数 p2-p1 = 3
    
    /// 如果二维数组的列数和指针数组的元素个数一样,并且把二维数组的指针(数组名)赋值给指针数组,则指针数组等价于二维数组
    
    /// a[2][3] 第i行j列的元素地址引用 a代表行地址 a[i]+j 展开就是*(a+i) + j; a+i表示第i行的地址,第(a + i)取*表示当前行第0列的列地址,然后再+j表示第i行第j列的地址
    
    
}

int myAtoi(char *str) {
    int sum = 0;
    while (*str != '\0' && (*str >= '0' && *str <= '9')) {
        sum = sum *10 + *str - '0';
        str++;
    }
    return sum;
}

void atoiOpertaion(const char *s) {
    int a = atoi(s);
    printf("转换成整型的操作:%d\n",a);
    
    long b = atol(s);
    printf("转换成长整型的操作:%ld\n",b);
//    char str[128] = "";
//    printf("请输入字符串:\n");
//    scanf("%s",str);
//    printf("my_atoi:%s\n",str);
    
    char buf[] = "123:456:678";
    
    char *arr[32] = {NULL};
    int i = 0;
    arr[i] = strtok(buf, ":");
    while (arr[i] != NULL) {
        i++;
        arr[i] = strtok(NULL, ":");
    }
    int j = 0;
    while (arr[j] != NULL) {
        printf("%s\n",arr[j]);
        j++;
    }
}

void strtokOpertaions(char *s) {
    
}

void sprintfOperation(void) {
    int year = 2021;
    int month = 5;
    int day = 12;
    char buf[128] = "";
    sprintf(buf, "%d年%d月%d日",year,month,day);
    printf("组装好的字符串:%s\n",buf);
    
    char newBuf[] = "2021年5月12日";
    int newYear = 0;
    int newMonth = 0;
    int newDay = 0;
    sscanf(newBuf, "%d年%d月%d日",&newYear,&newMonth,&newDay);
    printf("解包后的数据:%d %d %d\n",newYear, newMonth, newDay);
    char str[128] = "";
    
    sscanf(buf, "2021%s5月12日",str);
    printf("字符串的解包:%s\n",str);
    int data = 0;
    sscanf("1234 5678", "%*s %d",&data);
    printf("解包后的数据:%d\n",data);
    
    int data1 = 0;
    sscanf("1234 5678", "%*5s%d",&data1);
    printf("拆包后的数据:%d\n",data1);
    int data2 = 0;
    int data3 = 0;
    sscanf("12345678", "%*2d%2d%*2d%d",&data2,&data3);
    printf("拆包后的数据:%d\n%d\n",data2,data3);
    
    char buf1[124] ="";
    sscanf("aaBBcEdef", "%[aBc]",buf1);
    printf("buf1提取后的字符串:%s\n",buf1);
    char buf2[] = "";
    sscanf("abcdEfa","%[a-z]",buf2);
    printf("提取后的字符串:%s\n",buf2);
    
    char buf3[] = "";
    sscanf("dabcdfefdjkk", "%[^ek]",buf3);
    printf("提取到的数据:%s\n",buf3);
    char name[32] = "";
    char addr[32] = "";
    sscanf("lldd@1000phone.com", "%[^@]%*1s%[^.]",name,addr);
    printf("提取到的数据:%s\n",name);
    printf("提取到的数据:%s\n",addr);
    
    int data4 = 0;
    sscanf("[123.143.4][12.97]好的颠三倒四", "[%d.143.4][12.97]好的颠三倒四",&data4);
    printf("提取后的数据:%d\n",data4);
}

void constOperation(void) {
    const int a = 10;
    //a = 100;
    printf("%d\n",a);
    printf("a的地址:%p\n",&a);
    *(int *) (&a) = 10000;
    printf("通过地址赋值:%d\n",a);
    
    int num = 200;
    
    /// const 修饰 *p
    const int *p = &num;
    
    printf("*p的值:%d\n",*p);
    
    //*p = 1000;
    printf("*p的值:%d\n",*p);
    
    int * const p1 = &num;
    //p1 = &num;
    *p1 = 12000;
    printf("*p1:%d\n",*p1);
    
}

