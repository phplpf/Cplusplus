/*
 * 动态分配内存练习
 * */
#include <stdio.h>
#include <stdlib.h>
typedef struct {
    int row;
    int col;
} pt_t;
typedef struct {
    pt_t pt1;
    pt_t pt2;
} rect_t;
pt_t *midpt(const rect_t *p_rect) {
    pt_t *p_mid = (pt_t *)malloc(sizeof(pt_t));
    if (p_mid) {
        p_mid->row = (p_rect->pt1.row + p_rect->pt2.row) / 2;
        p_mid->col = (p_rect->pt1.col + p_rect->pt2.col) / 2;
    }
    return p_mid;
}
int main() {
    rect_t rect = {0};
    pt_t *p_mid = NULL;
    printf("请输入水平长方形的位置：");
    scanf("%d%d%d%d", &(rect.pt1.row), &(rect.pt1.col), &(rect.pt2.row), &(rect.pt2.col));
    p_mid = midpt(&rect);
    if (p_mid) {
        printf("中心点位置是(%d, %d)\n", p_mid->row, p_mid->col);
        free(p_mid);
        p_mid = NULL;
    }
    return 0;
}





