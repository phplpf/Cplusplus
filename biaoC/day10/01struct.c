/*
 * 结构体演示
 * */
#include <stdio.h>
typedef struct {
    int row;    //记录行号
    int col;    //记录列号
} pt_t;    //记录点位置的结构体类型
typedef struct {
    pt_t pt1;   //记录一个点的位置
    pt_t pt2;   //记录另外一个点的位置
} rect_t;  //记录水平长方形位置的结构体类型
int main() {
    int area = 0;
    rect_t r = {0};
    rect_t *p_r = &r;   //结构体指针指向结构体变量r
    pt_t mid = {0};       //记录水平长方形中心点位置
    pt_t *p_mid = &mid; //结构体指针指向mid结构体变量
    printf("请输入一个水平长方形的位置：");
    /*scanf("%d%d%d%d", &(r.pt1.row), &(r.pt1.col), &(r.pt2.row), &(r.pt2.col));
    printf("水平长方形位置是((%d, %d), (%d, %d))\n", r.pt1.row, r.pt1.col, r.pt2.row, r.pt2.col);*/
    scanf("%d%d%d%d", &(p_r->pt1.row), &(p_r->pt1.col), &(p_r->pt2.row), &(p_r->pt2.col));
    printf("水平长方形的位置是((%d, %d), (%d, %d))\n", p_r->pt1.row, p_r->pt1.col, p_r->pt2.row, p_r->pt2.col);
    //area = (r.pt1.row - r.pt2.row) * (r.pt1.col - r.pt2.col);   //计算水平长方形的面积
    area = (p_r->pt1.row - p_r->pt2.row) * (p_r->pt1.col - p_r->pt2.col);
    area = area >= 0 ? area : 0 - area;   //计算绝对值
    printf("面积是%d\n", area);
    //mid.row = (r.pt1.row + r.pt2.row) / 2;
    //mid.col = (r.pt1.col + r.pt2.col) / 2;
    //printf("中心点位置是(%d, %d)\n", mid.row, mid.col);
    p_mid->row = (p_r->pt1.row + p_r->pt2.row) / 2;
    p_mid->col = (p_r->pt1.col + p_r->pt2.col) / 2;
    printf("中心点位置是(%d, %d)\n", p_mid->row, p_mid->col);
    return 0;
}





