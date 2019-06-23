/*
 * 二叉树演示
 * */
#include <stdlib.h>
#include "02tree.h"
//树的初始化函数
void tree_init(tree_t *p_tree) {
    p_tree->p_node = NULL;    //没有节点的空树
}
//树的清理函数
void tree_deinit(tree_t *p_tree) {
    if (!(p_tree->p_node)) {
        //处理不能分解的空树
        return ;
    }
    tree_deinit(&(p_tree->p_node->left));    //清理左子树
    tree_deinit(&(p_tree->p_node->right));   //清理右子树
    free(p_tree->p_node);    //释放根节点
    p_tree->p_node = NULL;
}
//在有序二叉树里查找某个数字的位置
tree_t *tree_search(const tree_t *p_tree, int val) {
    if (!(p_tree->p_node)) {
        //没有节点的空树不可以分解
        return (tree_t *)p_tree;
    }
    if (p_tree->p_node->val == val) {
        //如果根节点里的数字就是要查找
        //的数字
        return (tree_t *)p_tree;
    }
    else if (p_tree->p_node->val > val) {
        //如果根节点里的数字比要查找的
        //数字大就应该在左子树里继续查找
        return tree_search(&(p_tree->p_node->left), val);
    }
    else {
        //如果根节点里的数字比要查找的
        //数字小就应该在右子树里继续查找
        return tree_search(&(p_tree->p_node->right), val);
    }
}
//向有序二叉树里插入新数字的函数
int tree_insert(tree_t *p_tree, int val) {
    node_t *p_node = NULL;
    tree_t *p_tr = tree_search(p_tree, val);  //在有序二叉树里查找要插入的数字所在的位置
    if (p_tr->p_node) {
        //要插入的数字已经存在了
        return 0;
    }
    p_node = (node_t *)malloc(sizeof(node_t));  //动态分配节点记录要插入的数字
    if (!p_node) {
        //动态分配内存失败
        return 0;
    }
    //向动态分配节点里填充内容
    p_node->val = val;
    p_node->left.p_node = NULL;
    p_node->right.p_node = NULL;
    //把动态分配节点挂在找到的方块下面
    p_tr->p_node = p_node;
    return 1;
}
//以中序遍历方式处理有序二叉树里所有节点
void tree_miter(const tree_t *p_tree, pfunc_t p_func) {
    if (!(p_tree->p_node)) {
        //没有节点的树不能分解
        return ;
    }
    tree_miter(&(p_tree->p_node->left), p_func);   //中序遍历左子树里所有节点
    p_func(p_tree->p_node->val);   //处理根节点里的数字
    tree_miter(&(p_tree->p_node->right), p_func);  //中序遍历右子树里所有节点
}









