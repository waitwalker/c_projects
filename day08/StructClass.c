//
//  StructClass.c
//  day08
//
//  Created by waitwalker on 2021/5/12.
//

#include "StructClass.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

struct Data {
    int a;
    int b;
};

typedef struct Data DataStruct;

struct Data2 {
    int c;
    int d;
    DataStruct e;
};

struct stu {
    int num;
    int age;
    char name[32];
};

struct person {
    char c;
    int i;
};

struct Resource {
    int a;
    short b;
    char c;
    short i;
};

typedef struct stu StuStruct;

typedef int * intPoint;

void lengthOfStuct(void) {
    printf("结构体占用空间大小:%lu\n",sizeof(struct stu));
    struct stu lucy; /// lucy是局部变量
    lucy.age = 18;
    strcpy(lucy.name, "张三");
    lucy.num = 99;
    printf("%s\n",lucy.name);
    
    struct stu bob = {
        12,
        18,
        "张世超"
    };
    printf("结构体初始化:%d %d %s\n",bob.num, bob.age, bob.name);
    
    /// 结构体全部清0
    //memset(&bob, 0, sizeof(bob));
    printf("结构体初始化:%d %d %s\n",bob.num, bob.age, bob.name);
    
    struct stu meimei;
    memset(&meimei, 0, sizeof(meimei));
    printf("请输入分数 年龄 姓名:");
    scanf("%d %d %s",&meimei.num, &meimei.age, meimei.name);
    printf("\nmeimei结构体初始化:%d %d %s\n",meimei.num, meimei.age, meimei.name);
    
    meimei.age = bob.age;
    strcpy(meimei.name, bob.name);
    meimei.num = bob.num;
    printf("\nmeimei结构体初始化:%d %d %s\n",meimei.num, meimei.age, meimei.name);
    
    /// 直接赋值
    meimei = lucy;
    printf("\nmeimei结构体初始化:%d %d %s\n",meimei.num, meimei.age, meimei.name);
    memcpy(&bob, &meimei, sizeof(struct stu));
    printf("\nmeimei结构体初始化:%d %d %s\n",meimei.num, meimei.age, meimei.name);
}

void structArray(void) {
    struct stu arr[5] = {
        {100,6,"zhangsan1"},
        {100,7,"zhangsan2"},
        {100,8,"zhangsan3"},
        {100,9,"zhangsan4"},
        {100,10,"zhangsan5"},
    };
    
    printf("结构体数组:%lu\n",sizeof(arr));
    int n = sizeof(arr) / sizeof(arr[0]);
    for (int i = 0; i < n; i++) {
        printf("数组中结构体成员:%d %d %s\n",arr[i].num,arr[i].age,arr[i].name);
    }
    memset(arr, 0, sizeof(arr));
    printf("请输入5个学生信息:");
    for (int i = 0; i < 5; i++) {
        scanf("%d %d %s",&arr[i].num, &arr[i].age, arr[i].name);
    }
    
    int sum = 0;
    for (int i = 0; i < n; i++) {
        printf("输入的数组中结构体成员:%d %d %s\n",arr[i].num,arr[i].age,arr[i].name);
        sum += arr[i].age;
    }
    
    printf("平均年龄为:%d\n",sum / 5);
}

void bubbleSort(void) {
    int arr[6] = {12,46,56,22,77,90};
    
    for (int i = 0; i < sizeof(arr) / sizeof(arr[0]) - 1; i++) {
        for (int j = 0; j < sizeof(arr) / sizeof(arr[0]) - 1 - i; j++) {
            printf("当前第%d轮 第%d个数(%d)和第%d个数(%d)的比较\n",i,j,arr[j],j+1,arr[j+1]);
            /// 正序排列 从小到大
            if (arr[j] > arr[j+1]) {
                int tmp = 0;
                tmp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = tmp;
            }
        }
    }
    char buf[256] = "";
    for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++) {
        sprintf(buf, "%s--%d(%d)",buf,arr[i],i);
    }
    
    printf("排序完的数组:%s\n",buf);
    
    printf("请输入数组元素个数:\n");
    int n = 0;
    scanf("%d",&n);
    /// 根据元素个数申请空间
    int *array = NULL;
    array = (int *)calloc(n, sizeof(int));
    if (array == NULL) {
        return;
    }
    
    printf("请输入%d个int型数据\n",n);
    for (int i = 0; i < n; i++) {
        scanf("%d",array + i);/// 第i个元素的地址
    }
    
    /// 排序
    int flag = 0;
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            if (array[j] > array[j+ 1]) {
                int tmp = array[j];
                array[j] = array[j+1];
                array[j+1] = tmp;
                flag = 1;
            }
        }
        if (flag == 0) {
            break;
        }
        printf("经过了%d轮排序\n",i);
    }
    
    /// 遍历
    char str[1024] = "";
    for (int i = 0; i < n; i++) {
        sprintf(str, "%s--%d(%d)",str,array[i],i);
    }
    
    printf("拼接完的数组元素:%s\n",str);
    
    ///释放空间
    if (array != NULL) {
        free(array);
        array = NULL;
    }
}

