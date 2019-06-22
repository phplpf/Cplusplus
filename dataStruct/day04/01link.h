/*
 * 链表演示
 * */
#ifndef         __01LINK_H__
#define         __01LINK_H__
typedef struct node {
    int val;
    struct node *p_prev;     //指向前一个节点
    struct node *p_next;     //指向后一个节点
} node_t;
typedef struct {
    node_t *p_cur;   //记录遍历过程中上一个操作过的节点.如果是空指针就表示链表没有处于遍历状态，否则链表就处于遍历状态
    node_t head;     //无效头节点
    node_t tail;     //无效尾节点
} link_t;     //代表链表的结构体
//链表初始化函数
void link_init(link_t *);
//链表清理函数
void link_deinit(link_t *);
//判断是否空的函数
int link_empty(const link_t *);
//获得数字个数的函数
int link_size(const link_t *);
//在最后位置插入新数字的函数
int link_append(link_t *, int );
//在链表的最前面插入新数字的函数
int link_add_head(link_t *, int );
//按照从小到大的顺序把新数字
//插入到链表中间
int link_insert(link_t *, int );
//删除最后有效数字的函数
int link_remove_tail(link_t *);
//删除最前面有效节点的函数
int link_remove_head(link_t *);
//从链表里删除某个数字所在的节点
int link_remove(link_t *, int );
//从链表里获得最后有效数字的函数
int link_get_tail(const link_t *, int *);
//获得最前面数字的函数
int link_get_head(const link_t *, int *);
//根据编号获得数字的函数
int link_get(const link_t *, int , int *);
void link_begin(link_t *);
int link_next(link_t *, int *);
#endif         //__01LINK_H__







