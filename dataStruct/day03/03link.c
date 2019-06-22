/*
 * 链表演示
 * */
#include <stdlib.h>
typedef struct node {
    int val;
    struct node *p_next;
} node_t;
typedef struct {
    node_t head;     //无效头节点
    node_t tail;     //无效尾节点
} link_t;     //代表链表的结构体
//链表初始化函数
void link_init(link_t *p_link) {
    p_link->head.p_next = &(p_link->tail);
    p_link->tail.p_next = NULL;
}
//链表清理函数
void link_deinit(link_t *p_link) {
    node_t *p_first = NULL, *p_mid = NULL, *p_last = NULL;
    while (p_link->head.p_next != &(p_link->tail)) {   //头结点向后不指向尾节点就说明还存在有效节点，这个时候循环就应该继续
        //每次释放最前面的有效节点
        //让三个指针指向链式物理结构
        //最前面的三个节点
        p_first = &(p_link->head);0
        p_mid = p_first->p_next;    //指向第一个有效节点
        p_last = p_mid->p_next;
        p_first->p_next = p_last;   //把p_mid指针指向的第一个有效节点从链式物理结构里摘出来
        free(p_mid);    //释放p_mid指针指向的第一个有效节点
        p_mid = NULL;
    }
}
//判断是否空的函数
int link_empty(const link_t *p_link) {
    return p_link->head.p_next == &(p_link->tail);    //根据头结点后面是不是尾节点判断链表是否为空
}
//获得数字个数的函数
int link_size(const link_t *p_link) {
    int cnt = 0;
    const node_t *p_tmp = NULL, *p_first = NULL, *p_mid = NULL, *p_last = NULL;;
    //用for循环依次处理每个节点
    //只要遇到一个有效节点就数一个
    //数字
    for (p_tmp = &(p_link->head);p_tmp != &(p_link->tail);p_tmp = p_tmp->p_next) {
        p_first = p_tmp;
        p_mid = p_first->p_next;
        p_last = p_mid->p_next;
        if (p_mid != &(p_link->tail)) {
            //p_mid指针不是指向尾节点
            //就一定指向一个有效节点
            cnt++;
        }
    }
    return cnt;
}
//在最后位置插入新数字的函数
int link_append(link_t *p_link, int val) {
    node_t *p_first = NULL, *p_mid = NULL, *p_last = NULL, *p_tmp = NULL;
    node_t *p_node = NULL;
    p_node = (node_t *)malloc(sizeof(node_t));   //动态分配节点用来存放新数字
    if (!p_node) {
        //动态分配内存失败
        return 0;
    }
    //把动态分配节点内容设置好
    p_node->val = val;
    p_node->p_next = NULL;
    //使用for循环找到尾节点前面
    //的位置
    for (p_tmp = &(p_link->head);p_tmp != &(p_link->tail);p_tmp = p_tmp->p_next) {
        p_first = p_tmp;
        p_mid = p_first->p_next;
        p_last = p_mid->p_next;
        if (p_mid == &(p_link->tail)) {
            //p_first和p_mid之间就是
            //最后可以插入的位置
            //(尾节点前面的位置)
            //把新节点插入到p_first和
            //p_mid中间
            p_first->p_next = p_node;
            p_node->p_next = p_mid;
            break;
        }
    }
    return 1;
}
//在链表的最前面插入新数字的函数
int link_add_head(link_t *p_link, int val) {
    node_t *p_node = NULL, *p_first = NULL, *p_mid = NULL, *p_last = NULL;
    p_node = (node_t *)malloc(sizeof(node_t));
    if (!p_node) {
        //动态分配节点失败
        return 0;
    }
    //向动态分配节点里填充内容
    p_node->val = val;
    p_node->p_next = NULL;
    //找到最前面的插入位置
    //(头结点后面的位置)
    //让三个指针指向链式物理结构
    //中最前面的三个节点
    //p_first和p_mid中间就是最前面
    //的可插入位置
    p_first = &(p_link->head);
    p_mid = p_first->p_next;
    p_last = p_mid->p_next;
    //把新节点插入到p_first和p_mid中间
    p_first->p_next = p_node;
    p_node->p_next = p_mid;
    return 1;
}
//按照从小到大的顺序把新数字
//插入到链表中间
int link_insert(link_t *p_link, int val) {
    node_t *p_node = NULL, *p_first = NULL, *p_mid = NULL, *p_last = NULL, *p_tmp = NULL;
    p_node = (node_t *)malloc(sizeof(node_t));    //动态分配节点记录新数字
    if (!p_node) {
        //如果动态分配失败
        return 0;
    }
    //向动态分配节点里填充内容
    p_node->val = val;
    p_node->p_next = NULL;
    //利用for循环找到要插入的位置
    for (p_tmp = &(p_link->head);p_tmp != &(p_link->tail);p_tmp = p_tmp->p_next) {
        p_first = p_tmp;
        p_mid = p_first->p_next;
        p_last = p_mid->p_next;
        if (p_mid == &(p_link->tail) || p_mid->val > val) {
            //如果p_mid指针指向尾节点
            //或者p_mid指向节点里的数字
            //比要插入的数字大就把新
            //节点插入到p_first和p_mid
            //中间
            p_first->p_next = p_node;
            p_node->p_next = p_mid;
            break;
        }
    }
    return 1;
}







