/*
 * 二叉树演示
 * */
#ifndef         __02TREE_H__
#define         __02TREE_H__
struct node;
typedef struct {
    struct node *p_node;
} tree_t;
typedef struct node {
    int val;
    tree_t left;
    tree_t right;
} node_t;
typedef void (*pfunc_t)(int);    //给函数指针类型起名字
//树的初始化函数
void tree_init(tree_t *);
//树的清理函数
void tree_deinit(tree_t *);
//向有序二叉树里插入新数字的函数
int tree_insert(tree_t *, int );
//以中序遍历方式处理有序二叉树里所有节点
void tree_miter(const tree_t *, pfunc_t );
#endif          //__02TREE_H__








