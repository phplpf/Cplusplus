/*
 * 链式物理结构演示
 * */
#include <stdio.h>
typedef struct node {
    int val;
    struct node *p_next;
} node_t;
int main() {
    node_t head = {0}, tail = {0}, node1 = {10}, node2 = {20}, node3 = {30};
    node_t node4 = {25};
    node_t *p_tmp = NULL;
    //把所有节点连成链式物理结构
    head.p_next = &node1;
    node1.p_next = &node2;
    node2.p_next = &node3;
    node3.p_next = &tail;
    //在链式物理结构里插入新节点
    //首先使用for循环找到插入位置
    for (p_tmp = &head;p_tmp != &tail;p_tmp = p_tmp->p_next) {
        node_t *p_first = p_tmp;
        node_t *p_mid = p_first->p_next;
        node_t *p_last = p_mid->p_next;
        if (p_mid == &tail/*p_mid指向尾节点*/ || p_mid->val > node4.val/*p_mid节点里的数字比新数字大*/) {
            //p_first和p_mid中间就是
            //要插入的位置
            p_first->p_next = &node4;   //p_first节点向后指向新节点
            node4.p_next = p_mid;       //新节点向后指向p_mid节点
            break;
        }
    }
    //从链式物理结构里删除一个数字
    for (p_tmp = &head;p_tmp != &tail;p_tmp = p_tmp->p_next) {
        node_t *p_first = p_tmp;
        node_t *p_mid = p_first->p_next;
        node_t *p_last = p_mid->p_next;
        if (p_mid != &tail && p_mid->val == 20) {
            //p_mid指针指向的节点
            //就是要删除的节点
            p_first->p_next = p_last;
            break;
        }
    }
    //使用for循环从前向后依次处理
    //链式物理结构中的每个节点
    for (p_tmp = &head;p_tmp != &tail;p_tmp = p_tmp->p_next) {
        node_t *p_first = p_tmp;
        node_t *p_mid = p_first->p_next;
        node_t *p_last = p_mid->p_next;
        if (p_mid != &tail) {
            //如果p_mid不是指向尾节点
            //就一定指向一个有效节点
            printf("%d ", p_mid->val);
        }
    }
    printf("\n");
    return 0;
}







