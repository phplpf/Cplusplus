/*
 * 链式物理结构演示
 * */
#include <stdio.h>
typedef struct node {
    int val;
    struct node *p_next;
} node_t;
int main() {
    node_t node1 = {10}, node2 = {20}, node3 = {30};
    node_t *p_tmp = NULL;
    node_t head = {0}, tail = {0};
    node1.p_next = &node2;
    node2.p_next = &node3;
    head.p_next = &node1;
    node3.p_next = &tail;
    //用来从头结点开始向后查找某个
    //节点或某个位置的固定代码
    for (p_tmp = &head;p_tmp != &tail;p_tmp = p_tmp->p_next) {
        //指针循环变量从头结点
        //开始向后一直指到最后一个
        //有效节点为止
        node_t *p_first = p_tmp;
        node_t *p_mid = p_first->p_next;   //从第一个有效节点一直指到尾节点
        node_t *p_last = p_mid->p_next;
    }
    return 0;
}





