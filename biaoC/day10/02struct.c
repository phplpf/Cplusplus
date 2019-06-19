/*
 * 结构体演示
 * */
#include <stdio.h>
typedef struct {
    int row;
    int col;
} pt_t;
typedef struct {
    pt_t pt1;
    pt_t pt2;
} rect_t;
rect_t *read(void) {   //把结构体存储区的地址作为返回值传递给调用函数，这样就可以把自己的存储区开放给调用函数使用了
    static rect_t r = {0};
    printf("请输入水平长方形的位置：");
    scanf("%d%d%d%d", &(r.pt1.row), &(r.pt1.col), &(r.pt2.row), &(r.pt2.col));
    return &r;
}
void print(const rect_t *p_r) {
    printf("位置是((%d, %d), (%d, %d))\n", p_r->pt1.row, p_r->pt1.col, p_r->pt2.row, p_r->pt2.col);
}
int area(const rect_t *p_r) {
    int ret = (p_r->pt1.row - p_r->pt2.row) * (p_r->pt1.col - p_r->pt2.col);
    return ret >= 0 ? ret : 0 - ret;
}
pt_t *midpt(const rect_t *p_r) {
    static pt_t mid = {0};
    mid.row = (p_r->pt1.row + p_r->pt2.row) / 2;
    mid.col = (p_r->pt1.col + p_r->pt2.col) / 2;
    return &mid;
}
int main() {
    rect_t *p_r = read();
    pt_t *p_mid = NULL;
    print(p_r);
    printf("面积是%d\n", area(p_r));
    p_mid = midpt(p_r);
    printf("中心点位置是(%d, %d)\n", p_mid->row, p_mid->col);
    return 0;
}




