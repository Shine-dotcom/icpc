#include <iostream>
using namespace std;

// 1. 定义二叉树节点结构体（二叉链表）
typedef struct BiTNode {
    char data;               // 节点数据（存储字符A/B/C等）
    struct BiTNode* lchild;  // 左子树指针
    struct BiTNode* rchild;  // 右子树指针
} BiTNode, *BiTree;

// 2. 按先序遍历序列创建二叉树（递归实现）
// 输入：二叉树指针的引用（需修改指针本身，用&）、先序序列、序列索引（用&保证递归中索引递增）
void CreateBiTree(BiTree& T, string pre, int& index) {
    // 1. 终止条件：遇到@（空节点）或索引超出序列长度
    if (index >= pre.size() || pre[index] == '@') {
        T = NULL;  // 空节点
        index++;   // 索引后移（跳过@）
        return;
    }
    // 2. 创建根节点：取当前索引位置的字符
    T = new BiTNode;  // 分配内存
    T->data = pre[index];
    index++;  // 索引后移（处理下一个节点）
    // 3. 递归创建左子树（先序：根→左→右，左子树在前）
    CreateBiTree(T->lchild, pre, index);
    // 4. 递归创建右子树
    CreateBiTree(T->rchild, pre, index);
}

// 3. 先序遍历二叉树（递归）
void PreOrderTraverse(BiTree T) {
    if (T != NULL) {
        cout << T->data << " ";  // 1. 访问根节点
        PreOrderTraverse(T->lchild);  // 2. 遍历左子树
        PreOrderTraverse(T->rchild);  // 3. 遍历右子树
    }
}

// 4. 中序遍历二叉树（递归）
void InOrderTraverse(BiTree T) {
    if (T != NULL) {
        InOrderTraverse(T->lchild);  // 1. 遍历左子树
        cout << T->data << " ";  // 2. 访问根节点
        InOrderTraverse(T->rchild);  // 3. 遍历右子树
    }
}

// 5. 后序遍历二叉树（递归）
void PostOrderTraverse(BiTree T) {
    if (T != NULL) {
        PostOrderTraverse(T->lchild);  // 1. 遍历左子树
        PostOrderTraverse(T->rchild);  // 2. 遍历右子树
        cout << T->data << " ";  // 3. 访问根节点
    }
}

// 6. 释放二叉树内存（避免内存泄漏）
void DestroyBiTree(BiTree& T) {
    if (T != NULL) {
        DestroyBiTree(T->lchild);  // 先释放左子树
        DestroyBiTree(T->rchild);  // 再释放右子树
        delete T;  // 最后释放根节点
        T = NULL;  // 指针置空，防止野指针
    }
}

int main() {
    // 实验要求的先序序列
    string preSequence = "AB@DG@@@CE@H@@F@@";
    BiTree T;  // 二叉树根节点
    int index = 0;  // 序列索引，初始为0

    // 1. 创建二叉树
    CreateBiTree(T, preSequence, index);
    cout << "二叉树创建完成！" << endl << endl;

    // 2. 三种遍历输出
    cout << "先序遍历结果：";
    PreOrderTraverse(T);
    cout << endl;

    cout << "中序遍历结果：";
    InOrderTraverse(T);
    cout << endl;

    cout << "后序遍历结果：";
    PostOrderTraverse(T);
    cout << endl;

    // 3. 释放内存
    DestroyBiTree(T);
    return 0;
}