#ifndef XWBinaryTree
#define XWBinaryTree

typedef struct BinaryTreeNode {
	int data;
	int frequency;
	struct BinaryTreeNode *left;
	struct BinaryTreeNode *right;
}BinaryTreeNode;

typedef BinaryTreeNode *BinaryTree;

void searchCompare(int data); //������Ͷ���������в��Ҹ��������Ƿ���ڣ�������ķ�ʱ��
void Initialize(int size);  //����size����size��С�����鼰���������

#endif