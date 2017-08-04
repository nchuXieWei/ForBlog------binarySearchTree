#ifndef XWBinaryTree
#define XWBinaryTree

typedef struct BinaryTreeNode {
	int data;
	int frequency;
	struct BinaryTreeNode *left;
	struct BinaryTreeNode *right;
}BinaryTreeNode;

typedef BinaryTreeNode *BinaryTree;

void searchCompare(int data); //在数组和二叉查找树中查找给定数据是否存在，并输出耗费时间
void Initialize(int size);  //根据size创建size大小的数组及二叉查找树

#endif