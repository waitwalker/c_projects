//
//  StructClass.c
//  day08
//
//  Created by waitwalker on 2021/5/12.
//

#include "StructClass.h"
#include <string.h>

struct stu {
    int num;
    int age;
    char name[32];
};

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