void structScanf(void) {
    struct stu arr[5];
    int n = sizeof(arr) / sizeof(arr[0]);
    memset(arr, 0, sizeof(arr));
    printf("请输入%d个学生信息\n",n);
    for (int i = 0; i < n; i++) {
        scanf("%d %d %s",&arr[i].num, &arr[i].age, arr[i].name);
    }
    for (int i = 0; i < n; i ++) {
        printf("第%d个结构体成员:%d %d %s\n",i,arr[i].num,arr[i].age,arr[i].name);
    }
    
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1 -i; j++) {
            if (arr[j].age > arr[j+1].age ) {
                struct stu tmp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = tmp;
            }
        }
    }
    for (int i = 0; i < n; i ++) {
        printf("第%d个结构体成员:%d %d %s\n",i,arr[i].num,arr[i].age,arr[i].name);
    }
}

void choiceSort(void) {
    int arr[10] = {0};
    int n = sizeof(arr) / sizeof(arr[0]);
    int i = 0, j = 0, min = 0;
    printf("请输入%d个int类型数据\n",n);
    for (i = 0; i < n;i++ ) {
        scanf("%d",&arr[i]);
    }
    
    for (i = 0; i < n-1; i++) {
        for (min = i,j=min+1; j < n;j ++) {
            /// 记录一下j的位置
            if (arr[min] > arr[j]) {
                min = j;
            }
        }
        if (min != i) {
            int tmp = 0;
            tmp = arr[i];
            arr[i] = arr[min];
            arr[min] = tmp;
        }
    }
    for (i = 0; i < n; i++) {
        printf("排序后的数据:%d\n",arr[i]);
    }
}

void typedefOperation(void) {
    StuStruct lucy = {
        100,
        12,
        "张三丰"
    };
    int num = 10;
    intPoint p = &num;
    printf("取别名后定义一个结构体变量:%d %d %s\n",(&lucy)->num, lucy.age, lucy.name);
    printf("指针指向的空间内容:%d\n",*p);
    
    StuStruct *p1 = &lucy;
    printf("通过指向获取结构体变量内容:%s\n",p1->name);
}


void structPointer(void) {
    StuStruct *p = NULL;
    
    p = (StuStruct *)calloc(1, sizeof(StuStruct));
    if (p == NULL) {
        printf("error");
        return;
    }
    
    printf("请输入一个学生信息:num age name\n");
    scanf("%d %d %s",&p->num,&p->age,(*p).name);
    
    /// 遍历结构体中的成员
    printf("num:%d age: %d name:%s\n",p->num, p->age,p->name);
    if (p != NULL) {
        free(p);
        p = NULL;
    }
}

void mySetStuData(StuStruct *p) {
    printf("请输入一个学生的信息num age name\n");
    scanf("%d %d %s",&p->num,&p->age,p->name);
}

void myPrint(const StuStruct *p) {
    printf("num:%d age:%d name:%s",p->num,p->age,p->name);
}

void test(void) {
    StuStruct lucy;
    
    /// 初始化 给结构体初始化
    memset(&lucy, 0, sizeof(lucy));
    
    /// 定义一个函数 给lucy成员获取键盘输入
    mySetStuData(&lucy);
    
    myPrint(&lucy);
}

StuStruct *getArrayAddr(int n) {
    return (StuStruct *)calloc(n, sizeof(StuStruct));
}

void inputData(StuStruct *arr, int n) {
    printf("请输入%d个学生信息\n",n);
    for (int i = 0; i < n; i++) {
        scanf("%d %d %s",&arr[i].num, &arr[i].age,arr[i].name);
    }
}

void structUse(void) {
    
    struct Resource resource1;
    printf("%lu\n",sizeof(resource1));
    printf("%p\n",&resource1.a);
    printf("%p\n",&resource1.b);
    printf("%p\n",&resource1.c);
    printf("%p\n",&resource1.i);
    
    struct person person1;
    printf("%lu\n",sizeof(person1));
    printf("%p\n%p\n",&person1.c,&person1.i);
    int n = 0;
    StuStruct *arr = NULL;
    printf("请输入学生个数:\n");
    scanf("%d",&n);
    /// 根据学生的个数, 从堆区申请空间
    arr = getArrayAddr(n);
    if (arr == NULL) {
        printf("err");
        return;
    }
    /// 从键盘 给结构体数组arr 输入数据
    inputData(arr, n);
    
    for (int i = 0; i < n; i++) {
        printf("num:%d age:%d name:%s\n",arr[i].num,arr[i].age,arr[i].name);
    }
    
    if (arr != NULL) {
        free(arr);
        arr = NULL;
    }
}

void structStructOperation(void) {
    struct Data2 data = {1,2,{3,4}};
    printf("%d\n",data.e.a);
}

typedef struct {
    /// 相邻位域可以压缩 但是不能超过自身类型大小
    unsigned char a:2;
    unsigned char :2;/// 无意义位段 只是占位 2位
    unsigned char b:2;
} Data2;

void bitFieldOperation(void) {
    printf("%lu\n",sizeof(Data2));
    Data2 data;
    data.a = 3;/// 位段不能进行超过其基本类型的赋值操作
    printf("%d\n",data.a);
}
