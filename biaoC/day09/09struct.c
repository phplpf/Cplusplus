/*
 * 结构体演示
 * */
#include <stdio.h>
#include <string.h>
/*struct person {
    int age;
    float height;
    char name[10];
};
typedef struct person person_t;    //给结构体类型起别名*/
typedef struct /*person*/ {   //起了别名就可以省略本身的名称
    int age;
    float height;
    char name[10];
} person_t;
int main() {
    //struct person prsn;    //结构体变量声明语句
    person_t prsn1 = {20, 1.73f, "abc"};    //把别名作为类型名称使用声明结构体变量
    person_t prsn2 = {0};
    person_t *p_person = NULL;
    printf("请输入年龄：");
    scanf("%d", &(prsn1.age));
    printf("请输入身高：");
    scanf("%g", &(prsn1.height));
    scanf("%*[^\n]");
    scanf("%*c");
    printf("请输入姓名：");
    fgets(prsn1.name, 10, stdin);
    if (strlen(prsn1.name) == 9 && prsn1.name[8] != '\n') {
        scanf("%*[^\n]");
        scanf("%*c");
    }
    printf("年龄是%d\n", prsn1.age);
    printf("身高是%g\n", prsn1.height);
    printf("姓名是%s\n", prsn1.name);
    prsn2 = prsn1;   //同类型结构体变量之间可以直接赋值
    printf("年龄是%d\n", prsn2.age);
    printf("身高是%g\n", prsn2.height);
    printf("姓名是%s\n", prsn2.name);
    p_person = &prsn1;    //结构体指针指向prsn1结构体存储区
    printf("年龄是%d\n", p_person->age);
    printf("身高是%g\n", p_person->height);
    printf("姓名是%s\n", p_person->name);
    return 0;
}







