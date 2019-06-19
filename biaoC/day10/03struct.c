/*
 * 结构体练习
 * */
#include <stdio.h>
typedef struct {
    int row;
    int col;
} pt_t;
typedef struct {
    pt_t center;     //记录圆心的位置
    int radius;      //记录半径
} circle_t;
//计算圆面积的函数
float area(const circle_t *p_cl) {
    return 3.14f * p_cl->radius * p_cl->radius;
}
//从两个圆里找到面积比较大的圆的函数
circle_t *max(const circle_t *p_cl1, const circle_t *p_cl2) {
    return (circle_t *)(p_cl1->radius >= p_cl2->radius ? p_cl1 : p_cl2);
}
int main() {
    circle_t cl1 = {0}, cl2 = {0};
    circle_t *p_cl = NULL;
    printf("请输入一个圆的位置：");
    scanf("%d%d%d", &(cl1.center.row), &(cl1.center.col), &(cl1.radius));
    printf("请再输入一个圆的位置：");
    scanf("%d%d%d", &(cl2.center.row), &(cl2.center.col), &(cl2.radius));
    printf("第一个圆的面积是%g\n", area(&cl1));
    printf("第二个圆的面积是%g\n", area(&cl2));
    p_cl = max(&cl1, &cl2);
    printf("面积比较大的圆是((%d, %d), %d)\n", p_cl->center.row, p_cl->center.col, p_cl->radius);
    return 0;
}








